#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#include "folderstruct.h"


folder create_folder(void)
{
    folder f;

    f.day= create_date();
    strcpy(f.cas_positifs, "000000");
    strcpy(f.guerison, "000000");
    strcpy(f.deces, "000000");
    strcpy(f.nb_vaccin, "000000");


    return f;
}



int numerique(char nb[])
{
    int proceed= 1, i=0;
    while((proceed)&&(i<strlen(nb)))
    {
        if((nb[i]<'0')||(nb[i]>'9'))
        {
            proceed= 0;
        }
        i++;
    }

    return proceed;
}



void read_folder(folder* f, char pays[])
{
    read_date(&(f->day));

    system("cls");



    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h,249);
    printf("\tGouvernorat:\t");
    printf("%s", pays);

    printf("\t|\tDATE:\t");
    date_display(f->day);
    SetConsoleTextAttribute(h,240);
    printf("\n\n");



    int verify=0;

    while(!verify)
    {
        printf("\tCas positifs:\t");
        fflush(stdin);
        gets(f->cas_positifs);


        if(numerique(f->cas_positifs))
        {
            if((atoi(f->cas_positifs)<=999999)&&(atoi(f->cas_positifs)>=0))
            {
                verify=1;
            }
            else
            {
                printf("\n\tERREUR: nombre doit etre entre 0 et 999999\n");
            }
        }

        else
        {
            printf("\n\tERREUR: seulement des chiffres sont acceptes\n");
        }
    }


    verify= 0;

    while(!verify)
    {
        printf("\tGuerisons:\t");
        fflush(stdin);
        gets(f->guerison);


        if(numerique(f->guerison))
        {
            if((atoi(f->guerison)<=999999)&&(atoi(f->guerison)>=0))
            {
                verify=1;
            }
            else
            {
                printf("\n\tERREUR: nombre doit etre entre 0 et 999999\n\t");
            }
        }

        else
        {
            printf("\n\tERREUR: seulement des chiffres sont acceptes\n\t");
        }
    }


    verify= 0;

    while(!verify)
    {
        printf("\tDeces:\t");
        fflush(stdin);
        gets(f->deces);


        if(numerique(f->deces))
        {
            if((atoi(f->deces)<=999999)&&(atoi(f->deces)>=0))
            {
                verify=1;
            }
            else
            {
                printf("\n\tERREUR: nombre doit etre entre 0 et 999999\n\t");
            }
        }

        else
        {
            printf("\n\tERREUR: seulement des chiffres sont acceptes\n\t");
        }
    }


    verify= 0;

    while(!verify)
    {
        printf("\tNombre de vaccins:\t");
        fflush(stdin);
        gets(f->nb_vaccin);


        if(numerique(f->nb_vaccin))
        {
            if((atoi(f->nb_vaccin)<=999999)&&(atoi(f->nb_vaccin)>=0))
            {
                verify=1;
            }
            else
            {
                printf("\n\tERREUR: nombre doit etre entre 0 et 999999\n\t");
            }
        }

        else
        {
            printf("\n\tERREUR: seulement des chiffres sont acceptes\n\t");
        }
    }

}



void affect_folder(folder f2, folder*f1)
{
    *f1= f2;
}



void folder_display(folder f)
{
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h,249); //248 or 243 or 249
    printf("\tDATE:\t");
    date_display(f.day);
    SetConsoleTextAttribute(h,240);
    printf("\n");

    printf("\t\4cas positifs: %i    \4guerisons: %i   \4deces: %i   \4nombre de vaccins: %i\n\n\n", atoi(f.cas_positifs), atoi(f.guerison), atoi(f.deces), atoi(f.nb_vaccin));
}



int foldercmp(folder f1, folder f2)
{
    int diff=0;


            if(atoi(f1.cas_positifs)!=atoi(f2.cas_positifs))
            {
                diff= 1;
            }

            else
            {
                if(atoi(f1.guerison)!=atoi(f2.guerison))
                {
                    diff= 1;
                }

                else
                {
                    if(atoi(f1.deces)!=atoi(f2.deces))
                    {
                        diff= 1;
                    }

                    else
                    {
                        if(atoi(f1.nb_vaccin)!=atoi(f2.nb_vaccin))
                        {
                            diff= 1;
                        }
                        else
                        {

                        }
                    }
                }
            }



    return diff;
}


