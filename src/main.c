/* crude scheme
 * 
 * Copyright 2010 l.c. mathie
 */


#include <stdlib.h>


/* 
 * basic data types: all are with a union inside object_t, discriminated by 
 * the type field. 
 * 
 * Reaching NULL through a Scheme object is an error.  nil is represented
 * by a special singleton object.
 * 
 * All objects should be created through cs_alloc_object, so that they can be
 * garbage collected etc.
 */


enum object_type {
    cons = 100,
    integer,
    builtin_func,
    nil,
};


typedef struct object object_t;


typedef struct {
    object_t *car, *cdr;
} cons_t;


struct object {
    enum object_type type;     
    union {
        cons_t cons;
        int integer;
    };
};


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
object_t *make_cons(object_t *car, object_t *cdr)
{
    object_t *c = cs_alloc_object(cons);

    c->cons.car = car;
    c->cons.cdr = cdr;

    return c;
}


int main(void)
{
    object_t *my_cons = make_cons(NIL, NIL);

    return 0;
}


/* vim: sw=4 cindent et 
 */
