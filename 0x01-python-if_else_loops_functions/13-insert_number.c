#include "lists.h"

listint_t *insert_node(listint_t **head, int number) {
listint_t *new = malloc(sizeof(listint_t));
listint_t *current = *head;

Copy code
if (new == NULL) {
    return NULL;
}

new->n = number;
new->next = NULL;

if (*head == NULL) {
    *head = new;
    return new;
}

if (current->n > number) {
    new->next = current;
    *head = new;
    return new;
}

while (current->next != NULL && current->next->n < number) {
    current = current->next;
}
new->next = current->next;
current->next = new;
return new;