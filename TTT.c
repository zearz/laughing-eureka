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

void CheckRows(char **tab)
{
    for(int i =0;i<3;i++)
    {
        if(tab[i][0] == 'X'&& tab[i][1] == 'X'&& tab[i][2] == 'X')
        {
            printf("Les X ont gagne\n");
            return;
        }
        else if(tab[i][0] == 'O' && tab[i][1] == 'O' && tab[i][2] == 'O')
        {
            printf("Les O ont gagne\n");
            return;
        }
    }
    return;
}

void CheckColumns(char **tab)
{
    for(int i =0;i<3;i++)
    {
        if(tab[0][i] == 'X'&& tab[1][i] == 'X'&& tab[2][i] == 'X')
        {
            printf("Les X ont gagne\n");
            return;
        }
        else if(tab[0][i] == 'O' && tab[1][i] == 'O' && tab[2][i] == 'O')
        {
            printf("Les O ont gagne\n");
            return;
        }
    }
    return;
}

void CheckDiagonal(char **tab)
{
    if(tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O')
    {
        printf("Les O ont gagne\n");
        return;
    }
    else if(tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X')
    {
        printf("Les X ont gagne\n");
        return;
    }
    if(tab[2][0] == 'O' && tab[1][1] == 'O' && tab[0][2] == 'O')
    {
        printf("Les O ont gagne\n");
        return;
    }
    else if(tab[2][0] == 'X' && tab[1][1] == 'X' && tab[0][2] == 'X')
    {
        printf("Les X ont gagne\n");
        return; 
    }
    return;
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

