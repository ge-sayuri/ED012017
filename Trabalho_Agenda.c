//Angela Sayuri Delci 16/0057370
//Trabalho 02 - Agenda eletronica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a estrutura dos elementos da lista
typedef struct contato{
    char nome[30], email[50], fone[20];
    struct contato* prox;
} Contato;

typedef struct lista{
    Contato* prim;
}Lista;

//Cria a lista
Lista* lst_cria (void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    return l;
};

void lst_insere(Lista* l){
    Contato* novo = (Contato*)malloc(sizeof(Contato));
    printf("\n\n1 - Inserir contato\n");
    printf("Nome: ");
    scanf("%s", &novo->nome);
    getchar();
    printf("E-mail: ");
    scanf("%s", &novo->email);
    getchar();
    printf("Telefone: ");
    scanf("%s", &novo->fone);
    getchar();
    printf("\n [ %s - %s - %s ]", novo->nome, novo->email, novo->fone);
}


int main (){

int op=0;

Lista* l = lst_cria();


while (op==0 || op>7){
    printf("\n\n\n  >> Agenda Eletronica <<\n\n");
    printf("  1 - Inserir contato\n");
    printf("  2 - Ordenar contatos\n");
    printf("  3 - Listar contatos\n");
    printf("  4 - Buscar/mostrar contato\n");
    printf("  5 - Editar contato\n");
    printf("  6 - Remover contato\n");
    printf("  7 - Sair\n\n");
    printf("Escolha a opcao desejada: ");
    scanf("%d", &op);

    switch(op){
     case 1:
        lst_insere(l);
        op=0;
        break;
     case 2:
        printf("\n\n %d \n", 2);
        op=0;
        break;
     case 3:
        printf("\n\n %d \n", 3);
        op=0;
        break;
     case 4:
        printf("\n\n %d \n", 4);
        op=0;
        break;
     case 5:
        printf("\n\n %d \n", 5);
        op=0;
        break;
     case 6:
        printf("\n\n %d \n", 6);
        op=0;
        break;
     case 7:
        break;
    }
}
return 0;
}
