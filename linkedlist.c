#include<stdio.h>
struct node{
	int data;
	struct node *next;
};	
void print(struct node *n)
{
	while(n!=NULL)
	{
		printf("%d",n->data);
		n=n->next;
		}
		
}
//insert ele at starrting
void push(struct node** headref,int newdata)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=(*headref);
	(*headref)=newnode;
	
}
//add ele in middle
void insertafter(struct node* pnode,int newdata)
{
	if(pnode==NULL)
	{
		printf("cannot be inserted");
		return;
		}
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=newdata;
	newnode->next=pnode->next;
	pnode->next=newnode;
}
//inserting at end
void append(struct node** headref,int newdata)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	struct node *last=*headref;
	newnode->data=newdata;
	newnode->next=NULL;
	if(*headref==NULL)
	{
		*headref=newnode;
		return;
		}
		while(last->next!=NULL)
		last=last->next;
		last->next=newnode;
		//return;
}
//delete a node
void delete(struct node** headref,int key)
{
	struct node *temp=*headref,*prev;
	if(temp!=NULL && temp->data==key)
	{
        (*headref)=temp->next;
		free(temp);
		return;
		}
		while(temp!=NULL && temp->data!=key)
		{
			prev=temp;
			temp=temp->next;
			}
			if(temp==NULL)
			return;
			prev->next=temp->next;
			free(temp);
			
}
// count the no of nodes
int getcount(struct node* head)
{
	if(head==NULL)
	return 0;
	return (1+getcount(head->next));
	}
//add someele to all nodes
void add(struct node *node,int x)
{
	while(node!=NULL)
	{
		node->data=node->data+x;
		node=node->next;
		}
}
	




int main(){
	struct node* head=NULL;
	struct node* second=NULL;
	struct node* third=NULL;
	struct node* newhead=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	print(head);
	printf("\npush op\n");
	push(&head,5);
	print(head);
	printf("\n inserting in middle \n");
	insertafter(second,7);
	print(head);
	printf("\n inserting at last\n");
	append(&head,8);
	print(head);
	printf("\n delete op\n");
	delete(&head,3);
	print(head);
	printf("\n get the no of count %d",getcount(head));
	printf("\n after adding");
	add(head,1);
	print(head);
}


