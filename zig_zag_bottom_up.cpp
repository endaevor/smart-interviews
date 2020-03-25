/*
This is same as zig-zag top bottom. but instead of printing elemets we store them in another vector and print it later. use 2 vectors.
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
    int data;
    node* right;
    node* left;
    node(int dat)
    {
        left=right=NULL;
        data=dat;
    }
};

node* create(node* root,int x)
{
    if(root==NULL)
    {
        node* temp=new node(x);
        return temp;
    }
    if(x< root->data)
    {
        root->left=create(root->left,x);
    }
    else
    {
        root->right=create(root->right,x);
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
        
        node* root=NULL;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            root=create(root,temp);
        }
        int count=1;
        
        queue <node*> q;
        vector <int> vec;
        vector <int> ans;
        q.push(root);
        q.push(NULL);
        
        int ncnt=0;
        
        while(1)
        {
            node* temp=q.front();
            if(temp!=NULL)
            {
                vec.push_back(temp->data);
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    count++;
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    count++;
                }
                q.pop();
                count--;
            }
            else
            {
                if(ncnt%2==0)
                {
                    for(auto i=vec.begin();i!=vec.end();i++)
                    {
                        ans.push_back(*i);
                    }
                }
                else{
                    
                    for(auto i=vec.end()-1;i>=vec.begin();i--)
                    {
                        ans.push_back(*i);
                    }
                }
                ncnt++;
                vec.clear();
                q.pop();
                q.push(NULL);
                if(count==0)
                    break;
            }
        }
        for(auto i=ans.end()-1;i>=ans.begin();i--)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
