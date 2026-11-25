#include "menu.h"

// fonction pour modifier les couleurs
void Color(int couleur_texte, int couleur_fond){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleur_fond*16+couleur_texte);
}

void print_text() {
    Color(5,0);
    printf("\t\t\t#####################################################################################################\n\t\t\t#                                                                                                   #\n\t\t\t#   #         #        ####    #####  #     #   #     ##    #  #### #    # #####    ####    #####   #\n\t\t\t#   #        # #       #   #   #      #     #  # #    # #   # #     #    # #        #    #  #       #\n\t\t\t#   #       #####      #####   #####   #   #  #####   #  #  # #     ###### #####    #     # #####   #\n\t\t\t#   #      #     #     #    #  #        # #  #     #  #   # # #     #    # #        #    #  #       #\n\t\t\t#   ##### #       #    #     # #####     #  #       # #    ##  #### #    # #####    ####    #####   #\n\t\t\t#                                                                                                   #\n\t\t\t#                              ####  ##    #  ####   ####  #### #     #                             #\n\t\t\t#                             #      ##    # #    # #    # #   # #   #                              #\n\t\t\t#                              ####  #  #  # #    # #    # ####    #                                #\n\t\t\t#                                  # #   # # #    # #    # #       #                                #\n\t\t\t#                              ####  #    ##  ####   ####  #       #                                #\n\t\t\t#                                                                                                   #\n\t\t\t#####################################################################################################\n\n");
}


// couleurs :

//0 noir -> mais blanc pour le fond
//1 bleu ++
//2 vert +
//3 turquoise +
//4 rouge +
//5 violet +
//6 jaune ++
//7 gris
//8 gris +
//9 bleu +
//10 vert -
//11 turquoise
//12 rouge
//13 violet -
//14 jaune