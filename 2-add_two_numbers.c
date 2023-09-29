#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *dummyHead = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    struct ListNode *curr = dummyHead;
    char carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum >= 10 ? 1 : 0;
        curr->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        curr->next->val = sum >= 10 ? sum - 10 : sum;
        curr = curr->next;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    return dummyHead->next;
}

void freeListNode(struct ListNode *list)
{
    struct ListNode *current = list;
    struct ListNode *next;

    while (current->next)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(current);
}

int main(void)
{
    struct ListNode a2l1 = {
        .val = 5,
        .next = NULL};
    struct ListNode a1l1 = {
        .val = 3,
        .next = &a2l1};
    struct ListNode l1 = {
        .val = 4,
        .next = &a1l1};
    struct ListNode a1l2 = {
        .val = 4,
        .next = NULL};
    struct ListNode l2 = {
        .val = 6,
        .next = &a1l2};
    struct ListNode *head = addTwoNumbers(&l1, &l2);
    struct ListNode *result = head;
    printf("[%d", result->val);
    result = result->next;
    while (result->next)
    {
        printf(",%d", result->val);
        result = result->next;
    }
    printf(",%d]", result->val);

    freeListNode(head);

    return 0;
}