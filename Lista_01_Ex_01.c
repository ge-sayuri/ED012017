#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A populacao tera 10 elementos
#define ELEMENTOS 10

int main (){

float vr[ELEMENTOS], media=0, desvio=0;
int i=0;

printf("\n");
printf("\n");
printf("Neste programa calcularemos o desvio padrao em uma populacao de %d elementos informados pelo usuario", ELEMENTOS);
printf("\n\n");

printf("Forneca os valores dos elementos:");
printf("\n\n");

//Armazenar os valores dos elementos e armazena sua soma na variavel media
for(i=0;i<ELEMENTOS;i++){
    printf("  %d - ",i+1);
    scanf("%f", &vr[i]);
    media = media + vr[i];
}
printf("\n");

//Calcular a media dos valores fornecidos, dividindo a soma pelo total de elementos
media = media/ELEMENTOS;
//printf("Media = %f", media);
//printf("\n\n");

//1º) somatorio de (xi-media)^2
for(i=0;i<ELEMENTOS;i++){
    desvio= desvio + pow(vr[i]-media,2);
    //printf(" [ %f ] ", desvio);
}
printf("\n");

//2º) Raiz da soma dividida pela quantidade de elementos
desvio = sqrt(desvio/ELEMENTOS);
printf("     O desvio padrao da populacao informada e: %f", desvio);
printf("\n\n");
return 0;
}
