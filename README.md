PROGETTO DI PROGRAMMAZIONE


GRUPPO: 

Emilio Giacomoni emilio.giacomoni@studio.unibo.it Matricola: 0001069281
David Dinu: david.dinu@studio.unibo.it Matricola: 0001090449
Francesco Biglieri: francesco.biglieri@studio.unibo.it Matricola: 0001090725

NOME DEL GIOCO:


@'s adventures


PER COMPILARE IL GIOCO:

g++ main.cpp savingSystem/SaveLoad.cpp class/layout.cpp class/objects.cpp class/map/room.cpp class/map/map.cpp class/map/platform.cpp class/personaggio.cpp  class/enemy.cpp class/proiettile.cpp game.cpp -lncurses -o test

PER AVVIARE IL GIOCO:

./test

PER MUOVERSI NEL MENU' DI GIOCO:

- usare le frecce (SU E GIU') per selezionare la scelta:

CONTINUA LA PARTITA: mantiene i potenziamenti acquisiti nelle partite precedenti;

NUOVA PARTITA: azzera i potenziamenti ottenuti nelle partite precedenti;

ESCI DAL GIOCO: chiude il gioco.

- premere INVIO per comfermare la scelta.

NEL GIOCO:

il personaggio può essere mosso con le frecce (SINISTRA e DESTRA) o con i tasti (A e D);
il personaggio salta con la freccia (SU) e con il tasto (W);
mentre salta il personaggio può essere mosso con le frecce (SINISTRA e DESTRA) o con i tasti (A e D);
il personaggio può sparare con SPAZIO 5 colpi e poi deve ricaricare;
all'inizio il danno fatto dal giocatore  è pari a 1 per proiettile;

ci sono tre tipi di nemici:
- nemici 'X': si muovono, attaccano solo per contatto ed hanno VITA: 3, DANNO: 2, GOLD: 3;
- nemici 'Y':non si muovono, attaccano per contatto e sparando ed hanno VITA: 5, DANNO: 4, GOLD: 5;
- nemici 'Z': si muovono, attaccano per contatto e sparando ed hanno VITA: 7, DANNO: 6, GOLD: 10.

ogni cinque livelli compare un livello shop in cui il giocatore può leggere la descrizione di un oggetto posizionandosi sulle pareti della cassa '|' ed acquistarlo premendo INVIO:
- Heal potion: Ripristina parte dei punti vita massimi;
- Jump boost: Aumenta l'altezza massima di salto;
- Sight upgrade: Migliora il mirino, aumentando leggermente i danni inflitti;
- Mag upgrade: Migliora il caricatore, aumentando i danni inflitti;
- Bullets upgrade: Migliora i proiettili usati, aumentando enormemente i danni inflitti;
- Helmet upgrade: Migliora il tuo elmo, aumentando leggermente i pv massimi;
- Greaves upgrade: Migliora i tuoi schinieri, aumentando i pv massimi;
- Armor upgrade: Migliora la tua corazza, aumentando enormemente i pv massimi;
- Shield: Uno scudo che blocchera parte dei danni in arrivo.

In qualsiasi momento per interrompere la partita si può premere 'e';






