#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

struct Node* printMiddle(struct Node *head) 
{ 
	struct Node *slow = head; 
	struct Node *fast= head; 

	if (head!=NULL) 
	{ 
		while (fast != NULL && fast->next != NULL) 
		{ 
			fast = fast->next->next; 
			slow = slow->next; 
		} 
		return slow
	} 
}
