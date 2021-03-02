char** createTab();
void ShowTab(char **tab);
void PutCharacterInTab(char **tab, int x, int y ,char lettre);
int CheckRows(char **tab);
int CheckColumns(char **tab);
int CheckDiagonal(char **tab);
void EraseTab(char **tab);
void MainMenu();
void Play();
int collider(char **tab);

/*
Le rond : O
La croix : X
*/
