#include<bits/stdc++.h>
using namespace std;

class node
{
public:
int data;
node *left,*right;
};

class bst
{
public:
node *root;
bst()
{
    root=NULL;
}
void create(int a);				
void inorder(node *);			
void preorder(node *);			
void postorder(node *);			
int search(int);		
int height(node *root);				

};
void bst :: create(int a)
{
node *curr;
curr=new node;
curr->data=a;
curr->left=NULL;
curr->right=NULL;
{
if(root==NULL)
    root=curr;
else
{
    node *temp;
    temp=root;
    while(1)
    {
        if(temp->data > curr->data)
        {
            if(temp->left==NULL)
            {
                temp->left=curr;
                break;
            }
            
            else
                temp=temp->left;
        }
        
        else
        {
            if(temp->right==NULL)
            {
                temp->right=curr;
                break;
            }
            else
                temp=temp->right;
        }
    }
}
}
}
void bst :: inorder(node *curr)
{
if(curr!=NULL)
{
inorder(curr->left);
cout<<curr->data<<" ";
inorder(curr->right);
}
}
void bst :: preorder(node *curr)
{
if(curr!=NULL)
{
cout<<curr->data<<" ";
inorder(curr->left);
inorder(curr->right);
}
}
void bst :: postorder(node *curr)
{
if(curr!=NULL)
{
inorder(curr->left);
inorder(curr->right);
cout<<curr->data<<" ";
}
}
int bst :: search(int key)
{
node *curr;
curr=root;
while(curr!=NULL)
{
if(curr->data==key)
    return 1;
else
{
    if(key<curr->data)
    {
        curr=curr->left;
    }
    
    else
    {
        curr=curr->right;
    }
}
}

return -1;
}
int bst :: height(node *root)
{
if(root==NULL)
return 0;
else
{
if (height(root->right) > height(root->left))
{
    return 1+ height(root->right);
}
return 1+ height(root->left);
}
}
int main()
{
bst t;							
int ch,data,flag=0,key,ans;
while(flag==0)
{	
cout<<"1.CREATE\n5.SEARCH\n6.HEIGHT\n7.EXIT\n";
cout<<"enter your choice :- ";
cin>>ch;
switch(ch)
{
case 1:
    cout<<"Enter the data: ";
    cin>>data;
    t.create(data);				
    break;
case 2:
    t.inorder(t.root);			
    break;
case 3:
    t.preorder(t.root);			
    break;
case 4:
    t.postorder(t.root);			
    break;
case 5:
    cout<<"Enter the element to be Searched: ";
    cin>>key;
    ans=t.search(key);			
    if(ans==1)
        cout<<"Element found";
    else
        cout<<"Element NOT found";
    break;
case 6:
    cout<<"Height of the tree is:"<<"\t"<<t.height(t.root);		
    break;
case 7:
    flag=1;	
    break;
default:
    cout<<"ERROR: no such command found";
}
}
}