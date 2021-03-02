#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TTT.h"
int main(void)
{
    char **tab = createTab();
    PutCharacterInTab(tab,0,0,'X');
    PutCharacterInTab(tab,1,1,'X');
    PutCharacterInTab(tab,2,2,'X');
    ShowTab(tab);
    EraseTab(tab);
    return 0;
}