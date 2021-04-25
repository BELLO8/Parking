#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include <string.h>
#include"../Header/menu.h"
#include"../Header/parking.h"

void menu()
{

    printf("\t\t\t+------------------ Gestion de Parking ------------------+\n");
    printf("\t\t\t|                                                        |\n");
    printf("\t\t\t|            1 - ENTRER DANS LE PARKING                  |\n");
    printf("\t\t\t|            2 - PLACE DISPONIBLE DANS LE PARKING        |\n");
    printf("\t\t\t|            3 - SORTIR DU PARKING                       |\n");
    printf("\t\t\t|                                                        |\n");
    printf("\t\t\t+--------------------------------------------------------+\n\n");

}

void instruction(MYSQL *c)
{


    menu();
        int choixMenu;
        printf("\n\t\t\tCHOISISSEZ UNE OPTION :");
        scanf("%d", &choixMenu);
        printf("\n");
        
        switch(choixMenu)
        {
            case 1 : 
                printf("\t\t\t  +----- *BIENVENUE DANS LE PARKING CHER USAGER* -----+ \n\n");
                place_disp(c);
                entrer_parking(c);
                break;

            case 2 : 
                place_disp(c);
                break;
            
            case 3 :
                printf("\t\t\t +------------- AU REVOIR CHER USAGER ------------------+\n");
                break;

            default :
                printf("\t\t\tErreur de saisir reessayer !\n");
                break;

        }

}

