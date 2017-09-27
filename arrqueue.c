#include<stdio.h>
#define MAX_SIZE 2

int queue[MAX_SIZE],rear=-1,front=-1;

int isFull()
{
	return rear==MAX_SIZE-1;
}
int isEmpty()
{
	return rear==-1&&front==-1;
}
void insert(int e)
{
	if(!isFull())
	{
		if(isEmpty())
		{
			front=0;
		}
		queue[++rear]=e;
		printf("\nElement %d is successfully inserted!!!\n",e);
	}
	else
	{
		printf("\nQueue is Full");
	}
}
int delete()
{
	int d;
	if(!isEmpty())
	{
		d=queue[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			d=queue[front++];
			return d;
		}
		return d;
	}
	else
	{
		printf("\nQueue Is Empty\n");
		return -1;
	}
}
 void display()
{
	int i;
	if(!isEmpty())
	{
		printf("Element Of Queue is => ");
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
	else 
	printf("\nQueue is Empty\n");
}
int main()
{
	int choice,e;
	do
	{
		printf("\n\t\t --------Implemention Of Queue Using Array --------");
		printf("\n1)Insert\n2)Delete\n3)Display\n4)Exit");
		printf("\nPlease Enter Your Choice => ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nPlease Enter the Element to be Inserted => ");
				scanf("%d",&e);
				insert(e);
				break;
			case 2:
				e=delete();
				printf("\nThe Element Deleted is => %d",e);
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("\nInvalid Choide");
				break;
		}
	}while(1);
	return 0;
}
