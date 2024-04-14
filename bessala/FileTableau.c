
#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct file {
  int collecte[max];
  int tete;
  int dernier;
  int nbr_elts;
} file;

file creer_file(){
    file ma_file;
    ma_file.dernier = ma_file.tete = ma_file.nbr_elts = 0;
    return ma_file;
}

int est_vide(file *ma_file) {
   return ma_file->nbr_elts == 0;
}

int est_pleine(file *ma_file){
    return ma_file->nbr_elts == max;
}

void enfiler(file *ma_file, int elt){
    if(est_pleine(ma_file)){
        printf("ERREUR: la file est pleine !!\n");
        exit(0);
    }
    ma_file->collecte[ma_file->dernier] = elt;
    ma_file->dernier++;
    if(ma_file->dernier == max){
        ma_file->dernier = 0;
    }
    ma_file->nbr_elts++;
}

int defiler(file *ma_file){
    if(est_vide(ma_file)){
        printf("ERREUR: la file est vide!!\n");
        exit(0);
    }
    int tmp = ma_file->collecte[ma_file->tete];
    ma_file->tete++;
    if(ma_file->tete == max){
        ma_file->tete = 0;
    }
    ma_file->nbr_elts--;
    return tmp;
}

int tete(file *ma_file){
    if(est_vide(ma_file)){
        exit(0);
    }
    return ma_file->collecte[ma_file->tete];
}
void afficher(file *ma_file) {
    if(est_vide(ma_file)) {
        printf("La file est vide.\n");
        return;
    }

    int i = ma_file->tete;
    int count = 0;

    printf("Éléments de la file : ");
    while(count < ma_file->nbr_elts) {
        printf("%d ", ma_file->collecte[i]);
        i++;
        count++;
        if(i == max) {
            i = 0;
        }
    }
    printf("\n");
}


int main(){
    int tet,choix,elt;
  file ma_file=creer_file();
  // puisque ma file est au depart
   printf("Veuiller entrer l'element a enfiler\n");
   scanf("%d",&elt);
  enfiler(&ma_file,elt);
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
     printf("\n");
     printf("Votre choix!\n");
     scanf("%d",&choix);
     printf("\n");

     switch (choix)
     {
     case 0 :
        if(est_pleine(&ma_file)){
        printf("la file est pleine !!\n");
       }else if(est_vide(&ma_file)){
        printf("la file est vide!!\n");
        }
        printf("AU REVOIR ET MERCI POUR LA VISITE !\n");

        break;
    case 1: 
     printf("Veuiller entrer l'element a enfiler\n");
     scanf("%d",&elt);
     enfiler(&ma_file,elt);
      printf("\n");
       break;
    case 2:
      tet=tete(&ma_file);
      printf("la tete dela file est : %d\n",tet);
      printf("\n");
      break;

    case 3:
     afficher(&ma_file);
     printf("\n");
      break;

    case 4:
      defiler(&ma_file);
     printf("element defiler avec success !!\n");
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
