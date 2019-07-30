#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "mode.h"


int main()
{
    int partie;
    while (partie != 0)
    {
    int choix = 0;
    printf("Bienvenue dans un jeu\n");
    printf("======================\n\n");
    printf("Choisissez un mode =D !\n\n");
    printf("1 : jeu + ou -\n2 : Pendu\n3 : Kaleron\n4 : Mode d'emploi\n");
    printf("Choix : ");
    scanf("%d", &choix);
    system("cls");
    switch (choix)
    {
    case 1 :
        plusmoins();
        break;
    case 2 :
        pendu();
        break;
    case 3 :
        AcceuilRPG();
    case 4 :
        emploiguid();
        break;
    }
    system("PAUSE");
    system("cls");
        printf("1 : Menu\n2 : Quitter\n");
        printf("Choix :");
        scanf("%d", &partie);

    }
    system("cls");

    printf("\t\t\tBy Keziah =D !!!!\n");
    printf("\t\t\t=================\n");
    printf("\t\t\tMerci d'avoir jouer\n");
    return 0;
}
