#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"

#define min(x, y) ((x) < (y) ? (x) : (y))

list_ele_t *ele_new(const char *s)
{
    list_ele_t *e = malloc(sizeof(list_ele_t));
    if (!e)
        return NULL;
    e->next = NULL;
    if (s) {
        // allocate space for the string and copy it
        int sz = strlen(s);
        e->value = malloc(sz + 1);
        if (!e->value) {
            free(e);
            return NULL;
        }
        strncpy(e->value, s, sz);
        e->value[sz] = 0;
    } else {
        e->value = NULL;
    }
    return e;
}

void ele_free(list_ele_t *e, char *sp, size_t bufsize)
{
    if (!e)
        return;
    if (e->value) {
        if (sp) {
            int l = min(strlen(e->value), bufsize - 1);
            strncpy(sp, e->value, l);
            sp[l] = 0;
        }
        free(e->value);
    }
    free(e);
}

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q)
        return NULL;
    q->head = NULL;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    // free the list elements and the strings
    while (q_remove_head(q, NULL, -1)) {
    }
    /* Free queue structure */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    // if q is NULL and fail to allocate for a new queue
    if (!q && !(q = q_new()))
        return false;
    list_ele_t *newh = ele_new(s);
    if (!newh)
        return NULL;
    // append queue's head to the new element
    newh->next = q->head;
    q->head = newh;
    q->size++;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    // NULL or empty
    if (!q || !q->head)
        return false;
    // free queue's head
    list_ele_t *h = q->head;
    q->head = q->head->next;
    q->size--;
    ele_free(h, sp, bufsize);
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (!q || !q->head)
        return 0;
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
