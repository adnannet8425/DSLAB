#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *r){
	if(r!=NULL){
		traverse_inorder(r->left);
		printf("%d\t",r->data);
		traverse_inorder(r->right);
	}
}

void insert(node **r,int num){
	node *temp,*ptr;
	temp=*r;
	
	if(temp==NULL){
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
		*r=ptr;
	}
	else{
		if(num>temp->data){
			insert(&temp->right,num);
		}
		else{
			insert(&temp->left,num);
		}
	}
}
int search_bst(node *r,int num){
	if(r==NULL)
		return 0;
	else{
		if(r->data==num)
			return 1;
		else{
			if(num>r->data)
				return search_bst(r->right,num);
			else
				return search_bst(r->left,num);
		}
	}
}

void search_node(node **x,node *root,node **parent,int num,int *f){
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			*f=1;
			*x=temp;
			return;
		}
		*parent=temp;
		if(num>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}
}
void delete(node **r,int num){
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;x=NULL;xsucc=NULL;
	temp=*r;
	search_node(&x,temp,&parent,num,&f);
	if(f==0){
		printf("\nThe Element %d id not found",num);
		return;
	}
	//x has no child
	if(x->left==NULL&&x->right==NULL)
	{
		if(x->data>parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	//x has left child
	else if(x->left!=NULL&&x->right==NULL)
	{
		if(x->data>parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
	}
	//x has right child
	else if(x->right!=NULL&&x->left==NULL)
	{
		if(x->data>parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}
	//x has both left and right child
	else if(x->left!=NULL&&x->right!=NULL)
	{
		xsucc=x->right;
		parent=x;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		x->data=xsucc->data;
		x=xsucc;
		if(x->data>parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	free(x);
}

int main(){
	node *root;
	root =NULL;
	int c,no;
	do
	{
		printf("\n\t\t------ Implementation Of Binary Search Tree ------\n");
		printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Search\n5.Exit\n");
		printf("\nPlease Enter Your Choice => ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nPlease Enter the Element to be Inserted => ");
				scanf("%d",&no);
				insert(&root,no);
				break;
			case 2:
				printf("\nPlease Enter the Element to be Deleted => ");
				scanf("%d",&no);
				delete(&root,no);
				break;
			case 3:
				traverse_inorder(root);
				break;
			case 4:
				printf("\nPlease Enter the Element to be Search => ");
				scanf("%d",&no);
				if(search_bst(root,no)==1)
				printf("\nThe number is found");
				else
				printf("\nThe number is not found");
				break;
			case 5:
				exit(0);
			default:
				printf("\t\t\t------ Invalid Choice ------");
				break;
			}
		}while(1);
	return 0;
}
	
