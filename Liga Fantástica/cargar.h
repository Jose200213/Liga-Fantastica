#ifndef _CARGAR_H_
#define _CARGAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

//En primer lugar, hacemos una lista declarando los tipos de datos que usaremos, en este caso serán todos enteros//
//Y luego, declararemos también unos punteros que apuntan hacia vectores de distintos datos//

int nUsuarios;//Número de usuarios en usuarios.txt//
int nEquipos;//Número de equipos en equipos.txt//
int nFutbolistas;//Número de futbolistas en equipos.txt//
int nPlantillas;//Número de plantillas en plantillas.txt//
int nJugplants;//Número de relaciones entre jugadores y plantillas en jugadores_plantillas.txt//
int nConfigs;//Número de datos de configuración general en configuracion.txt//

usuario *vUsuarios;//Puntero con la direccion de inicio de un vector de usuario//
equipo *vEquipos;//Puntero con la direccion de inicio de un vector de equipo//
futbolista *vFutbolistas;//Puntero con la direccion de inicio de un vector de futbolista//
plantilla *vPlantillas;//Puntero con la direccion de inicio de un vector de plantilla//
jugplant *vJugplants;//Puntero con la direccion de inicio de un vector de jugplant//
config *vConfigs;//Puntero con la direccion de inicio de un vector de config//

int cargar();
int cargarUsuarios(usuario **,int *);//usuario ** significa que apunta al interior del inicio de un vector, y la posición//
// del vector será la que nos dé con el int * para llegar al usuario correspondiente almacenado en dicha posición del vector//
int cargarEquipos(equipo **,int *);
int cargarFutbolistas(futbolista **,int *);
int cargarPlantillas(plantilla **,int *);
int cargarJugplants(jugplant **,int *);
int cargarConfigs(config **,int *);

//También declaramos las funciones que podrán realizar aquellas funciones en las que se deba usar esta cabecera//

void imprimir();
void printCargarUsuarios(usuario *,int);
void printCargarEquipos(equipo *,int);
void printCargarFutbolistas(futbolista *,int);
void printCargarPlantillas(plantilla *,int);
void printCargarJugplants(jugplant *,int);
void printCargarConfigs(config *,int);

#endif
