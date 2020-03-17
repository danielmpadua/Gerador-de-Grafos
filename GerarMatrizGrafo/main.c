#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int aleatorio, NVERTICES;
    printf(">>> GERADOR DE GRAFOS ALEATORIOS [COMPLETO e DIRECIONADO] COM PESOS DE 1 A 10 <<<\n\nInfome a quantidade de vertices desejado: ");
    scanf("%d",&NVERTICES);
    printf("Gerando Grafo...\n\n");

    int gr[NVERTICES][NVERTICES];
        for(int i=0; i<NVERTICES;i++){
        for(int j=0; j<=i; j++){
            if(i==j){
                gr[i][j] = 0;
            }else{
                aleatorio = rand()%100;
                if(aleatorio>50){
                    gr[i][j] = (rand()%10) + 1;
                    gr[j][i] = 0;
                }else{
                    gr[i][j] = 0;
                    gr[j][i] = (rand()%10) + 1;
                }
            }
        }
    }

    char url[]="grafo2.txt";
    int aux;
    FILE *arq;
    arq = fopen(url, "w");
    aux =NVERTICES;
    fprintf(arq, "%d\n", aux);
    for(int i=0; i<NVERTICES;i++){
        for(int j=0; j<NVERTICES; j++){
            aux=gr[i][j];
            fprintf(arq, "%d ", aux);
        }
        fprintf(arq, "\n");
    }
    fclose(arq);
    printf("SUCESSO!!!\n\n");
    printf("O arquivo se encontra na pasta do projeto!\n\n");
    return 0;
}
