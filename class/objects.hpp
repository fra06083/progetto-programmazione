#pragma once
#include <cstring>

//struttura rappresentante un oggetto/potenziamento
struct object{
    char name[20], description[90];
    char symbol[4];
    int price;
    int possession;
};

class objects {
    private:
    object all_obj[9];  //Array di oggetti objects

    public:
    objects();

    object* get_current_object (char symbol[4]);

    void buy_obj (object current_obj);

    int get_possession (int position);

    void load_possession (int position, int n);
};
