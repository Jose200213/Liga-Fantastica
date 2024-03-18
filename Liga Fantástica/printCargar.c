#include "tipos.h"
#include "cargar.h"

void imprimir(){
    printCargarUsuarios(vUsuarios,nUsuarios);
    printCargarEquipos(vEquipos,nEquipos);
    printCargarFutbolistas(vFutbolistas,nFutbolistas);
    printCargarPlantillas(vPlantillas,nPlantillas);
    printCargarJugplants(vJugplants,nJugplants);
    printCargarConfigs(vConfigs,nConfigs);
}

void printCargarUsuarios(usuario *vUsuarios,int n){
    int i;

    printf("\n#_____________USUARIOS_____________#\n");

    for(i=0;i<n;i++){
            printf("\nID USUARIO:%s\n",vUsuarios[i].id);
            printf("\nNOMBRE:%s\n",vUsuarios[i].nombre);
            printf("\nPERFIL:%s\n",vUsuarios[i].perfil);
            printf("\nLOGIN:%s\n",vUsuarios[i].login);
            printf("\nPASS:%s\n",vUsuarios[i].pass);
    }
}

void printCargarEquipos(equipo *vEquipos,int n){
    printf("\n#_____________EQUIPOS_____________#\n");

    for(int i=0;i<n;i++){
            printf("\nID EQUIPO: %s\n",vEquipos[i].id);
            printf("\nNOMBRE: %s\n",vEquipos[i].nombre);
    }
}

void printCargarFutbolistas(futbolista *vFutbolistas,int n){
    printf("\n#_____________FUTBOLISTAS_____________#\n");

    for(int i=0;i<n;i++){
            printf("\nID FUTBOLISTA: %s\n",vFutbolistas[i].id);
            printf("\nID EQUIPO: %s\n",vFutbolistas[i].ideq);
            printf("\nNOMBRE: %s\n",vFutbolistas[i].nombre);
            printf("\nPRECIO: %d\n",vFutbolistas[i].precio);
            printf("\nVALORACION: %d\n",vFutbolistas[i].valor);
    }
}

void printCargarPlantillas(plantilla *vPlantillas,int n){
    printf("\n#_____________PLANTILLAS_____________#\n");

    for(int i=0;i<n;i++){
            printf("\nID PROPIETARIO: %s\n",vPlantillas[i].idprop);
            printf("\nID PLANTILLA: %s\n",vPlantillas[i].idplant);
            printf("\nNOMBRE: %s\n",vPlantillas[i].nombre);
            printf("\nPRESUPUESTO: %d\n",vPlantillas[i].presup);
            printf("\nPUNTUACION: %d\n",vPlantillas[i].punt);
    }
}

void printCargarJugplants(jugplant *vJugplants,int n){
    printf("\n#_____________JUGADORES DE LA PLANTILLA_____________#\n");

    for(int i=0;i<n;i++){
            printf("\nID USUARIO: %s\n",vJugplants[i].idjug);
            printf("\nID PLANTILLA: %s\n",vJugplants[i].idplant);
    }
}

void printCargarConfigs(config *vConfigs,int n){
    printf("\n#_____________CONFIGURACION_____________#\n");

    for(int i=0;i<n;i++){
            printf("\nCONFIGURACION: %s\n",vConfigs[i].config);
            printf("VALOR: %d\n",vConfigs[i].valor);
    }
}
