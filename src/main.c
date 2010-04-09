/* crude scheme
 * 
 * Copyright 2010 l.c. mathie
 */


#include <stdlib.h>

#include "types.h"


int main(void)
{
    cs_make_cons(
        cs_make_integer(2),
        cs_make_integer(3));

    return 0;
}


/* vim: set cindent sw=4 expandtab: */
