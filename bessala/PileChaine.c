#include <stdio.h>
#include <stdlib.h>

typedef struct liste {
    int elt;
    struct liste* suiv;
} liste;

typedef struct pile {
    liste* sommet;
} pile;

pile cree_pile() {
    pile Pile;
    Pile.sommet = NULL;
    return Pile;
}

int est_vide(pile p) {
    return p.sommet == NULL;
}

int sommet(pile p) {
    if (est_vide(p)) {
        printf("La pile est vide !!\n");
        exit(0);
    }
    return p.sommet->elt;
}

void empiler(pile* Pile, int elt) {
    liste* ma_liste = (liste*)malloc(sizeof(liste));
    ma_liste->elt = elt;
    ma_liste->suiv = Pile->sommet;
    Pile->sommet = ma_liste;
}


int depiler(pile* Pile) {
    if (est_vide(*Pile)) {
        printf("La pile est vide !!\n");
        exit(0);
    }
    int elt = Pile->sommet->elt;
    liste* tmp = Pile->sommet;
    Pile->sommet = Pile->sommet->suiv;
    free(tmp);
    return elt;
}

void vider(pile* Pile) {
    while (Pile->sommet) {
        depiler(Pile);
    }
}

void affichepile(pile* Pile) {
    if (est_vide(*Pile)) {
        printf("Pile vide!\n");
    } else {
        liste* tmp = Pile->sommet;
        printf("Contenu de la pile :\n");
        while (tmp != NULL) {
            printf("%d\n", tmp->elt);
            tmp = tmp->suiv;
        }
    }
}

int main() {
    pile Pile = cree_pile();
    int choix,elts,elt;
    // entrer le premier element de la pile

     printf("Veuillez entrer l'element a empiler\n");
     scanf("%d",&elts);
     empiler(&Pile,elts);
     printf("BIENVENUE DANS LE MENU\n");
     printf("\n");

    do{
        printf("QUE SOUHAITEZ VOUS FAIRE !!!\n");
        printf("\t 0 quitter le menu\n");
        printf("\t 1 empiler un element\n");
        printf("\t 2 afficher le sommet\n");
        printf("\t 3 depiler un element\n");
        printf("\t 4 afficher la pile\n");
        printf("\t 5 vider la pile\n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 0:
          if (est_vide(Pile)) {
           printf("La pile est vide !!\n");
          }
            printf("AU REVOIR ET MERCI POUR VOTRE VISITE\n");
            break;
        case 1:
            printf("Veuillez entrer le nouvel'element a empiler\n");
            scanf("%d",&elts);
            empiler(&Pile,elts);
            printf("elements empiler avec succes!!\n");
            printf("\n");
         break;

        case 2:
             printf("Le sommet est : %d\n", sommet(Pile));
          break;

        case 3:
         elt = depiler(&Pile);
         printf("L'élément dépilé est : %d\n", elt);
         printf("\n");
        break;

        case 4: 
         affichepile(&Pile);
         printf("\n");
         break;
        
        case 5:
          vider(&Pile);
          printf("Pile vider avec success !\n");
          printf("\n");
          break;
        
        default:
          printf("Désolé votre choix n est pas disponible.Veuilles reessayer\n");
        break;
        }

    }while(choix !=0);
   


    return 0;
}