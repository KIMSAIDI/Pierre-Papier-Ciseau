#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PIERRE 1
#define FEUILLE PIERRE+1
#define CISEAUX FEUILLE+1
#define NBESSAIS 3
#define POINTSGAGNANTS 3

void affichage_objet(int obj){
  if (obj == PIERRE){
    printf("Le coup choisi est : PIERRE\n");
  } else {
    if (obj == FEUILLE){
      printf("Le coup choisi est : FEUILLE\n");
    } else {
      printf("Le coup choisi est : CISEAUX\n");
    }
  }
}

int choix_ordinateur(void) {
  int i = rand() % 4;
    if (i == 0){
      i++;
    }
    return i;
  }

int choix_joueur() {
  int i;
  printf("Saisissez une valeur comprise entre 1 et 3 :\nRappel :\n1 siginfie PIERRE\n2 siginfie FEUILLE\n3 siginfie CISEAUX\n");
  scanf("%d", &i);
  if (i > CISEAUX || i < PIERRE){
      printf("Saisissez une valeur comprise entre 1 et 3\n");
      scanf("%d",&i);
      if  (i > CISEAUX || i < PIERRE){
        printf("Saisissez une valeur comprise entre 1 et 3\n");
        scanf("%d",&i);
        if  (i > CISEAUX || i < PIERRE){
          i = choix_ordinateur();
        }
     }
  }
  return i;
}

void score(int choixJ, int choixO, int *scoreJ, int *scoreO){
 if (choixJ == PIERRE && choixO == CISEAUX){
   *scoreJ = *scoreJ + 1;
 }
 if (choixJ == PIERRE && choixO == FEUILLE){
   *scoreO = *scoreO + 1;
 }
 if (choixJ == FEUILLE && choixO == PIERRE){
   *scoreJ = *scoreJ + 1;
 }
 if (choixJ == FEUILLE && choixO == CISEAUX){
   *scoreO = *scoreO + 1;
 }
 if (choixJ == CISEAUX && choixO == FEUILLE){
   *scoreJ = *scoreJ + 1;
 }
 if (choixJ == CISEAUX && choixO == PIERRE){
   *scoreO = *scoreO + 1;
 }
}


void jeu() {
 
  int scoreJoueur = 0;
  int scoreOrdi = 0;
  int n = 0;
  int choixJoueur;
  int choixOrdinateur;

  while (n != 1){
    printf("Le joueur commence cette manche\n");
    printf("--------------------------------\n");
      choixJoueur = choix_joueur();
      affichage_objet(choixJoueur);

      printf("--------------------------------\n");

      printf("Au tour de l'ordinateur\n");
      choixOrdinateur = choix_ordinateur();
      affichage_objet(choixOrdinateur);

      printf("--------------------------------\n");

      printf("Calculons les scores !\n");
      score(choixJoueur, choixOrdinateur, &scoreJoueur, &scoreOrdi);
      printf("les scores sont de :\n");
      printf("%d pour l'ordinateur\n", scoreOrdi);
      printf("%d pour le joueur\n", scoreJoueur);

      printf("--------------------------------\n");

      if (scoreJoueur == POINTSGAGNANTS && scoreOrdi == POINTSGAGNANTS){
         printf("--------------------------------\n");
         printf("Pas de gagnant pour cette partie, vous êtes execo\n");
         n = 1;
      }

      if (scoreJoueur == POINTSGAGNANTS && scoreOrdi < scoreJoueur){
        printf("--------------------------------\n");
        printf("Bravo ! Tu gagnes la partie\n");
          n = 1;
        }
        if (scoreOrdi == POINTSGAGNANTS && scoreJoueur < scoreOrdi){
          printf("--------------------------------\n");
          printf("L'ordinateur gagne la partie...\n");
          n = 1;
        }
    }
}



  int main() {

    srand(time(NULL));

    jeu();
    return 0;
  }
