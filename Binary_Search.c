#include <stdio.h>
 
int main()
{
	int i, first, last, middle, n, search, array[100];
	printf("\nPlease Enter the Size of Array =>");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("\nElement No.%d=> ",i+1);
		scanf("%d",&array[i]);
	}
	printf("\nEnter the element to be search =>");
	scanf("%d", &search);
	 
	first = 0;
	last = n - 1;
	middle = (first+last)/2;
	 
	while (first <= last) 
	{
		if (array[middle]<search)
		first=middle+1;    
		else if(array[middle]==search) 
		{
			printf("\nElement %d is Found at index %d ",search,middle+1);
			break;
		}
		else
		last=middle - 1;
		middle=(first + last)/2;
	}
	if (first>last)
		printf("Not found! %d is not present in the list.\n",search);
	return 0;   
}
