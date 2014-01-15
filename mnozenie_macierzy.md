```sh
#include <stdio.h>

void main(){
        int i;
        int j;
        int k;

        int kolu1;
        int wier1;

        int kolu2;
        int wier2;

        printf("Podaj rozmiar macierzy np. 2x2: \n");
        scanf("%ix%i", &wier1, &kolu1);
        printf("Podaj rozmiar macierzy np. 3x3: \n");
        scanf("%ix%i", &wier2, &kolu2);

        int tab1[wier1][kolu1];
        int tab2[wier2][kolu2];
        int wyn[wier1][kolu2];
        
        if(kolu1 != wier2){
                printf("Macierz niewymnazalna!\n");
        }else{
                printf("Podaj liczby pierwszej macierzy: \n");
                for(i=0; i<wier1; i++){
                        for(j=0; j<kolu1; j++){
                                scanf("%i", &tab1[i][j]);
                        }
                }

                printf("Podaj liczby drugiej macierzy: \n");
                for(i=0; i<wier2; i++){
                        for(j=0; j<kolu2; j++){
                                scanf("%i", &tab2[i][j]);
                        }
                }

                for(i=0; i<wier1; i++){
                        for(j=0; j<kolu2; j++){
                                wyn[i][j] = 0;
                                for(k=0; k<kolu1; k++){
                                        wyn[i][j] += tab1[i][k] * tab2[k][j];
                                }
                        }
                }

                printf("\nWynik mnozenia!: \n");
                for(i=0; i<wier1; i++){
                        if(i>0)printf("\n");
                        for(j=0; j<kolu2; j++){
                                if(j>0)printf(" ");
                                printf("%i", wyn[i][j]);
                        }
                }
                printf("\n");
        }
}
```
