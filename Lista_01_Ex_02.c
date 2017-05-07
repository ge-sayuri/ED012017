#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A populacao tera 10 elementos
#define ELEMENTOS 10

float desviopadrao(float *p, int tamanho){

    float media=0, resultado=0;
    int j=0, var=0, x, y;

    //Calcular a media dos valores fornecidos, dividindo a soma pelo total de elementos
    var = sizeof(float);
    x=0; //Esta variavel vai nos auxiliar na movimenta��o pela memoria de float em float
    for (j=0;j<tamanho;j++){
            y = (int)*(p+x);
            media = media + (float)y;
            x = x + var;
    }
    printf("\n");
    media = media/tamanho;

    //Somatorio de (xi-media)^2
    x=0;
    for(j=0;j<tamanho;j++){
        y = (int)*(p+x);
        resultado = resultado + pow((((float)y)-media),2);
        x=x+var;
    }

    //Raiz da soma dividida pela quantidade de elementos
    resultado = sqrt(resultado/tamanho);
    return resultado;
}

int main (){

float vr[ELEMENTOS], desvio=0;
int i=0;

printf("\n");
printf("\n");
printf("Neste programa calcularemos o desvio padrao em uma populacao de %d elementos informados pelo usuario", ELEMENTOS);
printf("\n\n");

printf("Forneca os valores dos elementos:");
printf("\n\n");

//Armazenar os valores dos elementos
for(i=0;i<ELEMENTOS;i++){
    printf("  %d - ",i+1);
    scanf("%f", &vr[i]);
}
printf("\n");

//Obtem o ponteiro do 1� elemento do vetor
desvio = desviopadrao(&vr[0], ELEMENTOS);

printf("     O desvio padrao da populacao informada e: %f", desvio);
printf("\n\n");
return 0;
}
