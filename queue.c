#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


struct node {
    struct node *next;
    int value;
};

struct list {
    struct node* head;
    struct node* tail;
    int size;
};

typedef struct list* queue;

queue queue_create(void) {
    queue q = calloc(0, sizeof(struct list));
    if(q == NULL){
        return NULL;
    }

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}


bool queue_enqueue(queue qu, int value) {
    struct node *node = calloc(0, sizeof(struct node));
    if(node == NULL){
        return false;
    }
    node->value = value;
    node->next = NULL;
    if(qu->tail == NULL){
        qu->head = node;
        qu->tail = node;
    } else {
        node->next = NULL;
        qu->tail = node;
    }
    (qu->size)++;

    return true;
}


bool queue_dequeue(queue qu, int *out) {
    if(qu->head == NULL){
        return false;
    } 

    struct node* node = qu->head;
    qu->head = qu->head->next;
    *out = node->value;
    (qu->size)--;

    if(qu->size == 0) {
        qu->tail = NULL;
    }

    // free mem
    free(node);
    return true;
}


bool queue_peek(queue qu, int* out){
    if(qu->head == NULL){
        return false;
    }
    *out = qu->head->value;
    return true;
}


int queue_size(queue qu) {
    return qu->size;
}

void queue_free(queue qu) {
    struct node* np;
    while(qu->head != NULL){
        np = qu->head;
        qu->head = qu->head->next;
        free(np);
    }
    free(qu);
}



int main(void){
    puts("Testing queues");

    queue q = queue_create();

    queue_enqueue(q, 10);

    assert(queue_size(q) == 1);

    int out;
    assert(queue_peek(q, &out));
    assert(out == 10);

    assert(queue_dequeue(q, &out));
    assert(out == 10);


    queue_free(q);


    puts("done testing queues");
    return EXIT_SUCCESS; 
}
