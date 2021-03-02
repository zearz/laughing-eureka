#define or ||
#include "TTT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** createTab()
{
    char **tab = NULL;
    tab = malloc(sizeof(char*)*3);
    for(int i =0;i<3;i++)
    {
        tab[i]= malloc(sizeof(char)*3);
    }
    for(int i = 0; i<3;i++)
        for(int j =0;j<3;j++)
        {
            strcpy(&tab[i][j],"."); 
            //unsigned char a = "s" strcpy(&a,":/\;") on accede &a pour le modifier
        }
        
    return tab;
}

void ShowTab(char **tab)
{
    for(int i = 0; i<3;i++)
    {
        printf("=======\n"); 
        for(int j =0;j<3;j++)
        {
            printf("|");
            printf("%c",tab[i][j]);
            
        }
        printf("|");
         
        printf("\n");  
    }
    printf("=======\n");
    return;
}

void PutCharacterInTab(char **tab, int x, int y ,char lettre)
{
/**
 * Place une lettre dans le tableau
 * 
 * @param tableau 2d ; int x ; int y ; char lettre
 * @return none
 */
    if (tab[x][y] == 'O'|| tab[x][y] == 'X')
    {
        return;
    }
    else
    {
        tab[x][y] = lettre;
    }
    return;
}

int CheckRows(char **tab)
{
    for(int i =0;i<3;i++)
    {
        if(tab[i][0] == 'X'&& tab[i][1] == 'X'&& tab[i][2] == 'X')
        {
            printf("Les X ont gagne\n");
            return 1;
        }
        else if(tab[i][0] == 'O' && tab[i][1] == 'O' && tab[i][2] == 'O')
        {
            printf("Les O ont gagne\n");
            return 1;
        }
    }
    return 0;
}

int CheckColumns(char **tab)
{
    for(int i =0;i<3;i++)
    {
        if(tab[0][i] == 'X'&& tab[1][i] == 'X'&& tab[2][i] == 'X')
        {
            printf("Les X ont gagne\n");
            return 1;
        }
        else if(tab[0][i] == 'O' && tab[1][i] == 'O' && tab[2][i] == 'O')
        {
            printf("Les O ont gagne\n");
            return 1;
        }
    }
    return 0;
}

int CheckDiagonal(char **tab)
{
    if(tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O')
    {
        printf("Les O ont gagne\n");
        return 1;
    }
    else if(tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X')
    {
        printf("Les X ont gagne\n");
        return 1;
    }
    if(tab[2][0] == 'O' && tab[1][1] == 'O' && tab[0][2] == 'O')
    {
        printf("Les O ont gagne\n");
        return 1;
    }
    else if(tab[2][0] == 'X' && tab[1][1] == 'X' && tab[0][2] == 'X')
    {
        printf("Les X ont gagne\n");
        return 1; 
    }
    return 0;
}

void EraseTab(char **tab)
{
    for(int i =0;i<3;i++)
    {
        free(tab[i]);
    }
    free(tab);
    return;
}

void MainMenu()
{
    short int launch = 1;
    while (launch == 1)
    {
    int Input= -1;
    printf("0. Menu \n");
    printf("1. Jouer\n");
    printf("2. Quitter\n");
    scanf("%i",&Input);
    switch (Input)
        {
        case 1:
            Play();
            break;
        case 2:
            launch = 0;
            break;
        default:
            printf("Mauvaise Input\n");
        }
    
    }
}

void Play()
{
    char **tab = createTab();
    char input = '0';
    int inputx = 0;
    int inputy = 0;
    while(collider(tab)!= 1)
    {
        printf("Input de type X ou O puis [x;y]\n");
        scanf("%c",&input);
        scanf("%d",&inputx);
        scanf("%d",&inputy);
        PutCharacterInTab(tab,inputx,inputy,input);
        ShowTab(tab);
    }
    EraseTab(tab);
    return;
}

int collider(char **tab)
{
    if(CheckColumns(tab) == 1 or CheckDiagonal(tab)==1 or CheckRows(tab) ==1)
    {
        return 1;
    }
}