#pragma once
#include <cstring>

struct object{
    char name[20], description[90];
    char symbol[4];
    int price;
    int possession;
};

class objects {
    private:
    object all_obj[9];

    public:
    objects();

    object* get_current_object (char symbol[4]);

    object* get_all_obj();

    void buy_obj (object current_obj);

    int get_possession (int position);

    void load_possession (int position, int n);
};