#include "platform.hpp"


    platform::platform  (int x, int y, int platN, int width){
        this-> x = x;
        this-> y = y;
        this-> platN = platN; 
        this-> width = width;
    }
    int platform::platX (){  // X della piattaforma
        return x;
    }
    int platform::platY (){   // Y della piattaforma
        return y;
    }
    int platform::platNumber (){  // Numero di piattaforme di ogni template 
        return platN;
    }
    int platform::platW(){   // Larghezza della piattaforma
        return width;
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