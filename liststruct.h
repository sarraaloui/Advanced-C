#ifndef liststruct_h
#define liststruct_h
#include "link2.h"


typedef struct structnoeud
{
    folder info;
    struct structnoeud* precedent;
    struct structnoeud* suivant;

} structnoeud, *noeud;


typedef struct
{
    noeud Tete;
    noeud Queue;
    int lg;

    char gov[20];

} lastruct, *liste;


#endif // liststruct_h

