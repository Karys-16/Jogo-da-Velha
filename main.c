/* Karys Barbosa - sept - 2022*/
#include <stdio.h>
#include <stdlib.h>


//Protótipos das funções verificadoras
int diag_ver(char player, int cur_position, int cur_positionY, char game[3][3]);
int col_ver(char player, int cur_position, int cur_positionY, char game[3][3]);
int row_ver(char player, int cur_position, int cur_positionY, char game[3][3]);

//Função principal
int main()
{
    //Variável de confirmação 
    int confirmacao;
    int retd, retc, retl;

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

            if(game[linha-1][coluna-1] == '-')
            { //Verifica se aquela posição ainda não foi mexida
                game[linha-1][coluna-1] = aux;
                retd = diag_ver(aux, linha-1, coluna-1, game);
                retc = col_ver(aux, linha-1, coluna-1, game);
                retl = row_ver(aux, linha-1, coluna-1, game);
                if(retd || retc || retl)
                {
                    printf("O jogador %c venceu!", aux);
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
//cur_position - última posição jogada
//game - matriz 3x3 do jogo


//Função para a verificação da diagonal
//Essa posição será chamada apenas quando o jogador não estiver nas posições [1][0] e [1][2] (não possuem diagonais)
int diag_ver(char player, int cur_positionX, int cur_positionY, char game[3][3])
{
    int contP = 0;
    int contS = 0;
    //Diagonal principal
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            //Achando a diagonal principal'
            if(j == i)
            {
                //Se o conteudo dessa diagonal for igual ao char do player o contador chega a 3
                if(game[i][j] == player)
                    contP++;
            }
        }
    }   

    //Diagonal secundária
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j+i<2)
            {
                if(game[i][j] == player)
                    contS++;
            }
        }
    }

    if(contP >= 3 || contS >= 3)
    {
        return 1;
    }
}

//verifica a coluna
int col_ver(char player, int cur_positionX, int cur_positionY, char game[3][3])
{

}

//verifica a linha
int row_ver(char player, int cur_positionX, int cur_positionY, char game[3][3])
{

}