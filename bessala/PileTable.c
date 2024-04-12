#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct pile {
    int table[max];
    int sommet;
} pile;

int est_vide(pile *ma_pile) {
    if (ma_pile->sommet == -1) {
        return 1;
    } else {
        return 0;
    }
}

int est_pleine(pile *p) {
    if (p->sommet == max - 1) {
        return 1;
    } else {
        return 0;
    }
}

int sommet(pile *ma_pile) {
    if (est_vide(ma_pile)) {
        printf("ERREUR: la pile est vide !!\n");
        exit(0);
    } else {
        return ma_pile->table[ma_pile->sommet];
    }
}

void empiler(pile *ma_pile, int x) {
    if (est_pleine(ma_pile)) {
        printf("ERREUR: la pile est vide !!\n");
        exit(0);
    } else {
        ma_pile->sommet = ma_pile->sommet + 1;
        ma_pile->table[ma_pile->sommet] = x;
    }
}

void depiler(pile *ma_pile) {
    if (est_vide(ma_pile)) {
        printf("ERREUR: la pile est vide !!\n");
        exit(0);
    } else {
      ma_pile->sommet = ma_pile->sommet - 1;
    }
     
}

pile init() {
    pile *ma_pile = (pile*)malloc(sizeof(pile));
    ma_pile->sommet = -1;
    return *ma_pile;
}

void aff(pile *ma_pile) {
    for (int i = ma_pile->sommet; i >= 0; i--) {
        printf("%d\n", ma_pile->table[i]);
    }
}

int main() {
    int somme,choix,elt;
    pile ma_pile = init();
    //puisque ma pile est vide l'utilisateur doit d' abord entrer empiler un premier element
    printf("Veuillez entrer l element a empiler\n");
    scanf("%d",&elt);
    empiler(&ma_pile, elt);
    printf("\n");
    printf("..........---: BIENVENUE DANS LE MENU !! :--......\n");
    printf("\n");
    printf("**********************************************\n");
    printf("\n");

    do {

        printf("QUE SOUHAITEZ VOUS FAIRE ??\n");
        printf("\t 0 QUITTER LE PROGRAMME\n");
        printf("\t 1 EMPILER DE NOUVEAU\n");
        printf("\t 2 AFFFICHER LE SOMMET\n");
        printf("\t 3 AFFICHER LE CONTENU DE LA PILE\n");
        printf("\t 4 DEPILER UN ELEMENT\n");
        printf("\n");
        printf("Votre choix!!\n");
        scanf("%d",&choix);
        printf("\n");
        switch (choix)
        {
        case 0: 
         if (est_vide(&ma_pile)) {
         printf("La pile est vide !!\n");
         exit(0);
         }else if (est_vide(&ma_pile)) {
         printf("ERREUR: la pile est vide !!\n");
         exit(0);
          }
          printf("AU REVOIR ET MERCI POUR VOTRE VISITE\n");
            break;

        case 1:
           printf("Veuillez entrer a empiler\n");
            scanf("%d",&elt);
           empiler(&ma_pile, elt);
           printf("element empiler avec success !!\n");
           printf("\n");
          break;
        case 2:
         somme=sommet(&ma_pile);
         printf("le sommet de la pile est : %d\n",somme);
          printf("\n");
         break;

        case 3:
           aff(&ma_pile);
           printf("\n");
         break;

        case 4: 
            depiler(&ma_pile);
            printf("Operation realisee avec success !!\n");
            break;

        default:
        printf("Désolé cete fonctionnalité n'est pas disponible.veuillez réessayer !!\n");
            break;
        }   
    }while(choix!=0);

    return 0;
    
}