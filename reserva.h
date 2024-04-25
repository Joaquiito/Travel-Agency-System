#ifndef TP_MAQUINA_RESERVA_H
#define TP_MAQUINA_RESERVA_H

#include <string.h>
#include <malloc.h>

typedef struct {
    int anio;//entre 2021 y 2022
    int mes; //entre diciembre y febrero
    int dia; //entre 1 y 31
} fecha;

typedef struct {
    char cuil[12];
    char nombre[40];
    char destino[30];
    int cant_acomp;
    int tipvinc;
    double senia;
    fecha fechav;
    int tiposer;
    double costo;

} reserva;

void carga_cuil(reserva *r, char aux[]) {
    strcpy(r->cuil,aux);
}

void carga_nombre(reserva *r, char aux[]) {
    strcpy(r->nombre, aux);
}

void carga_amcomp(reserva *r, int aux) {
    r->cant_acomp = aux;
}

void carga_fecha(reserva *r, fecha aux) {
    r->fechav = aux;
}

void carga_tipvinc(reserva *r, int aux) {
    r->tipvinc = aux;
}

void carga_senia(reserva *r, double aux) {
    r->senia = aux;
}

void carga_tiposer(reserva *r, int aux) {
    r->tiposer = aux;
}

void carga_costo(reserva *r, double aux) {
    r->costo = aux;
}

void carga_destino(reserva *r, char aux[]) {
    strcpy(r->destino, aux);
}

void modifica_senia(reserva *r, double aux) {
    r->senia += aux;
}

void modifica_tipser(reserva *r, int aux) {
    r->tiposer = aux;
}

void modifica_costo(reserva *r, double aux) {
    (*r).costo = aux;
}

char *obtener_cuil(reserva r) {
    char *auxcuil;
    auxcuil = (char*) malloc(sizeof (auxcuil) * strlen(r.cuil));
    if(auxcuil == NULL){
        return "0";
    } else {
        strcpy(auxcuil, r.cuil);
        return auxcuil;
    }
}

char *obtener_nombre(reserva r) {
    char *auxnomb;
    auxnomb = (char *) malloc(sizeof(auxnomb) * strlen(r.nombre));
    if (auxnomb == NULL) {
        return "0";
    } else {
        strcpy(auxnomb, r.nombre);
        return auxnomb;
    }
}

int obtener_acompan(reserva r) {
    return r.cant_acomp;
}

char *obtener_destino(reserva r) {
    char *auxdest;
    auxdest = (char *) malloc(sizeof(char) * strlen(r.destino));
    if (auxdest == NULL) {
        return "0";
    } else {
        strcpy(auxdest, r.destino);
        return auxdest;
    }
}

int obtener_vinculo(reserva r) {
    return r.tipvinc;
}

double obtener_senia(reserva r) {
    return r.senia;
}

double obtener_monto(reserva r) {
    return r.costo;
}

fecha obtener_fecha(reserva r) {
    return r.fechav;
}

int obtener_tiposer(reserva r) {
    return r.tiposer;
}

void mod_anio(fecha *f, int aux) {
    f->anio = aux;
}

void mod_mes(fecha *f, int aux) {
    f->mes = aux;
}

void mod_dia(fecha *f, int aux) {
    f->dia = aux;
}

int copy_dia(fecha f) {
    return f.dia;
}

int copy_mes(fecha f) {
    return f.mes;
}

int copy_anio(fecha f) {
    return f.anio;
}

#endif //TP_MAQUINA_RESERVA_H
