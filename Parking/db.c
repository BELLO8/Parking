#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include "../Header/db.h"

void db(MYSQL *db)
{

    if( db == NULL)
    {
        fprintf(stderr,"%s\n",mysql_error(db));
        exit(0);
    }
    if(mysql_real_connect(db,"localhost","root","kader","Parking",0,NULL,CLIENT_MULTI_STATEMENTS) == NULL)
    {
        fprintf(stderr,"%s\n",mysql_error(db));
        mysql_close(db);
        exit(0);
    }
    else
    {
        printf("\n **Parking** \n\n");

    }

}