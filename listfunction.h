#ifndef listfunction_h
#define listfunction_h
#include "listprim.h"


noeud noeud_creer(folder f)
{
    noeud n= (noeud)malloc(sizeof(structnoeud));

    if(!n)
    {
        printf("\n\tPlus d'espace");
    }
    else
    {
        affect_folder(f, &n->info);
        n->precedent= NULL;
        n->suivant= NULL;
    }

    return n;
}


void noeud_detruire(noeud n)
{
    free(n);
}


int isempty(liste l)
{
    return (l->lg==0);
}


int isfull(liste l)
{
    noeud test= (noeud)malloc(sizeof(structnoeud));
    int sature= 1;

    if(test!=NULL)
    {
        free(test);
        sature= 0;
    }

    return sature;
}


int inserer(liste l, folder f, int pos)
{
    int succee= 1;
    int i;

    noeud n, p, s;

    if(isfull(l))
    {
        printf("\n\tListe sature\n\t");
        succee= 0;
    }
    else
    {
        if((pos<1)||(pos>l->lg+1))
        {
            printf("\n\tposition invalide\n\t");
            succee=0;
        }
        else
        {
            n= noeud_creer(f);

            if(isempty(l))
            {
                l->Tete=n;
                l->Queue=n;
            }
            else
            {
                if(pos==1)
                {
                    n->suivant= l->Tete;
                    l->Tete->precedent= n;
                    l->Tete= n;
                }

                else if(pos==l->lg+1)
                {
                    n->precedent= l->Queue;
                    l->Queue->suivant= n;
                    l->Queue= n;
                }

                else
                {
                    s= l->Tete;
                    for(i=1; i<pos; i++)
                    {
                        p=s;
                        s=s->suivant;
                    }
                    p->suivant= n;
                    n->precedent= p;

                    n->suivant= s;
                    s->precedent= n;
                }
            }
            l->lg++;
        }
    }

    return succee;
}


folder recuperer(liste l, int pos)
{


        folder f= create_folder();
        noeud p= l->Tete;

    if(isempty(l))
    {
        printf("\n\tListe vide\n\t");
    }
    else
    {
        if((pos<1)||(pos>l->lg+1))
        {
            printf("\n\tPosition invalide\n\t");
        }
        else
        {
            int i;

            for(i=1; i<pos; i++)
            {
                p= p->suivant;
            }
            affect_folder(p->info, &f);
        }
    }

    return f;
}



liste create_list(void)
{
    liste l= (liste)malloc(sizeof(lastruct));

    if(!l)
    {
        printf("\n\tProbleme de memoire\n\t");
    }
    else
    {
        l->lg=0;
        l->Tete=NULL;
    }

    return l;
}


void destruct_list(liste l)
{
    int i;
    noeud p, s;

    s= l->Tete;

    for(i=1; i<=l->lg; i++)
    {
        p=s;
        s=s->suivant;
        noeud_detruire(p);
    }

    free(l);
}


void display_list(liste l)
{
    noeud p= l->Tete;
    int i;

    for(i=1; i<=l->lg; i++)
    {
        folder_display(p->info);

        p= p->suivant;
    }
}




int supprimer(liste l, int pos)
{
    int i, succee=1;
    noeud p, s;

    if(isempty(l))
    {
        printf("\n\tListe vide\n\t");
        succee= 0;
    }
    else if((pos<1)||(pos>l->lg))
    {
        printf("\n\tPosition invalide\n\t");
        succee= 0;
    }
    else
    {
        if(l->lg==1)
        {
            s=l->Tete;
            l->Tete= NULL;
            l->Queue= NULL;
        }
        else
        {
            if(pos==1)
            {
                s= l->Tete;
                l->Tete= l->Tete->suivant;
                l->Tete->precedent= NULL;
            }

            else if(pos== l->lg)
            {
                s= l->Queue;
                l->Queue= l->Queue->precedent;
                l->Queue->suivant= NULL;
            }

            else
            {
                s= l->Tete;
                for(i=1; i<pos; i++)
                {
                    p= s;
                    s= s->suivant;
                }

                s->suivant->precedent= p;
                p->suivant= s->suivant;
            }
        }
    }
    noeud_detruire(s);
    l->lg--;

    return succee;
}



void gov_name(liste l, char name[])
{
    strcpy(l->gov, name);
}



#endif // listfunction_h

