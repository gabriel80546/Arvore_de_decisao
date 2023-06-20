#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* label;
    struct Node* children;
    int numChildren;
};

typedef struct Node Node;

Node* createNode(char* label, int numChildren) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->label = label;
    node->children = (Node*)malloc(numChildren * sizeof(Node));
    node->numChildren = numChildren;
    return node;
}

void printTree(Node* root, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("- %s\n", root->label);

    for (int i = 0; i < root->numChildren; i++) {
        printTree(&root->children[i], level + 1);
    }
}

void navigateTree(Node* currentNode) {
    printf("%s\n", currentNode->label);

    if (currentNode->numChildren > 0) {
        printf("Opções:\n");
        for (int i = 0; i < currentNode->numChildren; i++) {
            printf("%d. %s\n", i + 1, currentNode->children[i].label);
        }

        int choice;
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= currentNode->numChildren) {
            navigateTree(&(currentNode->children[choice - 1]));
        } else {
            printf("Opção inválida.\n");
        }
    }
}

Node init() {
    Node tipoSerVivo = {"Tipo de Ser Vivo", NULL, 3};

    Node animal = {"Animal", NULL, 1};
    Node* animalCaracteristicas = createNode("Características", 3);
    animal.children = animalCaracteristicas;

    Node pelos = {"Pelos", NULL, 0};
    Node numPatas = {"Número de Patas", NULL, 0};
    Node alimentacao = {"Alimentação", NULL, 0};
    animalCaracteristicas->children[0] = pelos;
    animalCaracteristicas->children[1] = numPatas;
    animalCaracteristicas->children[2] = alimentacao;

    Node planta = {"Planta", NULL, 1};
    Node* plantaCaracteristicas = createNode("Características", 3);
    planta.children = plantaCaracteristicas;

    Node tipo = {"Tipo", NULL, 0};
    Node folhas = {"Folhas", NULL, 0};
    Node flores = {"Flores", NULL, 0};
    plantaCaracteristicas->children[0] = tipo;
    plantaCaracteristicas->children[1] = folhas;
    plantaCaracteristicas->children[2] = flores;

    Node fungo = {"Fungo", NULL, 1};
    Node* fungoCaracteristicas = createNode("Características", 2);
    fungo.children = fungoCaracteristicas;

    Node forma = {"Forma", NULL, 0};
    Node habitat = {"Hábitat", NULL, 0};
    fungoCaracteristicas->children[0] = forma;
    fungoCaracteristicas->children[1] = habitat;

    tipoSerVivo.children = (Node*)malloc(tipoSerVivo.numChildren * sizeof(Node));
    tipoSerVivo.children[0] = animal;
    tipoSerVivo.children[1] = planta;
    tipoSerVivo.children[2] = fungo;

    navigateTree(&tipoSerVivo);

    return tipoSerVivo;
}

int main() {

    // Node* arvore = 
    init();

    // printTree(&arvore, 0);
    // navigateTree(arvore);

    return 0;
}
