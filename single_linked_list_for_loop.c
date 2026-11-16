#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_node (struct node **head, int data, int position) {
    //Creation of single linked list
    int k = 1;
    struct node *p, *q, *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    // if (new_node == NULL) {
      //  printf("Memory allocation failed\n");
      //  return;
    //}

    new_node->data = data;
    p = *head;

    if (position == 1) {
        new_node->next = p;
        *head = new_node;
        return;
    }
    
    for (k=1; k<position && p!= NULL; k++){
        q=p;
        p=p->next;
        }

      q->next = new_node;
      new_node->next = p;
    
    
}

int main() {
    struct node *head = NULL;

    insert_node(&head, 10, 1);
    insert_node(&head, 20, 2);
    insert_node(&head, 30, 3);

    struct node *p = head;

    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }

    printf("NULL\n");

    return 0;
}