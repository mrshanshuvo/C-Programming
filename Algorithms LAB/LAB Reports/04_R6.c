#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int value;
    struct ListNode *next;
};

struct ListNode *mergeSort(struct ListNode *head);
struct ListNode *merge(struct ListNode *left, struct ListNode *right);
struct ListNode *getMiddle(struct ListNode *head);

void printLinkedList(struct ListNode *head)
{
    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->value = 4;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->value = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->value = 1;
    head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->value = 3;
    head->next->next->next->next = NULL;

    printf("Original Linked List: ");
    printLinkedList(head);

    head = mergeSort(head);

    printf("Sorted Linked List: ");
    printLinkedList(head);

    struct ListNode *current = head;
    struct ListNode *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

struct ListNode *mergeSort(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *middle = getMiddle(head);
    struct ListNode *nextToMiddle = middle->next;
    middle->next = NULL;

    struct ListNode *leftHalf = mergeSort(head);
    struct ListNode *rightHalf = mergeSort(nextToMiddle);

    return merge(leftHalf, rightHalf);
}

struct ListNode *merge(struct ListNode *left, struct ListNode *right)
{
    struct ListNode *merged = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = merged;

    while (left != NULL && right != NULL)
    {
        if (left->value < right->value)
        {
            current->next = left;
            left = left->next;
        }
        else
        {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left != NULL)
    {
        current->next = left;
    }
    else if (right != NULL)
    {
        current->next = right;
    }

    return merged->next;
}
struct ListNode *getMiddle(struct ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}