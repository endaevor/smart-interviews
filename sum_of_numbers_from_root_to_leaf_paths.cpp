#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node (int x)
    {
        left=right=nullptr;
        data=x;
    }
};

node* create(node* root,int x)
{
    if(root==nullptr)
    {
    root=new node(x);
    return root;
    }
 
    if(x < root->data)
    {
        root->left=create(root->left,x);
    }
    else
    {
        root->right=create(root->right,x);
    }
    return root;
}

void sum(node* root, vector <unsigned long long int> &arr,unsigned long long int num)
{
    if(root==nullptr)
        return;
    unsigned long long int p;
    int temp=root->data,count=0;
    
    if(temp==0)
    {
        p=10;
    }
    else
    {
        while(temp!=0)         // power 
       {
         count++;
         temp=temp/10;
       }
        p=pow(10,count);
    }
    
    if(root->left==nullptr && root->right==nullptr)                      // adding num to vector 
    {
        num=((num*p)%1000000007+(root->data)%1000000007)%1000000007;
        arr.push_back(num);
                                                                         //cout<<num<<"*"<<endl;
        return;
    }
    num=((num*p)%1000000007+(root->data)%1000000007)%1000000007;            // padding zeros to the number and adding root.data
                                                                            //cout<<num<<endl;
    sum(root->left,arr,num);
    sum(root->right,arr,num);
}

int main() {
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int temp;
        node* root=nullptr;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            root=create(root,temp);
        }
        vector <unsigned long long int> arr;
        sum(root,arr,0);
        unsigned long long int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            ans=(ans%1000000007+arr[i]%1000000007)%1000000007;
        }
        cout<<ans<<endl;
    }
    return 0;
}
