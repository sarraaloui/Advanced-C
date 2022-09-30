#ifndef govarr_funtion_h
#define govarr_funtion_h

#include "govarr_prim.h"
#include <unistd.h>
#include <windows.h>
#include "link1.h"




void remplissage (FILE *fichier , liste tab[])
{


    int i, j, succee, trouve, trouve2;




    char container[20], nom[20],cs[6],deces[6],guer[6],vacc[6];
    date d;
    fichier=fopen("corona_data.txt","r");
    if (fichier == NULL)
    {
        printf("Un probléme s'est produit, pas d'acces à la base de donnee (verifier l'existance du fichier \"corona_data.txt\")");
    }
    else
    {

        folder f= create_folder();
        noeud n= noeud_creer(f);


        fgets(container, 200, fichier);
        while (!feof(fichier))
        {

            fscanf(fichier,"%s %s %s %s %s %s ", d.date_str, &nom, &cs, &guer, &deces, &vacc);
            strcpy(container, d.date_str);


            strcpy(d.jour, strtok(container, "/"));
            strcpy(d.mois, strtok(NULL, "/"));
            strcpy(d.annee, strtok(NULL, "/"));
            date_format(&d);

            date_affect(d, &f.day);
            strcpy(f.cas_positifs,cs);
            strcpy(f.deces,deces);
            strcpy(f.guerison,guer);
            strcpy(f.nb_vaccin,vacc);

            trouve=0;
            i=0;
            detect_name(nom);

            while((i<=23)&&(!trouve))
            {

                trouve2=0;
                if (strcmp(tab[i]->gov,nom)==0)
                {
                    j=1;
                    n= tab[i]->Tete;

                    if(!isempty(tab[i]))
                    {

                        while((!trouve2)&&(j<=tab[i]->lg))          //si la date est dupliquée, on garde la date qui a été sauvegardé la premiére
                        {


                            if(!datecmp(d, n->info.day))
                            {
                                trouve2= 1;
                            }

                            else
                            {
                                n= n->suivant;
                            }
                            j++;

                        }
                    }

                    trouve= 1;

                    if(!trouve2)
                    {
                        succee=inserer(tab[i],f,tab[i]->lg+1);
                    }
                }
                i++;

            }
        }
    }


    fclose(fichier);

}


void detect_name(char nom[])
{
    int i;
    for(i=0; i<=strlen(nom)-1; i++) //car le caractére d'indice strlen(nom) est '\0'
    {
        if((toupper(nom[i])>=65)&&(toupper(nom[i])<=90))
        {
            nom[i]= tolower(nom[i]);  //au debut rendre tous les lettre en minuscule
        }
        else
        {
            int j;
            for(j=i+1; j<=strlen(nom); j++)
            {
                nom[j-1]= nom[j];
            }
            i--;    /*i décrémente car sinn elle saute un caractére, exemple sidi_Bouzid,
                        aprés ecraser le char '_', i se place a l'indice de i et non pas B*/
        }
    }

    nom[0]= toupper(nom[0]);
}




void gov_init(liste tab[])     //distribution des noms de gouvernorats dans les liste
{
    int i;

    for(i=0; i<24; i++)
    {
        tab[i]=create_list();
    }


    gov_name(tab[0], "Ariana");
    gov_name(tab[1], "Beja");
    gov_name(tab[2], "Benarous");
    gov_name(tab[3], "Bizerte");
    gov_name(tab[4], "Gabes");
    gov_name(tab[5], "Gafsa");
    gov_name(tab[6], "Jendouba");
    gov_name(tab[7], "Kairouan");
    gov_name(tab[8], "Kasserine");
    gov_name(tab[9], "Kebili");
    gov_name(tab[10], "Kef");
    gov_name(tab[11], "Mahdia");
    gov_name(tab[12], "Manouba");
    gov_name(tab[13], "Medenine");
    gov_name(tab[14], "Monastir");
    gov_name(tab[15], "Nabeul");
    gov_name(tab[16], "Sfax");
    gov_name(tab[17], "Sidibouzid");
    gov_name(tab[18], "Siliana");
    gov_name(tab[19], "Sousse");
    gov_name(tab[20], "Tataouine");
    gov_name(tab[21], "Tozeur");
    gov_name(tab[22], "Tunis");
    gov_name(tab[23], "Zaghouan");
}


void gov_destruct(liste tab[])
{
    int i;

    for(i=0; i<24; i++)
    {
        destruct_list(tab[i]);
    }
}


void affichage(liste tab[])
{


    SetConsoleTitle("Corona en Tunisie");




    //pour savoir la largeur de la console pour l'affichage
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns= csbi.srWindow.Right- csbi.srWindow.Left+ 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;


        //position de curseur
    COORD coord;

    int i;
    for(i=1; i<=columns+1; i++)
    {
        printf("*");
    }
    printf(" ");
    for(i=1; i<=columns-4; i++)
    {
        printf("*");
    }
    printf(" *");
    for(i=2; i<=rows-3; i++)
    {

        coord.X = 0;
        coord.Y = i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("* *");
        coord.X = columns-3;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("* *");
    }
    printf("* ");
    for(i=1; i<=columns-4; i++)
    {
        printf("*");
    }
    printf(" ");
    for(i=1; i<=columns+1; i++)
    {
        printf("*");
    }





    int choix, choix2, verif=1;

    coord.X = columns/2 -68;
    coord.Y = 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("       ccccccccccccccc           cccccccccccccc            ccc                           ccc       ccccc       ccccccccccccccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("    cccccccccccccccccc        cccccccccccccccccccc        ccccc                         ccccc      ccccc       cccccccccccccccccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("  cccccccccccccccccccc       cccccccccccccccccccccc        ccccc                       ccccc       ccccc       cccccccccccccccccccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 6;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf(" cccccccc                   ccccc              ccccc        ccccc                     ccccc        ccccc       ccccc            cccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 7;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccccc                     ccccc              ccccc         ccccc                   ccccc         ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 8;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccc                       ccccc              ccccc          ccccc                 ccccc          ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 9;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccc                       ccccc              ccccc           ccccc               ccccc           ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccc                       ccccc              ccccc            ccccc             ccccc            ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 11;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccc                       ccccc              ccccc             ccccc           ccccc             ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 12;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccc                       ccccc              ccccc              ccccc         ccccc              ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 13;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccc                       ccccc              ccccc               ccccc       ccccc               ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 14;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("ccccccc                     ccccc              ccccc                ccccc     ccccc                ccccc       ccccc              ccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 15;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf(" cccccccc                   ccccc              ccccc                 ccccc   ccccc                 ccccc       ccccc            cccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 16;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("  cccccccccccccccccccc       cccccccccccccccccccccc                   ccccccccccc                  ccccc       cccccccccccccccccccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 17;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("    cccccccccccccccccc        cccccccccccccccccccc                     ccccccccc                   ccccc       cccccccccccccccccccc\n");

    coord.X = columns/2 -68;
    coord.Y = 18;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("       ccccccccccccccc           cccccccccccccc                          ccccc                     ccccc       ccccccccccccccccc\n");



    coord.X = columns/2 -12;
    coord.Y = 23;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("1\4Ajouter une/des dates\n");

    coord.X = columns/2 -15;
    coord.Y = 25;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("2\4Modifier une date existante\n");

    coord.X = columns/2 -13;
    coord.Y = 27;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("3\4supprimer une/des dates\n");

    coord.X = columns/2 -11;
    coord.Y = 29;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("4\4Afficher les donnees\n");

    coord.X = columns/2 -5;
    coord.Y = 31;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("5\4QUITTER\n\n");


    i=33;
    do
    {
        if(!verif)
        {
                coord.X = columns/2 -7;
                coord.Y = i;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            printf("Choix incorrect\n\n");
            i++;
        }
                coord.X = columns/2;
                coord.Y = i;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        scanf("%i", &choix);
        i++;

        switch(choix)
        {

            case 1:
                system("cls");
                ajout(tab);
                verif=1;
            break;

            case 2:
                system("cls");
                modif(tab);
                verif=1;
            break;

            case 3:
                system("cls");
                delete_data(tab);
                verif=1;
            break;

            case 4:
                system("cls");
                display_data(tab);
                verif=1;
            break;

            case 5:
                printf("\a");
                choix2= MessageBox(0,"QUITTER!", "Corona en Tunisie", 4 );

                    if(choix2==7)
                    {
                        system("cls");
                        affichage(tab);
                    }

            break;

            default:
                verif= 0;
            break;
        }

    }while(!verif);
}


int gov_choice()
{
    //pour savoir la largeur de la console pour l'affichage
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;


        int pays, verif_gov=0, i;
        int nb_spaces= columns/9;
        printf("\t\t\t\t\t\t\t\t\t\t\t       _____________________\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t      |liste de gouvernaurat|\n");

        for(i=1; i<=columns; i++)
        {
            printf("_");
        }

        printf("\n\n");
        printf(" 1\4Ariana");
        for(i=1; i<=nb_spaces-6; i++)
        {
            printf(" ");
        }
        printf("2\4Beja");
        for(i=1; i<=nb_spaces-4; i++)
        {
            printf(" ");
        }
        printf("3\4BenArous");
        for(i=1; i<=nb_spaces-8; i++)
        {
            printf(" ");
        }
        printf("4\4Bizerte");
        for(i=1; i<=nb_spaces-7; i++)
        {
            printf(" ");
        }
        printf("5\4Gabes");
        for(i=1; i<=nb_spaces-5; i++)
        {
            printf(" ");
        }
        printf("6\4Gafsa");
        for(i=1; i<=nb_spaces-5; i++)
        {
            printf(" ");
        }
        printf("7\4Jendouba");
        for(i=1; i<=nb_spaces-8; i++)
        {
            printf(" ");
        }
        printf("8\4Kairouan\n\n 9\4Kasserine");
        for(i=1; i<=nb_spaces-10; i++)
        {
            printf(" ");
        }
        printf("10\4Kebili");
        for(i=1; i<=nb_spaces-7; i++)
        {
            printf(" ");
        }
        printf("11\4Kef");
        for(i=1; i<=nb_spaces-4; i++)
        {
            printf(" ");
        }
        printf("12\4Mahdia");
        for(i=1; i<=nb_spaces-7; i++)
        {
            printf(" ");
        }
        printf("13\4Manouba");
        for(i=1; i<=nb_spaces-8; i++)
        {
            printf(" ");
        }
        printf("14\4Medenine");
        for(i=1; i<=nb_spaces-9; i++)
        {
            printf(" ");
        }
        printf("15\4Monastir");
        for(i=1; i<=nb_spaces-9; i++)
        {
            printf(" ");
        }
        printf("16\4Nabeul\n\n17\4Sfax");
        for(i=1; i<=nb_spaces-5; i++)
        {
            printf(" ");
        }
        printf("18\4SidiBouzid");
        for(i=1; i<=nb_spaces-11; i++)
        {
            printf(" ");
        }
        printf("19\4Siliana");
        for(i=1; i<=nb_spaces-8; i++)
        {
            printf(" ");
        }
        printf("20\4Sousse");
        for(i=1; i<=nb_spaces-7; i++)
        {
            printf(" ");
        }
        printf("21\4Tataouine");
        for(i=1; i<=nb_spaces-10; i++)
        {
            printf(" ");
        }
        printf("22\4Tozeur");
        for(i=1; i<=nb_spaces-7; i++)
        {
            printf(" ");
        }
        printf("23\4Tunis");
        for(i=1; i<=nb_spaces-6; i++)
        {
            printf(" ");
        }
        printf("24\4Zaghouan\n");


        for(i=1; i<=columns; i++)
        {
            printf("_");
        }

        printf("\n\n");


        printf("\t\t\t\t\t\t\t\t\t\t\t          entrer un choix\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t                 ");

        while(!verif_gov)
        {
            scanf("%i", &pays);
            if((pays<1)||(pays>24))
            {
                printf("\t\t\t\t\t\t\t\t\t\t\t          choix incorrect\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t                 ");
            }
            else
            {
                verif_gov=1;
            }
        }

        return pays;
}



void ajout(liste tab[])
{


    SetConsoleTitle("Corona en Tunisie | Ajout");

    int repeat= 1;


    while(repeat==1)
    {

        int pays;
        pays=gov_choice();

        system("cls");



            HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(h,249); //248 or 243 or 249
            printf("\tgouvernaurat:\t");
            puts(tab[pays-1]->gov);
            SetConsoleTextAttribute(h,240);
            printf("\n\n");



        int check=1;

        folder fl= create_folder();
        read_folder(&fl, tab[pays-1]->gov);
        system("cls");

            int i=1, cmp=1;
            noeud compared= tab[pays-1]->Tete;
            while((i<=tab[pays-1]->lg)&&(cmp))
            {
                cmp= datecmp(fl.day, compared->info.day);
                if(cmp)
                {
                    compared= compared->suivant;
                    i++;
                }
                else
                {
                    cmp= 0;
                }
            }

            if(cmp)
            {
                i=1;
                compared= tab[pays-1]->Tete;

                while((i<=tab[pays-1]->lg)&&(datecmp(fl.day, compared->info.day)==1))
                {
                    compared= compared->suivant;
                    i++;
                }
                check= inserer(tab[pays-1], fl, i);
                printf("\tDonnees enregistrees\n\t");
            }
            else
            {
                printf("\tCette date existe\n\t");


            }


        if(!check)      //au cas ou la condition précédente n'est pas véfiée, celle aussi ne sera pas vérifiée car check initialisée à 1
        {
            printf("\t=>insertion refusée");
        }

        printf("\n\n\t1\4Ajouter une date\n\t2\4Menu principal");
        do
        {
            scanf("%i", &repeat);
            if((repeat<1)||(repeat>2))
            {
                printf("\tChoix incorrect");
            }
        }while((repeat<1)||(repeat>2));

        system("cls");

    }
    affichage(tab);

}


void delete_data(liste tab[])
{


    SetConsoleTitle("Corona en Tunisie | Suppression");

    int choix, verif=0;


    printf("\t1\4Supprimer tous les donnees d'un gouvernaurat\n\t2\4Supprimer les donnees d'une date specifique\n\n\t\t");
    while(!verif)
    {
        scanf("%i", &choix);

        if((choix==1)||(choix==2))
        {
            verif= 1;
        }
        else
        {
            printf("\tChoix incorrect");
        }
    }

    switch(choix)
    {
        case 1:
            system("cls");
            delete_whole_gov(tab);
        break;

        case 2:
            system("cls");
            delete_specific_date(tab);
        break;

    }
}


void delete_whole_gov(liste tab[])
{
    int repeat=1;

    while(repeat==1)
    {

        int pays;
        pays=gov_choice();


        system("cls");




            HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(h,249);
            printf("\tgouvernaurat:\t");
            puts(tab[pays-1]->gov);
            SetConsoleTextAttribute(h,240);
            printf("\n\n");



        if(!(isempty(tab[pays-1])))
        {
            char nom_gov[20];
            strcpy(nom_gov, tab[pays-1]->gov);
            destruct_list(tab[pays-1]);
            tab[pays-1]= create_list();     //pour recreer la liste detruite et la reinitialiser
            strcpy(tab[pays-1]->gov, nom_gov);
            printf("\tDonnees supprimees");
        }
        else
        {
            printf("\tListe vide... Rien a supprimer");
        }


        printf("\n\n\t\t\tclicker sur entree pour continuer... ");
        getch();
        system("cls");


        printf("\n\n\t1\4supprimer les donnees d'un autre gouvernaurat\n\t2\4Menu principal\n\t\t");
        do
        {
            scanf("%i", &repeat);
            if((repeat<1)||(repeat>2))
            {
                printf("\tChoix incorrect\n\t\t");
            }
        }while((repeat<1)||(repeat>2));

        system("cls");

    }
    affichage(tab);

}


void delete_specific_date(liste tab[])
{
    int repeat=1;

    while(repeat==1)
    {


        int pays;
        pays=gov_choice();


        system("cls");




            HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(h,249);
            printf("\tgouvernaurat:\t");
            puts(tab[pays-1]->gov);
            SetConsoleTextAttribute(h,240);
            printf("\n\n");



        if(!(isempty(tab[pays-1])))
        {
            int i=1, stop=0;

            date d= create_date();
            read_date(&d);

            system("cls");

            folder f=create_folder();
            noeud n= noeud_creer(f);    //pour parcourir la liste
            n= tab[pays-1]->Tete;

            while((i<=tab[pays-1]->lg)&&(!stop))
            {
                if(!datecmp(n->info.day, d))
                {
                    stop=1;
                    supprimer(tab[pays-1], i);
                    printf("\tDate supprimee");
                }
                else
                {
                    n=n->suivant;
                }
                i++;
            }


            if(!stop)
            {
                    printf("\tDate n'existe pas... Rien a supprimer");
            }


        }
        else
        {
            printf("\tListe vide... Rien a supprimer");
        }


        printf("\n\n\t\t\tclicker sur entree pour continuer... ");
        getch();
        system("cls");


        printf("\n\n\t1\4supprimer les donnees d'une autre date\n\t2\4Menu principal\n\t\t");
        do
        {
            scanf("%i", &repeat);
            if((repeat<1)||(repeat>2))
            {
                printf("\tChoix incorrect\n\t\t");
            }
        }while((repeat<1)||(repeat>2));

        system("cls");

    }
    affichage(tab);

}


void display_data(liste tab[])
{


    SetConsoleTitle("Corona en Tunisie | Affichage");

    int choix, verif=0;


    printf("\t1\4Afficher les donnee d'un seul gouvernorat a une date donnee\n\t2\4Afficher tous les donnees et statistiques d'un gouvernaurat\n\t3\4Afficher les donnees de tous les gouvernorats a une date specifique\n\n\t\t");
    while(!verif)
    {
        scanf("%i", &choix);

        if((choix>=1)&&(choix<=3))
        {
            verif= 1;
        }
        else
        {
            printf("\tChoix incorrect\n\t\t");
        }
    }

    switch(choix)
    {
        case 1:
            system("cls");
            single_date_display(tab);
        break;

        case 2:
            system("cls");
            single_gov_display(tab);
        break;

        case 3:
            system("cls");
            display_by_date(tab);
        break;

    }

}



void single_date_display(liste tab[])
{

    int repeat=1;

    while(repeat==1)
    {


        int pays;
        pays=gov_choice();



        system("cls");


        if(isempty(tab[pays-1]))
        {
            printf("\tListe vide... Rien a Afficher");
        }

        else
        {


                HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

                SetConsoleTextAttribute(h,249);
                printf("\tgouvernaurat:\t");
                puts(tab[pays-1]->gov);
                SetConsoleTextAttribute(h,240);
                printf("\n\n");

            date d= create_date();
            read_date(&d);

            system("cls");

            folder f= create_folder();

            int check= search_by_date(tab[pays-1], d, &f);

            if(check)
            {
                HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

                    SetConsoleTextAttribute(h,249);
                    printf("\tgouvernaurat:\t");
                    printf("%s\t|",tab[pays-1]->gov);
                    SetConsoleTextAttribute(h,240);

                folder_display(f);
            }
            else
            {
                printf("\tdate introuvable (pas de donnees pour cette date)");
            }
        }


        printf("\n\n\t\t\tclicker sur entree pour continuer... ");
        getch();
        system("cls");


        printf("\n\n\t1\4Afficher une autre date\n\t2\4Menu principal\n\t\t");
        do
        {
            scanf("%i", &repeat);
            if((repeat<1)||(repeat>2))
            {
                printf("\tChoix incorrect\n\t\t");
            }
        }while((repeat<1)||(repeat>2));

        system("cls");


    }
    affichage(tab);
}


int search_by_date(liste l, date d, folder* f)
{
    noeud n= noeud_creer(*f);
    n= l->Tete;

    int i=1, trouve=0;


    while((!trouve)&&(i<=l->lg))
    {
        if(!datecmp(d, n->info.day))
        {
            trouve= 1;
            *f= recuperer(l, i);
        }
        else
        {
            n= n->suivant;
        }

        i++;
    }

    return trouve;
}


void single_gov_display(liste tab[])
{


    int repeat=1;

    while(repeat==1)
    {


        int pays;
        pays=gov_choice();



        system("cls");



                HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

                SetConsoleTextAttribute(h,249);
                printf("\tgouvernaurat:\t");
                puts(tab[pays-1]->gov);
                SetConsoleTextAttribute(h,240);
                printf("\n\n");


        if(!isempty(tab[pays-1]))
        {
            folder f= create_folder();
            noeud n= noeud_creer(f);
            n= tab[pays-1]->Tete;
            int i=1;

            while(i<= tab[pays-1]->lg)
            {
                f= recuperer(tab[pays-1], i);
                folder_display(f);

                n= n->suivant;

                i++;

            }

            if(tab[pays-1]->lg>1)
            {
                show_stat(tab[pays-1]);
            }
            else if(tab[pays-1]->lg==1)
            {
                printf("\t\tDonnees insuffisantes pour calculer les statistiques\n");   /*les statistiques s'affichent ssi le nombre de données
                                                                                            est superieur à 1*/
            }
        }
        else
        {
            printf("\tListe vide... Rien a afficher\n");
        }


        printf("\n\n\t\t\tclicker sur entree pour continuer... ");
        getch();
        system("cls");




        printf("\n\n\t1\4Afficher les donnees d'un autre gouvernorat\n\t2\4Menu principal");
        do
        {
            scanf("%i", &repeat);
            if((repeat<1)||(repeat>2))
            {
                printf("\tChoix incorrect");
            }
        }while((repeat<1)||(repeat>2));

        system("cls");


    }


    affichage(tab);
}


void show_stat(liste l)
{
    folder f= create_folder();
    noeud n=noeud_creer(f);
    n= l->Tete;

    int stat[3][4], i;

    //initialisation pour la comparaison
    for(i=0; i<=3; i++)
    {
        stat[0][i]=0;   //impossible d'avoir une valeur inferieure à celle ci
        stat[1][i]=999999;  //impossible d'avoir une valeur superieure à celle ci
        stat[2][i]=0;
    }


    /* ligne 1: les valeur max, ligne 2: valeurs min, ligne3: moyenne
       colonne1: cas positifs, c2: guerisson, c3: deces, c4: nb vaccinees,
       à propos la moyenne, somme/ lg car lg est le nombre total de donnees pour ce gouvernorat
    */

    float nombre_donne= l->lg;

    i=1;
    while(i<= l->lg)
    {
        f= recuperer(l, i);

        int val_cas_positifs= atoi(f.cas_positifs);
        int val_guerison= atoi(f.guerison);
        int val_deces= atoi(f.deces);
        int val_nb_vaccin= atoi(f.nb_vaccin);




        //max
        if(val_cas_positifs>stat[0][0])
        {
            stat[0][0]= val_cas_positifs;
        }
        if(val_guerison>stat[0][1])
        {
            stat[0][1]= val_guerison;
        }
        if(val_deces>stat[0][2])
        {
            stat[0][2]= val_deces;
        }
        if(val_nb_vaccin>stat[0][3])
        {
            stat[0][3]= val_nb_vaccin;
        }




        //min
        if(val_cas_positifs<stat[1][0])
        {
            stat[1][0]= val_cas_positifs;
        }
        if(val_guerison<stat[1][1])
        {
            stat[1][1]= val_guerison;
        }
        if(val_deces<stat[1][2])
        {
            stat[1][2]= val_deces;
        }
        if(val_nb_vaccin<stat[1][3])
        {
            stat[1][3]= val_nb_vaccin;
        }

        stat[2][0]+= atoi(f.cas_positifs);
        stat[2][1]+= atoi(f.guerison);
        stat[2][2]+= atoi(f.deces);
        stat[2][3]+= atoi(f.nb_vaccin);


        n= n->suivant;

        i++;

    }

    date first_date= create_date(), last_date=create_date();
    first_date= l->Tete->info.day;
    last_date= l->Queue->info.day;



    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    printf("\n\tdurant la periode du ");

            SetConsoleTextAttribute(h,249);
    printf("%s", first_date.date_str);   //on utilise printf au lieu de puts pour ne pas avoir un line break

            SetConsoleTextAttribute(h,240);
    printf(" jusqu'au ");

                SetConsoleTextAttribute(h,249);
    printf("%s:\n", last_date.date_str);

                SetConsoleTextAttribute(h,240);

    if(stat[1][0]==stat[0][0])
    {
        printf("\n\t\t\4Le nombre des cas positifs est constant et egal a %i", stat[0][0]);
    }
    else
    {
        printf("\n\t\t\4Le nombre des cas positifs varie dans l'interval [%i; %i], ayant une moyenne de %.1f", stat[1][0], stat[0][0], stat[2][0]/nombre_donne);
    }

    if(stat[1][1]==stat[0][1])
    {
        printf("\n\t\t\4Le nombre de guerisons est constant et egal a %i", stat[0][1]);
    }
    else
    {
        printf("\n\t\t\4Le nombre de guerisons varie dans l'interval [%i; %i], ayant une moyenne de %.1f", stat[1][1], stat[0][1], stat[2][1]/nombre_donne);
    }

    if(stat[1][2]==stat[0][2])
    {
        printf("\n\t\t\4Le nombre de deces est constant et egal a %i", stat[0][2]);
    }
    else
    {
        printf("\n\t\t\4Le nombre de deces varie dans l'interval [%i; %i], ayant une moyenne de %.1f", stat[1][2], stat[0][2], stat[2][2]/nombre_donne);
    }

    if(stat[1][3]==stat[0][3])
    {
        printf("\n\t\t\4Le nombre de vaccines est constant et egal a %i", stat[0][3]);
    }
    else
    {
        printf("\n\t\t\4Le nombre de vaccines varie dans l'interval [%i; %i], ayant une moyenne de %.1f", stat[1][3], stat[0][3], stat[2][3]/nombre_donne);
    }



}


void display_by_date(liste tab[])
{

        folder f= create_folder();
        date d= create_date();
        read_date(&d);

        system("cls");



        int tout_vide=1, j;
        int mat_taille=-1;
        char matrice_triee[24][5][15];

        for(int i=0; i<=23; i++)
        {



            if(!isempty(tab[i]))
            {



                folder f= create_folder();
                noeud n= noeud_creer(f);
                n= tab[i]->Tete;
                j=1;

                while((j<= tab[i]->lg)&&(datecmp(d, n->info.day)))
                {


                    n= n->suivant;

                    j++;

                }



                if(j<= tab[i]->lg)
                {
                    mat_taille++;

                    f= recuperer(tab[i], j);

                    strcpy(matrice_triee[mat_taille][0], f.cas_positifs);
                    strcpy(matrice_triee[mat_taille][1], f.guerison);
                    strcpy(matrice_triee[mat_taille][2], f.deces);
                    strcpy(matrice_triee[mat_taille][3], f.nb_vaccin);
                    strcpy(matrice_triee[mat_taille][4], tab[i]->gov);


                    tout_vide= 0;

                }


            }

        }




        if(tout_vide)
        {
            printf("\tRien a afficher (pas de données pour cette date)...\n");
            usleep(500000);
        }
        else
        {
                trier_tab(matrice_triee, mat_taille);
                system("cls");


                        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(h,249);
                        printf("\t\t\t\t\t\t\t\t\t\t\t\tDate:\t");
                    date_display(d);
                        SetConsoleTextAttribute(h,240);
                    printf("\n\n");

                for(j=0; j<=mat_taille; j++)
                {


                    strcpy(f.cas_positifs, matrice_triee[j][0]);
                    strcpy(f.guerison, matrice_triee[j][1]);
                    strcpy(f.deces, matrice_triee[j][2]);
                    strcpy(f.nb_vaccin, matrice_triee[j][3]);


                        SetConsoleTextAttribute(h,249);
                        printf("\t\t\t\t\t\t\tgouvernaurat:\t");
                        puts(matrice_triee[j][4]);
                        SetConsoleTextAttribute(h,240);
                        printf("\n");

                    printf("\t\t\t\t\t\t\4cas positifs: %i\t\t   \4guerisons: %i\t\t   \4deces: %i\t\t   \4nombre de vaccins: %i\n\n\n", atoi(f.cas_positifs), atoi(f.guerison), atoi(f.deces), atoi(f.nb_vaccin));

                    usleep(100000);
                }



                usleep(500000);
        }

        printf("\t\t\t\t\t\t\t\t\t\t      appuyer sur entree pour revenir au menu principal");
        fflush(stdin);
        getchar();

        system("cls");


    affichage(tab);

}



void trier_tab(char tab[23][5][15], int nb_gov)
{

    printf("\tChoisir les clefs de tri des donnees selon priorite de l'affichage\n");
    printf("\t\t1\4Cas positifs\n\t\t2\4Guerisons\n\t\t3\4Deces\n\t\t4\4nombre de vaccines\n\n");
    int verif=0, clef1, clef2, clef3 ,clef4;

    printf("\tClef 1 (dont la prioritee est la plus forte):\t");
    while(!verif)
    {
        scanf("%i", &clef1);
        if((clef1<1)||(clef1>4))
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t          choix incorrect\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t                 ");
        }
        else
        {
            verif=1;
        }
    }

    verif=0;

    printf("\tClef 2:\t");
    while(!verif)
    {
        scanf("%i", &clef2);
        if((clef2<1)||(clef2>4)||(clef2==clef1))
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t          choix incorrect\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t                 ");
        }
        else
        {
            verif=1;
        }
    }

    verif=0;

    printf("\tClef 3:\t");
    while(!verif)
    {
        scanf("%i", &clef3);
        if((clef3<1)||(clef3>4)||(clef3==clef1)||(clef3==clef2))
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t          choix incorrect\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t                 ");
        }
        else
        {
            verif=1;
        }
    }

    verif=0;

    printf("\tClef 4 (dont la prioritee est la plus faible):\t");
    while(!verif)
    {
        scanf("%i", &clef4);
        if((clef4<1)||(clef4>4)||(clef4==clef1)||(clef4==clef2)||(clef4==clef3))
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t          choix incorrect\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t                 ");
        }
        else
        {
            verif=1;
        }
    }


    system("cls");
    printf("\tChoisir l'ordre d'affichage\n");
    printf("\t\t1\4croissant\n\t\t2\4decroissant\n\n");

    verif=0;
    int ordre;
    while(!verif)
    {
        scanf("%i", &ordre);
        if((ordre<1)||(ordre>2))
        {
            printf("\t\t\t\t\t\t\t\t\t\t\t          choix incorrect\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t                 ");
        }
        else
        {
            verif=1;
        }
    }
    clef1--;
    clef2--;
    clef3--;
    clef4--;





    int proceed=1, suivant=0, j=0, diff;


    switch(ordre)
    {
        case 1:
            while(proceed)
            {
                proceed= 0;
                suivant++;

                for(j=0; j<nb_gov-suivant+1; j++)
                {

                    char container[10];
                    int cell;

                    diff= atoi(tab[j][clef1])- atoi(tab[j+1][clef1]);
                    if(diff>0)
                    {
                        proceed= 1;

                        for(cell=0; cell<=4; cell++)
                        {
                            strcpy(container, tab[j][cell]);
                            strcpy(tab[j][cell], tab[j+1][cell]);
                            strcpy(tab[j+1][cell], container);
                        }
                    }
                    else if(diff==0)
                    {
                        diff= atoi(tab[j][clef2])- atoi(tab[j+1][clef2]);
                        if(diff>0)
                        {
                            proceed= 1;

                            for(cell=0; cell<=4; cell++)
                            {
                                strcpy(container, tab[j][cell]);
                                strcpy(tab[j][cell], tab[j+1][cell]);
                                strcpy(tab[j+1][cell], container);
                            }
                        }

                        else if(diff==0)
                        {
                            diff= atoi(tab[j][clef3])- atoi(tab[j+1][clef3]);
                            if(diff>0)
                            {
                                proceed= 1;

                                for(cell=0; cell<=4; cell++)
                                {
                                    strcpy(container, tab[j][cell]);
                                    strcpy(tab[j][cell], tab[j+1][cell]);
                                    strcpy(tab[j+1][cell], container);
                                }
                            }

                            else if(diff==0)
                            {
                                diff= atoi(tab[j][clef4])- atoi(tab[j+1][clef4]);
                                if(diff>0)
                                {
                                    proceed= 1;

                                    for(cell=0; cell<=4; cell++)
                                    {
                                        strcpy(container, tab[j][cell]);
                                        strcpy(tab[j][cell], tab[j+1][cell]);
                                        strcpy(tab[j+1][cell], container);
                                    }
                                }

                                else if(diff==0)
                                {
                                    diff= strcmp(tab[j][4], tab[j+1][4]);
                                    if(diff>0)
                                    {
                                        proceed= 1;

                                        for(cell=0; cell<=4; cell++)
                                        {
                                            strcpy(container, tab[j][cell]);
                                            strcpy(tab[j][cell], tab[j+1][cell]);
                                            strcpy(tab[j+1][cell], container);
                                        }
                                    }
                                }

                            }

                        }

                    }



                }
            }
        break;


        case 2:

            while(proceed)
            {
                proceed= 0;
                suivant++;

                for(j=0; j<nb_gov-suivant+1; j++)
                {

                    char container[10];
                    int cell;

                    diff= atoi(tab[j][clef1])- atoi(tab[j+1][clef1]);
                    if(diff<0)
                    {
                        proceed= 1;

                        for(cell=0; cell<=4; cell++)
                        {
                            strcpy(container, tab[j][cell]);
                            strcpy(tab[j][cell], tab[j+1][cell]);
                            strcpy(tab[j+1][cell], container);
                        }
                    }
                    else if(diff==0)
                    {
                        diff= atoi(tab[j][clef2])- atoi(tab[j+1][clef2]);
                        if(diff<0)
                        {
                            proceed= 1;

                            for(cell=0; cell<=4; cell++)
                            {
                                strcpy(container, tab[j][cell]);
                                strcpy(tab[j][cell], tab[j+1][cell]);
                                strcpy(tab[j+1][cell], container);
                            }
                        }

                        else if(diff==0)
                        {
                            diff= atoi(tab[j][clef3])- atoi(tab[j+1][clef3]);
                            if(diff<0)
                            {
                                proceed= 1;

                                for(cell=0; cell<=4; cell++)
                                {
                                    strcpy(container, tab[j][cell]);
                                    strcpy(tab[j][cell], tab[j+1][cell]);
                                    strcpy(tab[j+1][cell], container);
                                }
                            }

                            else if(diff==0)
                            {
                                diff= atoi(tab[j][clef4])- atoi(tab[j+1][clef4]);
                                if(diff<0)
                                {
                                    proceed= 1;

                                    for(cell=0; cell<=4; cell++)
                                    {
                                        strcpy(container, tab[j][cell]);
                                        strcpy(tab[j][cell], tab[j+1][cell]);
                                        strcpy(tab[j+1][cell], container);
                                    }
                                }

                                else if(diff==0)
                                {
                                    diff= strcmp(tab[j][4], tab[j+1][4]);
                                    if(diff>0)
                                    {
                                        proceed= 1;

                                        for(cell=0; cell<=4; cell++)
                                        {
                                            strcpy(container, tab[j][cell]);
                                            strcpy(tab[j][cell], tab[j+1][cell]);
                                            strcpy(tab[j+1][cell], container);
                                        }
                                    }
                                }

                            }

                        }

                    }



                }
            }


        break;


    }

}






void modif (liste tab[])
{

    SetConsoleTitle("Corona en Tunisie | Modification");



    int repeat=1;

    while(repeat==1)
    {


        int pays;
        pays=gov_choice();



        system("cls");


        if(isempty(tab[pays-1]))
        {
            printf("\tListe vide... Rien a Modifier");
        }

        else
        {


                HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

                SetConsoleTextAttribute(h,249); //248 or 243 or 249
                printf("\tgouvernaurat:\t");
                puts(tab[pays-1]->gov);
                SetConsoleTextAttribute(h,240);
                printf("\n\n");

            date d= create_date();
            read_date(&d);

            system("cls");


            folder f= create_folder();

            int check= search_by_date(tab[pays-1], d, &f);





            if(!check)
            {
                printf("\tdate introuvable (pas de donnees pour cette date)");
            }
            else
            {

                int stop=0, i=1;
                noeud n=noeud_creer(f);
                n= tab[pays-1]->Tete;

                while((i<=tab[pays-1]->lg)&&(!stop))
                {
                    if(!datecmp(n->info.day, d))
                    {
                        stop=1;
                        supprimer(tab[pays-1], i);
                    }
                    else
                    {
                        n=n->suivant;
                    }
                    i++;
                }

                int choix, verif=0;


                printf("\t1\4Modifier un seul champ\n\t2\4Modifier tous les donnees\n\n\t");
                while(!verif)
                {
                    scanf("%i", &choix);

                    if((choix>=1)&&(choix<=2))
                    {
                        verif= 1;
                    }
                    else
                    {
                        printf("\tChoix incorrect\n\t");
                    }
                }

                switch(choix)
                {
                    case 1:
                        system("cls");
                        modif_seul_champ(&f);
                    break;

                    case 2:
                        system("cls");
                        modif_tout(&f);
                    break;

                }

                inserer(tab[pays-1], f, 1);




            }
        }
        printf("\n\n\t\t1\4Modifier une autre information\n\t\t2\4Menu principal");
        do
        {
            scanf("%i", &repeat);
            if((repeat<1)||(repeat>2))
            {
                printf("\tChoix incorrect");
            }
        }while((repeat<1)||(repeat>2));

        system("cls");


    }


    affichage(tab);
}






void modif_seul_champ(folder* f)
{

    int choix, verif=0;
    printf("\tChoisir l'information a modifier\n\t\t1\4Cas positifs\n\t\t2\4Guerisons\n\t\t3\4Deces\n\t\t4\4Nombre de vaccines\n\t\t");

    while(!verif)
    {
        scanf("%i", &choix);

        if((choix>=1)&&(choix<=4))
        {
            verif= 1;
        }
        else
        {
            printf("\tChoix incorrect");
        }
    }


                int verify;

                switch(choix)
                {
                    case 1:
                        verify= 0;
                        while(!verify)
                        {
                            printf("\tCas positifs:\t");
                            fflush(stdin);
                            gets(f->cas_positifs);


                            if(numerique(f->cas_positifs))
                            {
                                if((atoi(f->cas_positifs)>999999)||(atoi(f->cas_positifs)<0))
                                {
                                    printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
                                }
                                else
                                {
                                    verify=1;
                                }
                            }

                            else
                            {
                                printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
                            }
                        }

                    break;

                    case 2:
                        verify= 0;

                        while(!verify)
                        {
                            printf("\tGuerisons:\t");
                            fflush(stdin);
                            gets(f->guerison);


                            if(numerique(f->guerison))
                            {
                                if((atoi(f->guerison)>999999)||(atoi(f->guerison)<0))
                                {
                                    printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
                                }
                                else
                                {
                                    verify=1;
                                }
                            }

                            else
                            {
                                printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
                            }
                        }

                    break;

                    case 3:
                        verify= 0;

                        while(!verify)
                        {
                            printf("Deces:\t");
                            fflush(stdin);
                            gets(f->deces);


                            if(numerique(f->deces))
                            {
                                if((atoi(f->deces)>999999)||(atoi(f->deces)<0))
                                {
                                    printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
                                }
                                else
                                {
                                    verify=1;
                                }
                            }

                            else
                            {
                                printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
                            }
                        }

                    break;

                    case 4:
                        verify= 0;

                        while(!verify)
                        {
                            printf("\tNombre de vaccins:\t");
                            fflush(stdin);
                            gets(f->nb_vaccin);


                            if(numerique(f->nb_vaccin))
                            {
                                if((atoi(f->nb_vaccin)>999999)||(atoi(f->nb_vaccin)<0))
                                {
                                    printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
                                }
                                else
                                {
                                    verify=1;
                                }
                            }

                            else
                            {
                                printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
                            }
                        }

                    break;

                }
                system("cls");

}


void modif_tout(folder* f)
{
    folder temporaire= create_folder();
    affect_folder(*f, &temporaire);

    int verify=0;

    while(!verify)
    {
        printf("\tCas positifs:\t");
        fflush(stdin);
        gets(temporaire.cas_positifs);


        if(numerique(temporaire.cas_positifs))
        {
            if((atoi(temporaire.cas_positifs)>999999)||(atoi(temporaire.cas_positifs)<0))
            {
                printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
            }
            else
            {
                verify=1;
            }
        }

        else
        {
            printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
        }
    }


    verify= 0;

    while(!verify)
    {
        printf("\tGuerisons:\t");
        fflush(stdin);
        gets(temporaire.guerison);


        if(numerique(temporaire.guerison))
        {
            if((atoi(temporaire.guerison)>999999)||(atoi(temporaire.guerison)<0))
            {
                printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
            }
            else
            {
                verify=1;
            }
        }

        else
        {
            printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
        }
    }


    verify= 0;

    while(!verify)
    {
        printf("\tDeces:\t");
        fflush(stdin);
        gets(temporaire.deces);


        if(numerique(temporaire.deces))
        {
            if((atoi(temporaire.deces)>999999)||(atoi(temporaire.deces)<0))
            {
                printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
            }
            else
            {
                verify=1;
            }
        }

        else
        {
            printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
        }
    }


    verify= 0;

    while(!verify)
    {
        printf("\tNombre de vaccins:\t");
        fflush(stdin);
        gets(temporaire.nb_vaccin);


        if(numerique(temporaire.nb_vaccin))
        {
            if((atoi(temporaire.nb_vaccin)>999999)||(atoi(temporaire.nb_vaccin)<0))
            {
                printf("\n\t***ERREUR: nombre doit etre entre 0 et 999999***\n\t");
            }
            else
            {
                verify=1;
            }
        }

        else
        {
            printf("\n\t***ERREUR: seulement des chiffres sont acceptes***\n\t");
        }
    }


    system("cls");

    printf("\tConfimrmation d'operation:\n\n\t1\4Effectuer la modification\n\t2\4Annuler\n\n\t\t");

    int verif=0, choix;

    while(!verif)
    {
        scanf("%i", &choix);

        if((choix>=1)&&(choix<=2))
        {
            verif= 1;
        }
        else
        {
            printf("\tChoix incorrect");
        }
    }

    system("cls");
    switch(choix)
    {
        case 1:
            affect_folder(temporaire, f);
            printf("\t\tModification effectuee avec succee\n");
        break;

        case 2:
            printf("\t\tModification Annulee\n");
        break;

    }


}




void data_update(FILE *fichier , liste tab[])
{
    int i, j, space_counter;
    folder f= create_folder();
    noeud n= noeud_creer(f);
    char container[10], date_string[10];


    fichier=fopen("corona_data.txt","w");
    fprintf(fichier, "Date             Gouvernorat        Cas positifs          Guérisons           Décès         Nombre de vaccinés\n\n");

    for(i=0; i<=23; i++)
    {

        n= tab[i]->Tete;
        j=1;
        while(j<=tab[i]->lg)
        {
            strcpy(container, "");
            strcpy(date_string, "");
            itoa(atoi(n->info.day.jour), container, 10);
            strcat(date_string, container);
            strcat(date_string, "/");
            itoa(atoi(n->info.day.mois), container, 10);
            strcat(date_string, container);
            strcat(date_string, "/");
            itoa(atoi(n->info.day.annee), container, 10);
            strcat(date_string, container);



            fprintf(fichier, "%s", date_string);
            for(space_counter=1; space_counter<=17-strlen(date_string); space_counter++)
            {
                fprintf(fichier," ");
            }

            fprintf(fichier, "%s", tab[i]->gov);
            for(space_counter=1; space_counter<=23-strlen(tab[i]->gov); space_counter++)
            {
                fprintf(fichier," ");
            }

            fprintf(fichier, "%s", n->info.cas_positifs);
            for(space_counter=1; space_counter<=21-strlen(n->info.cas_positifs); space_counter++)
            {
                fprintf(fichier," ");
            }

            fprintf(fichier, "%s", n->info.guerison);
            for(space_counter=1; space_counter<=19-strlen(n->info.guerison); space_counter++)
            {
                fprintf(fichier," ");
            }

            fprintf(fichier, "%s", n->info.deces);
            for(space_counter=1; space_counter<=20-strlen(n->info.deces); space_counter++)
            {
                fprintf(fichier," ");
            }

            fprintf(fichier, "%s\n", n->info.nb_vaccin);



            n= n->suivant;
            j++;
        }
        fprintf(fichier, "\n");
    }


    fclose(fichier);
}



#endif // govarr_funtion_h

