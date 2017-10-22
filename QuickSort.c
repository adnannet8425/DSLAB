#include<stdio.h>
#define MAX_SIZE 100
int split(int arr[],int lower,int upper)
{
	int pivot=lower,a=lower+1,b=upper,temp;
	while(b>=a)
	{
		while(arr[a]<arr[pivot])
			a++;
		while(arr[b]>arr[pivot])
			b--;
		if(b>a)
		{
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
	}
	temp=arr[pivot];
	arr[pivot]=arr[b];
	arr[b]=temp;
	return b;
}

void Quick_sort(int a[],int lower,int upper)
{
	int i;
	if(lower<upper)
	{
		i=split(a,lower,upper);
		Quick_sort(a,lower,i-1);
		Quick_sort(a,i+1,upper);
	}
}

int main()
{
	int i,arr1[MAX_SIZE],n;
	printf("\nPlease Enter The Size of Array => ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Element No.%d => ",i+1);
		scanf("%d",&arr1[i]);
	}
	Quick_sort(arr1,0,n-1);
	printf("\nSorted Array Using Quick Sort\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement No.%d => %d",i+1,arr1[i]);
	}
	return 0;
}
