#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"

struct expr * expr_create( expr_t kind, struct expr *left, struct expr *right ) {
    struct expr *e = malloc(sizeof(*e));
    e->kind = kind;
    e->left = left;
    e->right = right;
    return e;
}
struct expr * expr_create_name( const char *n ) {
    struct expr *e = expr_create(EXPR_NAME, 0, 0);
    e->name = n;
    return e;
}
struct expr * expr_create_integer_literal( int c ) {
    struct expr *e = expr_create(EXPR_INTLIT, 0, 0);
    e->literal_value = c;
    return e;
}
struct expr * expr_create_boolean_literal( int c ) {
    struct expr *e = expr_create(EXPR_BOOLLIT, 0, 0);
    e->literal_value = c;
    return e;
}
struct expr * expr_create_char_literal( char c ) {
    struct expr *e = expr_create(EXPR_CHARLIT, 0, 0);
    e->literal_value = c;
    return e;
}
struct expr * expr_create_string_literal( const char *str ) {
    struct expr *e = expr_create(EXPR_STRINGLIT, 0, 0);
    e->string_literal = str;
    return e;
}

void expr_print(struct expr *e) {
    if(e->kind == EXPR_NAME) {
        printf("%s", e->name);
    }
    if(e->kind == EXPR_INTLIT) {
        printf("%i", e->literal_value);
    }
    if(e->kind == EXPR_BOOLLIT) {
        if(e->literal_value == 0) {
            printf("false");
        }
        else
            printf("true");
    }
    if(e->kind == EXPR_STRINGLIT) {
        for(int i = 0; i < strlen(e->string_literal); i++) {
            if(e->string_literal[i] == 10) {
                printf("\\n");
            }
            else if(e->string_literal[i] == 0) {
                printf("\\0");
            }
            else{
                printf("%c", e->string_literal[i]);
            }
        }
    }
    if(e->kind == EXPR_CHARLIT) {
        printf("\'");
        if(e->literal_value == 10) {
            printf("\\n");
        }
        else if(e->literal_value == 0) {
            printf("\\0");
        }
        else{
            printf("%c", e->literal_value);
        }
        printf("\'");
    }
    if(e->kind == EXPR_FCALL) {
        expr_print(e->left);
        printf("(");
        expr_print(e->right);
        printf(")");
    }
    if(e->kind == EXPR_GROUP) {
        printf("(");
        expr_print(e->left);
        printf(")");
    }
    if(e->kind == EXPR_ARRIND) {
        expr_print(e->left);
        printf("[");
        expr_print(e->right);
        printf("]");
    }
    if(e->kind == EXPR_BRACKET) {
        expr_print(e->left);
        printf("]");
        if(e->right != NULL) {
            printf("[");
            expr_print(e->right);
        }
    }
    if(e->kind == EXPR_CURLS) {
        printf("{");
        if(e->left != NULL) {
            expr_print(e->left);
        }
        printf("}");
    }
    if(e->kind == EXPR_ARGS) {
        expr_print(e->left);
        if(e->right != NULL) {
            printf(", ");
            expr_print(e->right);
        }
    }
    if(e->kind == EXPR_INC) {
        expr_print(e->left);
        printf("++");
    }
    if(e->kind == EXPR_DEC) {
        expr_print(e->left);
        printf("--");
    }
    if(e->kind == EXPR_NOT) {
        printf("!");
        expr_print(e->left);
    }
    if(e->kind == EXPR_NEG) {
        printf("-");
        expr_print(e->left);
    }
    if(e->kind == EXPR_EXPON) {
        expr_print(e->left);
        printf("^");
        expr_print(e->right);
    }
    if(e->kind == EXPR_MOD) {
        expr_print(e->left);
        printf("%%");
        expr_print(e->right);
    }
    if(e->kind == EXPR_DIV) {
        expr_print(e->left);
        printf("/");
        expr_print(e->right);
    }
    if(e->kind == EXPR_MULT) {
        expr_print(e->left);
        printf("*");
        expr_print(e->right);
    }
    if(e->kind == EXPR_SUB) {
        expr_print(e->left);
        printf("-");
        expr_print(e->right);
    }
    if(e->kind == EXPR_ADD) {
        expr_print(e->left);
        printf("+");
        expr_print(e->right);
    }
    if(e->kind == EXPR_NEQUAL) {
        expr_print(e->left);
        printf("!=");
        expr_print(e->right);
    }
    if(e->kind == EXPR_EQUAL) {
        expr_print(e->left);
        printf("==");
        expr_print(e->right);
    }
    if(e->kind == EXPR_GE) {
        expr_print(e->left);
        printf(">=");
        expr_print(e->right);
    }
    if(e->kind == EXPR_GREATER) {
        expr_print(e->left);
        printf(">");
        expr_print(e->right);
    }
    if(e->kind == EXPR_LE) {
        expr_print(e->left);
        printf("<=");
        expr_print(e->right);
    }
    if(e->kind == EXPR_LESS) {
        expr_print(e->left);
        printf("<");
        expr_print(e->right);
    }
    if(e->kind == EXPR_AND) {
        expr_print(e->left);
        printf("&&");
        expr_print(e->right);
    }
    if(e->kind == EXPR_OR) {
        expr_print(e->left);
        printf("||");
        expr_print(e->right);
    }
    if(e->kind == EXPR_ASSIGN) {
        expr_print(e->left);
        printf("=");
        expr_print(e->right);
    }
}