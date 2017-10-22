#include<stdio.h>
#include<stdlib.h>
typedef struct doublyLL
{
	int data;
	struct doublyLL *next,*prev;
}node;

void print(node *q)
{
	node *temp;
	temp=q;
	while(temp!=NULL)
	{
		printf("  %d\t",temp->data);
		temp=temp->next;
	}
}
void insert_beg(node **q,int num)
{
	node *ptr,*temp;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	ptr->prev=NULL;
	temp=*q;
	if(temp==NULL)
		ptr->next=NULL;
	else
	{
		ptr->next=temp;
		ptr->prev=ptr;
	}
	*q=ptr;
	printf("\nElement %d Inserted Successfully, New Link List is =>\n",num);
	print(*q);
}

void insert_end(node **q,int num)
{
	
	node *ptr,*temp;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=num;
	temp=*q;
	ptr->next=NULL;
	if(temp==NULL)
	{
		*q=ptr;
		ptr->prev=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
				temp=temp->next;
		}		
		temp->next=ptr;
		ptr->prev=temp;
	}
	printf("\nElement %d Inserted Successfully, New Link List is =>\n",num);
	print(*q);
}
void insert_loc(node *q,int num)
{
	node *ptr,*temp;
	int loc,i;
	ptr=(node*)malloc(sizeof(node*));
	ptr->data=num;
	temp=q;
	printf("\nEnter The Location where node is to be Inserted => ");
	scanf("%d",&loc);
	if(loc==1)
	{
		printf("\nPlease Use Insert at Begining Option!!!");
		return;
	}
	for(i=1;i<loc;i++)
	{
		if(temp==NULL)
		{
			printf("\nThe Number Of Nodes in linked list is less then location!!!");
			return;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(temp==NULL)
	{
		printf("\nPlease At the End Option!!!");
		return;
	}
	ptr->prev=temp->prev;
	ptr->next=temp;
	temp->prev->next=ptr;
	temp->prev=ptr;
	printf("\nElement %d Inserted Successfully, New Link List is =>\n",num);
	print(q);
}

void delete(node **q,int num)
{
	node *temp;
	temp=*q;
	int f=0;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			f=1;
			if(temp==*q)
			{
				*q=temp->next;
				temp->next->prev=NULL;
			}
			else
			{
				temp->prev->next=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=temp->prev;
			}
			free(temp);
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(f==0)
	{
		printf("\nElement Not Found!!!");
		return;
	}
	printf("\nElement %d Deleted Successfully, New Link List is =>\n",num);
	print(*q);
}

void traverse(node *q)
{
	printf("\nThe Element Of Linked List are =>\n");
	print(q);
	printf("\n\n");
}
int main()
{
	node *temp,*start,*ptr;
	int choice,i,n,e;
	printf("\n\t\t------ Implementation Of Doubly Link List ------\n");
	printf("\nEnter Number Of Nodes => ");
	scanf("%d",&n);
	if(n<1)
	{
		printf("\nInvalid Number Of Nodes!!!");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		ptr=(node*)malloc(sizeof(node));
		if(i==0)
			start=ptr;
		else
			temp->next=ptr;
		printf("\nEnter the data for Node %d => ",(i+1));
		scanf("%d",&ptr->data);
		temp->next=ptr;
		ptr->prev=temp;
		temp=ptr;
	}
	temp->next=NULL;
	traverse(start);
	do
	{
		printf("\n\t\t------ Operation On Singly Link List ------\n");
		printf("\n1.Insert At The Beginning\n2.Insert At The End\n3.Insert At The Location\n4.Delete a Node\n5.Traversing\n6.Exit");
		printf("\nEnter Your Choice => ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("\nEnter The Node To Be Inserted at beginning => ");
					scanf("%d",&e);
					insert_beg(&start,e);
					break;
			case 2:
					printf("\nEnter The Node To Be Inserted at End => ");
					scanf("%d",&e);
					insert_end(&start,e);
					break;
			case 3:
					printf("\nEnter The Node To Be Inserted at Location =>" );
					scanf("%d",&e);
					insert_loc(start,e);
					break;
			case 4:
					printf("\nEnter The Node To Be Deleted => ");
					scanf("%d",&e);
					delete(&start,e);
					break;
			case 5:
					traverse(start);
					break;
			case 6:
					return 0;
					break;
			default:
					printf("\t\t\t------ Invalid Choice ------");
					break;
		}
	}while(1);
	return 0;
}
