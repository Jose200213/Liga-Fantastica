#ifndef _MENUS_H_
#define _MENUS_H_

#include "tipos.h"
#include "cargar.h"

//Este se trata de que el usuario pueda identificarse con menuInicio y que luego le aparezcan las disntintas acciones //
//que puede realizar partiendo de su tipo de usuario//

void menuInicio();
void menuParticipante(char *);
void menuParticipantePlantilla(char *);
void menuCronista();
void menuAdministrador();
void menuAdminEquipos();
void menuAdminUsuarios();

#endif