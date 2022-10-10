/* Karys Barbosa 2022*/
#include <stdio.h>
#include <stdlib.h>


//Protótipos das funções verificadoras
int diagp_ver(char player, char game[3][3]);
int diags_ver(char player, char game[3][3]);
int col_ver(char player, int cur_positionX, int cur_positionY, char game[3][3]);
int row_ver(char player, int cur_positionX, int cur_positionY, char game[3][3]);

//Função principal
int main()
{
    //Variável de confirmação 
    int confirmacao;
    int retd, retc, retl, retds;
    retd = 0;
    retds = 0;
    retl = 0;
    retc = 0;

    //Variáveis para armazenar a linha e coluna escolhidas pelo usuário
    int linha, coluna;

    //Matriz do jogo
    char game[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

    //Auxiliar para jogador
    char aux;
    printf("Iniciar jogo?\n 1-SIM\n 2-NÃO\n");
    while(scanf("%d", &confirmacao)!=2)
    {
        printf("INSTRUÇÃO:\n O primeiro jogador será considerado o jogador par e será X;\n O segundo a jogar será considerado o jogador Ímpar e jogará com O\n");
        printf("Digite a linha e Coluna como o exemplo: 3 2 (Terceira linha, Segunda coluna)\n");
        for(int k = 0; k < 9; k++)
        {  

            //Printa o estado atual da matriz
            printf("Estado atual:\n");
            for(int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%c", game[i][j]);
                }
                printf("\n");
            }
            printf("\n");


            //Verifica qual a vez de cada jogador
            if(k%2==0)
            {
                aux = 'X'; //Jogador 1
                printf("Vez do jogador 1:\n");
                scanf("%d %d", &linha, &coluna);
            }
            else 
            {
                aux = 'O'; //Jogador 2
                printf("Vez do jogador 2:\n");
                scanf("%d %d", &linha, &coluna);   
            }

            //Verifica se aquela posição ainda não foi mexida
            if(game[linha-1][coluna-1] == '-')
            {
                game[linha-1][coluna-1] = aux;
                retd = diagp_ver(aux, game);
                retds = diags_ver(aux, game);
                retc = col_ver(aux, (coluna-1), (linha-1), game);
                retl = row_ver(aux, (coluna-1), (linha-1), game);
                if(retc == 3 || retl == 3 || retd == 3 || retds == 3)
                {
                    printf("Jogador %c venceu!", aux);
                    //Encerra o programa quando alguém vence
                    return 0;
                    // printf("Linha: %d Coluna: %d diagonal: %d", retl, retc, retd);
                }
            }

            else 
            {
                k--; // decrementa pra aumentar o número de jogadas e volta para o jogador que estava antes
                printf("Essa casa já está selecionada;"); //Aviso
            }
        }
        
    }
    
}

//Parâmetros:
//Player - char que contem qual jogador jogou agora (X ou O)
//cur_position - posição atual
//game - matriz 3x3 do jogo


// Verificação da coluna
int col_ver(char player, int cur_positionX, int cur_positionY, char game[3][3])
{
    // printf("Posição Y: %d e Posição X: %d\n\n", cur_positionY, cur_positionX);
    char p = game[cur_positionY][cur_positionX];
    // printf("JOGADOR: %c\n", p);

    int contcol = 0;
    for(int i = 0; i < 3; i++)
    {
        if(p == game[i][cur_positionX])
        {
            contcol++;
            // printf("Contador de coluna: %d\n", contcol);
        }
    }

    if(contcol == 3)
        return contcol;
    else 
        return 0;
}


//verificando a linha
int row_ver(char player, int cur_positionX, int cur_positionY, char game[3][3])
{
    char p = game[cur_positionY][cur_positionX];
    // printf("JOGADOR: %c\n", p);

    int contlin = 0;
    for(int i = 0; i < 3; i++)
    {
        if(p == game[cur_positionY][i])
        {
            contlin++;
            // printf("Contador de linha: %d\n", contlin);
        }
    }

    if(contlin == 3)
        return contlin;
    else 
        return 0;
}

//verificando a diagonal principal
int diagp_ver(char player, char game[3][3])
{
    // printf("JOGADOR: %c\n", player);

    int contd = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j==i && game[i][j] == player && player!= '-')
            {
                contd++;
                // printf("Contador da  diagonal: %d\n", contd);
            }
        }
    }

    if(contd == 3)
        return contd;
    else 
        return 0;
}

//verificando a diagonal principal
int diags_ver(char player, char game[3][3])
{
    // printf("JOGADOR: %c\n", player);
    int contd = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if((j+i) < 3 && game[i][j] == player && player!= '-')
            {
                contd++;
                // printf("Contador da  diagonal secundária: %d\n", contd);
            }
        }
    }

    if(contd == 3)
        return contd;
    else 
        return 0;
}

/*
    Algoritmo desenvolvido com propósito de fixação  dos conteúdos apresentados na matéria de Construção de Algoritmos e Programação
    modularização
    matrizes
    lógica

    2022/1
*/