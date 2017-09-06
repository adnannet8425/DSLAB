#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;
//return true if stack os full else false
int isFull()
{
	return top=MAX_SIZE-1;
}
//return true if else is empty else return false
int isEmpty()
{
		return top==-1;
}
//return element at the top of stack
int peek()
{
	if(!isEmpty())
		return stack[top];
	else
	{
		printf("\nStack is Empty. Returning -1");
		return -1;
	}	
}	
void push(int e)
{
	if(!isFull())
	{
		stack[++top]=e;
		printf("\nElement is Successfully Inserted");
	}
	else
	{
		printf("\nStack Overflow. Element Cannot be Inserted");
	}
}
int pop()
{
	int d;
	if(!isEmpty())
	{
		d=stack[top--];
		return d;
	}
	else
	{
		printf("\nStack Underflow. No Element to Delete. Returning -1");
		return -1;
	}
}

int main()
{
	int choice,e;
	do
	{
		printf("\nPlease Enter Your Choice");
		printf("\n1.Push\n2.Pop\n3.Peak\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
				case 1:
					printf("\nPlease Enter the Element to be Inserted: ");
					scanf("%d",&e);
					push(e);
					break;
				case 2:
					e=pop();
					printf("\nElement Deleted is :%d",e);
					break;
				case 3:
					e=peek();
					printf("\nElement at the Top of Stack is :%d",e);
					break;
				case 4:
					return 0;
					break;
				default:
					printf("\nInvalid Choice");
					break;
		}
	}while(1);
	return 0;
}
