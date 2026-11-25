#include "header.h"
int main() {
    t_maillon*ancre=NULL;
    t_maillon* nouv;
    nouv=creerM(4.5);
    ///printf("%.2f \n",nouv->data);
    insererT(3.5,&ancre);
    insererT(12.2,&ancre);
    insererT(7.4,&ancre);
    afficherLC(ancre);
    insererF(3.9,&ancre);
    insererF(8.9,&ancre);
    insererF(98.2,&ancre);
    afficherLC(ancre);
}
