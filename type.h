#ifndef TYPE_H
#define TYPE_H

#include "param_list.h"

typedef enum {
	TYPE_INTEGER,
	TYPE_STRING,
	TYPE_CHAR,
	TYPE_BOOLEAN,
	TYPE_VOID,
	TYPE_ARRAY,
	TYPE_FUNCTION
} type_t;

struct type {
	type_t kind;
	struct param_list *params;
	struct type *subtype;
	int size;
};

struct type * type_create( type_t kind, struct type *subtype, struct param_list *params, int size );
void          type_print( struct type *t );

#endif
