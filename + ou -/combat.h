#ifndef combat
#define combat

//struct de carac
typedef struct caracter carac;
struct caracter
{
    char nom[100];
    int PV;
    int degat;
    int defense;
    int critique;
    int attspe;
    int classe;
    int or;
    int exp;
    int lvl;
    int mana;
};
carac persop;
carac persoinit;    //Structure du persop initial
carac ennemi;
carac items;    //Structure du persop + items
//struct inventaire

typedef struct inventaire inv;
struct inventaire
{
    int potion_vie;
    int potion_vieb;
    int potion_exp;
    int potion_mana;
};

inv perso;

// struct des spell
typedef struct magie mag;
struct magie
{
    char spell_nam[100];
    int mp;
    int degatmag;
    int lvlspell;
    int type;   //type 1 = Attaque  Type 2 = Soin
    int jauge;
    int up;
    int ID;

};



mag Empone;

mag Emptwo;

mag Empthird;


//prototype et variables globes
int jaugexp;
void init_persop();
void init_persod();
void action_cbt();
void affichage();
void refresh();
void affiIA();
void affistat();
void init_enn();
void action_IA(int choid);
void combat_IA();
void attattIA(int choix);
void BookOfSpell();


#endif // combat
