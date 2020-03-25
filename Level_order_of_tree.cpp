/*
we use a queue with null pointer. first we push root and null into the queue then we print root data and push left and right nodes of a root in tree untill we find null(pop node when children are pushed into queue). print newline & pop null and push null back again when we find null. keep track of nodes in queue using count variable and terminate when count=0. when left or right is null skip that node, dont push null into the queue.
*/
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
    public:
    node *left;
    node *right;
    int data;
    node(int x)
    {
        left=right=NULL;
        data=x;
    }
};

node* create(node* root,int data)
{
    if(root==NULL)
    {
        node *temp=new node(data);
        return temp;
    }

    if(data < root->data)
    {
        root->left=create(root->left,data);
    }
    else
    {
        root->right=create(root->right,data);
    }
    return root;
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int temp;
        node *root=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            root=create(root,temp);
        }
        queue <node*> qu;
        qu.push(root);
        qu.push(NULL);
        int count=1;
        while(1){
            
            if(count==0)
                break;
            
            node *temp=qu.front();
            
             if(temp!=NULL)
             {
                 cout<<temp->data<<" ";
                 if(temp->left !=NULL)
                 {
                     qu.push(temp->left);
                     count++;
                 }
                 if(temp->right !=NULL)
                 {
                     qu.push(temp->right);
                     count++;
                 }
                
                 qu.pop();
                 count--;
             }
             else
             {
                 cout<<endl;
                 qu.pop();
                 qu.push(NULL);
             }
        }
        cout<<endl<<endl;
    }
    return 0;
}
