#ifndef PARKING_H
#define PARKING_H

void entrer_parking(MYSQL *c);
void place_disp(MYSQL *connexion);
void sortir_parking();
void nbre_place(MYSQL *c , char *type);

#endif