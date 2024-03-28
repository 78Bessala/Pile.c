#include <stdio.h>

void stockerMatrice(int n, int m, int matrice[m][n]) {
    printf("Veuillez entrer les éléments de la matrice :\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("Matrice stockée avec succès !\n");
}

void afficherMatrice(int n, int m, int matrice[m][n]) {
    printf("Matrice :\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}

void additionnerMatrices(int n, int m, int matrice1[n][m], int matrice2[n][m]) {
    int resultat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            resultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
    afficherMatrice(n, m, resultat);
}

void soustraireMatrices(int n, int m, int matrice1[n][m], int matrice2[n][m]) {
    int resultat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            resultat[i][j] = matrice1[i][j] - matrice2[i][j];
        }
    }
    afficherMatrice(n, m, resultat);
}

void multiplierMatrices(int n, int m, int matrice1[n][m], int matrice2[m][n]) {
    int resultat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int produit = 0;
            for (int k = 0; k < m; k++) {
                produit += matrice1[i][k] * matrice2[k][j];
            }
            resultat[i][j] = produit;
        }
    }
    afficherMatrice(n, n, resultat);
}

void produitMatriceVecteur(int n, int m, int matrice[n][m], int vecteur[][m]) {
    multiplierMatrices(n, m, matrice, vecteur);
}

int main() {
    int n, m;
    printf("Veuillez entrer le nombre de lignes de la matrice :\n");
    scanf("%d", &n);
    printf("Veuillez entrer le nombre de colonnes de la matrice :\n");
    scanf("%d", &m);

    int matriceA[m][n], matriceB[n][m];
    int vecteur[n][n];

    int choix;
    do {
        printf("\t 0 Quitter le programme\n");
        printf("\t 1 Stocker une matrice\n");
        printf("\t 2 Afficher une matrice\n");
        printf("\t 3 Additionner deux matrices\n");
        printf("\t 4 Soustraire deux matrices\n");
        printf("\t 5 Multiplier deux matrices\n");
        printf("\t 6 Produit d'une matrice et d'un vecteur\n");
        printf("Votre choix :\n");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                  printf("AU REVOIR ET MERCI POUR LA VISITE\n");
                  break;
            case 1:
                stockerMatrice(n, m, matriceB);
                break;
            case 2:
                afficherMatrice(n, m, matriceB);
                break;
            case 3:
                 printf("Veuillez entrer les éléments de la matriceA :\n");
                 for (int i = 0; i < m; i++) {
                  for (int j = 0; j < n; j++) {
                  scanf("%d", &matriceA[i][j]);
                 }  
                 }
                 
                  printf("Veuillez entrer les éléments de la matriceB :\n");
                     for (int i = 0; i < n; i++) {
                     for (int j = 0; j < m; j++) {
                    scanf("%d", &matriceB[i][j]);
                     }
                    }

                additionnerMatrices(n, m, matriceA, matriceB);
                break;
            case 4:
               printf("Veuillez entrer les éléments de la matriceA :\n");
                 for (int i = 0; i < m; i++) {
                  for (int j = 0; j < n; j++) {
                  scanf("%d", &matriceA[i][j]);
                 }  
                 }
                 
                  printf("Veuillez entrer les éléments de la matriceB :\n");
                     for (int i = 0; i < n; i++) {
                     for (int j = 0; j < m; j++) {
                    scanf("%d", &matriceB[i][j]);
                     }
                    }

                
                soustraireMatrices(n, m, matriceA, matriceB);
             
                break;
            case 5:
               
                  printf("Veuillez entrer les éléments de la matriceA :\n");
                 for (int i = 0; i < m; i++) {
                  for (int j = 0; j < n; j++) {
                  scanf("%d", &matriceA[i][j]);
                 }  
                 }
                 
                  
                  printf("Veuillez entrer les éléments de la matriceB :\n");
                     for (int i = 0; i < n; i++) {
                     for (int j = 0; j < m; j++) {
                    scanf("%d", &matriceB[i][j]);
                     }
                    }
                    
                     multiplierMatrices(n, m, matriceA, matriceB);
                
                break;
            case 6:
                printf("Veuillez entrer les éléments de la matriceB :\n");
                     for (int i = 0; i < n; i++) {
                     for (int j = 0; j < m; j++) {
                    scanf("%d", &matriceB[i][j]);
                     }
                    }
                    
                     printf("Veuillez entrer les éléments du vecteur :\n");
                     for (int i = 0; i < n; i++) {
                     for (int j = 0; j < n; j++) {
                    scanf("%d", &vecteur);
                     }
                    }


                produitMatriceVecteur(n, m, matriceB, vecteur);
                break;
            default:
                printf("Désolé, cette fonction n'est pas disponible. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
