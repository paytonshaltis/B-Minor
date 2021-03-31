#include "decl.h"
#include "expr.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

struct decl * decl_create( char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next ) {
    struct decl *d = malloc(sizeof(*d));
    d->name = name;
    d->type = type;
    d->value = value;
    d->code = code;
    d->next = next;
    return d;
}

void decl_print(struct decl *d, int indent) {
    //for all declarations...
    printf("%s : ", d->name);
    type_print(d->type);
    
    //for declarations of type other than function...
    if(d->type->kind != TYPE_FUNCTION) {

        if(d->value != NULL){
            printf(" = ");
            expr_print(d->value);
        }
        printf(";\n");
    }

    //for declarations of type function...
    if(d->type->kind == TYPE_FUNCTION) {
        
        if(d->code != NULL) {
            printf(" = ");
            printf("\n{\n");
            stmt_print(d->code, indent + 1);
            printf("}");
        }
        else{
            printf(";");
        }
        printf("\n");

    }

    //prints out the next declaration with same indent
    if(d->next != NULL) {
        decl_print(d->next, 0);
    }
}