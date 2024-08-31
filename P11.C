#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
void insert(struct node **head,int ele){
	struct node *new1;
	new1 = (struct node*)malloc(sizeof(struct node));
	if(!new1){
		printf("memory not\n");
	}
	else{
		if(*head == NULL){
			new1 -> data = ele;
			new1 -> next = NULL;
			*head = new1;
		}
		else{
			new1 -> data = ele;
			new1 -> next = *head;
			*head = new1;
		}
			printf("inserted %d\n",new1 -> data);
	}
}
int del(struct node **head){
	int ele;
	if(*head == NULL){
		printf("link list is empty\n");
	}
	else{
		struct node *curr;
		curr = *head;
		ele = curr -> data;
		*head = curr -> next;
		free(curr);
	}
	return ele;
}
void modify(struct node *head,int ele){
	if(head == NULL){
		printf("list is empty\n");
	}
	else{
		int ele1;
		while(head != NULL){
			if(head -> data == ele){
				printf("enter your new value :- ");
				scanf("%d",&ele1);
				head -> data = ele1;
				printf("modify..\n");
			}
			head = head -> next;
		}
	}
}

void display(struct node *head){
	if(head == NULL){
		printf("list is empty\n");
	}
	else{
		while(head != NULL){
			printf("%d ->",head -> data);
			head = head -> next;
		}
	}
	printf("NULL\n");
}
void main(){
	int choice,ele;
	struct node *head = NULL;
	clrscr();
	while(1){
		printf("\n1.insert \n2.delete \n3.modify \n4.display \n5.exit \nenter your choice :- ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter value :-");
				scanf("%d",&ele);
				insert(&head,ele);
				break;
			case 2:
				printf("deleted :- %d\n",del(&head));
				break;
			case 3:
				printf("enter value you want to change :-");
				scanf("%d",&ele);
				modify(head,ele);
				break;
			case 4:
				display(head);
				break;
			case 5:
				exit(0);
			default:
				printf("invalid choice\n");
				break;
		}
	}
}