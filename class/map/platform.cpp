#include "platform.hpp"
#define MAX_Y 24
#define MAX_X 80


    platform::platform  (int x, int y, int platN, int width){
        this-> x = x;
        this-> y = y;
        this-> platN = platN; 
        this-> width = width;
    }

    void platform::platformType (platform *platf[], int randType){  // Templates 
        int i=0;
        switch (randType)
        {
        case 1:
            platf[i++] = new platform (2, 5, 3, 3);
            platf[i++] = new platform (7, 3, 3, 6);
            platf[i++] = new platform (15, 5, 3, 3);
            break;

        case 2: 
            platf[i++]= new platform (1, 3, 3, 4);
            platf[i++]= new platform (7, 6, 3, 5);
            platf[i++]= new platform (14, 4, 3, 5);
            break;

        case 3: 
            platf[i++]= new platform (1, 4, 3, 3);
            platf[i++]= new platform (7, 5, 3, 6);
            platf[i++]= new platform (12, 4, 3, 6);
            break;

        case 4:
            platf[i++]= new platform (3, 5, 3, 5);
            platf[i++]= new platform (7, 3, 3, 5);
            platf[i++]= new platform (14, 4, 3, 6);
            break;

        case 5:
            platf[i++]= new platform (1, 5, 2, 8);
            platf[i++]= new platform (7, 2, 3, 10);
            break;

        case 6:
            platf[i++]= new platform (1, 4, 4, 6);
            platf[i++]= new platform (7, 2, 4, 5);
            platf[i++]= new platform (16, 2, 4, 4);
            platf[i++]= new platform (14, 5, 4, 6);
            break;

        case 7:
            platf[i++]= new platform (1, 2, 3, 3);
            platf[i++]= new platform (5, 4, 3, 5);
            platf[i++]= new platform (11, 5, 3, 6);
            break;

        case 8:
            platf[i++]= new platform (1, 4, 3, 4);
            platf[i++]= new platform (7, 6, 3, 6);
            platf[i++]= new platform (11, 3, 3, 8);
            break;

        case 9:
            platf[i++]= new platform (1, 3, 4, 5);
            platf[i++]= new platform (11, 3, 4, 3);
            platf[i++]= new platform (16, 3, 4, 4);
            platf[i++]= new platform (7, 5, 4, 6);
            break;

        case 10:
            platf[i++]= new platform (1, 4, 2, 7);
            platf[i++]= new platform (12, 4, 2, 7);
            break;

        default:
            platf[i++]= new platform (16, 8, 1, 5);   // Piattaforma di "riempimento" che va tra le celle
            break;
        }
    }  

// Template dei 5 diversi tipi shop
void platform::shops_type(int rand_shop, platform* shop_layout[]){
    int i=0;
    switch (rand_shop)
    {
    case 1:{
        int n=23;        
        shop_layout[i++] =new platform(1, 13, n, 9);
        shop_layout[i++] =new platform(1, MAX_Y-1, n, MAX_X-1);
        shop_layout[i++] =new platform(3, 12, n, 5);
        shop_layout[i++] =new platform(7, 7, n, 3);
        shop_layout[i++] =new platform(11, 4, n, 7);
        shop_layout[i++] =new platform(11, 15, n, 6);
        shop_layout[i++] =new platform(12, 10, n, 4);
        shop_layout[i++] =new platform(13, 20, n, 5);
        shop_layout[i++] =new platform(20, 17, n, 9);
        shop_layout[i++] =new platform(21, 6, n, 7);
        shop_layout[i++] =new platform(22, 16, n, 5);
        shop_layout[i++] =new platform(31, 4, n, 6);
        shop_layout[i++] =new platform(39, 7, n, 13);
        shop_layout[i++] =new platform(43, 6, n, 5);
        shop_layout[i++] =new platform(56, 6, n, 5);
        shop_layout[i++] =new platform(58, 20, n, 9);
        shop_layout[i++] =new platform(60, 19, n, 5);
        shop_layout[i++] =new platform(62, 9, n, 5);
        shop_layout[i++] =new platform(68, 13, n, 3);
        shop_layout[i++] =new platform(69, 18, n, 5);
        shop_layout[i++] =new platform(70, 6, n, 9);
        shop_layout[i++] =new platform(72, 5, n, 5);
        shop_layout[i++] =new platform(75, 15, n, 4);
       
        break;}
    case 2:{        
        int n=13;
        shop_layout[i++] =new platform(1, MAX_Y-1, n, MAX_X-1);
        shop_layout[i++] =new platform(11, 15, n, 6);
        shop_layout[i++] =new platform(18, 19, n, 15);
        shop_layout[i++] =new platform(21, 11, n, 9);
        shop_layout[i++] =new platform(23, 10, n, 5);
        shop_layout[i++] =new platform(35, 6, n, 9);
        shop_layout[i++] =new platform(35, 16, n, 9);
        shop_layout[i++] =new platform(37, 5, n, 5);
        shop_layout[i++] =new platform(37, 15, n, 5);
        shop_layout[i++] =new platform(47, 19, n, 15);
        shop_layout[i++] =new platform(49, 11, n, 9);
        shop_layout[i++] =new platform(51, 10, n, 5);
        shop_layout[i++] =new platform(62, 15, n, 6);
        break;}

    case 3:{
        int n=15;
        shop_layout[i++] =new platform(1, MAX_Y-1, n, MAX_X-1);
        shop_layout[i++] =new platform(3, 6, n, 9);
        shop_layout[i++] =new platform(5, 5, n, 5);
        shop_layout[i++] =new platform(13, 8, n, 5);
        shop_layout[i++] =new platform(20, 11, n, 5);
        shop_layout[i++] =new platform(27, 14, n, 5);
        shop_layout[i++] =new platform(27, 21, n, 7);
        shop_layout[i++] =new platform(35, 19, n, 9);
        shop_layout[i++] =new platform(37, 18, n, 5);
        shop_layout[i++] =new platform(45, 21, n, 7);
        shop_layout[i++] =new platform(48, 14, n, 5);
        shop_layout[i++] =new platform(55, 11, n, 5);
        shop_layout[i++] =new platform(62, 8, n, 5);
        shop_layout[i++] =new platform(68, 6, n, 9);
        shop_layout[i++] =new platform(70, 5, n, 5);
        break;
    }

    case 4:{
        int n=17;
        shop_layout[i++] =new platform(1, MAX_Y-1, n, MAX_X-1);
        shop_layout[i++] =new platform(1, 12, n, 9);
        shop_layout[i++] =new platform(3, 11, n, 5);
        shop_layout[i++] =new platform(11, 15, n, 6);
        shop_layout[i++] =new platform(13, 9, n, 8);
        shop_layout[i++] =new platform(19, 17, n, 6);
        shop_layout[i++] =new platform(24, 9, n, 8);
        shop_layout[i++] =new platform(27, 19, n, 5);
        shop_layout[i++] =new platform(35, 12, n, 9);
        shop_layout[i++] =new platform(37, 11, n, 5);
        shop_layout[i++] =new platform(46, 19, n, 5);
        shop_layout[i++] =new platform(47, 9, n, 8);
        shop_layout[i++] =new platform(54, 17, n, 6);
        shop_layout[i++] =new platform(56, 9, n, 8);
        shop_layout[i++] =new platform(62, 15, n, 6);
        shop_layout[i++] =new platform(69, 12, n, 9);
        shop_layout[i++] =new platform(71, 11, n, 5);
        break;
    }

    case 5:{
        int n=18;
        shop_layout[i++] =new platform(1, MAX_Y-1, n, MAX_X-1);
        shop_layout[i++] =new platform(7, 15, n, 6);
        shop_layout[i++] =new platform(9, 9, n, 6);
        shop_layout[i++] =new platform(15, 5, n, 9);
        shop_layout[i++] =new platform(15, 18, n, 9);
        shop_layout[i++] =new platform(17, 4, n, 5);
        shop_layout[i++] =new platform(17, 17, n, 5);
        shop_layout[i++] =new platform(26, 8, n, 10);
        shop_layout[i++] =new platform(27, 20, n, 6);
        shop_layout[i++] =new platform(37, 5, n, 5);
        shop_layout[i++] =new platform(43, 8, n, 10);
        shop_layout[i++] =new platform(47, 20, n, 6);
        shop_layout[i++] =new platform(55, 5, n, 9);
        shop_layout[i++] =new platform(55, 18, n, 9);
        shop_layout[i++] =new platform(57, 4, n, 5);
        shop_layout[i++] =new platform(57, 17, n, 5);
        shop_layout[i++] =new platform(64, 9, n, 6);
        shop_layout[i++] =new platform(66, 15, n, 6);
        break;
    }

    default:
        int n=1;
        shop_layout[i++] =new platform(1, MAX_Y-1, n, MAX_X-1);
        break;
    }
}


/*
Piattaforme:  
             
1-           
               
             ======
              
        ===           ===



2-       
        ====
                    =====

            =====


3- 
        ===        ======
              ======


4-
        
               =====
                     ======
          =====
    
5-
               ==========


         ========

6- 

              =====    ====
        ======
                     ======

7-
        ===

            =====
                  ======

8-
                  ========
        ====

              ======

9-
        =====     === ====

              ======

10-
        ======    =======

*/
