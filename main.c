#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "link1.h"
#include "link2.h"
#include "link3.h"
#include "govarr_function.h"



void set_screen(void)
{




    //maximizer la fenêtre
    ShowWindow( GetConsoleWindow() , SW_MAXIMIZE);
    SetConsoleTitle("Corona en Tunisie");



    //interdir d'agrandir ou quitter en utilisant les bouton de menu de la console
    HWND h;
    HMENU sm;
    int i=0, close_index, maximize_index, nb_of_items;
    LPTSTR buf;

    h = GetConsoleWindow();
    sm = GetSystemMenu(h, 0);

    nb_of_items = GetMenuItemCount(sm);
    close_index = -1;
    maximize_index=-1;
    buf = (TCHAR*) malloc (256 *sizeof(TCHAR));


    //la recherche des boutons (chaque bouton a une chaine qui defini son role, exemple: &Close)
    while(i<=nb_of_items)
    {

        GetMenuString(sm, i, buf, 255, MF_BYPOSITION);

        if (!strcmp(buf, "&Close"))
        {
          close_index = i;
        }

            if (!strcmp(buf, "&Restore"))
        {
          maximize_index = i;
        }
        i++;
    }

    //si on trouve l'item, on le rend inactif (pour le bouton close et restore)
    if (close_index!=-1)
    {
        RemoveMenu(sm, close_index, MF_BYPOSITION);
    }

    if (maximize_index!=-1)
    {
        RemoveMenu(sm, maximize_index, MF_BYPOSITION);
    }


    //couleur d'affichage
    system("COLOR F0");
}


void loading()
{

        //pour savoir la largeur de la console pour l'affichage
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns= csbi.srWindow.Right- csbi.srWindow.Left+ 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;



        //position de curseur
    COORD coord;
    coord.X = columns/2 -12;
    coord.Y = rows/2 -2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

            SetConsoleTextAttribute(h,242);

            printf("CONNEXION A LA BASE DE DONNEE   ");
            for(int i=1; i<=3; i++)
            {
                printf("\b\b\b   \b\b\b.");
                usleep(300000);
                printf(".");
                usleep(300000);
                printf(".");
                usleep(300000);
            }
            SetConsoleTextAttribute(h,240);

    system("cls");
}



void main()
{

    set_screen();




    liste gov_arr[24];
    gov_init(gov_arr);

    FILE *fichier;
    remplissage(fichier, gov_arr);


    loading();
    affichage(gov_arr);
    data_update(fichier, gov_arr);

    gov_destruct(gov_arr);
    exit(0);


}
