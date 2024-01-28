#include "game.hpp"
Game::Game(Layout *l, Map *m, Player *p, p_base_en b_en, p_pro pr)
{
    this->layout = l;
    this->map = m;
    this->player = p;
    this->base_en = b_en;
    this->proiettile= pr;
        
    
}
int Game::updateJump(WINDOW* game, Player *p, Map *map, bool isJump, int i){

    if(i<=player->jump_max && !map->platformAbove(p->x, p->y) && !(p->y == 0)) {  // Interrompi il salto se c'è una piattaforma sopra. 
        p->y=p->y-1;
        i=i+1;
        mvwaddch(game, p->y + 1, p->x, ' ');
        wrefresh(game);
        
        mvwaddch(game, p->y, p->x, '@');
        wrefresh(game);

    }
    else{
        player->isJumping=false;
        this->counter=0;
        i=0;
    }
    return i;
}

p_base_en Game::b_update_enemy( p_base_en base_en, WINDOW* game, Map *map, Player *player, p_pro proiettile){
// Aggiorna la posizione e disegna i nemici vivi
    if (base_en != nullptr)
    {
        p_base_en count = base_en;
        p_base_en prev = nullptr;

        while (count != nullptr)
        {
            if (count->b_en->enemyattack(player->x, player->y) && contatore <= 0){
              player->health = player->health-2;
               contatore = 20;
            }
            if (!count->b_en->dead)
            {   if(count->b_en->timer==20){
                count->b_en->sparareProiettile(player->x, player->y);
                count->b_en->timer=0;
            }
                count->b_en->timer+= 1;
                int deltaX = player->x - count->b_en->x_;
                if(deltaX>0 && player->x-1!= count->b_en->x_ && !Base_isPositionOccupied(layout->game,  count->b_en->x_,  count->b_en->y_, deltaX)){
                    count->b_en->move(game, map, 'r');
                }
                if(deltaX<0 && player->x+1!= count->b_en->x_ && !Base_isPositionOccupied(layout->game,  count->b_en->x_,  count->b_en->y_, deltaX)){
                    count->b_en->move(game, map, 'l');
                }
                
            p_pro proiettileNemico = count->b_en->proiettili;
            while (proiettileNemico != NULL) {
                if (proiettileNemico->pro != nullptr && proiettileNemico->pro->isAttivo()) {
                    proiettileNemico->pro->move(layout->game, proiettileNemico, proiettileNemico->pro->dir);
                    
                    if((proiettileNemico->pro->x==player->x || proiettileNemico->pro->x==player->x-1
                    || proiettileNemico->pro->x==player->x+1)&& proiettileNemico->pro->y==player->y){
                        if(player->shield - count->b_en->damage >=0){
                            player->shield = player->shield - count->b_en->damage;
                        }
                        else if(player->shield - count->b_en->damage <0){
                            player->health = player->health + player->shield - count->b_en->damage;
                            player->shield =0;
                        }
                        else if(player->shield==0){
                        player->health = player->health - count->b_en->damage;
                        
                        }

                    }
                }
                proiettileNemico = proiettileNemico->next;
            }
            
            count->b_en->proiettili = pro_tail_delete(count->b_en->proiettili, map, player);

                count->b_en->draw(game);                            
                prev = count;
                count = count->next;
            }
            else
            {
                // Rimuovi il nemico morto dalla lista
                if (prev != nullptr)
                {
                    prev->next = count->next;
                    delete count->b_en;
                    delete count;
                    count = prev->next;
                }
                else
                {
                    base_en = count->next;
                    delete count->b_en;
                    delete count;
                    count = base_en;
                }
            }
        }

        // Rimuovi i nemici morti
        base_en = e_tail_delete(base_en, map, proiettile, player);
    }
    return base_en;
}

void Game::drawMap (Layout *game_window, Map *game_map){
    for (int i = 0; i < MAX_X; i++){   
        for (int j = 0; j < MAX_Y; j++){
            if (map->isPlatform(i, j)){

                srand(random_number+rooms->current_room+i+j);

                move(j, i);
                mvwprintw(layout->game, j, i, "=");
                int tempI=i, tempJ=j;

                //Disegna le box (| ? |) sulle piattaforme designate
                if(!map->shop_used){
                for(int v=1; map->isPlatform(tempI++, tempJ); v++){
                    if(v==5){
                        tempI=tempI-v;
                        tempJ++;
                        for(int k=0; map->isPlatform(tempI++, tempJ); k++){
                            if(k>=5 && tempJ != MAX_Y-1){
                                mvwprintw(layout->game, j-2, i+1, "___");
                                int t=rand()%9+1;
                                if (t==2 && all_obj->get_possession(1)>=10) t++;
                                switch(t){
                                    case 1:
                                    mvwprintw(layout->game, j-1, i,  "| H |");
                                    break;
                                    case 2:
                                    mvwprintw(layout->game, j-1, i,  "| J |");
                                    break;
                                    case 3:
                                    mvwprintw(layout->game, j-1, i,  "| ! |");
                                    break;
                                    case 4:
                                    mvwprintw(layout->game, j-1, i,  "|! !|");
                                    break;
                                    case 5:
                                    mvwprintw(layout->game, j-1, i,  "|!!!|");
                                    break;
                                    case 6:
                                    mvwprintw(layout->game, j-1, i,  "| + |");
                                    break;
                                    case 7:
                                    mvwprintw(layout->game, j-1, i,  "|+ +|");
                                    break;
                                    case 8:
                                    mvwprintw(layout->game, j-1, i,  "|+++|");
                                    break;
                                    case 9:
                                    mvwprintw(layout->game, j-1, i,  "| # |");
                                    break;
                                } 
                            }}
                    }}}
            }}
    }}   

void Game::shop_control(){
    //Legge le 3 posizioni a destra e a sinistra del player e le salva in shop_symbol
    mvwinnstr(layout->game, player->y, player->x+1, R_shop_symbol, 3);
    mvwinnstr(layout->game, player->y, player->x-3, L_shop_symbol, 3);

    //Current_obj è uguale all'oggetto di cui riconosce i simboli ( H ,+ +...), nullptr altrimenti
    current_obj=all_obj->get_current_object(R_shop_symbol);
    
    //Entra in questo if solo se ci trviamo davanti ad uno shop
    if (current_obj!=nullptr){
        if (buy && player->Valuta>=current_obj->price){
            player->Valuta=player->Valuta-current_obj->price;
            all_obj->buy_obj(*current_obj);
            player->set_stats(all_obj);
            if(strcmp(R_shop_symbol, " H ")== 0) player->heal();
            if(strcmp(R_shop_symbol, " # ")== 0) player->set_shield();
            rooms->normal_maps[rooms->current_room]->shop_used=true;
            drawMap(layout, map);
            wrefresh(layout->game);
            saveGame(all_obj, player);
        }
    }

    //Uguale al precedente ma dal lato sinistro
    current_obj=all_obj->get_current_object(L_shop_symbol);
    if (current_obj!=nullptr){
        if (buy && player->Valuta>=current_obj->price){
            player->Valuta=player->Valuta-current_obj->price;
            all_obj->buy_obj(*current_obj);
            player->set_stats(all_obj);
            if(strcmp(L_shop_symbol, " H ")== 0) player->heal();
            if(strcmp(L_shop_symbol, " # ")== 0) player->set_shield();
            rooms->normal_maps[rooms->current_room]->shop_used=true;
            drawMap(layout, map);
            wrefresh(layout->game);
            saveGame(all_obj, player);
        }
    }
}

void Game::gameLOOP(){
    char p_direction = 'r'; // Inizializzazione direzione proiettile

    // Loop principale del gioco
    while (!quit)
    {
        // Imposta la modalità di attesa per l'input
        halfdelay(1);

        erase();

        // Disegna la mappa
        drawMap(layout, map);
        srand(time(NULL));

        // Disegna il bordo del gioco
        layout->draw_box();
        layout->write_information(player->health, player->shield, player->maxhp, player->damage, player->Valuta, rooms->current_room, cooldown); // sostituito con player->health
        // Disegna e aggiorna i nemici
        if (base_en != nullptr && rooms->current_room%5!=0)
        {   
            base_en->b_en->draw(layout->game);
            werase(layout->game);
            drawMap(layout, map);
            srand(time(NULL));
            layout->draw_box();
           
            base_en = b_update_enemy(base_en, layout->game,map, player, proiettile);
        } 
        rooms->room_enemy[rooms->current_room]=base_en;

        // Disegna il giocatore
        player->draw(layout->game);

        shop_control();

        // Aggiorna lo schermo
        wrefresh(layout->game);

        // Gestisci i proiettili
        if (proiettile != NULL)
        {
            p_pro count = proiettile;
            while (count != NULL)
            {
        if (count->pro->isAttivo())
        {
            count->pro->move(layout->game, proiettile, count->pro->dir);
        }
        count = count->next;
            }

            // Rimuovi i proiettili
            proiettile = tail_delete(proiettile, map);
        }
        // Gestisci l'input dell'utente
        int ch = getch();
        buy=false;
        if (ch == ' ' && cooldown  <= 0)
        {
            // Sparo di un proiettile
            cooldown = 50;
            Proiettile *p = new Proiettile(player->x, player->y);
            p->spara();
            p->dir = p_direction;
            proiettile = head_insert(proiettile, p);
            proiettile->pro->draw(layout->game, player->x, player->y);

            wrefresh(layout->game);
        }
        cooldown--;
        contatore--;
        if (ch == 'a' || ch == 'A' || ch == KEY_LEFT)
        {
            // Movimento a sinistra del giocatore
            if (!Base_isPositionOccupied(layout->game, player->x, player->y, -1)){
            player->p_move(layout->game, 'l');
            p_direction = 'l';
            }
        }
        if (ch == 'd' || ch == 'D' || ch == KEY_RIGHT)
        {
            // Movimento a destra del giocatore
            if (!Base_isPositionOccupied(layout->game, player->x, player->y, 1)){
            player->p_move(layout->game, 'r');
            p_direction = 'r';
            }
        }
        if ((ch == 'w' || ch == 'W' || ch == KEY_UP) && (!player->fall && !player->isJumping))
        {
            // Inizia il salto se il giocatore non è già in salto o cadendo
            player->isJumping = true;
        }
        if (ch=='\n')buy=true;
        if (ch == 'e')
        {
            // Esci dal gioco
            quit = true;
        }
        if (!player->isJumping && !map->platformUnder(player->x, player->y))
        {
            // Se il giocatore non sta saltando e non è su una piattaforma, sta cadendo
            player->fall = true;
            player->y++;
        }
        if (map->platformUnder(player->x, player->y))
        player->fall = false;
        if (player->isJumping && !player->fall)
        {
            // Aggiorna la fase di salto del giocatore
            this->counter = updateJump(layout->game, player, map, player->isJumping, this->counter);
        }
        
        // GAME OVER
        if (player->health <= 0){
            
            layout->game_over();
            napms(100);
            quit = true;
            gameover = true;
            this->run();
        }
        shop_control();
        wrefresh(layout->game);
        

        // Caso in cui siamo già nell'ultima stanza generata
        if (player->x==MAX_X-1 && rooms->current_room == rooms->last_room && rooms->current_room != 2){
            
            //Genera e salva nuove mappe
            map=rooms->generate_new_room(); 

            //Riporta la x all'inizio alla generazione della nuova mappa
            player->x=2; 

            //controlla non ci siano piattaforme e sposta il player di conseguenza
            if (map->isPlatform(player->y, player->x)){
                player->y--;
            }         
            base_en=rooms->get_current_enemy();

            saveGame(all_obj, player);
        }

        if (rooms->current_room == 2 && rooms->current_room == rooms->last_room){
            next_map=rooms->generate_new_room();
            rooms->current_room--;
        }

        //Caso in cui vogliamo tornare indietro
        if (player->x==1 && rooms->current_room != 0){
            map=rooms->load_room(rooms->current_room-1);
            player->x=MAX_X-2;
            if (map->isPlatform(player->y, player->x)){
                player->y--;
            }
            base_en=rooms->get_current_enemy();
            saveGame(all_obj, player);
        }

        //Caso in cui si va avanti ma non siamo nell'ultima stanza
        if (player->x==MAX_X-1 && rooms->current_room != rooms->last_room){
            map=rooms->load_room(rooms->current_room+1);
            player->x=2;
            if (map->isPlatform(player->y, player->x)){
                player->y--;
            }
            base_en=rooms->get_current_enemy();
            saveGame(all_obj, player);
        }
    }
}

void Game::run()
{
    // Inizializza lo schermo di gioco
    layout->init_screen();
    quit = false;
    if (gameover){
        player->health = player->maxhp;
        saveGame(all_obj, player);
        gameover = false;
    }
    // Mostra il menu principale e ottieni la scelta dell'utente
   int scelta = layout->main_menu();
    if (scelta)
    {
        clear();

        // Se la scelta è 1, inizia una nuova partita
        if (scelta == 1)
        {
            // Genera la mappa di gioco
            map->generateFirstMap();
            rooms=new room(map);
            saveGame(all_obj, player);
           // Inizializza il giocatore
            player->init();

            bool game_over = false;
            quit=false;
            
            std::srand(std::time(0));

            gameLOOP();

        }

        else if(scelta==2){
            map->generateFirstMap();
            rooms=new room(map);
            loadGame(all_obj, player);

            player->set_stats(all_obj);
            player->init();

            bool game_over=false;
            quit=false;

            std::srand(std::time(0));

            gameLOOP();
        }

        // Aggiorna lo schermo principale
        refresh();
        // Termina la modalità NCurses
        endwin();
    }
}
