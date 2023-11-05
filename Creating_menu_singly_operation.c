#include<stdio.h>
#include<stdlib.h>

struct node {
    int val,data,value;
    struct node* next;
};
struct node *head = NULL, *tail = NULL;


int main(){

int choice ;
printf("\nTHE PROGRAME IS STARTING..........\n");
printf("\n-----------------------------------------------------\n");
printf("\n HERE IS THE LIST OF PROGRAMES \n");
printf("\n-----------------------------------------------------\n");
printf("1.insert new node : \n");
printf("2.insert new node at the beginning : \n");
printf("3.insert new node at any position : \n");
printf("4.delete node from last position : \n");
printf("5.delete node at the beginning :\n");
printf("6.delete node at any position : \n");
printf("7.reverse linked list : \n");
printf("8.remove duplicate data from the linked list : \n");
while(1){
        printf("\n--------------------------------------\n");
   printf("\n\nPlease enter your choice :\n");
   scanf("%d",&choice);
   switch(choice){
   case 1:
     printf(create());

    break;

case 2:
    printf(insertAtBeginning());

    break;

case 3:
printf(insertAtrandom());

    break;
case 4:
printf(delete_last_node());
    break;

case 5:
printf(delete_first_node());
    break;

case 6:
printf(delete ());

    break;

case 7:
printf(reverse());
    break;

case 8:
printf(delete_dup());

    break;
default :
printf("ERROR!!! PLEASE CHOOSE AGAIN ->\n");
break;
}


}
    return 0;
}


void create() {
    struct node *curr;
    int n, i;

    printf("enter the number of elements: ");
    printf("\n---------------------------------------\n");

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d:", i + 1);
        scanf("%d", &value);

        curr = (struct node *)malloc(sizeof(struct node));
        curr->val = value;
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
            tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
    }
   display();
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");

}



void display(){
    struct node *curr;
curr=head;
printf("the elements are --->");
while(curr!=NULL){
    printf("%d-->",curr->val);
    curr =curr->next;

}
}

void insertAtBeginning() {
  struct node *curr, *check;
 check = head;
 if(check != NULL){
 int value;
   printf("\n\nEnter the value that you want to insert in the starting: ");
   printf("\n-----------------------------------------------------\n");

   scanf("%d",&value);
   curr = (struct node*)malloc(sizeof(struct node));
   curr -> val = value;
   curr -> next = NULL;
if(head == NULL){
    head = curr;
    tail = curr;
   }
else{
    curr -> next = head;
    head = curr;
 }
 update();
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");

 }
 else
     printf("LINK LIST is empty!! Create it again!!");

}

void insertAtrandom() {
    struct node *curr , *temp1, *temp2, *check;
 check = head;
 if(check != NULL){
 int value,pos;

   printf("\n\nEnter the value that you want to insert: ");
   scanf("%d",&value);
   curr = (struct node*)malloc(sizeof(struct node));
   curr -> val = value;
   curr -> next = NULL;
   printf("\nEnter the position that you want to insert: ");
   scanf("%d",&pos);

if(head == NULL){
    head = curr;
    tail = curr;
}
else{
      temp1 = head;
      for(int i = 1; i<=pos-1 ; i++){
        temp2 = temp1;
        temp1 = temp1 -> next;
      }
    temp2 -> next = curr;
    curr -> next = temp1;
 }
 update();
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");

}}

void delete_last_node(){
struct node *curr,*temp;
    if(head != NULL){
    curr = head;
    while(curr -> next != NULL){
        temp = curr;
        curr = curr -> next;
    }
    temp -> next = NULL;
    free(curr);
     update();
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");

   }

}


void delete_first_node(){

struct node *temp;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
     temp = head;
        head = head->next;

       // printf("\nData deleted = %d\n",temp->data);

        /* Clears the memory occupied by first node*/
        free(temp);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");

    }
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");

    update();
}
void delete() {
    int val;
    struct node *tempAddress, *preAddress, *address;

    printf("\nEnter the value of the node you want to delete: ");
    scanf("%d", &val);

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Check if the node to be deleted is the head node
    if (head->val == val) {
        tempAddress = head;
        head = head->next;
        free(tempAddress);
        printf("Node with value %d deleted.\n", val);
        display(); // Display the updated list
        return;
    }

    preAddress = head;
    address = head->next;

    while (address != NULL && address->val != val) {
        preAddress = address;
        address = address->next;
    }

    if (address == NULL) {
        printf("Node with value %d not found in the list.\n");
        return;
    }

    preAddress->next = address->next;
    free(address);
    printf("Node with value %d deleted.\n", val);
    update();
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");

}

void reverse() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev; // Update the head to point to the new first node (previous tail).
    display();   // Display the reversed list.
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");

}

void delete_dup() {
    struct node* current = head;

    while (current != NULL) {
        struct node* runner = current;

        while (runner->next != NULL) {
            if (runner->next->val == current->val) {
                struct node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
         printf("\n\n ***PROGRAME ENDS***\t\n!! THANK YOU!!\n");
    display();
}
void update(){
    struct node *curr;
curr=head;
printf("the elements are ->");
while(curr!=NULL){
    printf("%d->",curr->val);
    curr =curr->next;

}

}

