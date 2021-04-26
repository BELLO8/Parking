#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>
#include "../Header/parking.h"

void nbre_place(MYSQL *c, char *type)
{
    MYSQL_RES *resultat;
    MYSQL_ROW ligne;
    char req[255];

    sprintf(req, "SELECT nbre_disp FROM parking where type_engin = %s", type);
    mysql_query(c, req);
    resultat = mysql_store_result(c);

    printf("\t\t\t PLACES DISPONIBLES \n\n");

    while ((ligne = mysql_fetch_row(resultat)))
    {
        printf("\t\t\t - %s - \n", ligne[0]);
    }

    mysql_free_result(resultat);
}
void place_disp(MYSQL *connexion)
{

    MYSQL_RES *resultat;
    MYSQL_ROW ligne;

    mysql_query(connexion, "SELECT * FROM parking");

    resultat = mysql_store_result(connexion);

    printf("\t\t\t **PLACES DISPONIBLES DANS LE PARKING** \n\n");

    while ((ligne = mysql_fetch_row(resultat)))
    {

        printf("\t\t\t+--------- %s ----------+\n", ligne[1]);
        printf("\t\t\t|                            |\n");
        printf("\t\t\t|  place disponible : %s     |\n", ligne[3]);
        printf("\t\t\t|                            |\n");
    }
    printf("\t\t\t+-----------------------------------+\n");

    mysql_free_result(resultat);
}

void entrer_parking(MYSQL *c)
{

    char type_vehicule[255], mat_vehicule[255], req[255], verif[255],type_place[1];

    int status = 0;

    printf("\n\n");
    printf("\t\t\t Quel est votre type de vehicule ? entrer exatement  => ( voiture - camion - moto) : ");
    scanf("%s", &type_vehicule);

    printf("\n");
    printf("\t\t\t Entrer votre matricule : ");
    scanf("%s", &mat_vehicule);

    sprintf(req, "SELECT nbre_disp FROM parking where type_engin = '%s'", type_vehicule);

    if (mysql_query(c, req))
    {
        fprintf(stderr, "\t\t\t%s\n", mysql_error(c));
        mysql_close(c);
        exit(1);
    }
    do
    {
        MYSQL_RES *result = mysql_store_result(c);

        if (result == NULL)
        {
            fprintf(stderr, "\t\t\t%s\n", mysql_error(c));
            mysql_close(c);
            exit(1);
        }

        MYSQL_ROW row = mysql_fetch_row(result);

        char place[5];
        strcpy(place, row[0]);
        int nbre = atoi(place);

        if (nbre == 0)
        {
            printf("\t\t\t +-----------------------------------------------------+ \n");
            printf("\t\t\t |       PLACES INDISPONIBLES : imposible de garer !!  |\n");
            printf("\t\t\t +-----------------------------------------------------+\n\n");

            printf("\t\t\t Pour l'indisponibilité de place nous vous proposons d'occuper une place entre celle des motos et des camion\n");

            printf("\t\t\t Entrer le type place  v pour voiture - c pour camion et m pour moto: ");
            scanf("%s", &type_place);

        }
        else
        {
            printf("\t\t\t +--------------------------------------------------+\n");
            printf("\t\t\t |       PLACES DISPONIBLES  %s :vous pouvez garer  |\n", place);
            printf("\t\t\t +--------------------------------------------------+ \n\n");
            printf("\n");
   

            sprintf(req, "INSERT INTO emplacement (mat_vehicule , heure_arrive , heure_depart , type,status,type_place) VALUES('%s',NOW(),NULL,'%s','entrer','p')", mat_vehicule, type_vehicule);

            if (mysql_query(c, req))
            {
                fprintf(stderr, "%s\n", mysql_error(c));
                mysql_close(c);
                exit(1);
            }
            else
            {
                printf("\t\t\t  +---------------------------------------------------+\n");
                printf("\t\t\t  |          GARER AVEC SUCCES !!                     | \n");
                printf("\t\t\t  +---------------------------------------------------+\n");
            }
        }

        mysql_free_result(result);

        if (status > 0)
        {
            fprintf(stderr, "\t\t\t%s\n", mysql_error(c));
            mysql_close(c);
            exit(1);
        }

    } while (status == 0);
    /*
    if (type_vehicule == "voiture")
    {

        //effectuer un recalcule de place disponible dans le parking
        /* si le type de vehicule est une voiture alors 
                faire un update du nombre de place -1 dans la bd 
                et ainsi de suite jusqu'a ce que on ait aucune place puis reafficher,
                de meme pour les autres types de vehicule.
            

        nbre_place(c, type_vehicule);

        sprintf(req, "UPDATE parking set nbre_disp = nbre_disp - 1 where type_engin = '%s'", type_vehicule);
        if (mysql_query(c, req))
        {
            fprintf(stderr, "%s\n", mysql_error(c));
            mysql_close(c);
            exit(1);
        }

        else
        {
            printf("\n\n");
            printf("\t\t\t  +-----------------------------+\n");
            printf("\t\t\t  |     GARER AVEC SUCCES !!    | \n");
            printf("\t\t\t  +-----------------------------+\n");
            printf("\n\n");
            place_disp(c);
        }
    }
    else if (type_vehicule == "camion")
    {

        //effectuer un recalcule de place disponible dans le parking
        /* si le type de vehicule est une voiture alors 
                faire un update du nombre de place -1 dans la bd 
                et ainsi de suite jusqu'a ce que on ait aucune place puis reafficher,
                de meme pour les autres types de vehicule.
            

        /* pour gerer l'insdisponibilité d'un type de vehicule il faut :

             - recuperer le nombre de place disponible 
             - faire si le nombre de place est different de 0 alors dit que la place est indisponible 
               sinon effectué l'operation
              
            

        sprintf(req, "UPDATE parking set nbre_disp = nbre_disp - 1 where type_engin = '%s'", type_vehicule);
        if (mysql_query(c, req))
        {
            fprintf(stderr, "%s\n", mysql_error(c));
            mysql_close(c);
            exit(1);
        }
        else
        {
            printf("\n\n");
            printf("\t\t\t  +-----------------------------+\n");
            printf("\t\t\t  |     GARER AVEC SUCCES !!    | \n");
            printf("\t\t\t  +-----------------------------+\n");
            printf("\n\n");
            place_disp(c);
        }
    }
    else
    {
        //effectuer un recalcule de place disponible dans le parking
        /* si le type de vehicule est une voiture alors 
                faire un update du nombre de place -1 dans la bd 
                et ainsi de suite jusqu'a ce que on ait aucune place puis reafficher,
                de meme pour les autres types de vehicule.
            

        sprintf(req, "UPDATE parking set nbre_disp = nbre_disp - 1 where type_engin = '%s'", type_vehicule);
        if (mysql_query(c, req))
        {
            fprintf(stderr, "%s\n", mysql_error(c));
            mysql_close(c);
            exit(1);
        }
        else
        {
            printf("\n\n");
            printf("\t\t\t  +-----------------------------+\n");
            printf("\t\t\t  |     GARER AVEC SUCCES !!    | \n");
            printf("\t\t\t  +-----------------------------+\n");
            printf("\n\n");
            place_disp(c);
        }
       
    }
 */
    mysql_close(c);
}