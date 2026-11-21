#include <stdio.h>
#include <stdlib.h>


typedef struct double_linkedlist
{
    int data;
    struct double_linkedlist *next;
    struct double_linkedlist *prev;
    
} dnode;



//Creation of Double Linked List

dnode *create (int n)
{
    dnode *head, *temp, *newnode;

    int i;

    if(n <= 0)
        return NULL;

    head = (dnode *)malloc(sizeof (dnode));

    printf("\nEnter the Head data: ");
    scanf("%d", &(head->data));


    head->next = NULL;
    head->prev = NULL;
    temp = head;
    

    //For the other nodes

    for(i=0; i<n-1; i++)
    {
        newnode = (dnode *)malloc(sizeof (dnode));

        printf("\nEnter the data: ");
        scanf("%d", &(newnode->data));

        newnode->next = NULL;
        newnode->prev = temp;

        temp->next = newnode;   
        temp = newnode;

    }
    return head;
}




//Insertion of Double Linked List

void insertion(dnode **head, int data, int pos)
{
    int k = 1;

    dnode *newnode, *temp;
    temp = *head;

    newnode = (dnode*)malloc(sizeof(dnode));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    //At the beginning
    
    if(pos == 1)
    {
        newnode->next = *head;
        
        if(*head)
        {
            (*head)->prev = newnode;
        }    

        *head = newnode;
        return;
        
    }

    if(*head == NULL)
    {
        printf("\nInvalid position!\n");
        free(newnode);
        return;
    }

    //At any position (except first) i.e. the middle and the end
    else
    {
        while((k<pos-1) && (temp->next != NULL))
        {
            temp = temp->next;
            k++;
            
        }

        // Invalid position

    if(k != pos - 1)
    {
        printf("\nInvalid position!\n");
        free(newnode);
        return;
    }



        newnode->next = temp->next;
        newnode->prev = temp;

        if(temp->next)
        {
            temp->next->prev = newnode;
        }

        temp->next = newnode;
        return;
        

    }

}


void deletion(dnode **head, int pos)
{
    dnode *temp;
    temp = *head;

    int k = 1;

      if(*head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }


    //At the beginning
    if(pos == 1)
    {
        (*head) = (*head)->next;

        if(*head!=NULL)
        {
            (*head)->prev = NULL;
        }    
        free(temp);
        return;
        
        
    }

    else
    {
        while((k<pos) && (temp->next!=NULL))
        {
            k++;
            temp = temp->next;
        }

         // Invalid position

        if(k != pos)
          {
             printf("\nInvalid position!\n");
             return;
          }
        
        temp->prev->next = temp->next;      

        if(temp->next)
        {
            temp->next->prev = temp->prev;
        }
        free(temp);
        return;         


    }
}


void traverse(dnode *head)
{
    int count = 0;
    dnode *temp = head;

    printf("\n---------Forward Traversing------------\n");

    // Move forward
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        count++;

        // Move to next node
        temp = temp->next;
    }

    printf("NULL\n");
    printf("TOTAL NUMBER OF NODES IS %d\n", count);


    // Move to last node
    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }


    printf("\n---------Backward Traversing------------\n");

    // Move backward using prev
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);

        temp = temp->prev;
    }

    printf("NULL\n");
}


int main()
{
    int n, choice, pos, data;

    dnode *head = NULL;


    while(1)
    {
        printf("\nEnter your choice: ");
        printf("\n1. Creation");
        printf("\n2. Insertion");
        printf("\n3. Deletion");
        printf("\n4. Traversing");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);


        switch (choice)
        {
            case 1:

            printf("\nEnter number of nodes: ");
            scanf("%d",&n);

            head = create(n);
            break;


            case 2:

            printf("\nEnter the position to enter the node: ");
            scanf("%d", &pos);

            printf("Enter the data of the node: ");
            scanf("%d",&data);

            insertion(&head, data, pos);
            break;


            case 3:

            printf("\nEnter the position to delete the node: ");
            scanf("%d",&pos);

            deletion(&head, pos);
            break;


            case 4:

            traverse(head);
            break;


            case 5:
            printf("\nExiting the program ...........");
            exit(0);


            default :
            break;
        }
    }
    return 0;
}