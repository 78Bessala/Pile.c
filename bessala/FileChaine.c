#include<stdio.h>
#include<stdlib.h>

typedef struct liste {
    int val;
    struct liste *suiv;
} liste;

typedef struct file {
    liste *deb;
    liste *fin;
} file;

file creer_file() {
    file ma_file;
    ma_file.deb = ma_file.fin = NULL;
    return ma_file;
}

int est_vide(file *ma_file) {
    return ma_file->deb == NULL;
}

void enfiler(file *ma_file, int val) {
    liste *ma_liste = (liste*)malloc(sizeof(liste));
    ma_liste->val = val;
    ma_liste->suiv = NULL;

    if(est_vide(ma_file)) {
        ma_file->deb = ma_liste;
        ma_file->fin = ma_liste;
    } else {
        ma_file->fin->suiv = ma_liste;
        ma_file->fin = ma_liste;
    }
}

file defiler(file *ma_file) {
    if(est_vide(ma_file)) {
        printf("ERREUR: la file est vide !!\n");
        exit(0);
    }

    liste *ma_liste = ma_file->deb;
    ma_file->deb = ma_file->deb->suiv;
    free(ma_liste);

    if(ma_file->deb == NULL) {
        ma_file->fin = NULL;
    }

    return *ma_file;
}

int sommet(file *ma_file) {
    if(est_vide(ma_file)) {
        printf("ERREUR: la file est vide !!\n");
        exit(0);
    }

    return ma_file->deb->val;
}

void vider(file *ma_file) {
    if(est_vide(ma_file)) {
        printf("ERREUR: la file est vide !!\n");
        exit(0);
    }

    while(ma_file->deb != NULL) {
        defiler(ma_file);
    }
    ma_file->fin = NULL;
}

void afficher(file *ma_file) {
    if(est_vide(ma_file)) {
        printf("La file est vide.\n");
        return;
    }

    liste *ma_liste = ma_file->deb;
    printf("Éléments de la file : ");
    while(ma_liste != NULL) {
        printf("%d ", ma_liste->val);
        ma_liste = ma_liste->suiv;
    }
    printf("\n");
}

int main() {
    file my_file = creer_file();
    int elt,som,choix;
    // puisque ma file est au depart
   printf("Veuiller entrer l'element a enfiler\n");
   scanf("%d",&elt);
   enfiler(&my_file, elt);
  //menu
    printf("BIENVENUE DANS LE MENU !!!\n");
  printf("\n");
  do{
     printf("QUE SOUHAITEZ VOUS FAIRE ?\n");
     printf("\t 0 QUITTER LE PROGRAMME\n");
     printf("\t 1 ENFILER UN ELEMENT \n");
     printf("\t 2 AFFICHER LA TETE DE FILE \n");
     printf("\t 3 AFFICHER LA FILE \n");
     printf("\t 4 DEFIILER LA FOILE\n");
     printf("\t 5 VIDER LA FILE\n");
     printf("\n");
     printf("Votre choix!\n");
     scanf("%d",&choix);
     printf("\n");

     switch (choix)
     {
     case 0 :
         if(est_vide(&my_file)){
        printf("la file est vide!!\n");
        }
        printf("AU REVOIR ET MERCI POUR LA VISITE !\n");

        break;
    case 1: 
     printf("Veuiller entrer l'element a enfiler\n");
     scanf("%d",&elt);
     enfiler(&my_file,elt);
      printf("\n");
       break;
    case 2 :
     som = sommet(&my_file);
      printf("Le sommet de la file est : %d\n", som);
       printf("\n");
      break;

    case 3:
     afficher(&my_file);
     printf("\n");
      break;

    case 4:
     my_file = defiler(&my_file);
     printf("element defiler avec success !!\n");
     printf("\n");
      break;
    
    case 5:
       vider(&my_file);
       printf("file vider avec success !\n");
       printf("\n");
     break;
      
     
     default:
     printf("Désole cette operation n'est pas disponible.Veuillez réessayer\n");
     printf("\n");
        break;
     }


  }while(choix !=0);


    return 0;
}