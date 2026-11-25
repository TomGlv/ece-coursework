#include <stdio.h>
#include <string.h>

int main() {
    char chaine[100];
    char caractere;
    int i, nombre_occurrences = 0;
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaine);
    printf("Entrez un caractere a rechercher : ");
    scanf(" %c", &caractere);
    for (i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] == caractere) {
            nombre_occurrences++;
        }
    }
    printf("Le caractere '%c' apparait %d fois dans la chaine.\n", caractere, nombre_occurrences);
    return 0;
}





