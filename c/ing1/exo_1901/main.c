#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pile.h"

// Prototypes de fonctions
bool checkParentheses(char* expression);
int precedence(char operator);
int applyOperation(int operand1, int operand2, char operator);
int evaluateExpression(char* expression);

int main() {
    char expression[100];  // Variable pour stocker l'expression arithmétique
    int choice;

    do {
        printf("1. Saisir une expression arithmetique\n");
        printf("2. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez une expression arithmetique : ");
                scanf("%s", expression);
                if (checkParentheses(expression)) {
                    int result = evaluateExpression(expression);
                    printf("Resultat : %d\n", result);
                } else {
                    printf("Erreur : Le nombre de parentheses est incorrect.\n");
                }
                break;
            case 2:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer 1 ou 2.\n");
        }
    } while (choice != 2);

    return 0;
}
bool checkParentheses(char* expression) {
    Element* stack = NULL;
    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == '(') {
            push(&stack, '(');
        } else if (expression[i] == ')') {
            if (isEmpty(stack) || pop(&stack) != '(') {
                return false;
            }
        }
        i++;
    }
    return isEmpty(stack);
}

int evaluateExpression(char* expression) {
    Element* operandStack = NULL;
    Element* operatorStack = NULL;

    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] >= '0' && expression[i] <= '9') {
            int operand = expression[i] - '0';
            push(&operandStack, operand);
        } else if (expression[i] == '(') {
            push(&operatorStack, '(');
        } else if (expression[i] == ')') {
            while (peek(operatorStack) != '(') {
                char operator = pop(&operatorStack);
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                int result = applyOperation(operand1, operand2, operator);
                push(&operandStack, result);
            }
            pop(&operatorStack); // Retirer la parenthèse ouvrante
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!isEmpty(operatorStack) && precedence(peek(operatorStack)) >= precedence(expression[i])) {
                char operator = pop(&operatorStack);
                int operand2 = pop(&operandStack);
                int operand1 = pop(&operandStack);
                int result = applyOperation(operand1, operand2, operator);
                push(&operandStack, result);
            }
            push(&operatorStack, expression[i]);
        }
        i++;
    }

    // Traiter les opérations restantes
    while (!isEmpty(operatorStack)) {
        char operator = pop(&operatorStack);
        int operand2 = pop(&operandStack);
        int operand1 = pop(&operandStack);
        int result = applyOperation(operand1, operand2, operator);
        push(&operandStack, result);
    }

    return pop(&operandStack);
}

// Fonction pour déterminer la priorité des opérateurs
int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0; // Pour les parenthèses
}

// Fonction pour appliquer l'opération donnée sur les deux opérandes
int applyOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Erreur : Division par zero.\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            return 0;
    }
}
