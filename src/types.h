/* crude scheme
 * 
 * Copyright 2010 l.c. mathie
 */


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


extern object_t * const NIL;

object_t *cs_make_cons(object_t *car, object_t *cdr);
