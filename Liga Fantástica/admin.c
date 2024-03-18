#include "admin.h"

void editConfig(config **vConfigs,int nConfigs){
    int i;
    int val;

    printf("\n<_______CONFIGURACION_______>\n");

    for(i=0;i<nConfigs;i++){
            printf("%d. %s: %d\n", i+1, (*vConfigs)[i].config, (*vConfigs)[i].valor);
    }

    printf("\n_______________________________________\n");

    i=-1;

    while(i<0 || i>nConfigs){
        printf("Introduzca el numero de la opcion de la configuracion que desea modificar");
	printf("\nSi desea volver al menu administrador introduzca 0\n");
        scanf("%d",&i);

        if(i!=0){
            if(i<1 || i>nConfigs){
                printf("\nPor favor, introduzca un valor entre 1 y %d\n",nConfigs);
            }
		else{
                	printf("\nEl valor actual de %s es de %d\n",(*vConfigs)[i-1].config,(*vConfigs)[i-1].valor);

                	printf("\nIntroduzca un nuevo valor para %s: ",(*vConfigs)[i-1].config);

               		scanf("%d",&val);

                	(*vConfigs)[i-1].valor=val;

                	printf("\nEl nuevo valor de %s es %d\n",(*vConfigs)[i-1].config,(*vConfigs)[i-1].valor);

            }
        }
    }
	//system pause;//
}

void listarUsuarios(usuario *vUsuarios,int nUsuarios){
    int i;

    printf("\n<_______USUARIOS_______>\n");
    printf("Introduzca los datos en el orden de: ID-NOMBRE-PERFIL-LOGIN-CONTRASENA\n");

    for(i=0;i<nUsuarios;i++){
            printf("%s-%s-%s-%s-%s\n",vUsuarios[i].id,vUsuarios[i].nombre,vUsuarios[i].perfil,vUsuarios[i].login,vUsuarios[i].pass);
    }

    printf("______________________________________\n");

}

void modificarUsuario(usuario **vUsuarios,int nUsuarios){

    int i;
    int u=-1;
    char resp=' ';
    char id[3];
    int nModUsuario=0;
    usuario *modUsuario;

    modUsuario=malloc(sizeof(usuario));

    printf("\nMODIFICAR USUARIO\n");
    printf("#################\n");

    while(u==-1){
        printf("\nIntroduzca el ID del usuario a modificar: \n");
        scanf("%2s",id);
        printf("\n");

        for(i=0;i<nUsuarios;i++){
            if(strcmp((*vUsuarios)[i].id,id)==0){
                u=i;
            }
        }

        if(u==-1){
            printf("\nSu usuario no existe, introduzca un usuario existente.\n");

        }
	else{
            printf("\nInfo del usuario: %s-%s-%s-%s-%s\n", (*vUsuarios)[u].id, (*vUsuarios)[u].nombre, (*vUsuarios)[u].perfil, (*vUsuarios)[u].login, (*vUsuarios)[u].pass);

            printf("Introduzca la nueva informacion siguiendo el modelo: \n(ID-NOMBRE-PERFIL-LOGIN-CONTRASENA)\n");

            anadirUsuario(&modUsuario,&nModUsuario,1);

            while(resp!='s' && resp!='n'){
                printf("¿Modificar el usuario? Responda (s/n) \n");
                fflush(stdin);
                scanf("%c",&resp);
            }

            if(resp=='s'){
                (*vUsuarios)[u]=modUsuario[0];
            }
		else{
                printf("\nNo se sobrescribiran los datos del usuario.\n");
            }
        }
    }
}

void anadirUsuario(usuario **vUsuarios,int *nUsuarios,int admin){
    int n;

    *vUsuarios=realloc((usuario *)(*vUsuarios),((*nUsuarios)+1)*sizeof(usuario));

    printf("\nIntroduzca el ID del usuario (ID --> 2 Cifras maximo): ");
    fflush(stdin);
    scanf("%2s",(*vUsuarios)[*nUsuarios].id);

    printf("\nAhora, introduzca el nombre completo del usuario (20 letras como maximo): ");
    fflush(stdin);
    scanf("%20s",(*vUsuarios)[*nUsuarios].nombre);

    while(n<1 || n>3){
        if(admin==1){
            printf("\nSeleccione el perfil del usuario:\n");
            printf("1) Administrador\n");
            printf("2) Cronista\n");
            printf("3) Participante\n");
            fflush(stdin);
            scanf("%d",&n);
        }
	else{
            n=3;
        }

        switch(n){
            case 1:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"Administrador");
                break;

            case 2:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"Cronista");
                break;

            case 3:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"Participante");
                break;

            default:
                printf("\nLa opcion que ha introducido no es correcta.\n");
        }
    }

    printf("\nIntroduzca el login del usuario (5 letras como maximo): ");
    fflush(stdin);
    scanf("%5s",(*vUsuarios)[*nUsuarios].login);

    printf("\nAhora, introduzca la contrasena del usuario (8 letras como maximo): ");
    fflush(stdin);
    scanf("%8s",(*vUsuarios)[*nUsuarios].pass);

    (*nUsuarios)++;
}

void eliminarUsuario(usuario **vUsuarios,int *nUsuarios){
    int i;
    int u;
    char resp=' ';
    char id[3];

    printf("\n<-------ELIMINAR USUARIO------->");

    printf("\n\nIntroduzca el ID del usuario que desea eliminar: (2 cifras maximo)  ");
    scanf("%2s",id);

    for(i=0;i<(*nUsuarios);i++){
        if(strcmp((*vUsuarios)[i].id,id)==0){
            u=i;
        }
    }

    while(resp!='s' && resp!='n'){
        printf("\nSe va a eliminar al usuario %s-%s-%s-%s-%s\n",(*vUsuarios)[u].id,(*vUsuarios)[u].nombre,(*vUsuarios)[u].perfil,(*vUsuarios)[u].login,(*vUsuarios)[u].pass);
        printf(" ¿Desea continuar? Responda con (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);
    }

    if(resp=='s'){
        for(i=u;i+1<(*nUsuarios);i++){
            strcpy((*vUsuarios)[i].id,(*vUsuarios)[i+1].id);
            strcpy((*vUsuarios)[i].nombre,(*vUsuarios)[i+1].nombre);
            strcpy((*vUsuarios)[i].perfil,(*vUsuarios)[i+1].perfil);
            strcpy((*vUsuarios)[i].login,(*vUsuarios)[i+1].login);
            strcpy((*vUsuarios)[i].pass,(*vUsuarios)[i+1].pass);
        }

        (*nUsuarios)--;

        *vUsuarios=realloc((usuario *)(*vUsuarios),(*nUsuarios)*sizeof(usuario));
    }
    else{
        printf("\nLa eliminacion del usuario ha sido cancelada.\n");
    }
}

void listarEquipos(equipo *vEquipos,int nEquipos){
    int i;

    printf("\n<------------EQUIPOS------------>\n");
    printf("ID-NOMBRE\n");

    for(i=0;i<nEquipos;i++){
            printf("%s %s\n",vEquipos[i].id,vEquipos[i].nombre);
    }
}

void modificarEquipo(equipo **vEquipos,int nEquipos){
    int i;
    int e=-1;
    char resp=' ';
    char id[3];
    int nModEquipo=0;

    equipo *modEquipo;

    modEquipo=malloc(sizeof(equipo));

    printf("\n<------------MODIFICAR EQUIPO------------>\n");

    while(e==-1){
        printf("\nIntroduzca el ID del equipo que desea modificar: (2 cifras como maximo");
        scanf("%2s",id);

        for(i=0;i<nEquipos;i++){
            if(strcmp((*vEquipos)[i].id,id)==0){
                e=i;
            }
        }

        if(e==-1){
            printf("\nUsuario no existente.\n");
        }
	else{
            printf("\nInformacion actual del equipo seleccionado --> %s-%s\n\n",(*vEquipos)[e].id,(*vEquipos)[e].nombre);
            printf("\nPor favor, introduzca la nueva informacion del equipo (siguiendo ID-NOMBRE)\n\n");

            anadirEquipo(&modEquipo,&nModEquipo);

            while(resp!='s' && resp!='n'){
                printf("¿Seguro que quiere modificar el equipo? Responda con (s/n)\n");
                fflush(stdin);
                scanf("%c",&resp);
            }

            if(resp=='s'){
                (*vEquipos)[e]=modEquipo[0];
            }
	    else{
                printf("\nLa modificacion no se guardara, ha sido cancelada.\n");
            }
        }
    }
}


void anadirEquipo(equipo **vEquipos,int *nEquipos){
    *vEquipos=realloc((equipo *)(*vEquipos),((*nEquipos)+1)*sizeof(equipo));

    printf("\nIntroduzca el ID del equipo (2 cifras como maximo): ");
    scanf("%2s",(*vEquipos)[*nEquipos].id);

    printf("\nAhora, introduzca el nombre del equipo (20 letras como maximo): ");
    scanf("%20s",(*vEquipos)[*nEquipos].nombre);

    (*nEquipos)++;

}

void eliminarEquipo(equipo **vEquipos,int *nEquipos){
    int i;
    int e;
    char resp=' ';
    char id[3];

    printf("\n<------------ELIMINAR EQUIPO------------>\n\n");

    printf("Introduzca el ID del equipo a eliminar (2 cifras como maximo):  ");
    scanf("%2s",id);

    for(i=0;i<(*nEquipos);i++){
        if(strcmp((*vEquipos)[i].id,id)==0){
            e=i;
        }
    }

    while(resp!='s' && resp!='n'){
        printf("\nSe va a eliminar el equipo %s-%s\n",(*vEquipos)[e].id,(*vEquipos)[e].nombre);
        printf("¿Esta seguro de eliminar el equipo? Responda con (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);
    }

    if(resp=='s'){
        for(i=e;i+1<(*nEquipos);i++){
            strcpy((*vEquipos)[i].id,(*vEquipos)[i+1].id);
            strcpy((*vEquipos)[i].nombre,(*vEquipos)[i+1].nombre);
        }

        (*nEquipos)--;

        *vEquipos=realloc((equipo *)(*vEquipos),(*nEquipos)*sizeof(equipo));
    }
    else{
        printf("\nEl equipo no sera eliminado, se ha cancelado el proceso.\n");
    }
}

void listarFutbolistas(futbolista *vFutbolistas,int nFutbolistas){
    int i;

    printf("\n<------------FUTBOLISTAS------------>\n");
    printf("FORMATO --> ID-ID_EQUIPO-NOMBRE-PRECIO(Millones)-VALORACION\n");

    for(i=0;i<nFutbolistas;i++){
            printf("%s-%s-%s-%d-%d\n",vFutbolistas[i].id,vFutbolistas[i].ideq,vFutbolistas[i].nombre,vFutbolistas[i].precio,vFutbolistas[i].valor);
    }
}

void modificarFutbolista(futbolista **vFutbolistas,int nFutbolistas){
    int i;
    int f=-1;
    char resp=' ';
    char id[3];
    int nModFutbolista=0;

    futbolista *modFutbolista;

    modFutbolista=malloc(sizeof(futbolista));

    printf("\n<------------MODIFICAR FUTBOLISTA------------>\n");

    while(f==-1){
        printf("\nIntroduzca el ID del futbolista que desea modificar (2 cifras como maximo): ");
        scanf("%2s",id);
        printf("\n");

        for(i=0;i<nFutbolistas;i++){
            if(strcmp((*vFutbolistas)[i].id,id)==0){
                f=i;
            }
        }

        if(f==-1){
            printf("\nNo existe ningun futbolista asociado a esa ID.");
        }
	else{
            printf("\nInformacion actual de: %s-%s-%s-%d-%d\n\n",(*vFutbolistas)[f].id,(*vFutbolistas)[f].ideq,(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].precio,(*vFutbolistas)[f].valor);
            printf("\nAhora, introduzca la nueva informacion del futbolista segun (ID-NOMBRE)\n");

            anadirFutbolista(&modFutbolista,&nModFutbolista);

            while(resp!='s' && resp!='n'){
                printf("¿Seguro que quiere guardar los cambios del futbolista? Responda con (s/n)\n");
                fflush(stdin);
                scanf("%c",&resp);
            }

            if(resp=='s'){
                (*vFutbolistas)[f]=modFutbolista[0];
            }
	    else{
                printf("\nNo se guardaran los cambios, la operacion ha sido cancelada.\n");
            }
        }
    }
}

void anadirFutbolista(futbolista **vFutbolistas, int *nFutbolistas){
    *vFutbolistas=realloc((futbolista *)(*vFutbolistas),((*nFutbolistas)+1)*sizeof(futbolista));

    printf("\nIntroduzca el ID del futbolista (2 cifras como maximo): ");
    scanf("%2s",(*vFutbolistas)[*nFutbolistas].id);

    printf("\nAhora, introduzca el ID del equipo del futbolista (2 cifras como maximo ambos): ");
    scanf("%2s",(*vFutbolistas)[*nFutbolistas].ideq);

    printf("\nA continuacion, introduzca el nombre del futbolista (20 caracteres como maximo): ");
    scanf("%20s",(*vFutbolistas)[*nFutbolistas].nombre);

    printf("\nAhora, marque el precio del futbolista en millones de euros (2 cifras maximo):");
    scanf("%d",&(*vFutbolistas)[*nFutbolistas].precio);

    printf("Finalmente, introduzca la valoracion del futbolista en una escala de 0 a 10: ");
    scanf("%d",&(*vFutbolistas)[*nFutbolistas].valor);

    (*nFutbolistas)++;
}

void eliminarFutbolista(futbolista **vFutbolistas,int *nFutbolistas){
    int i;
    int f;
    char resp=' ';
    char id[3];

    printf("\n<----------ELIMINAR FUTBOLISTA--------->");

    printf("\nIntroduzca el ID del futbolista a eliminar: ");
    scanf("%2s",id);

    for(i=0;i<(*nFutbolistas);i++){
        if(strcmp((*vFutbolistas)[i].id,id)==0){
            f=i;
        }
    }

    while(resp!='s' && resp!='n'){
        printf("\nSe va a eliminar el siguiente usuario: %s-%s-%s-%d-%d\n",(*vFutbolistas)[f].id,(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].precio,(*vFutbolistas)[f].valor);
        printf("\n¿Esta seguro que desea eliminar? Responda con (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);
    }

    if(resp=='s'){
        for(i=f;i+1<(*nFutbolistas);i++){
            strcpy((*vFutbolistas)[i].id,(*vFutbolistas)[i+1].id);
            strcpy((*vFutbolistas)[i].ideq,(*vFutbolistas)[i+1].ideq);
            strcpy((*vFutbolistas)[i].nombre,(*vFutbolistas)[i+1].nombre);
            (*vFutbolistas)[i].precio=(*vFutbolistas)[i+1].precio;
            (*vFutbolistas)[i].valor=(*vFutbolistas)[i+1].valor;
        }

        (*nFutbolistas)--;

        *vFutbolistas=realloc((futbolista *)(*vFutbolistas),(*nFutbolistas)*sizeof(futbolista));
    }
    else{
        printf("\nLa eliminacion no sera efectuada, se ha cancelado.\n");
    }
}
