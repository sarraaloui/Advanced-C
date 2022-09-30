#ifndef donneeprim_h
#define donneeprim_h

#include "folderstruct.h"


folder create_folder(void);

void affect_folder(folder, folder*);

void read_folder(folder*, char*);

void folder_display(folder);

int foldercmp(folder, folder);

int numerique(char);



#endif // donneeprim_h

