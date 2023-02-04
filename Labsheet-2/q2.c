#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;
// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}
// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}
// Function definition goes here
int listLength(Node *head)
{
    int length = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        length++;
    }
    return length;
}

Node *mergeLists(Node *head1, Node *head2)
{
    int l1 = listLength(head1), l2 = listLength(head2);
    Node *ptr1 = head1, *ptr2 = head2, *merged = createNode(0);
    for (int i = 0; i < l1 + l2; i++)
    {
        if (ptr1 != NULL || ptr2 != NULL)
        {
            if (ptr1 == NULL)
            {
                addToList(merged, ptr2->data);
                ptr2 = ptr2->next;
            }
            else if (ptr2 == NULL)
            {
                addToList(merged, ptr1->data);
                ptr1 = ptr1->next;
            }
            else
            {
                if (ptr1->data <= ptr2->data)
                {
                    addToList(merged, ptr1->data);
                    ptr1 = ptr1->next;
                }
                else
                {
                    addToList(merged, ptr2->data);
                    ptr2 = ptr2->next;
                }
            }
        }
    }
    return merged->next;
}

int main(void)
{
    // Function calls go here
    Node *head1 = readList();
    Node *head2 = readList();
    Node *merged = mergeLists(head1, head2);
    printList(merged);
    freeList(head1);
    freeList(head2);
    freeList(merged);
    return 0;
}