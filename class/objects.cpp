#include "objects.hpp"

 objects::objects(){
    strcpy(all_obj[0].name,"Heal potion");
    strcpy(all_obj[0].description,"Ripristina parte dei pv massimi");
    all_obj[0].price=30;
    strcpy(all_obj[0].symbol," H ");
    all_obj[0].possession=0;

    strcpy(all_obj[1].name,"Jump boost");
    strcpy(all_obj[1].description,"Aumenta l°altezza massima di salto");
    all_obj[1].price=40;
    strcpy(all_obj[1].symbol," J ");
    all_obj[1].possession=0;

    strcpy(all_obj[2].name,"Sight upgrade");
    strcpy(all_obj[2].description,"Migliora il mirino, aumentando leggermente i danni inflitti");
    all_obj[2].price=50;
    strcpy(all_obj[2].symbol," ! ");
    all_obj[2].possession=0;

    strcpy(all_obj[3].name,"Mag upgrade");
    strcpy(all_obj[3].description,"Migliora il caricatore, aumentando i danni inflitti");
    all_obj[3].price=75;
    strcpy(all_obj[3].symbol,"! !");
    all_obj[3].possession=0;

    strcpy(all_obj[4].name,"Bullets upgrade");
    strcpy(all_obj[4].description,"Migliora i proiettili usati, aumentando enormemente i danni inflitti");
    all_obj[4].price=100;
    strcpy(all_obj[4].symbol,"!!!");
    all_obj[4].possession=0;

    strcpy(all_obj[5].name,"Helmet upgrade");
    strcpy(all_obj[5].description,"Migliora il tuo elmo, aumentando leggermente i pv massimi");
    all_obj[5].price=50;
    strcpy(all_obj[5].symbol," + ");
    all_obj[5].possession=0;

    strcpy(all_obj[6].name,"Greaves upgrade");
    strcpy(all_obj[6].description,"Migliora i tuoi schinieri, aumentando i pv massimi");
    all_obj[6].price=75;
    strcpy(all_obj[6].symbol,"+ +");
    all_obj[6].possession=0;

    strcpy(all_obj[7].name,"Armor upgrade");
    strcpy(all_obj[7].description,"Migliora la tua corazza, aumentando enormemente i pv massimi");
    all_obj[7].price=100;
    strcpy(all_obj[7].symbol,"+++");
    all_obj[7].possession=0;

    strcpy(all_obj[8].name,"Shield");
    strcpy(all_obj[8].description,"Uno scudo che blocchera parte dei danni in arrivo");
    all_obj[8].price=60;
    strcpy(all_obj[8].symbol," # ");
    all_obj[8].possession=0;
}

object* objects::get_current_object(char symbol[4]){
    object* temp_obj=nullptr;
    for (int i=0; i<9; i++){
        if (strcmp(all_obj[i].symbol, symbol) == 0){
            temp_obj=&all_obj[i];
        }
    }
    return temp_obj;
}

object* objects::get_all_obj(){
    return all_obj;
}

void objects::buy_obj(object current_obj){
    for (int i=0; i<9; i++){
        if (strcmp(all_obj[i].symbol, current_obj.symbol) == 0){
            all_obj[i].possession++;
        }
    }
}