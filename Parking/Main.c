#include<stdlib.h>
#include<mysql/mysql.h>
#include <string.h>
#include "../Header/db.h"
#include"../Header/menu.h"

int main()
{
    MYSQL *c = mysql_init(NULL);
    
    db(c);
    instruction(c);

}