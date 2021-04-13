#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include"../Header/parking.h"
#include"../Header/place.h"

void entrer_parking(MYSQL *c)
{

    char type_vehicule[255],mat_vehicule[255],req[255];

    printf("\n\n");
    printf("\t\t\t Quel est votre type de vehicule ? (voiture/camion/moto) : ");
    scanf("%s",&type_vehicule);
    printf("\n");
    printf("\t\t\t Entrer votre matricule : ");
    scanf("%s",&mat_vehicule);

    sprintf(req,"INSERT INTO emplacement (mat_vehicule , heure_arrive , heure_depart , type,status) VALUES('%s',NOW(),NULL,'%s','entrer')",mat_vehicule,type_vehicule);
       
    if(mysql_query(c,req))
    {
        fprintf(stderr, "%s\n", mysql_error(c));
        mysql_close(c);
        exit(1);
    }
    else if(type_vehicule == "voiture")
    {      
            //effectuer un recalcule de place disponible dans le parking 
            /* si le type de vehicule est une voiture alors 
                  faire un update du nombre de place -1 dans la bd 
                  et ainsi de suite jusqu'a ce que on ait aucune place puis reafficher,
                de meme pour les autres types de vehicule.
            */ 
           
                sprintf(req,"UPDATE parking set nbre_disp = nbre_disp - 1 where type_engin = '%s'",type_vehicule);
                if(mysql_query(c,req))
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
    else if(type_vehicule == "camion")
    {      
            //effectuer un recalcule de place disponible dans le parking 
            /* si le type de vehicule est une voiture alors 
                  faire un update du nombre de place -1 dans la bd 
                  et ainsi de suite jusqu'a ce que on ait aucune place puis reafficher,
                de meme pour les autres types de vehicule.
            */ 
           
                sprintf(req,"UPDATE parking set nbre_disp = nbre_disp - 1 where type_engin = '%s'",type_vehicule);
                if(mysql_query(c,req))
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
            */ 
           
                sprintf(req,"UPDATE parking set nbre_disp = nbre_disp - 1 where type_engin = '%s'",type_vehicule);
                if(mysql_query(c,req))
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
    mysql_close(c);

}