#include "tipos.h"
#include "cargar.h"
#include "registro.h"
#include "acceso.h"
#include "menus.h"
#include "participante.h"
#include "cronista.h"
#include "admin.h"
#include "guardar.h"
#include "confPlant.h"


void menuInicio(){
    int n;

    while(n!=3){
        system("cls");

        printf("\nBienvenido a la Liga Fantastica MP\n");
        printf("<*-*-*-*-*-*-*-*-*-*-*-*-*-*-*->\n");
        printf("\nAcciones:(Responda con el numero)\n");
        printf("1. Registrarse");
        printf("\n2. Acceder al sistema");
        printf("\n3. Salir\n");
        scanf("%d",&n);

        system("cls");

        switch(n){
            case 1:
                anadirUsuario(&vUsuarios,&nUsuarios,0);
                break;

            case 2:
                acceso(vUsuarios,nUsuarios);
                break;

            case 3:
                break;
        }
    }
}

void menuParticipante(char *id){
    int n=0;

    contarPlantillas(id,vPlantillas,nPlantillas,&nPlantillasUsuario);

    system("pause");

    while(n!=6){
        system("cls");

        printf("\n|Usuario: PARTICIPANTE|");
        printf("\n<------------------------------>\n");
        printf("Selecciona una accion:(numero) \n");
        printf("\n1. Crear plantilla");
        printf("\n2. Configurar plantilla");
        printf("\n3. Lista de plantillas");
        printf("\n4. Eliminar Plantilla");
        printf("\n5. Ranking");
        printf("\n6. Salir\n");
        scanf("%d",&n);

        system("cls");

        switch(n){
            case 1:
                printf("\n|CREAR PLANTILLA NUEVA|\n\n");
                crearPlantilla(id,&vPlantillas,&nPlantillas,&vJugplants,&nJugplants,&nPlantillasUsuario);
		system("pause");
                break;

            case 2:
                printf("\n|MODIFICAR PLANTILLA|\n\n");
                menuParticipantePlantilla(id);
                system("pause");
                break;

            case 3:
                printf("\n|<--LISTADO DE PLANTILLAS-->|\n");
                printf("\nID_PROPIETARIO - ID_PLANTILLA - NOMBRE - PRESUPUESTO - PUNTUACION\n");
                listarplantillas(id, vPlantillas, nPlantillas, nPlantillasUsuario);
                system("pause");
                break;

            case 4:
                printf("\n|X ELIMINAR PLANTILLA X|\n");
                eliminarPlantilla(id,&vPlantillas,&nPlantillas,&nPlantillasUsuario);
                system("pause");
                break;

            case 5:
                printf("\n[:::::::TOP 3:::::::]\n");
                ranking(vPlantillas,nPlantillas);
                system("pause");
                break;

            case 6:
                break;
        }
    }

    guardar();
}

void menuParticipantePlantilla(char *id){
    int n=0;
    char idPlant[4];

    printf("\nIntroduce el ID de su plantilla: ");
    listarplantillas(id, vPlantillas, nPlantillas, nPlantillasUsuario);

    fflush(stdin);
    scanf("%3s",idPlant);

    system("pause");

    while(n!=5){
        system("cls");

        printf("\n# CONFIGURACION DE PLANTILLA #");
        printf("\nIntroduzca una opcion:(numero) ");
        printf("\n1. Lista de futbolistas de la plantilla actual");
        printf("\n2. Lista de futbolistas disponibles");
        printf("\n3. Anadir futbolista a la plantilla");
        printf("\n4. Eliminar jugador de plantilla");
        printf("\n5. Salir\n");

        fflush(stdin);
        scanf("%d",&n);

        system("cls");

        switch(n){
            case 1:
                printf("\nLista de futbolistas de la plantilla actual:\n");
                listarFutbPlant(idPlant, vJugplants, nJugplants);
                system("pause");
                break;

            case 2:
                printf("\nLista de futbolistas disponibles:\n");
                listarFutbDisp(idPlant, vJugplants, nJugplants, vFutbolistas, nFutbolistas);
                system("pause");
                break;

            case 3:
                printf("\nAnadir futbolista a la plantilla: ");
                ficharFutb(idPlant,&vJugplants, &nJugplants, vFutbolistas, nFutbolistas);
                system("pause");
                break;

            case 4:
                printf("\nEliminar jugador de la plantilla:");
                despedirFutb(idPlant, &vJugplants, &nJugplants, vFutbolistas ,nFutbolistas);
                system("pause");
                break;

	    case 5:
		break;

        }
    }
}

void menuCronista(){
    int n=0;

    system("cls");

    while(n!=3){
        printf("\n|MENU CRONISTA|\n");;
        printf("\nSeleccione una accion:(numero) ");
        printf("\n1. Listar equipos");
        printf("\n2. Valorar Equipos");
        printf("\n3. Salir del sistema.\n");
        scanf("%d",&n);

        system("cls");

        switch(n){
            case 1:
                listarEquipos(vEquipos,nEquipos);
                system("pause");
                system("cls");
                break;

            case 2:
                valorarEquipos(&vFutbolistas,nFutbolistas,vEquipos,nEquipos);
                system("cls");
                break;

            case 3:
                break;
        }
    }

   guardar();
}

void menuAdministrador(){
    int n=0;

    while(n!=4){
        system("cls");

        printf("\n|+ MENU ADMINISTRADOR +|\n");
        printf("\nSeleccione una opcion:(numero) ");
        printf("\n1. Equipos");
        printf("\n2. Usuarios");
        printf("\n3. Configuracion");
        printf("\n4. Salir del programa\n");

        scanf("%d",&n);

        system("cls");

        switch(n){
            case 1:
                menuAdminEquipos();
                break;

            case 2:
                menuAdminUsuarios();
                break;

            case 3:
                editConfig(&vConfigs,nConfigs);
                break;

            case 4:
                break;
        }
    }

    guardar();
}

void menuAdminEquipos(){
    int n=0;

    while(n!=9){
        system("cls");

        printf("\n#-------ADMINISTRAR EQUIPOS-------#\n");
        printf("\nSeleccione una opcion:(numero) ");
        printf("\n1. Listar equipos");
        printf("\n2. Modificar equipo");
        printf("\n3. Anadir equipo");
        printf("\n4. Eliminar equipo");
        printf("\n5. Listar futbolistas");
        printf("\n6. Modificar futbolista");
        printf("\n7. Anadir futbolista");
        printf("\n8. Eliminar futbolista");
        printf("\n9. Volver al menu administrador\n");

        scanf("%d",&n);

        system("cls");

        switch(n){

            case 1:
                listarEquipos(vEquipos,nEquipos);
                system("pause");
                break;

            case 2:
                modificarEquipo(&vEquipos,nEquipos);
                system("pause");
                break;

            case 3:
                printf("\nANADIR NUEVO EQUIPO\n");
                anadirEquipo(&vEquipos,&nEquipos);
                system("pause");
                break;

            case 4:
                eliminarEquipo(&vEquipos,&nEquipos);
                system("pause");
                break;

            case 5:
                listarFutbolistas(vFutbolistas,nFutbolistas);
                system("pause");
                break;

            case 6:
                modificarFutbolista(&vFutbolistas,nFutbolistas);
                system("pause");
                break;

            case 7:
                printf("\nANADIR NUEVO FUTBOLISTA\n");
                anadirFutbolista(&vFutbolistas,&nFutbolistas);
                system("pause");
                break;

            case 8:
                eliminarFutbolista(&vFutbolistas,&nFutbolistas);
                system("pause");
                break;

            case 9:
                break;
        }
    }
}

void menuAdminUsuarios(){
    int n=0;

    while(n!=5){
        system("cls");

        printf("\n#-------ADMINISTRAR USUARIOS-------#\n");
        printf("\nSeleccione una opcion:(numero) ");
        printf("\n1. Listar usuarios");
        printf("\n2. Modificar usuario");
        printf("\n3. Anadir usuario");
        printf("\n4. Eliminar usuario");
        printf("\n5. Volver al menu administrador\n");

        scanf("%d",&n);

        system("cls");

        switch(n){
            case 1:
                listarUsuarios(vUsuarios,nUsuarios);
                system("pause");
                break;

            case 2:
                modificarUsuario(&vUsuarios,nUsuarios);
                break;

            case 3:
                printf("\nREGISTRAR NUEVO USUARIO\n");
                anadirUsuario(&vUsuarios,&nUsuarios,1);
                system("pause");
                break;

            case 4:
                eliminarUsuario(&vUsuarios,&nUsuarios);
                system("pause");
                break;

            case 5:
                break;
        }
    }
}
