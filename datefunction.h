#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dateprim.h"




date create_date(void)
{
    date d;
    strcpy(d.jour, "00");
    strcpy(d.mois, "00");
    strcpy(d.annee, "0000");
    strcpy(d.annee, "00/00/0000");


    return d;
}


void date_affect(date d2, date* d1)
{
    *d1 = d2 ;
}



void read_date(date* d)
{




    int verify= 0;
    int value_a;
    int value_m;
    int value_j;

    while(!verify)
    {
        printf("\tentrer une annee valide...\n\t");
        fflush(stdin);
        gets(d->annee);

        value_a= atoi(d->annee); //a to int

        if((value_a>=2020)&&(value_a<=2021))
        {
            verify=1;
        }
        else if((value_a<2020)&&(value_a!=0))
        {
            printf("\n\t***ERREUR...CORONA a apparu en Tunisie en 2 mars 2020***\n\t");
        }
        else if((value_a>2021))
        {
            printf("\n\n\t***ERREUR... Aucune résultat concernant cette date***\n\t");
        }
        else
        {
            printf("\n\t***annee invalide***\n");
        }

    }

    verify= 0;


    while(!verify)
    {
        printf("\tentrer le mois:\n\t");
        gets(d->mois);

        value_m= atoi(d->mois);

        switch(value_a)
        {
            case 2020:
                if((value_m>0)&&(value_m<=2))
                {
                    printf("\n\t***ERREUR...CORONA a apparu en Tunisie en 2 mars 2020***\n\t");
                }
                else if((value_m>=3)&&(value_m<=12))
                {
                    verify=1;
                }
                else
                {
                    printf("\n\t***mois invalide***\n\t");
                }
            break;

            case 2021:
                if((value_m>=1)&&(value_m<=12))
                {
                    verify=1;
                }
                else
                {
                    printf("\n\t***mois invalide***\n\t");
                }
            break;
        }
    }

    verify= 0;


    while(!verify)
    {
        printf("\tentrer le jour:\n\t");
        gets(d->jour);

        value_j= atoi(d->jour);

        switch(value_a)
        {
            case 2020:
                switch(value_m)
                {
                    case 3:
                        if((value_j==1))
                        {
                            printf("\n\t***ERREUR...CORONA a apparu en Tunisie en 2 mars 2020***\n\t");
                        }
                        else if((value_j>=2)&&(value_j<=31))
                        {
                            verify= 1;
                        }
                        else
                        {
                            printf("\n\t***jour invalide***\n\t");
                        }


                    break;

                    case 5: case 7: case 8: case 10: case 12:
                        if((value_j>0)&&(value_j<=31))
                        {
                            verify= 1;
                        }
                        else
                        {
                            printf("\n\t***jour invalide***\n\t");
                        }
                    break;

                    case 4: case 6: case 9: case 11:

                        if((value_j>0)&&(value_j<=30))
                        {
                            verify= 1;
                        }
                        else
                        {
                            printf("\n\t***jour invalide***\n\t");
                        }
                    break;
                }
            break;

            case 2021:
                switch(value_m)
                {
                    case 2:
                        if((value_j>0)&&(value_j<=28))      //2021 n'est pas bisextile
                        {
                            verify= 1;
                        }
                        else
                        {
                            printf("\n\t***Date invalide***\n\t");
                        }

                    break;

                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        if((value_j>0)&&(value_j<=31))
                        {
                            verify= 1;
                        }
                        else
                        {
                            printf("\n\t***Date invalide***\n\t");
                        }
                    break;

                    case 4: case 6: case 9: case 11:

                        if((value_j>0)&&(value_j<=30))
                        {
                            verify= 1;
                        }
                        else
                        {
                            printf("\n\t***Date invalide***\n\t");
                        }
                    break;
                }
            break;
        }
    }


    date_format(d);


}




void date_format(date* d)
{




    if(atoi(d->mois)<=9)
    {
        char MONTH[2];
        strcpy(MONTH,"");

        strcat(MONTH, "0");
        strcat(MONTH, d->mois);

        strcpy(d->mois, MONTH);
    }


    if(atoi(d->jour)<=9)
    {
        char DAY[2];
        strcpy(DAY, "");
        strcat(DAY, "0");
        strcat(DAY, d->jour);

        strcpy(d->jour, DAY);
    }


    char dmy[10];
    strcpy(dmy,"");



    strcat(dmy, d->jour);
    strcat(dmy, "/");
    strcat(dmy, d->mois);
    strcat(dmy, "/");
    strcat(dmy, d->annee);

    strcpy(d->date_str,"");
    strcpy(d->date_str, dmy);


}




void date_display(date d)
{
    puts(d.date_str);
}




int datecmp(date d1, date d2)   //si la 1ere date sup à la 2eme: result positive, si egaux: 0, sinon négative
{
    int diff=0;


             //la comparaison des chaines "2020" et "2021" (non pas les valeurs, ça aura la même valeur)
    if(atoi(d1.annee)>atoi(d2.annee))
    {
        diff= 1;
    }

    else if(atoi(d1.annee)<atoi(d2.annee))
    {
        diff= -1;
    }


    else                        //si egaux,passer à la comparaison des mois
    {
        if(atoi(d1.mois)>atoi(d2.mois))
        {
            diff= 1;
        }

        else if(atoi(d1.mois)<atoi(d2.mois))
        {
            diff= -1;
        }


        else                    //si egaux,passer à la comparaison des jours
        {
            if(atoi(d1.jour)>atoi(d2.jour))
            {
                diff= 1;
            }

            else if(atoi(d1.jour)<atoi(d2.jour))
            {
                diff= -1;
            }                   //sinon rien à faire; la valeur de diff reste 0
        }
    }


    return diff;
}



