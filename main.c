#include <stdio.h>
#include <stdlib.h>
#include "TTT.h"
int main(void)
{
    char **tab = createTab();
    ShowTab(tab);
    EraseTab(tab);
    return 0;
}