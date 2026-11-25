#include <windows.h>
#include <stdio.h>

// Fonction pour détecter les clics de souris et afficher les coordonnées
void DetectMouseClicks() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    if (hInput == INVALID_HANDLE_VALUE) {
        printf("Erreur : Impossible de recuperer le handle de la console.\n");
        return;
    }
    DWORD prev_mode;
    if (!GetConsoleMode(hInput, &prev_mode)) {
        printf("Erreur : Impossible de recuperer le mode actuel de la console.\n");
        return;
    }

    if (!SetConsoleMode(hInput, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS)) {
        printf("Erreur : Impossible de definir le mode de la console.\n");
        return;
    }

    printf("Cliquez avec le bouton gauche ou droit dans la console pour obtenir les coordonnees (x, y).\n");

    while (1) {
        INPUT_RECORD inputRecord;
        DWORD events;
        if (ReadConsoleInput(hInput, &inputRecord, 1, &events) && events > 0) {
            // Vérifie si un clic de souris a eu lieu
            if (inputRecord.EventType == MOUSE_EVENT) {
                MOUSE_EVENT_RECORD mer = inputRecord.Event.MouseEvent;

                // Clic gauche
                if (mer.dwEventFlags == 0 && mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                    int x = mer.dwMousePosition.X;
                    int y = mer.dwMousePosition.Y;
                    printf("Clic gauche detecte à la position (x: %d, y: %d)\n", x, y);
                }

                // Clic droit
                if (mer.dwEventFlags == 0 && mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
                    int x = mer.dwMousePosition.X;
                    int y = mer.dwMousePosition.Y;
                    printf("Clic droit detecte à la position (x: %d, y: %d)\n", x, y);
                }
            }
        }
    }

    // Restaure le mode d'entrée initial
    SetConsoleMode(hInput, prev_mode);
}

int main() {
    // Appel de la fonction pour détecter les clics de souris
    DetectMouseClicks();
    return 0;
}
