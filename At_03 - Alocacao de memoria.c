#include <stdio.h>
#include <stdlib.h>


int main (){

float *vetor;
int i, j;
int n;
float soma, media;
soma=0;
media=0;

printf("Informe a repeticao: ");
scanf("%d", &n);

vetor = (float*)malloc(n*sizeof(float));

printf("Armazenando valores em vetor: \n\n");

for (i=0; i<n; i++){
    printf("Informe um valor %d: ", i);
    scanf("%f", &vetor[i]);
}
printf("\n");
printf("Calculo da media: \n");
for (i=0; i<n; i++){
  soma=soma+vetor[i];
}
media=soma/n;
printf("Media: %f", media);
free(vetor);
return 0;
}
