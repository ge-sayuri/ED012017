
#include <stdio.h>
#include <stdlib.h>


int main (){

float vetor[10], matriz[3][4];
int i, j;

printf("Armazenando valores em vetor: \n\n");

for (i=0; i<10; i++){
    printf("Informe um valor %d: ", i);
    scanf("%f", &vetor[i]);
}

printf("\n");
printf("Os valores armazenados no vetor sao: \n");
for (i=0; i<10; i++){
    printf("%d: %f\n", i, vetor[i]);

}
printf("\n");
printf("\n");

for (i=0; i<3; i++){
  for (j=0; j<4; j++){

  printf("Digite um valor para matriz [%d][%d]:",i,j);
  scanf("%f",&matriz[i][j]);

}
}

printf("\n");
printf("Os valores armazenados na matriz sao: \n");

for(i=0;i<3;i++) {
  for(j=0;j<4;j++) {
  printf("%f\t", matriz[i][j]);
}
printf("\n");
}
    return 0;
}
