/*
Given an array of unique elements, construct a Binary Search Tree and find the number of nodes at a distance K from the given source node S. Distance is defined as the number of edges between 2 nodes.
Solved in O(N) i guess and try to revise with an example.
*/
#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int ans=0;                                 //global ans

class node
{
    public:
    node* left;
    node* right;
    int data;
    node (int x)
    {
        left=right=NULL;
        data=x;
    }
};

node* create(node* root,int x)
{
    if(!root)
    {
        root=new node (x);
        return root;
    }
    if(root->data > x)
    {
        root->left=create(root->left,x);
    }
    else
    {
        root->right=create(root->right,x);
    }
    return root;
}

void distance(node* root,int s,int k,int meter)                 // distance from any node
{
    if(!root)
    {
        return;
    }
    if(root->data==s || meter>k)
    {
        return ;
    }
    else if(meter==k)
    {                                                    //cout<<root->data<<" "<<dist<<" "<<k<<endl;
        ++ans;
        return;
    }
    else
    {           
        distance(root->left,s,k,++meter);
        distance(root->right,s,k,meter);
    }
}

int traverse(node* root,int s,int k)
{
    if(!root)                                          // no need of it in this question, but i wrote it anyway
    {
        return 0;
    }
    
    if(k==0)                                          // exception
    {
        ++ans;
        return 0;
    }
    
    if(root->data==s)                                
    {   
        int dist=0;
        ++dist;                                       // dist at S is 0, passing dist=1 for pervious node
        distance(root->left,s,k,1);
        distance(root->right,s,k,1);
        return dist;
    }
    int dist;
    if(s < root->data)
    {
         dist=traverse(root->left,s,k);
        if(dist==k)
        {
            ++ans;
            return ++dist;                        //1. doest matter what we return unless it is greater than dist
        }
        ++dist;
        distance(root->right,s,k,dist);
    }
    else
    {
        dist=traverse(root->right,s,k);
        if(dist==k)
        {
            ++ans;
            return ++dist;                      //2. doest matter what we return unless it is greater than dist
        }
        ++dist;
        distance(root->left,s,k,dist);
    }
    return dist;                                // return dist is correct unlike 1. & 2. , we have to return dist
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n,s,k;
        cin>>n>>s>>k;
        int temp;
        node* root=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            root=create(root,temp);
        }      
                                                                              //cout<<"root "<<root->data;
        ans=0;
        traverse(root,s,k);

        cout<<ans<<endl;
    }
    return 0;
}
