#ifndef _CONFPLANT_H_
#define _CONFPLANT_H_
#include "tipos.h"

void listarFutbPlant(char *idPlant, jugplant *vJugplants, int nJugplants);
int esFutbTitular(char * idFutb, jugplant *vJugplants, int nJugplants );
void listarFutbDisp(char *idPlant, jugplant *vJugplants, int nJugplants, futbolista *vFutbolistas , int nFutbolistas);
void ficharFutb(char *idPlant, jugplant **vJugplants, int *nJugplants, futbolista *vFutbolistas , int nFutbolistas);
void despedirFutb(char *idPlant, jugplant **vJugplants, int *nJugplants, futbolista *vFutbolistas , int nFutbolistas);


#endif