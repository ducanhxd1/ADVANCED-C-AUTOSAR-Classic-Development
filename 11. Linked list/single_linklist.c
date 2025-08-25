#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct single_linklist_Node
{
    int data;                          // data
    struct single_linklist_Node *next; // con tro tro toi node ke tiep
};
typedef struct single_linklist_Node Node;

Node *createNode(int value)
{
    Node *head = (Node *)malloc(sizeof(Node *));
    head->data = value;
    head->next = NULL;

    return head;
}

bool empty(Node *head)
{
    return (head == NULL);
}

void printList(Node *head)
{
    if (empty(head))
    {
        printf("Empty list\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// void pushBack(Node **head, int value)
// {
// 	// tao node moi
// 	Node *node = createNode(value);
	
// 	// kiem tra va cap nhat node dau neu danh sach rong
// 	if
	
// }



int main(int argc, char const *argv[])
{

    return 0;
	
}
