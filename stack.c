#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct node {
    struct node *prev;
    int value;
};


struct stack_imp {
    int size;
    struct node *head;
};


typedef struct stack_imp* stack;


stack stack_create() {
    stack s = calloc(0, sizeof(struct stack_imp));
    if(s == NULL){
        return NULL;
    }
    s->size = 0;
    s->head = NULL;
    return s;
}

void stack_free(stack s) {
    struct node* cp;
    while(s->head != NULL){
        cp = s->head;
        s->head = cp->prev;
        free(cp);
    }
    free(s);
}

void stack_push(stack s, int item) {
    struct node* n = calloc(0, sizeof(struct node));
    n->value = item;
    n->prev = NULL;
    if(s->head == NULL) {
       s->head = n;
       (s->size)++;
       return;
    }

    n->prev = s->head;
    s->head = n;
    (s->size)++;
}

bool stack_pop(stack s, int *out) {
   if(s->head == NULL){
        return false;
   } 
    
    struct node *rp = s->head;
    *out = rp->value;
    s->head = rp->prev;
    free(rp);
    (s->size)--;
    return true;
}

bool stack_peek(stack s, int *out){
    if(s->head == NULL){
        return false;
    }
    *out = s->head->value;
    return true;
}

int stack_size(stack s) {
    return s->size;
}


int main(void) {
    puts("testing stack!");
    
    stack st = stack_create();

    stack_push(st, 10);
    assert(stack_size(st) == 1);

    int out;
    assert(stack_peek(st, &out));
    assert(out == 10);
    assert(stack_pop(st, &out));
    assert(out == 10);
    assert(stack_size(st) == 0);


    stack_free(st);
    

    puts("done testing");
   return EXIT_SUCCESS; 
}
