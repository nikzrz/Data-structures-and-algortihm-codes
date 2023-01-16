#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}NODE;
// NODE *head; prohibited
int main(){
	NODE *head;
	NODE *tail;
	NODE *tmp;
	NODE node1; node1.data=3;
	NODE node2; node2.data=4;
	NODE node3; node3.data=5;
	NODE node4; node4.data=6;
	
	head = &node1;
	node1.next=&node2;
	node1.prev=NULL;
	node2.next=&node3;
	node2.prev=&node1;
	node3.next=&node4;
	node3.prev=&node2;
	node4.next=NULL;
	node4.prev=&node3;
	tail = &node4;
	
	/*do{
		printf("%d %d\n",head->data, node1.data);
		head = head->next;
	}while(head->next!=NULL);
	
	do{
		printf("%d %d\n",head->data, node1.data);
		head = head->prev;
	}while(head!=NULL);*/
	
	traverseForward(head);
	traverseBackward(tail);
	head = addNode(head);
	
}

void addNode2(Node **head){
	
	
}

Node* addNode(Node *head){
	
	
	return head;
}

void deleteNode(){
	
}

void traverseForward(NODE *head){
	NODE *tmp=head;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void traverseBackward(NODE *tail){
	NODE *tmp=tail;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp = tmp->prev;
	}
	printf("\n");
}
