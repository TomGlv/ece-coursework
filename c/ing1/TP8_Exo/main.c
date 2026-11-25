#include <stdio.h>

struct Etudiant {
    float noteMaths;
    float noteInfo;
    float notePhysique;
};

int main() {
    char i;
    float b=0.00;
    struct Etudiant tableauEtudiants[5];
    tableauEtudiants[0].noteMaths = 15.5;
    tableauEtudiants[0].noteInfo = 10.0;
    tableauEtudiants[0].notePhysique = 5.5;
    tableauEtudiants[1].noteMaths = 6.0;
    tableauEtudiants[1].noteInfo = 17.5;
    tableauEtudiants[1].notePhysique = 5.0;
    tableauEtudiants[2].noteMaths = 9.0;
    tableauEtudiants[2].noteInfo = 18.5;
    tableauEtudiants[2].notePhysique = 19.0;
    tableauEtudiants[3].noteMaths = 18.5;
    tableauEtudiants[3].noteInfo = 8.0;
    tableauEtudiants[3].notePhysique = 7.0;
    tableauEtudiants[4].noteMaths = 8.0;
    tableauEtudiants[4].noteInfo = 10.5;
    tableauEtudiants[4].notePhysique = 8.0;

    FILE*pf=fopen("./fichier.txt","w+");
    if(pf==NULL){
        printf("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    for (i=0;i<5;i++){
        fprintf(pf,"Eleve %d : \n",i+1);
        fprintf(pf," Note en Mathématiques: %.1f\n", tableauEtudiants[i].noteMaths);
        fprintf(pf," Note en Informatique: %.1f\n", tableauEtudiants[i].noteInfo);
        fprintf(pf," Note en Physique: %.1f\n", tableauEtudiants[i].notePhysique);
    }
    fprintf(pf,"\nIl y a %d étudiant avec des notes",i);

    if (fwrite(tableauEtudiants, sizeof(char), i, pf) != i) {
        printf("Problème d'écriture dans le fichier.\n");
    }
    fseek(pf, 1*sizeof(int)+2*sizeof(float), SEEK_CUR);
    fread(&b, sizeof(float), 1, pf);
    fclose(pf);
    pf=NULL;
    return 0;
}