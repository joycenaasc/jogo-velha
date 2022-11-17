#ifndef JOGO_DA_VELHA_HEADER_H_INCLUDED
#define JOGO_DA_VELHA_HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#define PLAYER 'X'
#define COMPUTER 'O'
void play();


// ENTRADA: formar a parte visual do jogo


char matriz[3][3];
int win = 0;

void resetMatriz()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = ' ';
        }
    }
};

void printMatriz()
{
    printf(" %c | %c | %c", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c", matriz[2][0], matriz[2][1], matriz[2][2]);
	printf("\n   |   |   \n");

    printf("\n");
};

int checkEspacoLivre()
{
    int espacoLivre = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] != ' ')
            {
                espacoLivre--;
            }
        }
    }
    return espacoLivre;
};


//PROCESSAMENTO: reproduzir o jogo, recebendo as informações sobre posição escolhida do jogador


void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Digite a linha desejada de 1 a 3:");
        scanf("%d", &x);
        x--;

        printf("Digite a coluna desejada de 1 a 3:");
        scanf("%d", &y);
        y--;

        if (matriz[x][y] != ' ')
        {
            printf("Movimento inválido!\n");
        }
        else
        {
            matriz[x][y] = PLAYER;
            break;
        }

    } while (matriz[x][y] != ' ');
};

char printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("Você ganhou!");
        win++;
    }
    else if (winner == COMPUTER)
    {
        printf("Você perdeu");
    }
    else
    {
        printf("É um empate.");
    }
};

void computerMove()
{

    srand(time(0));
    int x;
    int y;

    if (checkEspacoLivre() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (matriz[x][y] != ' ');

        matriz[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}


// SAÍDA: verificar quem ganhou e exibir o resultado do jogo, dando a opção de escolher as preferências do menu novamente.


void printMenu()
{
    printf("  JOGO DA VELHA  ");
    printf("\n");
    printf(" Jogar - Digite 1 ");
    printf("\n");
    printf(" Sair -  Digite 2 ");
    printf("\n");
    printf(" Rank -  Digite 3 ");
    printf("\n");
    return;
}

char checkWinner()
{
    // verifica as linhas
    for (int i = 0; i < 3; i++)
    {
        if (matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2])
        {
            return matriz[i][0];
        };
    }

    // verifica as colunas
    for (int i = 0; i < 3; i++)
    {
        if (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i])
        {
            return matriz[0][i];
        };
    }

    // verifica as diagonais
    if (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2])
    {
        return matriz[0][0];
    };
    if (matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])
    {
        return matriz[0][2];
    };

    return ' ';
};

void Game()
{
    char winner = ' ';
    resetMatriz();

    while (winner == ' ' && checkEspacoLivre() != 0)
    {
        printMatriz();
        playerMove();
        winner = checkWinner();

        if (winner != ' ' || checkEspacoLivre() == 0)
        {
            break;
        }

        computerMove();
        winner = checkWinner();

        if (winner != ' ' || checkEspacoLivre() == 0)
        {
            break;
        }
    }

    printMatriz();
    printWinner(winner);

    printf("\n");
    printf("\n");

    play();
    return;
}

void play()
{
    int OPTION;
    printMenu();
    scanf("%d", &OPTION);
    switch (OPTION)
    {
    case 1:
        Game();
        break;
    case 2:
        exit(0);
        break;
    case 3:
        printf("\n");
        printf("Vitórias: %d", win);
        printf("\n");
        printf("\n");
        play();
        break;
    default:
        printf("Opcão não reconhecida!");
        break;
    }
    return;
}

#endif // JOGO_DA_VELHA_HEADER_H_INCLUDED
