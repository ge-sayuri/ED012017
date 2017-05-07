#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A populacao tera 10 elementos

float desviopadrao(float *p, int tamanho){
    float media=0, resultado=0;
    int j=0, x;

    //Calcular a media dos valores fornecidos, dividindo a soma pelo total de elementos
    for (j=0;j<tamanho;j++){
            x = (int)*(p+j);
            media = media + (float)x;
    }
    printf("\n");
    media = media/tamanho;

    //Somatorio de (xi-media)^2

    for(j=0;j<tamanho;j++){
        x = (int)*(p+j);
        resultado = resultado + pow((((float)x)-media),2);
    }

    //Raiz da soma dividida pela quantidade de elementos
    resultado = sqrt(resultado/tamanho);
    return resultado;
}

int main (){

int qtd;
printf("\n");
printf("\n");
printf("Neste programa calcularemos o desvio padrao em uma populacao com a quantidade de elementos desejada pelo usuario");
printf("\n\n");

printf("Informe a quantidade de elementos: ");
scanf("%d", &qtd);
printf("\n\n");

float vr[qtd], desvio=0;
int i=0;

printf("Forneca os valores dos elementos:");
printf("\n\n");

//Armazenar os valores dos elementos
for(i=0;i<qtd;i++){
    printf("  %d - ",i+1);
    scanf("%f", &vr[i]);
}
printf("\n");

//Obtem o ponteiro do 1º elemento do vetor
desvio = desviopadrao(&vr[0], qtd);

printf("     O desvio padrao da populacao informada e: %f", desvio);
printf("\n\n");
return 0;
}
