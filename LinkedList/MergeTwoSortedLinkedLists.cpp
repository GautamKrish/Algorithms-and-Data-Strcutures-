		#include<stdio.h>
		#include<stdlib.h>
			
			struct Node
			{
				int data;
				struct Node* next;
			};
			void push(struct Node**, int);
			void printList(struct Node*);
			struct Node* Merge(struct Node*, struct Node*);
			 
			int main()
			{
				struct Node* headFirst=NULL;
				push(&headFirst, 20);
				push(&headFirst, 15);
				push(&headFirst, 10);
				push(&headFirst, 5);
				push(&headFirst, 3);
				push(&headFirst, 2);
				printf("The first sorted list\n");
				printList(headFirst);
				struct Node* headSecond=NULL;
				push(&headSecond, 65);
				push(&headSecond, 52);
				push(&headSecond, 43);
				push(&headSecond, 27);
				push(&headSecond, 13);
				push(&headSecond, 7);
				printf("\nThe second sorted list\n");
				printList(headSecond);
				struct Node *head = Merge(headFirst, headSecond);
				printf("\nThe merged list\n");
				printList(head);
				return 0;
				
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
			
