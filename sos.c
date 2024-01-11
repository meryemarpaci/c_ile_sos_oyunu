#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

int baslama() {
    srand(time(NULL));

    char saha[3][3] = {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%-5c", saha[i][j]);
        }
        printf("\n\n");
    }

    printf("X or O -> ");
    char secim;
    scanf(" %c", &secim);
    secim = tolower(secim);

    bool capraz, yatay, dikey;

    while (1) {
        int a, b;
        printf("seciminiz (a,b) : ");
        scanf("%d,%d", &a, &b);

        if (saha[a][b] == '_') {
            saha[a][b] = secim;
            system("cls");

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("%-5c", saha[i][j]); //bosluklu yazdýr
                }
                printf("\n\n");
            }

            capraz = (saha[0][0] == secim && saha[1][1] == secim && saha[2][2] == secim) || (saha[0][2] == secim && saha[1][1] == secim && saha[2][0] == secim);
            yatay = (saha[0][0] == secim && saha[0][1] == secim && saha[0][2] == secim) || (saha[1][0] == secim && saha[1][1] == secim && saha[1][2] == secim) || (saha[2][0] == secim && saha[2][1] == secim && saha[2][2] == secim);
            dikey = (saha[0][0] == secim && saha[1][0] == secim && saha[2][0] == secim) || (saha[0][1] == secim && saha[1][1] == secim && saha[2][1] == secim) || (saha[0][2] == secim && saha[1][2] == secim && saha[2][2] == secim);

            if (capraz || yatay || dikey) {
                printf("\nKAZANDINIZ !");
                return 0;
            }

            while (1) {  //sosnuz dongü
                a = rand() % 3;
                b = rand() % 3;

                if (saha[a][b] == '_') {
                    if(secim=='x'){
                    	saha[a][b] = 'o';
					}else{
						saha[a][b]='x';
					}
                    
                    system("cls");
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            printf("%-5c", saha[i][j]);
                        }
                        printf("\n\n");
                    }

                    capraz = (saha[0][0] == secim && saha[1][1] == secim && saha[2][2] == secim) || (saha[0][2] == secim && saha[1][1] == secim && saha[2][0] == secim);
                    yatay = (saha[0][0] == secim && saha[0][1] == secim && saha[0][2] == secim) || (saha[1][0] == secim && saha[1][1] == secim && saha[1][2] == secim) || (saha[2][0] == secim && saha[2][1] == secim && saha[2][2] == secim);
                    dikey = (saha[0][0] == secim && saha[1][0] == secim && saha[2][0] == secim) || (saha[0][1] == secim && saha[1][1] == secim && saha[2][1] == secim) || (saha[0][2] == secim && saha[1][2] == secim && saha[2][2] == secim);

                    if (capraz || yatay || dikey) {
                        printf("\nKAYBETTINIZ !");
                        return 0;
                    }

                    break;
                }
            }
        } else {
            printf("Geçersiz hamle. Lütfen boþ bir hücre seçin.\n");
        }
    }

    return 0;
}

