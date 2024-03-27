#include <stdio.h>

void stock(int n, int B[][n]) {
    printf("Veuillez entrer les éléments du tableau\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
}

void aff(int n, int B[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }
}

void add(int n, int B[][n], int E[][n]) {
    int A[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j] + E[i][j];
        }
    }
    aff(n, A);
}

void sous(int n, int B[][n], int E[][n]) {
    int A[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j] - E[i][j];
        }
    }
    aff(n, A);
}

float calculerNorme(int n, int A[][n]) {
    int sommeCarres = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sommeCarres += A[i][j] * A[i][j];
        }
    }
    float norme = 0.0;
    int precision = 1000; // Précision pour l'arrondi à deux décimales
    int normeCarre = sommeCarres * precision;
    int racineCarree = normeCarre;
    int difference = 1;
    while (difference > 0) {
        difference = (racineCarree + (normeCarre / racineCarree) - (2 * precision)) / 2;
        racineCarree = (racineCarree + (normeCarre / racineCarree)) / 2;
    }
    norme = racineCarree / precision;
    return norme;
}

void calculerDistance(int n, int B[][n], int E[][n]) {
    float distance = calculerNorme(n, B) - calculerNorme(n, E);
    printf("Distance entre les deux vecteurs : %.2f\n", distance);
}

int main() {
    int n;
    printf("Veuillez entrer le nombre d'éléments des vecteurs : ");
    scanf("%d", &n);
    int B[n][n], E[n][n];
    int choix;
    do {
    printf("\t0 pour quitter\n");
    printf("\t1 pour stocker\n");
    printf("\t2 pour afficher\n");
    printf("\t3 pour l'addition\n");
    printf("\t4 pour la soustraction\n");
    printf("\t5 pour la norme\n");
    printf("\t6 pour la distance\n");
    printf("Veuillez faire votre choix : ");
    scanf("%d", &choix);
   
   
    switch (choix) {
        case 1:
            stock(n, B);
            break;
        case 2:
            aff(n, B);
            break;
        case 3:
            stock(n, B);
            stock(n, E);
            add(n, B, E);
            break;
        case 4:
            stock(n, B);
            stock(n, E);
            sous(n, B, E);
            break;
        case 5:
            stock(n, B);
            float normeB = calculerNorme(n, B);
            printf("Norme du vecteur B : %.2f\n", normeB);
            break;
        case 6:
            stock(n, B);
            stock(n, E);
            calculerDistance(n, B, E);
            break;
        default:
            printf("Désolé, cette fonctionnalité n'est pas disponible. Veuillez réessayer.\n");
            break;
    }
    printf("\n");
    }while(choix !=0);
    
    return 0;
}


