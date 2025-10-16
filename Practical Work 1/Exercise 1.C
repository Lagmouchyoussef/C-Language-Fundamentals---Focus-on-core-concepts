#include<stdio.h>
#include<stdlib.h>
// Exercise 1.C: Array operations in C
void afficher_tableau(int t[], int taille) {
    for(int i = 0; i < taille; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}

float moyenne(int t[], int taille) {
    int somme = 0;
    for(int i = 0; i < taille; i++) {
        somme += t[i];
    }
    return (float)somme / taille;
}

int rechercher_valeur(int t[], int taille, int x) {
    for(int i = 0; i < taille; i++) {
        if(t[i] == x) {
            return i;
        }
    }
    return -1; 
}

int max_tableau(int t[], int taille) {
    int max = t[0];
    for(int i = 1; i < taille; i++) {
        if(t[i] > max) {
            max = t[i];
        }
    }
    return max;
}

int nb_occurrences(int t[], int taille, int x) {
    int count = 0;
    for(int i = 0; i < taille; i++) {
        if(t[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int taille;
    printf("Entrez la taille du tableau: ");
    scanf("%d", &taille);
    
    int *tableau = (int*)malloc(taille * sizeof(int));
    if(tableau == NULL) {
        printf("Erreur d'allocation de memoire\n");
        return 1;
    }
    
    printf("Entrez les elements du tableau:\n");
    for(int i = 0; i < taille; i++) {
        scanf("%d", &tableau[i]);
    }
    
    printf("Tableau: ");
    afficher_tableau(tableau, taille);
    
    printf("Moyenne: %.2f\n", moyenne(tableau, taille));
    
    int x;
    printf("Entrez une valeur a rechercher: ");
    scanf("%d", &x);
    int index = rechercher_valeur(tableau, taille, x);
    if(index != -1) {
        printf("Valeur %d trouvee a l'index %d\n", x, index);
    } else {
        printf("Valeur %d non trouvee\n", x);
    }
    
    printf("Maximum: %d\n", max_tableau(tableau, taille));
    
    printf("Entrez une valeur pour compter les occurrences: ");
    scanf("%d", &x);
    printf("Nombre d'occurrences de %d: %d\n", x, nb_occurrences(tableau, taille, x));
    
    free(tableau);
    return 0;
}