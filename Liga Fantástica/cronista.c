#include "tipos.h"
#include "cargar.h"
#include "cronista.h"
#include "menus.h"
#include "admin.h"

void valorarEquipos(futbolista **vFutbolistas,int nFutbolistas,equipo *vEquipos,int nEquipos){
    int i, e, f;
         //e=indice para identificar el equipo seleccionado

    char ideq[3]="";
    char idfut[3]="";
    int val=0;

    printf("\nPara valorar un equipo seleccione su ID acontinuacion:(0=volver a menu) ");
    scanf("%2s",ideq);

    if(strcmp(ideq,"0")==0){
        menuCronista();
    }
    else{
        for(i=0;i<nEquipos;i++){ //Busca el indice del equipo y lo guarda en 'e'.
            if(strcmp(vEquipos[i].id,ideq)==0){
                e=i;
	    }
        }

        while(strcmp(idfut,"0")!=0){
            printf("\n<__________%s__________>\n",vEquipos[e].nombre);

            for(i=0;i<nFutbolistas;i++){
	// A continuación se mostraran por pantalla todos los futbolistas que pertenecen al equipo seleccionado antes
                if(strcmp((*vFutbolistas)[i].ideq,vEquipos[e].id)==0){
                    printf("%s %s\n",(*vFutbolistas)[i].id,(*vFutbolistas)[i].nombre);
		}
            }

	// Ahora se realizará la valoración de los futbolistas

            printf("\nA continuacion introduzca el ID del futbolista que quiere valorar:(0=volver a menu)  ");
            scanf("%2s",idfut);

            if(strcmp(idfut,"0")!=0){
                for(i=0;i<nFutbolistas;i++){
	//Realizamos este bucle para ver que id de futbolista introducido por el usuario es
                    if(strcmp((*vFutbolistas)[i].id,idfut)==0){
                        f=i;
		    }
                }

                do{
                    if(val<0 || val>10){
                        printf("\nPor favor, introduzca una valoracion comprendida entre 0 y 10, sino se repetira esta accion.\n");
		    }

                    printf("\nLa valoracion de %s es %d\n",(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].valor);

                    printf("\nIntroduzca la nueva valoracion de %s (numero de 0 a 10): ",(*vFutbolistas)[f].nombre);
                    scanf("%d",&val);
                }while(val<0 || val>10);

                actualizarPlantillas(vJugplants,nJugplants,&vPlantillas,nPlantillas,idfut,val);
	 // Necesitamos una función para guardar en ella las nuevas valoraciones
                (*vFutbolistas)[f].valor=val;

                printf("\nLa valoracion actualizada de %s es %d\n",(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].valor);
            }

            system("pause");

            system("cls");
        }
    }
    system("pause");
}

void actualizarPlantillas(jugplant *vJugplants,int nJugplants,plantilla **vPlantillas,int nPlantillas,char *idfut,int newVal){
    char idplant[4]="";
    int i;

    for(i=0;i<nJugplants;i++){
        if(strcmp(vJugplants[i].idjug,idfut)==0){	//Comparamos
            strcpy(idplant,vJugplants[i].idplant);	//Copiamos el contenido de vJugplants[i].idplant en idplant
	}
    }

    if(strcmp(idplant,"")!=0){
        for(i=0;i<nPlantillas;i++){
            if(strcmp((*vPlantillas)[i].idplant,idplant)==0){
                (*vPlantillas)[i].punt=(*vPlantillas)[i].punt+newVal;
	    }
        }
    }
}
