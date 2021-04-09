// Reversing the linked list using the iterative method
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev,*next;
};
struct node *revdll(struct node *head){
  struct node *a = head;
  struct node *b = head->next;
  a->next = NULL;
  a->prev = b;
  while(b != NULL){
    b->prev = b->next;
    b->next = a;
    a = b;
    b = b->prev;
  }
  head = a;
  return head;
  
}
struct node *createdll(struct node *head,int data){
   struct node *temp = malloc(sizeof(struct node));
   temp->data = data;
   temp->next = NULL;
   temp->prev = NULL;
   struct node *head1 = head;
   if(head == NULL){
       head = temp;
   } 
   else{
       while(head1->next != NULL){
           head1 = head1->next;
       }
       head1->next = temp;
       temp->prev = head1;
   }
   return head;
}
int main(){
    struct node *head = NULL;
    int n,data;
    printf("Enter the no of nodes in the dll");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&data);
        head = createdll(head,data);
    }
    struct node *head2 = head;
    for(int i = 0;i<n;i++){
        printf("%d",head2->data);
        head2 = head2->next;
    }
    head = revdll(head);
    printf("%d",head->data);
    for(int i = 0;i<n;i++){
      printf("%d",head->data);
      head = head->next;
    }
}
