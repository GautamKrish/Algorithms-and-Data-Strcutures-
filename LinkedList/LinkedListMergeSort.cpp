	#include<stdio.h>
	#include<stdlib.h>
	
	struct Node
	{
		int data;
		struct Node* next;
	};
	
	void push(struct Node**, int);
	void Sort(struct Node**);
	void FrontBackSplit(struct Node*, struct Node**, struct Node**);
	struct Node* Merge(struct Node* , struct Node*);
	void printList(struct Node*);
	
	int main()
	{
		struct Node* head=NULL;
		push(&head, 15);
		push(&head, 10);
		push(&head, 5);
		push(&head, 20);
		push(&head, 3);
		push(&head, 2);
		printList(head);
		Sort(&head);
		printf("\nThe List after sorting\n");
		printList(head);
		return 0;
		
	}
	
	void Sort(struct Node** headRef)
	{
		struct Node* head=*headRef;
		struct Node* front=NULL;
		struct Node* back=NULL;
		
		if((head==NULL)||(head->next==NULL))
		{
			return;
		}
		
		FrontBackSplit(head,&front,&back);
		Sort(&front);
		Sort(&back);
		
		*headRef = Merge(front,back);
		
	}
	
	
	void FrontBackSplit(struct Node* head, struct Node** frontRef, struct Node** backRef)
	{
		struct Node* slow=head;
		struct Node* fast=head->next;
		
		while(fast!=NULL)
		{
			fast=fast->next;
			while(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		
		*frontRef=head;
		*backRef=slow->next;
		slow->next=NULL;
	}
	
	
	void printList(struct Node* head)
	{
		if(head==NULL)
			printf("List is empty");
		else
		{
			while(head!=NULL)
			{
				printf("%d ", head->data);
				head=head->next;
			}
		}
	}
	
	
	struct Node* Merge(struct Node* front, struct Node* back)
	{
		
		if(front==NULL)
			return back;
		else if(back==NULL)
			return front;
		
		struct Node* result=NULL;
		if(front->data<=back->data)
		{
			result=front;
			result->next=Merge(front->next,back);
		}
		else
		{
			result=back;
			result->next=Merge(front,back->next);
		}
		return result;
	}
	
	
	
	void push(struct Node** headRef, int data)
	{
		struct Node* newNode=(struct Node*)(malloc(sizeof(struct Node)));
		newNode->data=data;
		newNode->next=*headRef;
		*headRef=newNode;
	}
