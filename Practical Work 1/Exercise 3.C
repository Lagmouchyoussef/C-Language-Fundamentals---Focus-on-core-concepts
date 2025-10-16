#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MODULE 50

typedef struct {
    char module[MAX_MODULE];
    int coef;
    float note;
} Note;

typedef struct {
    char nom[50];
    int age;
    Note *notes;
    int taille;
    int nbNote;
} Etudiant;

Etudiant init_etudiant(char nom[], int age, int nb_notes) {
    Etudiant e;
    strcpy(e.nom, nom);
    e.age = age;
    e.taille = nb_notes;
    e.nbNote = 0;
    e.notes = (Note*)malloc(nb_notes * sizeof(Note));
    return e;
}

void affiche_etud(Etudiant e) {
    printf("\n=== Etudiant: %s ===\n", e.nom);
    printf("Age: %d ans\n", e.age);
    printf("Notes (%d/%d):\n", e.nbNote, e.taille);
    
    if(e.nbNote == 0) {
        printf("Aucune note enregistree\n");
        return;
    }
    
    for(int i = 0; i < e.nbNote; i++) {
        printf("  %s (coef %d): %.2f/20\n", 
               e.notes[i].module, e.notes[i].coef, e.notes[i].note);
    }
}

int module_existe(Etudiant e, char module[]) {
    for(int i = 0; i < e.nbNote; i++) {
        if(strcmp(e.notes[i].module, module) == 0) {
            return i;
        }
    }
    return -1;
}

bool ajouter_note(Etudiant *e, char module[], int coef, float note) {

    if(e->nbNote >= e->taille) {
        printf("Erreur: Capacite maximale atteinte\n");
        return false;
    }
    
    if(module_existe(*e, module) != -1) {
        printf("Erreur: Le module '%s' existe deja\n", module);
        return false;
    }
    
    if(note < 0 || note > 20) {
        printf("Erreur: La note doit etre entre 0 et 20\n");
        return false;
    }
    
    if(coef <= 0) {
        printf("Erreur: Le coefficient doit etre positif\n");
        return false;
    }
    
    strcpy(e->notes[e->nbNote].module, module);
    e->notes[e->nbNote].coef = coef;
    e->notes[e->nbNote].note = note;
    e->nbNote++;
    
    printf("Note ajoutee avec succes\n");
    return true;
}

bool modifier_note(Etudiant *e, char module[], float nouvelle_note) {
    int index = module_existe(*e, module);
    if(index == -1) {
        printf("Erreur: Module '%s' non trouve\n", module);
        return false;
    }
    
    if(nouvelle_note < 0 || nouvelle_note > 20) {
        printf("Erreur: La note doit etre entre 0 et 20\n");
        return false;
    }
    
    e->notes[index].note = nouvelle_note;
    printf("Note modifiee avec succes\n");
    return true;
}

bool supprimer_note(Etudiant *e, char module[]) {
    int index = module_existe(*e, module);
    if(index == -1) {
        printf("Erreur: Module '%s' non trouve\n", module);
        return false;
    }
    
    for(int i = index; i < e->nbNote - 1; i++) {
        e->notes[i] = e->notes[i + 1];
    }
    e->nbNote--;
    
    printf("Note supprimee avec succes\n");
    return true;
}

float calculer_moyenne(Etudiant e) {
    if(e.nbNote == 0) return 0;
    
    float somme_notes = 0;
    int somme_coef = 0;
    
    for(int i = 0; i < e.nbNote; i++) {
        somme_notes += e.notes[i].note * e.notes[i].coef;
        somme_coef += e.notes[i].coef;
    }
    
    return somme_notes / somme_coef;
}

float note_maximale(Etudiant e) {
    if(e.nbNote == 0) return 0;
    
    float max = e.notes[0].note;
    for(int i = 1; i < e.nbNote; i++) {
        if(e.notes[i].note > max) {
            max = e.notes[i].note;
        }
    }
    return max;
}

int main() {
    Etudiant etud = init_etudiant("Jean Dupont", 20, 5);
    
    printf("=== Gestion des notes d'etudiants ===\n");
    
    ajouter_note(&etud, "Mathematiques", 3, 15.5);
    ajouter_note(&etud, "Physique", 2, 18.0);
    ajouter_note(&etud, "Informatique", 4, 16.5);
    
    affiche_etud(etud);
    
    ajouter_note(&etud, "Mathematiques", 3, 14.0);
    
    modifier_note(&etud, "Physique", 19.5);
    
    affiche_etud(etud);

    printf("\nMoyenne generale: %.2f/20\n", calculer_moyenne(etud));
    printf("Note maximale: %.2f/20\n", note_maximale(etud));
    
    supprimer_note(&etud, "Informatique");
    affiche_etud(etud);
    
    free(etud.notes);
    
    return 0;
}