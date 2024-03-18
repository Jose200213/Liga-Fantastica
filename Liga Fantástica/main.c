#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "cargar.h"
#include "guardar.h"
#include "participante.h"
//Incluímos todos los ficheros de cabecera que nos hace falta para el main (ojo wue no hace falta meter admin ni cronista//

int main(){
    cargar();

    menuInicio();

    guardar();

    return (0);
}