#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>






// Fonction pour la difficulté
int difficult(int maxi)
{
    int maximum = 0;
    int choix = 0;


    while (choix < 1 || choix > 3)
    {
    printf("Choix : ");
    scanf("%d", &choix);
    switch (choix)
    {
        case 1 :
            maximum = 100;
            break;
        case 2 :
            maximum = 1000;
            break;
        case 3 :
            maximum = 10000;
            break;
        default :
            printf("Vous n'avez rien choisi\n");
            break;
    }
    }
    system("cls");
    return maximum;

}

//Fonction pour le mode classique
void classique ()
{
    int max = 0;
    int min = 1;
    int unknow = 0;
    int nb = 0;
    int cpt = 0;
    int choix = 0;


// Debut du jeu
do
    {
    printf("Mode classique\n");
    printf("==============\n\n");
    printf("\nVeuillez choisir un mode difficulte\n");
    printf("\n1 : 1 a 100\n2 : 1 a 1000\n3 : 1 a 10 000\n");

// Initialisation de la difficulté
    max = difficult(max);
    srand(time(NULL));
    unknow = (rand() % (max - min + 1)) + min;

// Affichage de la partie
    while (nb != unknow)
{
    printf("Veuillez rentrer un chiffre compris entre 0 et %d\n", max);
    printf("Choix :");
    scanf("%d", &nb);

   if (unknow > nb)
            printf("Le nombre est plus grand !\n\n");
        else if (unknow < nb)
            printf("Le nombre est plus petit !\n\n");


    cpt++;
}

// Fin de la partie
    system("cls");

    printf("Bravo tu as gagne !!\n\n");
    printf("Voici ton nombre d'essai : %d\n", cpt);
    printf("==============================\n\n");
    printf("1 : Recommencer\n0 : Arreter\n");
    printf("Fais ton choix : ");
    scanf("%d", &choix);

   } while (choix!=0);

}

//Fontion pour le monde Survie
void survie ()
{
    int max = 0;
    int min = 1;
    int unknow = 0;
    int nb = 0;
    int cpt = 0;
    int choix;
    int nbmax = 0;


// Debut du jeu
do
    {
    printf("\t Vous dans le mode survie\n\n");
    printf("=============================\n");
    printf("\nVeuillez choisir un mode difficulte\n");
    printf("\n1 : 1 a 100\n2 : 1 a 1000\n3 : 1 a 10 000\n");


// Initialisation de la difficulté
    max = difficult(max);
    srand(time(NULL));
    unknow = (rand() % (max - min + 1)) + min;

// Initialisation des coups
    printf("indique le nombre de coups maximum : ");
    scanf("%d", &nbmax);
    system("PAUSE");
    system("cls");


// Affichage de la partie
    while (nb != unknow && nbmax > 0)
{
    printf("Veuillez rentrer un chiffre compris entre 0 et %d\n", max);
    printf("Choix :");
    scanf("%d", &nb);

   if (unknow > nb)
   {
       printf("Le nombre est plus grand !\n");
       nbmax--;
       printf("Il vous reste %d coups\n\n", nbmax);
   }
        else if (unknow < nb)
        {
            nbmax--;
            printf("Le nombre est plus petit !\n");
            printf("Il te reste %d coups\n\n", nbmax);
        }

    cpt++;
}

// Fin de la partie
    system("cls");
    if (nbmax > 0)
    {
    printf("Bravo tu as gagne !!\n\n");
    printf("Il te reste %d de coups\n", nbmax);
    printf("tu as reussi en %d coups\n", cpt);
    }
    else
    {
    printf("Dommage ! Tu as perdu ..\n\n");
    printf("Le nombre mystere etait %d\n", unknow);
    }
    printf("==========================\n\n");
    printf("1 : Recommencer\n0 : Arreter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

   } while (choix != 0);

}

//Fonction pour le mode 2 joueurs
void multijoueur()
{
    {
//Variable joueur 1
    int max = 0;
    int min = 1;
    int unknow = 0;
    int nb = 0;
    int cpt = 0;
    int choix;
    char nomjoueur1 [20];
//Variable joueur 2
    char nomjoueur2 [20];
    int maxj2;
    int unknowj2;
    int cptj2 = 0;
    int nbj2;
    int indic;




// Debut du jeu
do
    {
    printf("Vous etes dans le multijoueur\n");
    printf("=============================\n");
    printf("Joueur 1 donnez un pseudo :");
    scanf("%s", nomjoueur1);
    printf("Joueur 2 donnez un pseudo :");
    scanf("%s", nomjoueur2);
    system("cls");
    printf("Voulez vous 2 nombres différents ?\n");
    printf("1 : Oui\n0 : Non\n");
    scanf("%d", &indic);

// Initialisation de la difficulté joueur 1

    printf("\n%s Choisi un mode de difficulte\n", nomjoueur1);
    printf("\n1 : 1 a 100\n2 : 1 a 1000\n3 : 1 a 10 000\n");
    max = difficult(max);
    srand(time(NULL));
    unknow = (rand() % (max - min + 1)) + min;


// Initialisation difficulté joueur 2

    printf("\n%s Choisi un mode de difficulte\n", nomjoueur2);
    printf("\n1 : 1 a 100\n2 : 1 a 1000\n3 : 1 a 10 000\n");
    maxj2 = difficult(maxj2);
    srand(time(NULL));
    unknowj2 = (rand() % (maxj2 - min + 1)) + min;

// Deroulement de la partie
    while (nb != unknow && nbj2 != unknowj2)
{
//Phase joueur 1 + 2 si un seul chiffre

    printf("%s Choisis un nombre entre 0 et %d\n", nomjoueur1, max);
    printf("Choix :");
    scanf("%d", &nb);

   if (unknow > nb)
            printf("Le nombre est plus grand !\n\n");
        else if (unknow < nb)
            printf("Le nombre est plus petit !\n\n");
            if (indic == 0)
            {
            printf("%s Choisis un nombre entre 0 et %d\n", nomjoueur2, max);
            printf("Choix :");
            scanf("%d", &nbj2);
   if (unknow > nbj2)
            printf("Le nombre est plus grand !\n\n");
        else if (unknow < nbj2)
            printf("Le nombre est plus petit !\n\n");
            cptj2++;
            }


            cpt++;


//Phase joueur 2 si 2 chiffres differents
if(indic == 1)
    {
    if (nb != unknow)
    {
    printf("%s Choisis un nombre entre 0 et %d\n", nomjoueur2, maxj2);
    printf("Choix :");
    scanf("%d", &nbj2);

   if (unknowj2 > nbj2)
            printf("Le nombre est plus grand !\n\n");
        else if (unknowj2 < nbj2)
            printf("Le nombre est plus petit !\n\n");

            cptj2++;
    }


    }
}

// Fin de la partie
    system("cls");
    if (nb == unknow && nbj2 == unknow && nbj2 == unknowj2)
    {
        printf("Bravo %s tu as gagne\n", nomjoueur1);
        printf("Desole pour toi %s.. Ton nombre mystere etait le %d\n", nomjoueur2, unknowj2);
    }
    else
    {
        printf("Bravo %s tu as gagne\n", nomjoueur2);
        printf("Desole pour toi %s.. Ton nombre mystere etait le %d\n", nomjoueur1, unknow);
    }
        printf("Voici vos nombre d'essai : \n");
        printf("%s : %d\n", nomjoueur1, cpt);
        printf("%s : %d\n", nomjoueur2, cptj2);
        printf("==============================\n\n");
        printf("1 : Recommencer\n0 : Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

   } while (choix!=0);

}
}

//Mode d'emploi

void emploiguid()
{
    int choix;
    printf("Vous etes dans le mode d'emploi\n");
    printf("1 : + ou -\n2 : Pendu\n3 : Kaleron\n\n");
    printf("Votre choix :");
    scanf("%d", &choix);
    system("cls");
    switch(choix)
    {
    case 1 :
        {
            printf("Le principe est de trouver le nombre mystere.\n");
            printf("Au debut vous allez choisir le nombre maximum que le pc ne pourra pas depasser.\n");
            printf("Une fois fait vous allez devoir trouver le nombre mystere.\n");
            printf("Pour les determinés il y a 2 autres modes.\n");
        }
        break;
    case 2 :
        {
            printf("C'est un pendu tout ce qu'il y a de plus classique\n");
            printf("Le dictionnaire fourni avec est modifiable\n");
            printf("juste mettre les mots a la ligne\n");
        }
        break;
    case 3 :
        printf("Kaleron est RPG pour l'instant en Alpha 0.1\n\n");
        printf("Il y a 3 classes dans le jeu :\n- Guerrier\n- Mage\n- Archer\n");
        printf("Il te faudra grimper en niveau pour prendre de la puissance\n");
        printf("\nLors des combats la classes joue un role !\n\nEffet lors du combat :\n\n");
        printf("- Guerrier :\n\tSi l'attaquant est pret a vous attaquer et qu vous defendez alors vous \n\tinfligerez aussi des degats\n\n");
        printf("- Mage :\n\tVos attaques magiques gagnent plus d'experience et vous faites plus \n\tde degats de sort que les autres classes\n\n");
        printf("- Archer :\n\tSi l'attaquant vous attaque et que vous esquivez son coups alors \n\tvous allez tirer une fleche faisant beaucoup de degats\n\n");
        printf("Les sortileges :\n\nLes sortileges gagne de l'experience a chaque fois que vous l'utilisez.\nA chaque fois que le sortilege passe un niveaux il gagne en puissance \net son coup en mana peut se voire diminuer\n\n");
        printf("Le shop :\n\nVous pouvez acheter des consommables (potion de vie, de mana, ...), \nil y a aussi des equipements a acheter pour augmenter vos caracteristiques\n\n");
        printf("Vous voila pret a rentrer dans le monde de Kaleron !!\n\n");
        break;
    default :
        printf("Tu n'as pas choisi de mode d'emploi\n");
        break;
    }
}


//Menu principal
void plusmoins()
{
    int choix;
    printf("Menu + ou -\n\n");
    printf("1 : Classique\n2 : Survie\n3 : Multijoueur\n4 : Menu\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1 :
        classique();
        break;
    case 2 :
        survie();
        break;
    case 3 :
        multijoueur();
        break;
    case 4 :
        main();
        break;
    }

}
