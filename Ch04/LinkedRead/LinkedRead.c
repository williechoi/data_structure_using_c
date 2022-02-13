#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next; 
} Node;

int main(void)
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* cur = NULL;

    Node *newNode = NULL;
    int readData;

    while(1)
    {
        printf("please type in any natural number: ");
        scanf("%d", &readData);
        if(readData < 1)
            break;

        // Add new nodes
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        // If first node, head should point to new node
        // else, the previous node should point to new node
        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        // get tail to point to new node 
        tail = newNode;
    }

    printf("print all nodes ! \n");
    if(head == NULL)
    {
        printf("There is no natural number saved!\n");
    }
    else 
    {
        cur = head;
        printf("%d ", cur->data);

        while(cur->next != NULL)
        {
            // head has no data, so cur->next should come first!
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }

    printf("\n\n");

    if(head == NULL)
    {
        return 0;
    }
    else 
    {
        Node* delNode;
        Node* delNextNode;
        
        delNode = head;
        delNextNode = head->next;
        printf("Delete %d \n", delNode->data);
        free(delNode);

        while(delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("Delete %d \n", delNode->data);
            free(delNode);
        }

    }
    return 0;

}