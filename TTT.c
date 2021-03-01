#include "TTT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** createTab()
{
    /*char *tab = malloc(sizeof(char)*3);
    for(int i =0;i<3;i++)
    {
        strcpy(&tab[i],"0");
    }
    for(int i =0;i<3;i++)
    {
        printf("%c",tab[i]);
    }*/
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
        for(int j =0;j<3;j++)
        {
            printf("%c",tab[i][j]);
        }  
        printf("\n");  
    }
}
void EraseTab(char **tab)
{
    for(int i =0;i<3;i++)
    {
        free(tab[i]);
    }
    free(tab);
}