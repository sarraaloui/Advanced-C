#ifndef govarr_prim_h
#define govarr_prim_h

#include "link3.h"




void remplissage (FILE* , liste*);


void detect_name(char*);


void gov_init(liste*);


void gov_destruct(liste*);


void affichage(liste*);


int gov_choice();


void ajout(liste*);


void delete_data(liste*);


void delete_whole_gov(liste*);


void delete_specific_date(liste*);


void display_data(liste*);


void single_date_display(liste*);


int search_by_date(liste, date, folder*);


void single_gov_display(liste*);


void show_stat(liste);


void display_by_date(liste*);


void modif (liste* tab);


void modif_seul_champ(folder*);


void modif_tout(folder*);


void data_update(FILE*, liste*);


#endif // govarr_prim_h


