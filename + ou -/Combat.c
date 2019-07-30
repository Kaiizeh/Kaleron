#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "combat.h"

//Partie Multijoueur

//Initialisation joueur 1
void init_persop()
{

    int choix;
    int reload;
    printf("Comment t'appelles-tu ?\n");
    printf("Pseudo :");
    scanf("%s", &persop.nom);
    while (reload != 1)
    {
    printf("\nTres bien %s maintenant tu vas selectionner une classe :\n\n", persop.nom);
    printf("(1) Guerrier (equipe d'une epee et d'un bouclier)\n\n");
    printf("(2) Magicien (equipe d'un baton elementaire)\n\n");
    printf("(3) Archer (equipe d'un Arc ancestral)\n\n");
    printf("Choix : ");
    scanf("%d", &choix);
    system("cls");
    switch (choix)
    {
    case 1 :
        {
        printf("Vous avez choisi guerrier.\n\n");
        persop.defense = 5;
        persop.critique = 2;
        persop.degat = 5;
        persop.attspe = 1;
        persop.PV = 55;
        persop.classe = 1;
        persop.or = 10;
        persop.exp = 0;
        persop.lvl = 1;
        persop.mana = 50;
        jaugexp = 100;
        printf("Voici vos statistiques :\nPv : %d\n",persop.PV);
        printf("Defense : %d\n", persop.defense);
        printf("Degat : %d\n", persop.degat);
        printf("Attaque speciale : %d\n", persop.attspe);
        printf("Critique : %d\n\n\n", persop.critique);
        }
        break;
    case 2 :
        {
        printf("Vous avez choisi le mage.\n\n");
        persop.defense = 3;
        persop.critique = 4;
        persop.degat = 7;
        persop.attspe = 2;
        persop.PV = 45;
        persop.classe = 2;
        persop.or = 10;
        persop.exp = 0;
        persop.lvl = 1;
        persop.mana = 50;
        jaugexp = 100;
        printf("Voici vos statistiques :\nPv : %d\n",persop.PV);
        printf("Defense : %d\n", persop.defense);
        printf("Degat : %d\n", persop.degat);
        printf("Attaque speciale : %d\n", persop.attspe);
        printf("Critique : %d\n\n\n", persop.critique);
        }
        break;
    case 3 :
        {
        printf("Vous avez choisi l'archer.\n\n");
        persop.defense = 1;
        persop.critique = 3;
        persop.degat = 8;
        persop.attspe = 6;
        persop.PV = 40;
        persop.classe = 3;
        persop.or = 10;
        persop.exp = 0;
        persop.lvl = 1;
        persop.mana = 50;
        jaugexp = 100;
        printf("Voici vos statistiques :\nPv : %d\n",persop.PV);
        printf("Defense : %d\n", persop.defense);
        printf("Degat : %d\n", persop.degat);
        printf("Attaque speciale : %d\n", persop.attspe);
        printf("Critique : %d\n\n\n", persop.critique);
        }
        break;
    }
    printf("\n\nCela te convient ?\n0 : Retour a la selection\n1 : Continuer\n");
    printf("Choix : ");
    scanf("%d", &reload);
    system("cls");
    }

}

//Fonction cls + Pause
void refresh()
{
    system("PAUSE");
    system("cls");
}

//Partie Solo


//affichage combat IA
void affiIA()
{
    printf("%s          %s\n", persop.nom, ennemi.nom);
    printf("PV : %d      PV : %d\n", persop.PV, ennemi.PV);
    printf("Mana : %d\n\n", persop.mana);
    printf("\n\n1 : Attaquer\n2 : Defendre\n3 : Esquive\n4 : Consommable\n5 : Sortilege\n");

}

// IA du mode solo

//Initialisation des caracteristiques

void creer_enn(int pv,int def,int deg,int crit,int attspe,int cla,int or,int exp)
{
    ennemi.PV = pv;
    ennemi.defense = def;
    ennemi.degat = deg;
    ennemi.critique = crit;
    ennemi.attspe = attspe;
    ennemi.classe = cla;
    ennemi.or = or;
    ennemi.exp = exp;
}

// Selection du monstre
void init_enn()
{

   int choix;
   srand(time(NULL));
   if (persop.lvl <= 3)
   choix = (rand() % (3 - 1 + 1)) + 1;
   else if (persop.lvl >= 4 && persop.lvl <= 7)
    choix = (rand() % (6 - 1 + 1)) + 1;
   switch(choix)
   {
   case 1 :
       {
          char nom_mons[100] = "Orc vicieux";
          creer_enn(60,5,3,1,2,1,25,30);
          strcpy(ennemi.nom, nom_mons);
       }
       break;
   case 2 :
    {
          char nom_mons[100] = "Gobelin geant";
          creer_enn(55,2,7,1,2,2,20,30);
          strcpy(ennemi.nom, nom_mons);
    }
        break;
   case 3 :
    {
          char nom_mons[100] = "Elf sans oreille";
          creer_enn(75,2,5,10,2,3,30,30);
          strcpy(ennemi.nom, nom_mons);
    }
        break;
   case 4 :
       {
          char nom_mons[100] = "Mouton enrage";
          creer_enn(65,5,6,10,2,1,40,40);
          strcpy(ennemi.nom, nom_mons);
        }
          break;
   case 5 :
       {
          char nom_mons[100] = "Golem de pierre";
          creer_enn(85,5,7,3,2,1,35,45);
          strcpy(ennemi.nom, nom_mons);
        }
          break;
   case 6 :
       {
          char nom_mons[100] = "Dragon pas bon";
          creer_enn(90,2,9,5,2,2,45,45);
          strcpy(ennemi.nom, nom_mons);
        }
          break;


   }

}


void action_IA(int choid)
{
    if (choid == 1)
        printf("%s degaine son epee !\n", ennemi.nom);
    else if (choid == 2)
        printf("%s se mets en posture de garde \n", ennemi.nom);
    else if (choid == 3)
        printf("%s se montre prudent et se recule un peu\n", ennemi.nom);
}


void combat_IA()
{
    init_enn();
    do
    {
    int choix, choid, resultat, choip;
    affiIA();
    srand(time(NULL));
    choid = (rand() % (3 - 1 + 1)) + 1;
    action_IA(choid);
    printf("Action de %s : ", persop.nom);
    scanf("%d", &choix);
    resultat = choid + choix;
    if (choix != 4 && choix != 5)
    {
    switch(resultat)
    {
        //Action si les deux attaques
    case 2 :
        attattIA(choix);
        break;
        //Action si Att+Def
    case 3 :
        attdefIA(choix);
        break;
        //Action si Att+esquive
    case 4 :
        atteskIA(choix);
        break;
    }
    }
    else if (choix == 4)
    {
        refresh();
        printf("Potion de vie : %d\nPotion d'experience : %d\nPotion de mana : %d\n\n", perso.potion_vie, perso.potion_exp, perso.potion_mana);
        printf("Que voulez vous utilisez ?");
        scanf("%d", &choip);
        switch (choip)
        {
        case 1 :
            {
            if (perso.potion_vie > 0)
            {
                persop.PV = 10 + persop.PV;
                printf("Vous avez recuperer 10 de PV\n");
                perso.potion_vie--;
                refresh();

            }
            else
                printf("Desole tu n'as pas cet objet sur toi\n");
            }
                break;
        case 2 :
             {
            if (perso.potion_exp > 0)
            {
                persop.exp = 5 + persop.exp;
                printf("Vous avez gagner 5 en Experience\n");
                perso.potion_exp--;
                refresh();
            }
            else
                printf("Desole tu n'as pas cet objet sur toi\n");
             }
                break;

        case 3 :
             {
            if (perso.potion_mana > 0)
            {
                persop.mana= 10 + persop.mana;
                printf("Vous avez gagner 10 en mana\n");
                perso.potion_mana--;
                refresh();
            }
            else
                printf("Desole tu n'as pas cet objet sur toi\n");
             }
                break;
        }
    }
    else if (choix == 5)
        spellint();

    }while (persop.PV > 0 && ennemi.PV > 0);
    if (persop.PV > 0)
    {
        geneOrXp();
    }
    passage();

}


void attattIA(int choix)
{
    printf("Vous lancez vos attaques en meme temps\n");
    if (ennemi.classe == 2)
    {
        printf("%s sort sa deuxieme lame est entaille %s\n", ennemi.nom, persop.nom);
        persop.PV = persop.PV - (ennemi.degat + ennemi.critique * 2);
        ennemi.PV = ennemi.PV - persop.degat;
    }
    else
    {
          persop.PV = persop.PV - ennemi.degat;
          ennemi.PV = ennemi.PV - persop.degat;
    }
    refresh();
}


void attdefIA(int choix)
{
     if (choix == 2)
            {
                printf("%s se defend face a l'attaque de %s\n", persop.nom, ennemi.nom);
                persop.PV = persop.PV - ennemi.degat / 2;
                if (persop.classe == 1) //Si perso a Bouclier + Epee
                    {
                        printf("%s se protege bien et inflige quelque degat a %s\n", persop.nom, ennemi.nom);
                        ennemi.PV = ennemi.PV - ennemi.critique;
                    }
            }
     else
     {
                printf("%s se defend face a l'attaque de %s\n", ennemi.nom, persop.nom);
                ennemi.PV = ennemi.PV - persop.degat / 2;
                if (ennemi.classe == 1) //Si perso a Bouclier + Epee
                    {
                        printf("%s se protege bien et inflige quelque degat a %s\n", persop.nom, ennemi.nom);
                        persop.PV = persop.PV - ennemi.critique;
                    }
     }
    refresh();
}


void atteskIA(int choix)
{
         if (choix == 3)
            {
                printf("%s a esquive l'attaque de %s mais tribuche betement et perd 2PV\n", persop.nom, ennemi.nom);
                persop.PV = persop.PV - 2;
                if (persop.classe == 3) //Si perso a Arc leger
                    {
                        printf("Mais %s reussi a decocher une fleche et touche %s\n", persop.nom, ennemi.nom);
                        ennemi.PV = ennemi.PV - (persop.critique + persop.degat);
                    }
            }
     else
            {
                printf("%s a esquive l'attaque de %s mais tribuche betement et perd 1PV\n", ennemi.nom, persop.nom);
                ennemi.PV = ennemi.PV - 2;
                if (ennemi.classe == 3) //Si perso a Arc leger
                    {
                        printf("Mais %s reussi a decocher une fleche et touche %s\n", ennemi.nom, persop.nom);
                        persop.PV = persop.PV - (ennemi.critique + ennemi.degat);
                    }
            }
    refresh();
}


//Systeme et economie

void geneOrXp()
{
    int or, xp, rest;
    srand(time(NULL));
    or = (rand() % (ennemi.or - 3 + 1)) + 3;
    persop.or = persop.or + or;
    printf("Vous avez gagne %d d'or\n", or);
    xp = (rand() % (ennemi.exp - 1 + 1)) + 1;
    persop.exp = xp + persop.exp;
    printf("Vous avez gagne %d d'exp\n", xp);
    rest = jaugexp - persop.exp;
    printf("Il vous reste %d xp avant de passer au prochain niveau\n", rest);
    refresh();
}


void passage()
{
    //1 = Guerrier & 2 = Mage & 3 = Archer
    //Passage de niveau pour un guerrier
    if (persop.classe == 1)
    {
        if (persop.exp >= jaugexp)
        {
            persop.critique++;
            persop.defense += 5;
            persop.degat += 2;
            persop.attspe++;
            persop.PV += 10;
            persop.mana += 2;
            jaugexp *= 1.5;
            persop.lvl++;
        }
    }

    if (persop.classe == 2)
    {
        if (persop.exp >= jaugexp)
        {
            persop.critique++;
            persop.defense += 2;
            persop.degat++;
            persop.attspe += 2;
            persop.PV += 5;
            persop.mana += 6;
            jaugexp *= 1.5;
            persop.lvl++;
        }
    }

    if (persop.classe == 1)
    {
        if (persop.exp >= jaugexp)
        {
            persop.critique += 2;
            persop.defense++;
            persop.degat += 4;
            persop.attspe++;
            persop.PV += 4;
            jaugexp *= 1.5;
            persop.lvl++;
        }
    }
        printf("Vous venez de passer au niveau %d\n", persop.lvl);
        printf("Voici vos statistiques :\nPv : %d\n",persop.PV);
        printf("Defense : %d\n", persop.defense);
        printf("Degat : %d\n", persop.degat);
        printf("Attaque speciale : %d\n", persop.attspe);
        printf("Critique : %d\n\n\n", persop.critique);
        persoinit = persop;
        refresh();

}






