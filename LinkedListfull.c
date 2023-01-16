#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}NODE;
void addFront(NODE **head, int data);
void addLast(NODE **head, int data);
void addMiddle(NODE **head, int data);
void traverseForward(NODE *head);
NODE* searchNode(NODE *head,int data);

int main(){
	NODE *head=NULL;
	NODE *tmp;
    /*addLast(&head,0);
    traverseForward(head);
    addFront(&head,10);
    traverseForward(head);
    addLast(&head,15);
    traverseForward(head);
    addFront(&head,20);
    traverseForward(head);
    addFront(&head,30);
    traverseForward(head);
    addFront(&head,40);
    traverseForward(head);
    addLast(&head,55);
	traverseForward(head);*/
	addMiddle(&head,35);
	traverseForward(head);
	addMiddle(&head,39);
	traverseForward(head);
	addMiddle(&head,36);
	traverseForward(head);
	addMiddle(&head,37);
	traverseForward(head);
	addMiddle(&head,44);
	traverseForward(head);
	addMiddle(&head,55);
	traverseForward(head);
	addMiddle(&head,50);
	traverseForward(head);
	addMiddle(&head,48);
	traverseForward(head);
	
	tmp = searchNode(head, 36);
	if(tmp==NULL){
		printf("Bulunamadi");
	}
	else{
		printf("Data = %d adres=%p\n",tmp->data,tmp);
	}
	
	deleteNode(&head,35);
	traverseForward(head);
	deleteNode(&head,37);
	traverseForward(head);
	deleteNode(&head,55);
	traverseForward(head);
	return 0;
	
}
NODE* getNode(int data){
	NODE *newNode=(NODE*) malloc(1*sizeof(NODE));
	newNode->data=data;
	newNode->next=NULL;	
	return newNode;
}

NODE* searchNode(NODE *head,int data){
	NODE *tmp=head;
	while(tmp!=NULL && tmp->data!=data){
		tmp = tmp->next;
	}	
	return tmp;
}

void addMiddle(NODE **head, int data){
	NODE *tmp;
	NODE *newNode=getNode(data);
	if(*head==NULL){
		*head=newNode;
	}
	else{
		tmp = *head;
		while(tmp->next!=NULL && tmp->next->data < data ){
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
}

void addFront(NODE **head, int data){
	NODE *newNode=getNode(data);
	newNode->next=*head;
	*head=newNode;
}

void addLast(NODE **head, int data){
	NODE *tmp;
	NODE *newNode=getNode(data);
	
	if(*head==NULL){
		*head=newNode;
	}
	else{
		tmp = *head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	
}

void deleteNode(NODE **head, int data){
	NODE *tmp, *current;
	if((*head)->data == data){
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		printf("%d silindi",data);
	}
	else{
		current=*head;
		while(current->next!=NULL && current->next->data!=data){
			current = current->next;
		}
		if(current->next!=NULL){
			tmp = current->next;
			current->next=current->next->next;
			free(tmp);
			printf("%d silindi",data);
		}
		else{
			printf("Aranan eleman yok");
		}
	}
}

void traverseForward(NODE *head){
	NODE *tmp=head;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void delete_front(NODE **head){ //pop_front
	NODE* tmp;
	if(*head==NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp = NULL;
	}
}

void pop_back(NODE** head_ref) {
  if(*head_ref != NULL) {
    
    //1. if head in not null and next of head
    //   is null, release the head
    if((*head_ref)->next == NULL) {
      *head_ref = NULL;
    } else {
      
      //2. Else, traverse to the second last 
      //   element of the list
      struct Node* temp = *head_ref;
      while(temp->next->next != NULL)
        temp = temp->next;
      
      //3. Change the next of the second 
      //   last node to null and delete the
      //   last node      
      struct Node* lastNode = temp->next;
      temp->next = NULL;
      free(lastNode); 
    }
  }
}
