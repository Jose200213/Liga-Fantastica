#include "guardar.h"

void guardarUsuario(usuario *u, size_t tam){
    FILE *fich;
    int i;

    fich=fopen("DATA/usuarios.txt","w+");

    i = 0;

    if(fich==NULL){
            printf("\nNo se ha podido editar el fichero debido a un error. Intentelo mas adelante.\n");
    }
    else{
            while(i<tam-1){
                fprintf(fich, "%s-%s-%s-%s-%s\n", u[i].id, u[i].nombre, u[i].perfil, u[i].login, u[i].pass);
                i++;
            }
            
	    fprintf(fich, "%s-%s-%s-%s-%s", u[i].id, u[i].nombre, u[i].perfil, u[i].login, u[i].pass );
    }

    printf("\nLos usuarios han sido guardados correctamente.\n");
}

void guardarEquipo(equipo *e, size_t tam){
    FILE *fich;
    int i;

    fich=fopen("DATA/equipos.txt","w+");

    i = 0;

    if(fich==NULL){
            printf("\nNo se ha podido editar el fichero debido a un error. Intentelo mas  adelante.\n");
    }
    else{
            while(i<tam-1){
                fprintf(fich, "%s-%s\n", e[i].id, e[i].nombre );
                i++;
            }
            
	    fprintf(fich, "%s-%s", e[i].id, e[i].nombre );
    }
    
    printf("\nLos equipos han sido guardados correctamente.\n");
}

void guardarFutbolistas(futbolista *f, size_t tam){
    FILE *fich;
    int i;

    fich=fopen("DATA/futbolistas.txt","w+");

    i = 0;

    if(fich==NULL){
            printf("\nNo se ha podido editar el fichero debido a un error. Intentelo mas tarde.\n");
    }
    else{
            while(i<tam-1){
                fprintf(fich, "%s-%s-%s-%d-%d\n", f[i].id, f[i].ideq, f[i].nombre, f[i].precio, f[i].valor );
                i++;
            }
            
	    fprintf(fich, "%s-%s-%s-%d-%d", f[i].id, f[i].ideq, f[i].nombre, f[i].precio, f[i].valor );
    }

    printf("\nLos futbolistas han sido guardados correctamente.\n");
}

void guardarPlantillas(plantilla *p, size_t tam){
    FILE *fich;
    int i;

    fich=fopen("DATA/plantillas.txt","w+");

    i = 0;

    if(fich==NULL){
            printf("\nNo se ha podido editar el fichero debido a un error. Intentelo mas tarde.\n");
    }    
    else{
            while(i<tam-1){
                fprintf(fich, "%s-%s-%s-%d-%d\n", p[i].idprop, p[i].idplant, p[i].nombre, p[i].presup, p[i].punt );
                i++;
            }
            fprintf(fich, "%s-%s-%s-%d-%d", p[i].idprop, p[i].idplant, p[i].nombre, p[i].presup, p[i].punt );
    }
    printf("\nLa plantilla ha sido guardada correctamente.\n");
}

void guardarJugPlant(jugplant *jp, size_t tam){
    FILE *fich;
    int i;

    fich=fopen("DATA/jugadores_plantillas.txt","w+");

    i = 0;

    if(fich==NULL){
            printf("\nNo se ha podido editar el fichero debido a un error. Intentelo mas tarde.\n");
    }    
    else{
            while(i<tam-1){
                fprintf(fich, "%s-%s-%s\n", jp[i].idjug, jp[i].ideq ,jp[i].idplant );
                i++;
            }

            fprintf(fich, "%s-%s-%s", jp[i].idjug, jp[i].ideq ,jp[i].idplant );
    }

    printf("\nLos datos de jugadoresplantilla se han guardado correctamente.\n");
}

void guardarConf(config *c, size_t tam){
    FILE *fich;
    int i;

    fich=fopen("DATA/configuracion.txt","w+");

    i = 0;

    if(fich==NULL){
            printf("\nNo se ha podido editar el fichero debido a un error. Intentelo mas tarde.\n");
    }
    else{
            while(i<tam-1){
                fprintf(fich, "%s-%d\n", c[i].config, c[i].valor );
                i++;
            }

            fprintf(fich, "%s-%d", c[i].config, c[i].valor );
    }

    printf("\nLa configuración ha sido guardada correctamente.\n");
}

void guardar(){
    char resp=' ';

    while(resp!='s' && resp!='n'){
        printf("\nHa seleccionado salir. ¿Antes de salir desea guardar los cambios realizados? Responda con (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);
    }

    if(resp=='s'){
        guardarUsuario(vUsuarios, nUsuarios);
        guardarEquipo(vEquipos, nEquipos );
        guardarFutbolistas(vFutbolistas, nFutbolistas);
        guardarPlantillas(vPlantillas, nPlantillas);
        guardarJugPlant(vJugplants, nJugplants);
        guardarConf(vConfigs, nConfigs);

        exit(0);
    }
    else{
        printf("\nLos cambios realizados no han sido guardados.\n");
    }
}