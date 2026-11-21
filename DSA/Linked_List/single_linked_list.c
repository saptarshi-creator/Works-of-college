#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create (int n)
{
    node *head,*q,*r;
    int i;

    printf("\n---------------Creating------------------\n");

    head = (node*)malloc(sizeof(node));

    printf("\nEnter data of head node : ");
    int status = scanf("%d",(&head->data));

    printf("\nStatus of scanf : %d",status);
    printf("\nHead data =%d",head->data);

    head->next = NULL;
    q=head;

    for(i = 0 ; i< n-1 ; i++)
    {
        printf("\nLoop iteration:%d\n",i);

        r = (node*)malloc(sizeof(node));

        printf("\nEnter data of node:");
        scanf("%d",(&r->data));

        r->next = NULL;
        q->next = r;
        q = r;
    }
    return head;

 };


void traverse(node *head)
{
    int count = 0;

    node *p;
    p=head;
    
    printf("\n--------------Traversing--------------\n");

    printf("\nThe linked list is: ");

    while(p!=NULL)
    {
        printf("%d-> ",p->data);
        count++;
        p=p->next;
    }
    printf("NULL\n");
    printf("\n\nTotal number of node is : %d\n\n",count);
    
}

void insertion(node **head, int data, int pos)
{
    int k=1;

    node *p, *q, *newnode;

    newnode = (node*)malloc(sizeof(node));

    newnode -> data = data;

    p = *head;
    q = NULL;

    if(pos == 1)
    {
        newnode -> next = p;
        *head = newnode;
    }
    else{
        while((p!=NULL)&&(k<pos))
        {
            k++;
            q = p;
            p = p->next;
        }

        q->next = newnode;
        newnode->next = p;
    }
}

void deletion(node **head, int pos)
{
    int k=1;
    node *p, *q;

    p=*head;

    if(pos==1)
    {
        (*head) = (*head)->next;
        free(p);
    }

    else
    {
        while((p!=NULL)&&(k<pos))
        {
            k++;
            q=p;
            p=p->next;
        }
        if(p == NULL)
        {
            printf("Position not found");
        }
        else
        {
        q->next = p->next;
        free(p);
        }
    }
}

int main()
{
    int n, choice, pos, data;
    node *head;

    while(1)
    {
        printf("Choice of yours");
        printf("\n1.Creation");
        printf("\n2.Traversing");
        printf("\n3.Insertion");
        printf("\n4.Deletion");
        printf("\n5.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of nodes : ");
            scanf("%d",&n);

            head = create(n);

            break;
        
        case 2:
            traverse(head);
            break;
        
        case 3:
            printf("\nEnter the position to enter the newnode:");
            scanf("%d",&pos);

            printf("Enter data of newnode");
            scanf("%d",&data);

            insertion(&head, data, pos);

            break;

        case 4:
            printf("\nEnter position to delete a node: ");
            scanf("%d",&pos);

            deletion(&head, pos);

            break;

        case 5:
           printf("Exiting the program");         
           exit(0);
        
        default:
            break;
        }
    }    
    return 0;
}