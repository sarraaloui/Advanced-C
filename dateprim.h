#ifndef dateprim_h
#define dateprim_h

#include "datestruct.h"


date create_date(void);

void affect_date(date*, date);

void read_date(date*);

void date_display(date);

int datecmp(date, date);

void date_format(date*);


#endif // dateprim_h

