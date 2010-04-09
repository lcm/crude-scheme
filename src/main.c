/* crude scheme
 * 
 * Copyright 2010 l.c. mathie
 */


#include <stdio.h>
#include <stdlib.h>

#include "crudescheme.h"


int main(void)
{
    object_t *two = cs_make_integer(2),
        *three = cs_make_integer(3);
    object_t *pair = cs_make_cons(two, three);

    cs_print_object(two);
    printf("\n");
    cs_print_object(pair);
    printf("\n");

    return 0;
}


/* vim: set cindent sw=4 expandtab: */
