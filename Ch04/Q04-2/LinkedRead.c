#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next; 
} Node;

int main(void)
{
    
    Node* tail = NULL;
    Node* cur = NULL;
    Node* head = NULL;

    Node *newNode = NULL;
    int readData;

    head = (Node*)malloc(sizeof(Node)); // head points to the empty (dummy) node
    tail = head;                        // tail should point to the empty (dummy) node

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

        tail->next = newNode;
        tail = newNode;
    }

    printf("print all nodes ! \n");
    if(head->next == NULL)
    {
        printf("There is no natural number saved!\n");
    }
    else 
    {
        cur = head;
        while(cur->next != NULL)
        {
            // head has no data, so cur->next should come first!
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }

    printf("\n\n");

    if(head->next == NULL)
    {
        return 0;
    }
    else 
    {
        Node* delNode = head;
        Node* delNextNode = head->next;

        while(delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("Delete %d \n", delNode->data);
            free(delNode);
        }

    }
    free(head);
    return 0;

}