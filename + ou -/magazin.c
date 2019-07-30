#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "combat.h"
//Réferencement d'équipement






//Procédure
void Equipement()
{
    int choix, achat, or, rest;
    refresh();
    printf("Magasin d'equipements\n");
    printf("votre bourse : %d or\n", persop.or);
    printf("1 : Casque\n\n");
    printf("2 : Armes\n\n");
    printf("5 : Retour menu\n\n");
    printf("Choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1 :
        {

        }
        break;
    case 2 :
        {

        }
        break;
    case 5 :
        AcceuilRPG();
        break;
    default :
        printf("Tu n'as rien choisi\n");
        break;
    }
    affistat();
    printf("Vous voulez acheter votre equipement ?\nOui(1) Non(0) : ");
    scanf("%d", &achat);
    if (achat == 1)
    {
        if(persop.or >= or)
        {
           persop.or = persop.or - or;
           printf("Merci de votre achat %s\n", persop.nom);
        }
        else
        {
            rest = or - persop.or;
            printf("Desole mais tu n'as pas assez d'argent.\nIl te manque %d or pour l'avoir\n", rest);
        }
    }

    refresh();
}
void Armure()
{
    int choix, achat, or, rest, quant;
    refresh();
    printf("Magasin a Armure\n");
    printf("votre bourse : %d or\n", persop.or);
    printf("1 : Armure Frigide   -   30or\n\n");
    printf("2 : Casque Aitte   -   35or\n\n");
    printf("3 : Casque de viking  -   35or\n\n");
    printf("4 : Casque Enfer   -   40or\n\n");
    printf("5 : Casque Epique   -   45or\n\n");
    printf("6 : Casque Apero   -   60or\n\n");
    printf("7: Casque Leger   -   60or\n\n");
    printf("8 : Casque Audio   -   650or\n\n");
    printf("9 : Casque Legendaire -   100or\n\n");
    printf("10 : Casque Gnagnagna -   150or\n\n");
    printf("11 : Menu\n\n");

    scanf("%d", &choix);






}
void consommable()
{
    int choix, achat, or, rest, quant;
    refresh();
    printf("Magasin de consommables\n");
    printf("votre bourse : %d or\n", persop.or);
    printf("1 : Potion de vie   -   10or\n\n");
    printf("2 : Potion de mana  -  15or\n\n");
    printf("3 : Potion d'experience  -   20or\n\n");
    printf("4 : Retour menu\n\n");
    printf("Choix : ");
    scanf("%d", &choix);
    printf("Combien en voulez vous ? : ");
    scanf("%d", &quant);
    switch (choix)
    {
    case 1 :
        {
        perso.potion_vie = perso.potion_vie + quant;
        or = 10;
        }
        break;
    case 2 :
        {
        perso.potion_mana = perso.potion_mana + quant;
        or = 15;
        }
        break;
    case 3 :
        {
        perso.potion_exp = perso.potion_exp + quant;
        or = 20;
        }
        break;
     case 4 :
        AcceuilRPG();
        break;
    default :
        printf("Tu n'as rien choisi\n");
        break;
    }
    printf("Vous voulez acheter ce consommable ?\nOui(1) Non(0) : ");
    scanf("%d", &achat);
    if (achat == 1)
    {
        or = or * quant;
        printf("Cela vous feras donc %d d'or", or);
        if(persop.or >= or)
        {
           persop.or = persop.or - or;
           printf("\nMerci de votre achat %s\n", persop.nom);
        }
        else
        {
            rest = or - persop.or;
            printf("Desole mais tu n'as pas assez d'argent.\nIl te manque %d d'or\n", rest);
        }
    }
    refresh();
}

void affistat()
{
        printf("Voici vos statistiques :\nPv : %d\n",persop.PV);
        printf("Defense : %d\n", persop.defense);
        printf("Degat : %d\n", persop.degat);
        printf("Attaque special : %d\n", persop.attspe);
        printf("Critique : %d\n\n\n", persop.critique);
}
