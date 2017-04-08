/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 1/2017
Turma: B
Alunos(as): Gustavo Costa de Souza - Matricula: 150128576
            Angela Sayuri Delci - Matricula: 160057370
Descrição: jogo Batalha Naval */

#include <stdio.h> // entrada e saida de dados
#include <string.h> // manipulacao de strings
#include <stdlib.h> // conversao de strings para numeros
#include <time.h> // manipulacao de datas e horas

/* Funcao que gera o tabuleiro inicial sem jogadas*/

void Inicia_Tabuleiro(int Mapa1[8][10], int Mapa2[8][10]){
    int i, j;

    for(i=0; i<8; i++){
        for(j=0; j<10; j++){
            Mapa1[i][j]=0;
            Mapa2[i][j]=0;
        }
    }
}

/* Funcao que gera e posiciona as embarcacoes(couracada e submarino) */
void Gerar_Embarcacoes(int matriz[8][10]){
    int encouracado=1, submarino=3;
    int i, j;

    srand(time(NULL)); /* semente que alimenta a funcao rand(),
        pega um numero de tempo diferente e gera uma sequencia diferente*/

    while((encouracado!=0) || (submarino!=0)){

        i=rand()%8; //gera numeros aleatorios
        j=rand()%10; // gera numeors aleatorios

        //gerar o encouracado
        if(encouracado>0){
            encouracado=encouracado-1;
            matriz[i][j]=5;
            matriz[i][j+1]=5;
            matriz[i][j+2]=5;
            matriz[i][j+3]=5;
        }

        i=rand()%8;
        j=rand()%10;

        //verifica se a posicao esta livre e a proxima e gera o submarino
        if((submarino>0) && ((matriz[i][j]<=0) &&(matriz[i][j+1]<=0))){
            submarino=submarino-1;
            matriz[i][j]=2;
            matriz[i][j+1]=2;
        }
    }
}

/* Funcao que armazena a jogada e indica o que acertou */
int Jogada(int matriz[8][10], int Tela[8][10], int *ponto){
    int linha, coluna;

    printf("\nIndique o numero da linha: ");
    scanf("%d", &linha);
    linha=linha-1;
    getchar();

    printf("\nIndique o numero da coluna: ");
    scanf("%d", &coluna);
    coluna=coluna-1;
    getchar();

    if(matriz[linha][coluna]!=0){
        if(matriz[linha][coluna]==5){
            printf("\nAcertou parte de ENCOURACADO!\n");
            printf("\nAperte 'ENTER' para continuar\n");
            getchar();
            *ponto=*ponto+1;
            Tela[linha][coluna]=5;
            return 5;
        }
        else{
            printf("\nAcertou parte de SUBMARINO!\n");
            printf("\nAperte 'ENTER' para continuar\n");
            getchar();
            *ponto=*ponto+1;
            Tela[linha][coluna]=2;
            return 2;
        }
    }
    else{
        printf("\nAcertou 'AGUA'\n");
        printf("\nAperte 'ENTER' para continuar\n");
        getchar();
        Tela[linha][coluna]=3;
        return 0;
    }
}

/* Funcao que vai exibir o conteudo do jogo na tela(parte grafica) */

void Tela(int Mapa1_Tela[8][10], int Mapa2_Tela[8][10], int J1_pontos, int J2_pontos){
    int i, j;

    printf("      JOGADOR 1                       JOGADOR 2\n    ");
    printf("  PONTO(S): %d                     PONTO(S): %d\n        ", J1_pontos, J2_pontos);
    printf("\n");

    for(j=0;j<11; j++){
        printf("%d ", j);
    }

    printf("            ");

    for(j=0; j<11; j++){
        printf("%d ", j);
    }

    printf("\n");


    for(i=0; i<8; i++){
        printf("%d-", i+1);
        for(j=0; j<10; j++){
            if(Mapa1_Tela[i][j]==3){
                printf("X ");
            }
            else{
                printf("%d ", Mapa1_Tela[i][j]);
            }
        }

        printf("             %d-", i+1);

        for(j=0; j<10; j++){
            if(Mapa2_Tela[i][j]==3){
                printf("X ");
            }
            else{
                printf("%d ", Mapa2_Tela[i][j]);
            }
        }

        printf("\n");
    }

    printf("\n");
}

int main(){
    int Mapa1[8][10], Mapa2[8][10], Mapa1_Tela[8][10], Mapa2_Tela[8][10];
    int J1_pontos, J2_pontos;
    int i, j;
    char Jogar = 's';

    printf("=================================\n");
    printf("==========BATALHA_NAVAL==========\n");
    printf("=================================\n");
    printf("\nAperte 'ENTER' para jogar...");
    getchar();
    system("clear || cls");

    while((Jogar=='s') || (Jogar=='S')){
        J1_pontos=0;
        J2_pontos=0;

        Inicia_Tabuleiro(Mapa1, Mapa2);
        Inicia_Tabuleiro(Mapa1_Tela, Mapa2_Tela);
        Gerar_Embarcacoes(Mapa1);
        Gerar_Embarcacoes(Mapa2);

        while((J1_pontos!=10) && (J2_pontos!=10)){
            system("clear || cls");
            for(i=0; i<8; i++){
                for(j=0; j<10; j++){
                    printf("%d", Mapa1[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            for(i=0; i<8; i++){
                for(j+0; j<10; j++){
                    printf("%d", Mapa2[i][j]);
                }
                printf("\n");
            }
            Tela(Mapa1_Tela, Mapa2_Tela, J1_pontos, J2_pontos);
            printf("\nJogador 1");
            Jogada(Mapa2, Mapa2_Tela, &J1_pontos);

            system("clear || cls");

            if(J1_pontos!=10){
                for(i=0; i<8; i++){
                    for(j=0; j<10; j++){
                        printf("%d", Mapa1[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");

                for(i=0; i<8; i++){
                    for(j=0; j<10; j++){
                        printf("%d", Mapa2[i][j]);
                    }
                    printf("\n");
                }

                Tela(Mapa1_Tela, Mapa2_Tela, J1_pontos, J2_pontos);
                printf("\nJogador 2");
                Jogada(Mapa1, Mapa1_Tela, &J2_pontos);
            }
        }

        system("clear || cls");

        if(J1_pontos==10){
            printf("\nPARABENS!!! JOGADOR 1 VENCEU\n");
        }
        else{
            printf("\nPARABENS!!! JOGADOR 2 VENCEU\n");
        }
        getchar();
        system("clear || cls");
        printf("\nDeseja jogar novamente? (S/N)\n");
        scanf("%c", &Jogar);
        getchar();
    }

    printf("\nObrigado por jogar!\n");
    getchar();
    return 0;
}
