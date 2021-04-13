#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include"../Header/place.h"

void place_disp(MYSQL *connexion)
{
    MYSQL_RES *resultat;
    MYSQL_ROW  ligne;

    mysql_query(connexion,"SELECT * FROM parking");

    resultat = mysql_store_result(connexion);

    printf("\t\t\t **PLACES DISPONIBLES DANS LE PARKING** \n\n");

    while((ligne = mysql_fetch_row(resultat)))
    {
        
        printf("\t\t\t+--------- %s ----------+\n", ligne[1]);
        printf("\t\t\t|                            |\n");
        printf("\t\t\t|  place disponible : %s     |\n", ligne[3]);
        printf("\t\t\t|                            |\n");

    }
    printf("\t\t\t+-----------------------------------+\n");
    
    mysql_free_result(resultat);
}