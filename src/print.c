/* crude scheme
 * 
 * Copyright 2010 l.c. mathie
 */

#include <stdio.h>

#include "crudescheme.h"


void cs_print_object(object_t *o)
{
    if (o == NULL) { 
        /* indicates an interpreter error */
        printf("<NULL>");
    } else if (o->type == integer) {
        printf("%d", o->integer);
    } else if (o->type == cons && o->cons.cdr->type != cons) {
        /* non-list pair */
        fputs("(", stdout);
        cs_print_object(o->cons.car);
        fputs(" . ", stdout);
        cs_print_object(o->cons.cdr);
        fputs(")", stdout);
    } else {
        printf("<unprintable type %d>", o->type);
    }
}


/* vim: set cindent sw=4 expandtab: */
