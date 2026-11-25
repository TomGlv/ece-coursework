

#ifndef PROJET_SNOOPY_FINALE_SNOOPY_STRUCT_H
#define PROJET_SNOOPY_FINALE_SNOOPY_STRUCT_H

typedef struct def_bloc{
    int x;
    int y;
    char perso;
    int vie;                    //valable seulement pour snoopy
    int nb_oiseaux;//idem
    int piege;     // vaut 1 si le bloc est piegé
    int sensTapis; //=-1 si snoopy monte, 1 si snoopy descend, -2 si snoopy va à gauche, 2 si snoopy va à droite.
    int directionX;// directions pour la balle
    int directionY;
}def_bloc;

#endif //PROJET_SNOOPY_FINALE_SNOOPY_STRUCT_H