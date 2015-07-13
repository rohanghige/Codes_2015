/*
 * =====================================================================================
 *
 *       Filename:  que_case.c
 *
 *    Description:  This is 10 operations on a queue
 *
 *        Version:  1.0
 *        Created:  Monday 13 July 2015 01:34:08  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rohan Ghige (), rohang@marvell.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

void show_list(Node *start){
    while(start){
        printf("Data: %d\n", start->data);
        start = start->next;
    }
}
Node *front, *rear;

int print_choices(){
    printf("\n=====================================\n");
    printf("1: Push a node (at rear))\n");
    printf("2: Push a node (at front))\n");
    printf("3: Display the List\n");
    printf("4: Reverse the list (Non-recursive)\n");
    printf("5: Reverse the list (recursive)\n");
    printf("6: Display list in Reverse the list\n");
    printf("7: Show centre of list\n");
    printf("8: Pop from the list (from front)\n");
    printf("9: Delete element (fromt front)\n");
    printf("10: Delete all link list\n");
    printf("=====================================\n");
    
    return 0;
}

void rev_no_rec(){
    Node *temp = malloc(sizeof(temp));
    Node *temp2 = temp;
    temp->data = 0;
    temp = front;
    while(temp->next){
        temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = front;
        front = temp2;
    }
}

void push_rear( int *in_data){
    Node *temp = malloc(sizeof(temp));
    temp->data = *in_data;
    temp->next = NULL;

    if(front){
        rear->next = temp;
        rear = temp;
    }
    else{
        front = rear = temp;
    }
    printf("Node added succesfully at rear Val: %d]\n", *in_data);
}

void push_front(int *in_data){
    Node *temp = malloc(sizeof(temp));
    temp->data = *in_data;

    if(front){
        temp->next = front;
        front = temp;
    }
    else{
        temp->next = NULL;
        front = rear = temp;
    }
    printf("Node added succesfully at front Val: %d]\n", *in_data);

}

int main(){
    int choice = 0; // Default case
    int data;

    while(1){
        print_choices();
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        if(choice > 10){
            break;
        }
        switch(choice){
            case 1:
                printf("Enter value of node to be added\n");
                scanf("%d", &data);
                push_rear(&data);
                break;
            
            case 2:
                printf("Enter value of node to be added\n");
                scanf("%d", &data);
                push_front(&data);
                break;
                
                
            case 3:
                printf("List is being show_listed\n");
                show_list(front);
                break;

            case 5:
                printf("Reversing the the list (Non-recursive)\n");
                rev_no_rec();
                break;
        }
    }
}
