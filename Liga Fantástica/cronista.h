#ifndef _CRONISTA_H_
#define _CRONISTA_H_

#include "tipos.h"
#include "cargar.h"

void listarEquipos(equipo *,int);
void valorarEquipos(futbolista **,int,equipo *,int);
void actualizarPlantillas(jugplant *,int,plantilla **,int,char *,int);

//Esta función será la encargada de valorar los equipos y para ello necesitará un puntero que apunte//
// a un puntero con la dirección de inicio de un vector de futbolista.//

#endif