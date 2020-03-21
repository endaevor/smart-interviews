#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int idx=0;
int Search(int *in,int data,int low,int high)     // searching each element of pre in IN
{
    for(int i=low;i<=high;i++)
    {
        if(in[i]==data)
            return i;                            // returning index i
    }
    return 0;
}

void postorder(int *pre,int *in,int low,int high)
{
    if(low>high)
    {
        return ;
    }
                                                           //cout<<idx<<endl;
    int root=Search(in,pre[idx++],low,high);
                                                          //cout<<low<<" "<<root<<" "<<high<<endl;
    postorder(pre,in,low,root-1);                         // checking left and right of position i
    postorder(pre,in,root+1,high);
    cout<<in[root]<<" ";
}

int main() {
       int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int n;
        cin>>n;
        int in[n],pre[n];
        for(int i=0;i<n;i++)
        {
            cin>>pre[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>in[i];
        }
        idx=0;
        postorder(pre,in,0,n-1);
        cout<<endl;
    }
    return 0;
}
