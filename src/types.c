/* crude scheme
 * 
 * Copyright 2010 l.c. mathie
 */


#include <stdlib.h>

#include "types.h"


object_t nil_value = { nil };
object_t * const NIL = &nil_value;


/* allocate a new object; the caller must fill in the body */
object_t *cs_alloc_object(enum object_type type)
{
    object_t *c = malloc(sizeof(object_t));
    c->type = type;
    return c;
}


/* allocate and return a new cons cell. */
object_t *cs_make_cons(object_t *car, object_t *cdr)
{
    object_t *c = cs_alloc_object(cons);

    c->cons.car = car;
    c->cons.cdr = cdr;

    return c;
}


object_t *cs_make_integer(int value)
{
    object_t *c = cs_alloc_object(integer);
    c->integer = value;
    return c;
}


/* vim: set cindent sw=4 expandtab: */
