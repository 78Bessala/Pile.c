#include <stdio.h>

int main() {
    printf("punition,recopier une phrase 100 fois avec 8 police differentes :\n");

    for (int repetition = 0; repetition < 100; repetition++) {
        for (int police = 0; police < 8; police++) {
            printf("\n");

            switch (police) {
                case 0:
                    printf("\x1b[0m");  
                    break;
                case 1:
                    printf("\x1b[1m");  
                    break;
                case 2:
                    printf("\x1b[3m");  
                    break;
                case 3:
                    printf("\x1b[4m");  
                    break;
                case 4:
                    printf("\x1b[7m");  
                    break;
                case 5:
                    printf("\x1b[9m");  
                    break;
                case 6:
                    printf("\x1b[31m"); 
                    break;
                case 7:
                    printf("\x1b[34m"); 
                    break;
            }

            printf("Je ne dirai jamais 'hour' pendant le cours d'INFO1122. (Police %d)", police);
        }
    }

    printf("\x1b[0m\n");  

    return 0;
}