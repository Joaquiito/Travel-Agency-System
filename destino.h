#ifndef TP_MAQUINA_DESTINO_H
#define TP_MAQUINA_DESTINO_H

typedef struct {
    char destino[30];
    double pasaje;
    double alojamiento;
    double allinclusive;
} Destino;

void mod_destino(Destino *destino,char aux[]){
    strcpy(destino->destino,aux);
}

void mod_pasaje(Destino *destino, double aux){
    destino->pasaje=aux;
}

void mod_alojamiento(Destino *destino, double aux){
    destino->alojamiento= aux;
}

void mod_allinclusive(Destino *destino, double aux){
    destino->allinclusive=aux;
}

char* obtener_dest(Destino destino){
    char *auxdestino;
    auxdestino = (char*)malloc(sizeof(auxdestino)* strlen(destino.destino));
    if(auxdestino==NULL){
        return auxdestino;
    }else {
        strcpy(auxdestino, destino.destino);
        return auxdestino;
    }
}

double obtener_pasaje(Destino destino){
    return destino.pasaje;
}

double obtener_alojamiento(Destino destino){
    return destino.alojamiento;
}

double obtener_allinclusive(Destino destino) {
    return destino.allinclusive;
}
#endif //TP_MAQUINA_DESTINO_H
