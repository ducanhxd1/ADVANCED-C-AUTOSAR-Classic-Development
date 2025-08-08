#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data; 
    struct Node* node;
} Node;

Node* createNode(int data)
{
    Node* head = (Node *)malloc(sizeof(Node));
    head->data = data;
    head->node = NULL;

    return head;
}

int main(int argc, char const *argv[])
{
    Node *node = NULL;
    Node* node2 = createNode(10);
    printf("Node = %d", node2->data);

    
    return 0;
}
