// code of binary tree -> creation, preoder, postorder, inorder

#include<iostream>
#define MAX 10
using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};


class tree:public node
{
	public:
	node *root;
	tree()
	{
		root=NULL;	
	}	
	void create();
	void preorder_r(node *);
	void postorder_r(node *);
	void inorder_r(node *);
	void preorder_n();
	void inorder_n();
	void postorder_n();
	void copy(node *&tree2,node *&tree);
	void mirror(node *&tree2,node *&tree);
	int countnodes(node *);
	int leafnodes(node *);
};

class stack
{
	public:
		node* item[MAX];
		int top;
		stack()
		{
			top=-1;
		}
		
		void push(node* n)
		{
			item[++top]=n;
		}
			
		
		node* pop()
		{
			return item[top--];
		}
			
		
		int isempty()
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}
		
		int isfull()
		{
			if(top==MAX)
				return 1;
			else
				return 0;
		}
};

void tree::create()
{
	
	int c;
	node *temp,*newnode;
	char ch='y',a;
	while(ch=='Y' || ch=='y')
	{
		cout<<"\nEnter element to be attached: ";
		cin>>c;
		newnode=new node;
		newnode->data = c;
		newnode->right = NULL;
		newnode->left = NULL;
				
		int flag=1;
				
		if(root==NULL)
			root=newnode;
				
		else
		{
			temp=root;
			while(flag==1)
			{
				cout<<"\nEnter \n L for left node \n R for right node: ";
				cin>>a;
						
				if(a=='l'||a=='L')
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						flag = 0;
					}
							
					else 
					{
						temp=temp->left;
						flag = 1;
					}
							
				}
						
				else
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						flag = 0;
					}
							
					else
					{
						temp=temp->right;
						flag= 1;
					}
				}
						
			}
		}
		cout<<"\nDo you want to add more nodes(Y/N): ";
		cin>>ch;
	}
}

void tree::preorder_r(node *curr)
{
	if(curr!=NULL)
	{
		cout<<" "<<curr->data;
		preorder_r(curr->left);
		preorder_r(curr->right);
	}
}

void tree::postorder_r(node *curr)
{
	if(curr!=NULL)
	{
		postorder_r(curr->left);
		postorder_r(curr->right);
		cout<<" "<<curr->data;
	}
}

void tree::inorder_r(node *curr)
{
	if(curr!=NULL)
	{
		inorder_r(curr->left);
		cout<<" "<<curr->data;
		inorder_r(curr->right);
	}
}

void tree::preorder_n()
{
	node *temp=root;
	stack s;
	while(1)
	{
		while(temp)
		{
			cout<<" "<<temp->data;
			s.push(temp);
			temp=temp->left;
		}
	
		if(s.isempty()==1)
		{
			break;
		}
		
		temp=s.pop();
		temp=temp->right;
	}
}

void tree::inorder_n()
{
	node *temp=root;
	stack s;
	while(1)
	{
		while(temp)
		{
			s.push(temp);
			temp=temp->left;
		}
	
		if(s.isempty()==1)
		{
			break;
		}
		
		temp=s.pop();
		cout<<" "<<temp->data;
		temp=temp->right;
	}	
}

void tree::postorder_n()
{
	node *temp=root;
	stack s;
	while(1)
	{
		while(temp)
		{
			s.push(temp);
			s.push(temp);
			temp=temp->left;
		}
	
		if(s.isempty()==1)
		{
			break;
		}
		temp=s.pop();
		if(s.item[s.top]==temp)
		{
			temp=temp->right;
		}
		else
		{
			cout<<" "<<temp->data;
			temp=NULL;
		}
	}	
}

void tree::copy(node *&tree2,node *&tree)
{
	if(tree == NULL)
	{
    	tree2 = NULL;
	}
	else
	{
    	tree2 = new node;
    	tree2->data = tree->data;

    	copy(tree2->left, tree->left);
    	//cout << tree2->data << " ";
    	copy(tree2->right, tree->right);
	}
}

void tree::mirror(node *&tree2,node *&tree)
{
	if(tree == NULL)
	{
    	tree2 = NULL;
	}
	else
	{
    	tree2 = new node;
    	tree2->data = tree->data;

    	mirror(tree2->left, tree->right);
    	//cout << tree2->data << " ";
    	mirror(tree2->right, tree->left);
	}
}

int tree::countnodes(node *root)
{
	static int count=0;
	if(root!=NULL)
	{
		count++;
		countnodes(root->left);
		countnodes(root->right);
	}
	return count;
}

int tree::leafnodes(node *root)
{
	static int count=0;
	if(root==NULL)
		return count;
	if(root->left==NULL && root->right==NULL)
		return ++count;
	leafnodes(root->left);
	leafnodes(root->right);
}


int main()
{
	char ch;
	tree t,t1;
	int n,count;
	while(ch!='n'||ch!='N')
	{
		cout<<"\nEnter \n 1.CREATION OF TREE \n 2.PREORDER RECURSIVE \n 3.POSTORDER RECURSIVE \n 4.INORDER RECURSIVE \n 5.PREORDER NON-RECURSIVE \n 6.INORDER NON-RECURSIVE \n 7.POSTORDER NON-RECURSIVE \n 8.COPY TREE \n 9.MIRROR TREE \n 10.COUNT NUMBER OF NODES \n 11.NUMBER OF LEAF NODES";
		cout<<"\nEnter your choice: ";
		cin>>n;
		switch(n)
		{
			case 1: t.create();
				break;
			
			case 2: 
				t.preorder_r(t.root);
				break;
			
			case 3: 
				t.postorder_r(t.root);
				break;
			
			case 4: 
				t.inorder_r(t.root);
				break;
			
			case 5: 
				t.preorder_n();
				break;
			
			case 6: 
				t.inorder_n();
				break;
			
			case 7: 
				t.postorder_n();
				break;
			
			case 8:
				t.copy(t1.root,t.root);
				t1.inorder_n();
				break;
			
			case 9:
				t.mirror(t1.root,t.root);
				t1.inorder_n();
				break;
			
			case 10:
				count=t.countnodes(t.root);
				cout<<"\nThe number of total nodes are "<<count;
				break;
			
			case 11:
				count=t.leafnodes(t.root);
				cout<<"\nThe number of leaf nodes are "<<count;
				break;
			
		}
		cout<<"\nDo you want to continue(Y/N): ";
		cin>>ch;
	}
	
}


