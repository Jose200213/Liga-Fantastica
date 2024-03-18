#ifndef _ACCESO_H_//El ifndef significa que si no existe el fichero en cuestión hará lo siguiente//
#define _ACCESO_H_//Y lo siguiente es crear el fichero que según el if de arriba no existe//

#include "tipos.h"//Aquí incluímos el fichero tipos ya que lo que se introducirá aquí es respecto a la estructura usuario//
#include "cargar.h"//Cargar también lo incluímos ya que cargará el usuario en el sistema y lo hará a partir de cargar.h//
//que aún no está finalizado pero creemos que deberá recurrirse a este fichero también//

void acceso(usuario *,int);//Ojo que no es que usuario no tenga tipo de dato, sino que usuario ya es un tipo de dato//

#endif//Esto simplemente hace de límite, si el #ifndef no se cumple salta lo que haya entre él y este endif (como un if)//
