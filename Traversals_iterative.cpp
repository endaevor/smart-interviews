#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *right,*left;
};

node* newnode(int d)
{
    node* root= (node*)malloc(sizeof(node));
    root->data=d;
    root->left=root->right=NULL;
    return root;
}

node* treecreate(node *root,int n)
{
    
    if(root==NULL)
    {
        node *temp=newnode(n);
        return temp;
    }
    if(n< root->data)
    {
        root->left=treecreate(root->left,n);
    }
    else
    {
        root->right=treecreate(root->right,n);
    }
    return root;
}
/*
In Preorder (root,left,right), print node data, push into stack , when root=null, stacktop->right , pop top. 
*/
void preorder(node *root)
{
    stack <node*>st;
    while(root!=NULL || !st.empty())
    {
        if(root)
        {
            st.push(root);
            cout<<(root->data)<<" ";
            root=root->left;
        }
        else
        {
            root=st.top();
            st.pop();
            root=root->right;
        }
    }
}
/*
In Inorder (left,root,right), store root in stack, when root=null ,print root data, stacktop->right , pop stack.
*/
void inorder(node *root)
{
    stack<node* > st;
    while(true)
    {
        if(root==NULL)
        {
            if(st.empty())
            break;
            root=st.top();
            st.pop();
            cout<<(root->data)<<" ";
            root=root->right;
        }
        else
        {
            
            st.push(root);
            root=root->left;
        }
    }
}
/*
In Postorder (left,right,root), here we can solve it using two stacks , instead we are using single stack, since we have to print 
root->data in the end.
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push NULL and then root to stack.
    b) Set root as root's left child.
2.2 Now pop stack in temp1 & temp2=stacktop(dont pop for temp2). 
    a) If temp2==NULL the it means that we have to traverse
       right(i.e we are not backtraking from rightside). now pop stack for the second time and re-push temp1 into the 
       stack.  (this is to know when you should pop and when you should print.)
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
Check code for edge case.
This is little tricky but you'll get it.
*/
void postorder(node *root)
{
    stack <node*> st;
    while(root!=NULL || !st.empty())
    {
        if(root)
        {
            st.push(NULL);
            st.push(root);
            root=root->left;
        }
        else
        {
            node* top1=st.top();
            st.pop();
            node* top2;
            if(!st.empty())
            top2=st.top();
            else
            top2=top1;
            if(top2==NULL)
            {
                st.pop();
                st.push(top1);
                root=top1->right;
            }
            else
            {
                cout<<(top1->data)<<" ";
            }
        }
    }
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        node *root=NULL;
        for(int i=0;i<n;i++)
        {
            root=treecreate(root,arr[i]);
        }
        preorder(root);
        cout<<endl;
        inorder(root);
        cout<<endl;
        postorder(root);
        cout<<endl<<endl;
        delete root;
    }
    return 0;
}
