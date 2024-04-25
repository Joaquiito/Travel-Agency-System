#ifndef TP_MAQUINA_LISTA_H
#define TP_MAQUINA_LISTA_H

#include "reserva.h"

struct nodo {
    reserva vipd;
    struct nodo *next;
};

typedef struct nodo Nodo;
typedef struct {
    Nodo *acc;
    Nodo *cur;
    Nodo *aux;
} lista_reserva;

void init(lista_reserva *reserv) {
    (*reserv).acc = NULL;
    (*reserv).cur = NULL;
    (*reserv).aux = NULL;
}

int isEmpty(lista_reserva reserv) {
    if (reserv.acc == NULL)
        return 1;
    else
        return 0;
}

int isFull() {
    Nodo *n;
    n = (Nodo *) malloc(sizeof(Nodo));
    if (n == NULL) {
        free(n);
        return 1;
    } else
        free(n);
        return 0;
}

int isOos(lista_reserva reserv) {
    if (reserv.cur == NULL)
        return 1;
    else
        return 0;
}

void Insert(lista_reserva *reserv, reserva x) {
    Nodo *l = (Nodo *) malloc(sizeof(Nodo));

    l->vipd = x;
    if (reserv->acc == reserv->cur) {
        reserv->acc = l;
        l->next = reserv->cur;
        reserv->cur = l;
        reserv->aux = l;
    } else {
        reserv->aux->next = l;
        l->next = reserv->cur;
        reserv->cur = l;
    }
}

void supress(lista_reserva *reserv) {
    if (reserv->cur == reserv->acc) {
        reserv->acc = reserv->acc->next;
        reserv->aux = reserv->acc;
        free(reserv->cur);
        reserv->cur = reserv->acc;
    } else
        reserv->aux->next = reserv->cur->next;
        free(reserv->cur);
        reserv->cur = reserv->aux->next;
}


void forwards(lista_reserva *reserv) {
    if (reserv->aux == reserv->cur)
        reserv->cur = reserv->cur->next;
    else {
        reserv->aux = reserv->cur;
        reserv->cur = reserv->cur->next;
    }
}

void reset(lista_reserva *reserv) {
    reserv->cur = reserv->acc;
    reserv->aux = reserv->acc;
}

reserva copy(lista_reserva reserv) {
    return reserv.cur->vipd;
}



#endif //TP_MAQUINA_LISTA_H
