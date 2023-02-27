/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Manuel Rodríguez Rodríguez LOGIN 1: m.rodriguez10@udc.es
 * AUTHOR 2:Adrián Rodríguez López LOGIN 2: adrian.rodriguez12@udc.es
 * GROUP: 1.4
 * DATE: 17 / 02 / 2023
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"

#define LNULL -1
#define MAX 1000

typedef int tPosL;

typedef struct {

    tItemL  data[MAX];
    tPosL lastPos;

}tList;

bool isEmptyList (tList L);
void createEmptyList(tList *L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p , tList L);
tPosL next(tPosL p , tList L);
tItemL getItem (tPosL p ,tList L);
void updateItem ( tItemL i, tPosL p, tList *L);
void deleteList (tList *L);
void deleteAtPosition(tPosL p, tList *L);
bool copyList (tList L, tList *M);
bool insertItem (tItemL d, tPosL p, tList *L);
tPosL findItem(tParticipantName d, tList L);

#endif