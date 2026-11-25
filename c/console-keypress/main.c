#include <windows.h>
#include <stdio.h>

HHOOK keyboardHook;

// Fonction de callback pour le hook clavier
LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* keyInfo = (KBDLLHOOKSTRUCT*)lParam;

        if (wParam == WM_KEYDOWN) {
            // Si la touche "3" est pressée (code virtuel de la touche "3" est 0x33)
            if (keyInfo->vkCode == 0x33) {
                printf("Touche 3 détectée !\n");
            }
        }
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

// Fonction pour simuler l'appui de la touche "3"
void simulateKeyPress(int key) {
    INPUT input[2] = {0};

    // Simuler l'appui de la touche
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = key;  // Touche à simuler (ici '3')

    // Simuler le relâchement de la touche
    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = key;
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;  // KEYUP signifie relâchement de la touche

    // Envoyer les événements pour appuyer et relâcher la touche
    SendInput(2, input, sizeof(INPUT));
    printf("Simuler la touche %d.\n", key);
}

int main() {
    // Installation du hook clavier global
    keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardProc, NULL, 0);
    if (keyboardHook == NULL) {
        printf("Erreur de l'installation du hook clavier\n");
        return -1;
    }

    // Simuler l'appui "33void win(const char* winner) {
    //    system("cls"); // Efface la console
    //
    //    printf("\n");
    //
    //        printf(" _   _ _____ _____ _____ _____________   __ ______ _______   _____   _      _____ \n");
    //        printf("| | | |_   _/  __ \\_   _|  _  | ___ \\ \\ / / | ___ \\  _  \\ \\ / / _ \\ | |    |  ___|\n");
    //        printf("| | | | | | | /  \\/ | | | | | | |_/ /\\ V /  | |_/ / | | |\\ V / /_\\ \\| |    | |__  \n");
    //        printf("| | | | | | | |     | | | | | |    /  \\ /   |    /| | | | \\ /|  _  || |    |  __| \n");
    //        printf("\\ \\_/ /_| |_| \\__/\\ | | \\ \\_/ / |\\ \\  | |   | |\\ \\\\ \\_/ / | || | | || |____| |___ \n");
    //        printf(" \\___/ \\___/ \\____/ \\_/  \\___/\\_| \\_| \\_/   \\_| \\_|\\___/  \\_/\\_| |_/\\_____/\\____/ \n");
    //        printf("                                                                                  \n");
    //    printf("\n");
    //    printf(" Félicitations, %s ! Vous avez remporté une VICTOIRE ROYALE ! \n", winner);
    //
    //    Sleep(5000);
    //    system("cls");
    //    Init();
    //};

    // Boucle d'attente pour détecter les événements clavier
    printf("Attente de la touche 3...\n");
    while (1) {
        Sleep(100);  // Attendre 100ms pour éviter un usage excessif du CPU
    }

    // Désinstaller le hook avant de quitter
    UnhookWindowsHookEx(keyboardHook);
    return 0;
}
