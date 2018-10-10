#include <bits/stdc++.h>
#define pb push_back

using namespace std;

struct Node{
    long long ans,left,right,len;
    void leaf(int val){
        ans=left=right=val;
        len=1;
    }
    void merge(Node l, Node r){
        ans = l.ans + r.ans + l.right*r.left;
        len = l.len + r.len;
        left = l.left;
        if(l.left==l.len){
            left+=r.left;
        }
        right = r.right;
        if(r.right==r.len){
            right+=l.right;
        }
    }
};

void build(int* a , Node* tree , int st , int en , int node)
{
    if(st == en)
    {
        tree[node].leaf(a[st]);
        return;
    }
    int mid = (st+en)/2;
    build(a , tree , st , mid , 2*node);
    build(a , tree , mid+1 , en , 2*node+1);
    tree[node].merge(tree[2*node] , tree[2*node+1]);
}

Node query(Node* tree, int st , int en , int node , int left , int right)
{
    if(st > right || en < left)
        return {0,0,0,0};

    if(left <= st && en <= right)
        return tree[node];

    else
    {
        int mid = (st+en)/2;
        Node x1 = query(tree , st , mid , 2*node , left , right);
        Node x2 = query(tree , mid+1 , en , 2*node+1 , left , right);
        Node ans;
        ans.merge(x1 , x2);
        return ans;
    }
}

void update(int* a , Node* tree , int st , int en , int node , int idx)
{
    if(st == en)
    {
        tree[node].leaf(a[st]);
        return;
    }
    int mid = (st + en)/2;
    if(idx > mid)
        update(a , tree , mid+1 , en , 2*node+1 , idx);
    else
        update(a, tree , st , mid , 2*node , idx);
    tree[node].merge(tree[2*node] , tree[2*node+1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,l,r;
    cin>>n>>q>>l>>r;
    l--;
    int a[n]={};
    int left[n]={};
    int right[n]={};
    for(int i=0; i<n; i++){
        if(a[i]<=l){
            left[i]=1;
        }
        if(a[i]<=r){
            right[i]=1;
        }
    }
    Node treeLeft[4*n];
    build(left, treeLeft, 0, n-1, 1);
    Node treeRight[4*n];
    build(right, treeRight, 0, n-1, 1);
    while(q--){
        int qt, L, R;
        cin>>qt>>L>>R;
        if(qt==1){
            a[L-1]=R;
            int prev=left[L-1];
            if(R<=l){
                left[L-1]=1;
            }else{
                left[L-1]=0;
            }
            if(prev!=left[L-1])
                update(left, treeLeft, 0, n-1, 1, L-1);
            prev = right[L-1];
            if(R<=r){
                right[L-1]=1;
            }else{
                right[L-1]=0;
            }
            if(prev!=right[L-1])
                update(right, treeRight, 0, n-1, 1, L-1);
        }else{
            long long leftAns = query(treeLeft, 0, n-1, 1, L-1, R-1).ans;
            long long rightAns = query(treeRight, 0, n-1, 1, L-1, R-1).ans;
            cout<<rightAns-leftAns<<endl;
        }
    }
    return 0;
}