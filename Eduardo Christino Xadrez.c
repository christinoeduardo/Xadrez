#include<stdio.h>
#include<stdlib.h>

int coordenadas(char c)
{
    int j;
    j = c;
    if (j > 90)
        j -= 96;
    else
        j -= 64;
    return j;
}

int confirmando(int i, char c)
{
    if (i == 0 && c == '0')
        return 0;
    else
        return 1;
}

int main()
{
    char c;
    int i, j, k, l, confirmacao, confirmacao1, confirmacao2, auxi, auxj, confirmacao_jogada;
    int jogador = 0, jogada = 0;
    int f[9] [9];
    char g[8] = {"ABCDEFGH"};
    printf ("Bem Vindo!! \ninstrucoes: \na peca tem dois numeros\no primeiro eh o numero do jogador (1 ou 2) e o segundo eh a peca: \n1 - peao\n2 - torre\n");
    printf ("3 - cavalo\n4 - bispo\n5 - rainha\n6 - rei\npara desistir basta digitar 0 na linha e 0 na coluna\naperte enter para comecar");
    scanf ("%c", &c);
    system("cls");
    j = 0;
    auxi = 0;
    for (i = 0; i <= 8; i++) //tabuleiro
    {
        f[i][j] = auxi;
        auxi++;
    }
    i = 0;
    printf ("%d    ", f[i][0]); //tabuleiro
    for (j = 0; j <= 8; j++)
    {
        printf ("%c  ", g[j]);
    }
    printf ("\n \n");
    i = 1;
    printf ("%d   ", f[i][0]);
    for (j = 1; j <= 8; j++) // tabuleiro
    {
        if (j == 1 || j == 8)
            f[i][j] = 12;
        if (j == 2 || j == 7)
            f[i][j] = 13;
        if (j == 3 || j == 6)
            f[i][j] = 14;
        if (j == 4)
            f[i][j] = 15;
        if (j == 5)
            f[i][j] = 16;
        printf ("|%d", f[i][j]);
    }
    printf ("|");
    printf ("\n    ------------------------\n");
    i = 2;
    printf ("%d   ", f[i][0]);
    for (j = 1; j <= 8; j++) // tabuleiro
    {
        f[i][j] = 11;
        printf ("|%d", f[i][j]);
    }
    printf ("|");
    printf ("\n    ------------------------\n");
    for (i = 3; i <= 6; i++) // tabuleiro
    {
        printf ("%d   ", f[i][0]);
        for (j = 1; j <= 8; j++)
        {
            f[i][j] = 88;
            printf ("|  ");
        }
        printf ("|");
        printf ("\n    ------------------------\n");
    }
    i = 7;
    printf ("%d   ", f[i][0]);
    for (j = 1; j <= 8; j++) // tabuleiro
    {
        f[i][j] = 21;
        printf ("|%d", f[i][j]);
    }
    printf ("|");
    printf ("\n    ------------------------\n");
    i = 8;
    printf ("%d   ", f[i][0]);
    for (j = 1; j <= 8; j++) // tabuleiro
    {
        if (j == 1 || j == 8)
            f[i][j] = 22;
        if (j == 2 || j == 7)
            f[i][j] = 23;
        if (j == 3 || j == 6)
            f[i][j] = 24;
        if (j == 4)
            f[i][j] = 26;
        if (j == 5)
            f[i][j] = 25;
        printf ("|%d", f[i][j]);
    }
    printf ("|");
    printf ("\n");
    confirmacao = 1;
    confirmacao_jogada = 1;
    while (confirmacao == 1) // comecando o jogo
    {
        printf ("Jogador %d \n", (jogador%2)+1);
        confirmacao = 1;
        printf ("escolha uma peca \n");
        printf ("linha: ");
        scanf ("%d", &i);
        printf ("coluna: ");
        fflush(stdin);
        scanf ("%c", &c);
        fflush(stdin);
        j = coordenadas(c);
        confirmacao = confirmando(i, c); // vendo se o jogador desistiu
        while (f[i][j] == 88) // confirmacao se as coordenadas dao no nada
        {
            printf ("digite um lugar valido: \n");
            scanf ("%d", &i);
            fflush(stdin);
            scanf ("%c", &c);
            fflush(stdin);
            j = coordenadas(c);
            confirmacao = confirmando(i, c);
        }

        if (f[i][j]/10 == (jogador%2)+1)
        {
            confirmacao_jogada = 1;
            if (f[i][j] == 11) // jogada do peao do jogador 1
            {
                printf ("digite as coordenadas do peao: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (i == auxi + 1 && j == auxj)
                {
                    if (f[i][j] == 88)
                    {
                        f[i][j] = 11;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (i == auxi + 1 && j == auxj + 1)
                    {
                        if (f[i][j] != 88 && f[i][j]/10 != 1)
                        {
                            f[i][j] = 11;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                    {
                        if (i == auxi + 1 && j == auxj - 1)
                        {
                            if (f[i][j] != 88 && f[i][j]/10 != 1)
                            {
                                f[i][j] = 11;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador --;
                        }
                        else
                            if (auxi == 2 && i == auxi + 2 && j == auxj)
                            {
                                if (f[i][j] == 88)
                                {
                                    f[i][j] = 11;
                                    f[auxi][auxj] = 88;
                                }
                                else
                                    jogador --;
                            }
                            else
                                jogador --;
                    }
                }
            }
            if (f[i][j] == 21) // jogada do peao do jogador 2
            {
                printf ("digite as coordenadas do peao: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (i == auxi - 1 && j == auxj)
                {
                    if (f[i][j] == 88)
                    {
                        f[i][j] = 21;
                        f[auxi][auxj] = 88;
                        confirmacao_jogada = 1;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (i == auxi - 1 && j == auxj + 1)
                    {
                        if (f[i][j] != 88 && f[i][j] != 2)
                        {
                            f[i][j] = 21;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                    {
                        if (i == auxi - 1 && j == auxj - 1)
                        {
                            if (f[i][j] != 88 && f[i][j]/10 != 2)
                            {
                                f[i][j] = 21;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador--;
                        }
                        else
                            if (auxi == 7 && i == auxi - 2 && j == auxj)
                            {
                                if (f[i][j] == 88)
                                {
                                    f[i][j] = 21;
                                    f[auxi][auxj] = 88;
                                }
                                else
                                    jogador --;
                            }
                            else
                                jogador --;
                    }
                }
            }
            if (f[i][j] == 12) // jogada da torre do jogador 1
            {
                printf ("digite as coordenadas da torre: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (j == auxj && i > auxi)
                {
                    for (k = auxi + 1; k < i; k++)
                    {
                        if (auxi + 1 != i)
                        {
                            if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                        }
                    }
                    if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                    {
                        f[i][j] = 12;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (j == auxj && i < auxi)
                    {
                        for (k = i + 1 ; k < auxi; k++)
                        {
                            if (auxi - 1 != i)
                            {
                                if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                            }
                        }
                        if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                        {
                            f[i][j] = 12;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                    {
                        if (i == auxi && j > auxj)
                        {
                            for (k = auxj + 1; k < j; k++)
                            {
                                if (auxj + 1 != j)
                                {
                                    if (f[i][k] != 88)
                                        confirmacao_jogada = 0;
                                }
                            }
                            if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                            {
                                f[i][j] = 12;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador --;
                        }
                        else
                        {
                            if (i == auxi && j < auxj)
                            {
                                for (k = j + 1; k < auxj; k++)
                                {
                                    if (auxj - 1 != j)
                                    {
                                        if (f[i][k] != 88)
                                        confirmacao_jogada = 0;
                                    }
                                }
                                if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                                {
                                    f[i][j] = 12;
                                    f[auxi][auxj] = 88;
                                }
                                else
                                    jogador --;
                            }
                            else
                                jogador --;
                        }
                    }
                }
            }
            if (f[i][j] == 22) // jogada da torre do jogador 2
            {
                printf ("digite as coordenadas da torre: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (j == auxj && i > auxi)
                {
                    for (k = auxi + 1; k < i; k++)
                    {
                        if (auxi + 1 != i)
                        {
                            if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                        }
                    }
                    if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                    {
                        f[i][j] = 22;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (j == auxj && i < auxi)
                    {
                        for (k = i + 1 ; k < auxi; k++)
                        {
                            if (auxi - 1 != i)
                            {
                                if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                            }
                        }
                        if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                        {
                            f[i][j] = 22;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                    {
                        if (i == auxi && j > auxj)
                        {
                            for (k = auxj + 1; k < j; k++)
                            {
                                if (auxj + 1 != j)
                                {
                                    if (f[i][k] != 88)
                                    confirmacao_jogada = 0;
                                }
                            }
                            if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                            {
                                f[i][j] = 22;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador --;
                        }
                        else
                        {
                            if (i == auxi && j < auxj)
                            {
                                for (k = j + 1; k < auxj; k++)
                                {
                                    if (auxj - 1 != j)
                                    {
                                        if (f[i][k] != 88)
                                        confirmacao_jogada = 0;
                                    }
                                }
                                if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                                {
                                    f[i][j] = 22;
                                    f[auxi][auxj] = 88;
                                }
                                else jogador --;
                            }
                            else
                                jogador --;
                        }
                    }
                }
            }
            if (f[i][j] == 14) // jogada do bispo do jogador 1
            {
                printf ("digite as coordenadas do bispo: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (j > auxj && i > auxi)
                {
                    l = auxj + 1;
                    for (k = auxi + 1; k < i; k++)
                    {
                        if (auxi + 1 != i )
                        {
                            if (f[k][l] != 88)
                                confirmacao_jogada = 0;
                        }
                    l++;
                    }
                    if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                    {
                        f[i][j] = 14;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (i > auxi && j < auxj)
                    {
                        l = auxj - 1;
                        for (k = auxi + 1; k < i; k++)
                        {
                            if (auxi + 1 != i)
                            {
                                if (f[k][l] != 88)
                                    confirmacao_jogada = 0;
                            }
                        l--;
                        }
                        if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                        {
                            f[i][j] = 14;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                    {
                        if (i < auxi && j > auxj)
                        {
                            for (k = auxj + 1; k < j; k++)
                            {
                                l = auxi - 1;
                                if (auxj + 1 != j)
                                {
                                    if (f[k][l] != 88)
                                        confirmacao_jogada = 0;
                                }
                                l--;
                            }
                            if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                            {
                                f[i][j] = 14;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador --;
                        }
                        else
                        {
                            if (i < auxi && j < auxj)
                            {
                                l = auxi - 1;
                                for (k = j + 1; k < auxj; k++)
                                {
                                    if (auxj - 1 != j)
                                    {
                                        if (f[k][l] != 88)
                                            confirmacao_jogada = 0;
                                    }
                                l--;
                                }

                                if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                                {
                                    f[i][j] = 14;
                                    f[auxi][auxj] = 88;
                                }
                                else
                                    jogador --;
                            }
                            else
                                jogador --;
                        }
                    }
                }
            }
            if (f[i][j] == 24) // jogada do bispo do jogador 2
            {
                printf ("digite as coordenadas do bispo: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (j > auxj && i > auxi)
                {
                    l = auxj + 1;
                    for (k = auxi + 1; k < i; k++)
                    {
                        if (auxi + 1 != i )
                        {
                            if (f[k][l] != 88)
                                confirmacao_jogada = 0;
                        }
                    l++;
                    }
                    if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                    {
                        f[i][j] = 24;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (i > auxi && j < auxj)
                    {
                        l = auxj - 1;
                        for (k = auxi + 1; k < i; k++)
                        {
                            if (auxi + 1 != i)
                            {
                                if (f[k][l] != 88)
                                    confirmacao_jogada = 0;
                            }
                        l--;
                        }
                        if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                        {
                            f[i][j] = 24;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                    {
                        if (i < auxi && j > auxj)
                        {
                            for (k = auxj + 1; k < j; k++)
                            {
                                l = auxi - 1;
                                if (auxj + 1 != j)
                                {
                                    if (f[k][l] != 88)
                                        confirmacao_jogada = 0;
                                }
                                l--;
                            }
                            if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                            {
                                f[i][j] = 24;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador --;
                        }
                        else
                        {
                            if (i < auxi && j < auxj)
                            {
                                l = auxi - 1;
                                for (k = j + 1; k < auxj; k++)
                                {
                                    if (auxj - 1 != j)
                                    {
                                        if (f[k][l] != 88)
                                            confirmacao_jogada = 0;
                                    }
                                l--;
                                }

                                if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                                {
                                    f[i][j] = 24;
                                    f[auxi][auxj] = 88;
                                }
                                else
                                    jogador --;
                            }
                            else
                                jogador --;
                        }
                    }
                }
            }
            if (f[i][j] == 13) // jogada do cavalo do jogador 1
            {
                printf ("digite as coordenadas do cavalo: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (f[i][j]/10 != 1)
                {
                if (i == auxi + 2 || i == auxi - 2)
                {
                    if (j == auxj + 1 || j == auxj - 1)
                    {
                        f[i][j] = 13;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (i == auxi + 1 || i == auxi - 1)
                    {
                        if (j == auxj + 2 || j == auxj - 2)
                        {
                            f[i][j] = 13;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                        jogador --;
                }
                }
                else
                    jogador --;
            }
            if (f[i][j] == 23) // jogada do cavalo do jogador 2
            {
                printf ("digite as coordenadas do cavalo: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (f[i][j]/10 != 2)
                {
                if (i == auxi + 2 || i == auxi - 2)
                {
                    if (j == auxj + 1 || j == auxj - 1)
                    {
                        f[i][j] = 23;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                {
                    if (i == auxi + 1 || i == auxi - 1)
                    {
                        if (j == auxj + 2 || j == auxj - 2)
                        {
                            f[i][j] = 23;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                        jogador --;
                }
                }
                else
                    jogador --;
            }
            if (f[i][j] == 15) // jogada da dama do jogador 1
            {
                printf ("digite as coordenadas da dama: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (j == auxj && i > auxi)
                {
                    for (k = auxi + 1; k < i; k++)
                    {
                        if (auxi + 1 != i)
                        {
                            if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                        }
                    }
                    if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                    {
                        f[i][j] = 15;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                    if (j == auxj && i < auxi)
                    {
                        for (k = i + 1 ; k < auxi; k++)
                        {
                            if (auxi - 1 != i)
                            {
                                if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                            }
                        }
                        if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                        {
                            f[i][j] = 15;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                        if (i == auxi && j > auxj)
                        {
                            for (k = auxj + 1; k < j; k++)
                            {
                                if (auxj + 1 != j)
                                {
                                    if (f[i][k] != 88)
                                    confirmacao_jogada = 0;
                                }
                            }
                            if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                            {
                                f[i][j] = 15;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador --;
                        }
                        else
                            if (i == auxi && j < auxj)
                            {
                                for (k = j + 1; k < auxj; k++)
                                {
                                    if (auxj - 1 != j)
                                    {
                                        if (f[i][k] != 88)
                                        confirmacao_jogada = 0;
                                    }
                                }
                                if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                                {
                                    f[i][j] = 15;
                                    f[auxi][auxj] = 88;
                                }
                                else
                                    jogador --;
                            }
                            else
                                if (j > auxj && i > auxi)
                                {
                                    l = auxj + 1;
                                    for (k = auxi + 1; k < i; k++)
                                    {
                                        if (auxi + 1 != i )
                                        {
                                            if (f[k][l] != 88)
                                                confirmacao_jogada = 0;
                                        }
                                    l++;
                                    }
                                    if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                                    {
                                        f[i][j] = 15;
                                        f[auxi][auxj] = 88;
                                    }
                                    else
                                        jogador --;
                                }
                                else
                                    if (i > auxi && j < auxj)
                                    {
                                        l = auxj - 1;
                                        for (k = auxi + 1; k < i; k++)
                                        {
                                            if (auxi + 1 != i)
                                            {
                                                if (f[k][l] != 88)
                                                    confirmacao_jogada = 0;
                                            }
                                        l--;
                                        }
                                        if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                                        {
                                            f[i][j] = 15;
                                            f[auxi][auxj] = 88;
                                        }
                                        else
                                            jogador --;
                                    }
                                    else
                                        if (i < auxi && j > auxj)
                                        {
                                            for (k = auxj + 1; k < j; k++)
                                            {
                                                l = auxi - 1;
                                                if (auxj + 1 != j)
                                                {
                                                    if (f[k][l] != 88)
                                                        confirmacao_jogada = 0;
                                                }
                                                l--;
                                            }
                                            if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                                            {
                                                f[i][j] = 15;
                                                f[auxi][auxj] = 88;
                                            }
                                            else
                                                jogador --;
                                        }
                                        else
                                            if (i < auxi && j < auxj)
                                            {
                                                l = auxi - 1;
                                                for (k = j + 1; k < auxj; k++)
                                                {
                                                    if (auxj - 1 != j)
                                                    {
                                                        if (f[k][l] != 88)
                                                            confirmacao_jogada = 0;
                                                    }
                                                l--;
                                                }
                                                if (confirmacao_jogada == 1 && f[i][j]/10 != 1)
                                                {
                                                    f[i][j] = 15;
                                                    f[auxi][auxj] = 88;
                                                }
                                                else
                                                    jogador --;
                                            }
                                            else
                                                jogador --;
            }
            if (f[i][j] == 25) // jogada da dama do jogador 2
            {
                printf ("digite as coordenadas da dama: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if (j == auxj && i > auxi)
                {
                    for (k = auxi + 1; k < i; k++)
                    {
                        if (auxi + 1 != i)
                        {
                            if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                        }
                    }
                    if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                    {
                        f[i][j] = 25;
                        f[auxi][auxj] = 88;
                    }
                    else
                        jogador --;
                }
                else
                    if (j == auxj && i < auxi)
                    {
                        for (k = i + 1 ; k < auxi; k++)
                        {
                            if (auxi - 1 != i)
                            {
                                if (f[k][j] != 88)
                                confirmacao_jogada = 0;
                            }
                        }
                        if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                        {
                            f[i][j] = 25;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                    }
                    else
                        if (i == auxi && j > auxj)
                        {
                            for (k = auxj + 1; k < j; k++)
                            {
                                if (auxj + 1 != j)
                                {
                                    if (f[i][k] != 88)
                                    confirmacao_jogada = 0;
                                }
                            }
                            if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                            {
                                f[i][j] = 25;
                                f[auxi][auxj] = 88;
                            }
                            else
                                jogador --;
                        }
                        else
                            if (i == auxi && j < auxj)
                            {
                                for (k = j + 1; k < auxj; k++)
                                {
                                    if (auxj - 1 != j)
                                    {
                                        if (f[i][k] != 88)
                                        confirmacao_jogada = 0;
                                    }
                                }
                                if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                                {
                                    f[i][j] = 25;
                                    f[auxi][auxj] = 88;
                                }
                                else
                                    jogador --;
                            }
                            else
                                if (j > auxj && i > auxi)
                                {
                                    l = auxj + 1;
                                    for (k = auxi + 1; k < i; k++)
                                    {
                                        if (auxi + 1 != i )
                                        {
                                            if (f[k][l] != 88)
                                                confirmacao_jogada = 0;
                                        }
                                    l++;
                                    }
                                    if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                                    {
                                        f[i][j] = 25;
                                        f[auxi][auxj] = 88;
                                    }
                                    else
                                        jogador --;
                                }
                                else
                                    if (i > auxi && j < auxj)
                                    {
                                        l = auxj - 1;
                                        for (k = auxi + 1; k < i; k++)
                                        {
                                            if (auxi + 1 != i)
                                            {
                                                if (f[k][l] != 88)
                                                    confirmacao_jogada = 0;
                                            }
                                        l--;
                                        }
                                        if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                                        {
                                            f[i][j] = 25;
                                            f[auxi][auxj] = 88;
                                        }
                                        else
                                            jogador --;
                                    }
                                    else
                                        if (i < auxi && j > auxj)
                                        {
                                            for (k = auxj + 1; k < j; k++)
                                            {
                                                l = auxi - 1;
                                                if (auxj + 1 != j)
                                                {
                                                    if (f[k][l] != 88)
                                                        confirmacao_jogada = 0;
                                                }
                                                l--;
                                            }
                                            if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                                            {
                                                f[i][j] = 25;
                                                f[auxi][auxj] = 88;
                                            }
                                            else
                                                jogador --;
                                        }
                                        else
                                            if (i < auxi && j < auxj)
                                            {
                                                l = auxi - 1;
                                                for (k = j + 1; k < auxj; k++)
                                                {
                                                    if (auxj - 1 != j)
                                                    {
                                                        if (f[k][l] != 88)
                                                            confirmacao_jogada = 0;
                                                    }
                                                l--;
                                                }
                                                if (confirmacao_jogada == 1 && f[i][j]/10 != 2)
                                                {
                                                    f[i][j] = 25;
                                                    f[auxi][auxj] = 88;
                                                }
                                                else
                                                    jogador --;
                                            }
                                            else
                                                jogador --;
            }
            if (f[i][j] == 16) // jogada do rei do jogador 1
            {
                printf ("digite as coordenadas do rei: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if ((i == auxi || i == auxi+1 || i == auxi-1) && (j == auxj || j == auxj+1 || j == auxj-1))
                {
                    if (i == auxi && j == auxj)
                        jogador --;
                    else
                        if (f[i][j]/10 != 1 )
                        {
                            f[i][j] = 16;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                }
                else
                    jogador --;
            }
            if (f[i][j] == 26) // jogada do rei do jogador 2
            {
                printf ("digite as coordenadas do rei: \n");
                auxi = i;
                auxj = j;
                printf ("linha: ");
                scanf ("%d", &i);
                printf ("coluna: ");
                fflush(stdin);
                scanf ("%c", &c);
                fflush(stdin);
                j = coordenadas(c);
                if ((i == auxi || i == auxi+1 || i == auxi-1) && (j == auxj || j == auxj+1 || j == auxj-1))
                {
                    if (i == auxi && j == auxj)
                        jogador --;
                    else
                        if (f[i][j]/10 != 2 )
                        {
                            f[i][j] = 26;
                            f[auxi][auxj] = 88;
                        }
                        else
                            jogador --;
                }
                else
                    jogador --;
            }
        }
        else
            jogador --;
        system("cls"); // apaga tudo oq tem antes
        printf ("%d    ", f[0][0]); // montando o tabuleiro de novo
        for (j = 0; j <= 7; j++)
            printf ("%c  ", g[j]);
        printf ("\n \n");
        for (i = 1; i <= 8; i++)
        {
            printf ("%d   ", f[i][0]);
            for (j = 1; j <= 8; j++)
            {
                if (f[i][j] == 88)
                    printf ("|  ");
                else
                    printf ("|%d", f[i][j]);
            }
            printf ("| \n    ------------------------- \n");
        }
        for (i = 1; i <= 8; i++) // confirmando se o jogo acabou
        {
            for (j = 1; j <= 8; j++)
            {
                if (f[i][j] == 16)
                    confirmacao1 = 1;
                if (f[i][j] == 26)
                    confirmacao2 = 1;
            }
        }
        if (confirmacao1 == 0 || confirmacao2 == 0)
            confirmacao = 0;
        confirmacao1 = 0;
        confirmacao2 = 0;
        jogador ++;
    }
    printf ("GAME OVER");
    return 0;
}

