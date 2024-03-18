//Recordemos que la acción de actualizar debe realziarse como mínimo una vez, en el final de cada sesión del usuario//
#ifndef _GUARDAR_H_
#define _GUARDAR_H_

#include "tipos.h"
#include "cargar.h"

//Ojo, esto es un ejemplo de lo que tendríamos que hacer con algunos módulos en la documentación interna//
//Precondición: Un vector usuario existente y una dimensión de vector//
//Postcondición: Guarda en el fichero los datos de los usuarios//

void guardar();
void guardarUsuario(usuario *u, size_t tam);
void guardarEquipo(equipo *e, size_t tam);
void guardarFutbolistas(futbolista *f, size_t tam);
void guardarPlantillas(plantilla *p, size_t tam);
void guardarJugPlant(jugplant *jp, size_t tam);
void guardarConf(config *c, size_t tam);

#endif //_GUARDAR_H_//
