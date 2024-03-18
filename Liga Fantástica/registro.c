#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "cargar.h"
#include "registro.h"

void registro(usuario **vUsuarios,int *n){
    printf("<----------REGISTRO---------->");

    printf("\nIntroduzca el ID de usuario que desee (2 caracteres como maximo): ");
    fflush(stdin);
    scanf("%2s",(*vUsuarios)[*n].id);

    printf("\nAhora, introduzca su nombre completo (20 caracteres como maximo): ");
    fflush(stdin);
    scanf("%20s",(*vUsuarios)[*n].nombre);

    printf("\nA continuacion, introduzca el login del usuario (5 caracteres como maximo): ");
    fflush(stdin);
    scanf("%5s",(*vUsuarios)[*n].login);

    printf("\nFinalmente, introduzca una contrasena de 8 caracteres como maximo: ");
    fflush(stdin);
    scanf("%8s",(*vUsuarios)[*n].pass);

    strcpy((*vUsuarios)[*n].perfil,"participante");//Recordemos que sólo se pueden registrar participantes.//

    (*n)++;
}
