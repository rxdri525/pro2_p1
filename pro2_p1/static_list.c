/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Manuel Rodríguez Rodríguez LOGIN 1: m.rodriguez10@udc.es
 * AUTHOR 2:Adrián Rodríguez López LOGIN 2: adrian.rodriguez12@udc.es
 * GROUP: 1.4
 * DATE: 17 / 02 / 2023
 */

#include "static_list.h"
#include <string.h>


bool isEmptyList (tList L){
    return L.lastPos==LNULL;
}

void createEmptyList(tList *L){
    //(*L).lastPos=LNULL
    L->lastPos=LNULL;
}

tPosL first(tList L){
    return 0;
}

tPosL last(tList L){
    return L.lastPos;
}

tPosL previous(tPosL p , tList L){
    if(p==0) return LNULL;

    return p--;
}

tPosL next(tPosL p , tList L){
    if(p==L.lastPos) return LNULL;
    return ++p;
}

tItemL getItem (tPosL p ,tList L){
    return L.data[p];
}


void updateItem ( tItemL i, tPosL p, tList *L){
    L->data[p]=i;
}

void deleteList (tList *L){
    L->lastPos=LNULL;
}

void deleteAtPosition(tPosL p, tList *L){
    tPosL i;
    L->lastPos--;
    for( i=p; i<=L->lastPos; i++){
        L->data[i]=L->data[i+1];
    }
}


bool copyList (tList L, tList *M){
    M->lastPos=L.lastPos;
    for (int i =0 ;i<L.lastPos; i++){
        M->data[i]=L.data[i];
    }
    return true;
}



bool insertItem (tItemL d, tPosL p, tList *L){
    tPosL i;
    if(L->lastPos==MAX-1)
        return false;
    else{
        L->lastPos++;
        if(p==LNULL){
            L->data[L->lastPos]= d;
        }else{
            for(i=L->lastPos ; i>p ; i--){
                L->data[i]=L->data[i-1];
            }
            L->data[p]=d;
        }
        return true;
    }
}

tPosL findItem(tParticipantName d, tList L){
    tPosL i;
    if (isEmptyList(L)) {
        return LNULL;
    }else{
        for (i = 0; (i < L.lastPos) && ( strcmp(L.data[i].participantName, d) != 0); i++);
        if (strcmp(L.data[i].participantName, d) == 0){
            return i;
        }else
            return LNULL;
    }
}

/*
tPosL findItem(tItemL d, tList L) {
    tPosL p;

    if (isEmptyList(L)) {
        return LNULL;
    } else {
        for (p = 0; (p < L.lastPos) && (L.data[p] != d); p++);
        if (L.data[p] == d) {
            return p;
        } else
            return LNULL;
    }
}
 */
