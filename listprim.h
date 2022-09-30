#ifndef listprim_h
#define listprim_h
#include "liststruct.h"


noeud noeud_creer(folder);

void noeud_detruire(noeud);

int isempty(liste);

int isfull(liste);

int inserer(liste, folder, int);

int supprimer(liste, int);

folder recuperer(liste, int);

liste create_list(void);

void destruct_list(liste);

void display_list(liste);

void gov_name(liste, char*);




#endif // listprim_h

