#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "combat.h"

void AcceuilRPG()
{
    int partie, joueur, choix, charge;
    static int sav = 0;

if (sav == 0)
    {
    printf("Avez vous une sauvegarde ?\n");
    printf("1 : Oui\n0 : Non\nChoix :");
    scanf("%d", &charge);
    if (charge == 1)
        {
        chargement();
        printf("Aah ! Te revoila %s\n", persop.nom);
        }
    else
        init_persop();
        sav++;
        sauvegarde();
    }
    refresh();
    do
    {
    printf("Bienvenue dans Kaleron 0.1\n\n");
    printf("Menu\n\n1 : Combattre\n2 : Magasin\n3 : Personnage\n4 : Auberge\n5 : Sauvegarde\n6 : Menu principale\nChoix : ");
    persoinit = persop;
    scanf("%d", &joueur);
    refresh();
    switch (joueur)
    {
    case 1 :
        combat_IA();
    break;
    case 2 :
        magazin();
        break;
    case 3 :
        personnage();
        break;
    case 4 :
        Auberge();
    case 5 :
        sauvegarde();
    case 6 :
        refresh();
        main();
        break;
    }
    } while (joueur != 5);

}

void Auberge()
{
    int choix, regenV, regenM;
    printf("Vous voila dans l'auberge\n\nVoulez vous vous reposer pour reprendre votre vie et votre mana ?\n\n1 : Oui    2 : Non\n\nChoix : ");
    scanf("%d", &choix);
    if (choix == 1)
        {
            if (persop.or >= 10)
            {
            printf("Votre sejour vous coutera 10 pieces d'or\n");
            persop.or -= 10;
            persop.PV = persoinit.PV;
            regenV = persoinit.PV - persop.PV;
            printf("Vous avez recupere %d PV\n", regenV);
            persop.mana = persoinit.mana;
            regenM = persoinit.mana - persop.mana;
            printf("Vous avez recupere %d point de mana\n", regenM);
            }
            else printf("Vous n'avez pas assez d'or ...\n");
            refresh();
            AcceuilRPG();
        }
    else AcceuilRPG();
}
void personnage()
{
    system("cls");
    int choix;
    printf("(1) Caracteristique\n(2) Inventaire\n(3) Livre de sortilege\n\nChoix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1 :
        {
        printf("Caracteristique\n\n");
        if (persop.classe==1)
            printf("Votre classe : Guerrier\n");
        else if (persop.classe == 2)
            printf("Votre classe : Mage\n");
        else if (persop.classe == 3)
            printf("Votre classe : Archer\n");
        printf("Votre niveau : %d\n", persop.lvl);
        printf("Jauge d'experience : %d/%d\n",persop.exp, jaugexp);
        printf("Pv : %d\n",persop.PV);
        printf("Defense : %d\n", persop.defense);
        printf("Degat : %d\n", persop.degat);
        printf("Attaque speciale : %d\n", persop.attspe);
        printf("Critique : %d\n\n", persop.critique);
        printf("Votre bourse : %d or\n\n\n", persop.or);
        }
        break;
    case 2 :
        printf("Inventaire");
        break;
    case 3 :
        BookOfSpell();
    }
    refresh();
}


void magazin()
{
    int choix;
    refresh();
    printf("Vous etes dans le magasin\n\n");
    printf("1 : Equipement\n2 : Consommable\n\n");
    printf("Choix : ");
    scanf("%d",&choix);
    switch (choix)
    {
        case 1 :
            Equipement();
            break;
        case 2 :
            consommable();
            break;
    }
}

int sauvegarde()
{
    FILE* save = NULL;
    save = fopen("save.bin", "wb");

    if (save != NULL)
    {
       fwrite(&persop, 1 * sizeof(persop), 1, save);
       fwrite(&Empone, 1 * sizeof(Empone), 1, save);
       fwrite(&Emptwo, 1 * sizeof(Emptwo), 1, save);
       fwrite(&Empthird, 1 * sizeof(Empthird), 1, save);
       fwrite(&perso, 1 * sizeof(perso), 1, save);
       fwrite(&jaugexp, 1 * sizeof(jaugexp), 1, save);
       fclose(save);
    }
    else
    {
        printf("Fichier de sauvegarde introuvable");
    }

    return 0;
}

int chargement()
{
    FILE* save = NULL;
    save = fopen("save.bin", "rb");

    if (save != NULL)
    {
        fread(&persop, sizeof(persop), 1, save);
        fread(&Empone, sizeof(Empone), 1, save);
        fread(&Emptwo, sizeof(Emptwo), 1, save);
        fread(&Empthird, sizeof(Empthird), 1, save);
        fread(&perso, sizeof(perso), 1, save);
        fread(&jaugexp, sizeof(jaugexp), 1, save);
        fclose(save);
    }
    else
    {
        printf("Sauvegarde inexistante ...");
        exit(1);
    }
    return 0;
}
