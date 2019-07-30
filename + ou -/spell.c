#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "combat.h"
// Struct sort vierge pour reinitiliser
mag Vierge = {};
// Sortilège Brasier
mag Brasier = {"Brasier", 10, 15, 1, 1, 0, 50, 1};

// Sortilège Aura réparatrice
mag Aura = {"Aura curative", 15, 10, 1, 1, 0, 50, 2};

//Sortilège Cri de givre
mag Cri = {"Cri de givre", 5, 8, 1, 1, 0, 50, 3};

//interface sort en combat

void spellint()
{
    int choix;
    refresh();
    printf("Menu de competence\n\n");
    printf("1 : %s\n", Empone.spell_nam);
    printf("2 : %s\n", Emptwo.spell_nam);
    printf("3 : %s\n", Empthird.spell_nam);
    printf("Votre choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1 :
        {
        CheckSpell(Empone.type, Empone.degatmag, Empone.mp, Empone.spell_nam);
        Empone.jauge += 5;
        break;
        }
    case 2 :
        {
        CheckSpell(Emptwo.type, Emptwo.degatmag, Emptwo.mp, Emptwo.spell_nam);
        Emptwo.jauge += 5;
        break;
        }
    case 3 :
        {
        CheckSpell(Empthird.type, Empthird.degatmag, Empthird.mp, Empthird.spell_nam);
        Empthird.jauge += 5;
        break;
        }
    }
}

//interface Sort Book
void BookOfSpell()
{
    refresh();
    int choix;
    while (choix != 2 && choix != 3)
    {
        printf("Vous etes dans le livre des sortileges\n\nEmplacement 1 : %s lvl %d  exp : %d/%d\n\n", Empone.spell_nam, Empone.lvlspell, Empone.jauge, Empone.up);
        printf("Emplacement 2 : %s lvl %d  exp : %d/%d\n\n", Emptwo.spell_nam, Emptwo.lvlspell, Emptwo.jauge, Emptwo.up);
        printf("Emplacement 3 : %s lvl %d  exp : %d/%d\n\n", Empthird.spell_nam, Empthird.lvlspell, Empthird.jauge, Empthird.up);
        printf("1 : Changer les sorts\n2 : Retour menu\n3 : Retour menu principal Kaleron\n\nChoix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1 :
            SelectSpell();
            break;
        case 2 :
            personnage();
            break;
        case 3 :
            AcceuilRPG();
            break;
        }
    }
}

void SelectSpell()
{
    int choix;
    printf("1 : %s\n2 : %s\n3 : %s\n\n", Brasier.spell_nam, Aura.spell_nam, Cri.spell_nam);
    printf("Veuillez choisir un sortilege  :");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1 :
        {
            getchar();
            printf("1 - Emplacement 1\n2 - Emplacement 2\n3 - Emplacement 3\n\nVeuillez choisir dans quel emplacement le mettre :\n");
            scanf("%d", &choix);
            if (choix == 1)
                Empone = Brasier;
            if (choix == 2)
                Emptwo = Brasier;
            if (choix == 3)
                Empthird = Brasier;
            break;
        }
    case 2 :
        {
            getchar();
            printf("1 - Emplacement 1\n2 - Emplacement 2\n3 - Emplacement 3\n\nVeuillez choisir dans quel emplacement le mettre :\n");
            scanf("%d", &choix);
            if (choix == 1)
                Empone = Aura;
            if (choix == 2)
                Emptwo = Aura;
            if (choix == 3)
                Empthird = Aura;
            break;
        }
    case 3 :
        {
            getchar();
            printf("1 - Emplacement 1\n2 - Emplacement 2\n3 - Emplacement 3\n\nVeuillez choisir dans quel emplacement le mettre :\n");
            scanf("%d", &choix);
            if (choix == 1)
                Empone = Cri;
            if (choix == 2)
                Emptwo = Cri;
            if (choix == 3)
                Empthird = Cri;
            break;
        }
    }

}
//Action d'un sort d'attaque
void AttackSpell(int degat, int mana)
{
    if (persop.mana >= mana)
        {
        ennemi.PV = ennemi.PV - degat;
        persop.mana = persop.mana - mana;
        }
        else printf("Vous n'avez pas assez de mana !\n");
}
//Action d'un sort guérison
void HealSpell(int Heal, int mana)
{
    if (persop.mana >= mana)
        {
        persop.PV = persop.PV + Heal;
        persop.mana = persop.mana - mana;

        }
        else printf("Vous n'avez pas assez de mana !\n");
}
//Verification du type de sort
void CheckSpell(int type, int degat, int mana, char nom)
{
    if (type == 1)
        {
       ("Vous avez lance %s et vous avez inflige %d de degat\n", nom, degat);
       AttackSpell(degat, mana);
        }
    if (type == 2)
        {
       ("Vous avez lance %s et vous vous etes regenere de %d\n", nom, degat);
        HealSpell(degat, mana);
        }
}

//Retrait du sort

void ChangSpell()
{
    int choix, check;
    printf("Changement de sortilege\n\n\n");
    printf("1 : %s\n2 : %s\n3 : %s\n\n", Empone.spell_nam, Emptwo.spell_nam, Empthird.spell_nam);
    printf("Quel sortilege voulez vous retirer ?\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1 :
        {
            getchar();
            check = Verification(Empone.ID, Brasier.ID);
            if (check == 1)
                Brasier = Empone;
            check = Verification(Empone.spell_nam, Cri.ID);
            if (check == 1)
                Cri = Empone;
            check = Verification(Empone.ID, Aura.ID);
            if (check == 1)
                Aura = Empone;


        }
    case 2 :
        {
            getchar();
            check = Verification(Emptwo.ID, Brasier.ID);
            if (check == 1)
                Brasier = Emptwo;
            check = Verification(Emptwo.spell_nam, Cri.ID);
            if (check == 1)
                Cri = Emptwo;
            check = Verification(Emptwo.ID, Aura.ID);
            if (check == 1)
                Aura = Emptwo;
            break;
        }
    case 3 :
        {
            getchar();
            check = Verification(Empthird.ID, Brasier.ID);
            if (check == 1)
                Brasier = Empthird;
            check = Verification(Empthird.spell_nam, Cri.ID);
            if (check == 1)
                Cri = Empthird;
            check = Verification(Empthird.ID, Aura.ID);
            if (check == 1)
                Aura = Empthird;
            break;
        }
    }


}

int Verification (int actuel, int reference)
{
    if (actuel == reference)
        return 1;
    else return 0;
}


//Verification du passage du niveau du sort
/*void CheckSpellUp(int xp, int up,)
{
    if (xp >= up)
    {

    }
}*/

