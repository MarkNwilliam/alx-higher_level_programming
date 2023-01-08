#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head) {
    // Check if the list is empty or has only one element
    if (*head == NULL || (*head)->next == NULL) {
        return 1;
    }

    // Find the middle of the list
    listint_t *slow = *head;
    listint_t *fast = *head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    listint_t *prev = NULL;
    listint_t *curr = slow;
    while (curr != NULL) {
        listint_t *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    // Compare the first half with the reversed second half
    listint_t *p = *head;
    listint_t *q = prev;
    while (q != NULL) {
        if (p->n != q->n) {
            return 0;
        }
        p = p->next;
        q = q->next;
    }

    return 1;
}
