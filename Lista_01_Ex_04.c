#include <stdio.h>
#include <stdlib.h>

int main(){
int M, N, i, j;


printf("Defina a altura da matriz: ");
scanf("%d", &M);
printf("\n");
printf("Defina a largura da matriz: ");
scanf("%d", &N);
printf("\n");

int matriz[M][N];

srand(time(NULL));

//gera e imprime os valores aleatórios
for(i=0;i<M;i++){

    for(j=0;j<N;j++){

        matriz[i][j] = rand();
        printf(" %d ", matriz[i][j]);
    }
    printf("\n");
}
return 0;
}
