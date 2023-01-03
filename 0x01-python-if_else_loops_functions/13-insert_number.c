#include "lists.h"


listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->n = number;

    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = NULL;
        return new_node;
    }

    listint_t *curr = *head;
    listint_t *prev = NULL;

    while (curr != NULL && curr->n < number)
    {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL)
    {
        *head = new_node;
        new_node->next = curr;
        return new_node;
    }

    prev->next = new_node;
    new_node->next = curr;
    return new_node;
}