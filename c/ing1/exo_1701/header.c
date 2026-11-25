#include "header.h"
t_maillon* creerM(float x){
    t_maillon* nouv;
    nouv = malloc(sizeof(t_maillon));
    nouv->data=x;
    nouv->next=NULL;
    return nouv;
}
void insererT(float x,t_maillon** pancre){
    t_maillon*nouv;
    nouv = creerM(x);
    if (*pancre == NULL){
        *pancre=nouv;
    }
    else{
        nouv->next=*pancre;
        *pancre=nouv;
    }
}
void afficherLC(t_maillon* ancre){
    t_maillon* temp;
    temp = ancre;
    while (temp!= NULL){
        printf("\n %f ",temp->data);
        temp = temp->next;
    }
}
void insererF(float x,t_maillon** pancre){
    t_maillon*nouv;
    t_maillon*temp;
    nouv = creerM(x);
    if (*pancre == NULL){
        *pancre=nouv;
    }
    else{
        temp=*pancre;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nouv;
    }
}