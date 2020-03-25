/*
This is same as level order top to bottom. instead of printing the data we store them in a stack and print.(null=newline in stack).
*/
#include <queue>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    node(int x)
    {
        right=left=NULL;
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
        node *root=NULL;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            root=create(root,temp);
        }
        
        queue <node*> qe;
        stack <node*> stak;
        
        qe.push(root);
        qe.push(NULL);
        
        int count=1;
        
        while(1)
        {
            if(count==0)
                break;
            node *temp;
            temp=qe.front();
            if(temp!=NULL)
            {
                stak.push(temp);
                if(temp->right!= NULL)
                {
                    qe.push(temp->right);
                    count++;
                }
                if(temp->left!= NULL)
                {
                    qe.push(temp->left);
                    count++;
                }
                qe.pop();
                count--;
            }
            else
            {
                stak.push(NULL);
                qe.pop();
                qe.push(NULL);
            }
            
        }
        while(!stak.empty())
        {
            if(stak.top()==NULL)
            {
                cout<<endl;
                stak.pop();
            }
            else
            {
                node* temp;
                temp=stak.top();
                cout<<temp->data<<" ";
                stak.pop();
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}
