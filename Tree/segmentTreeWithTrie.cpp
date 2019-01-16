#include <bits/stdc++.h>
#define MAXN 300001
typedef long long ll;
using namespace std;

struct TrieNode{
    TrieNode* left;
    TrieNode* right;
};

void combine(TrieNode* &root, TrieNode* root1, TrieNode* root2){
    if(root1==NULL && root2==NULL){
        return;
    }
    root = new TrieNode();
    if(root1==NULL){
        root = root2;
        return;
    }
    if(root2==NULL){
        root = root1;
        return;
    }
    combine(root->left, root1->left, root2->left);
    combine(root->right, root1->right, root2->right);
}

void insert(int x, TrieNode* root){
    TrieNode* curr = root;
    for(int i=31; i>=0; i--){
        int b = (x>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }else{
            if(!curr->right){
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

int query(int pref, TrieNode* root){
    int maxVal = 0;
    TrieNode* curr = root;
    for(int i=31; i>=0; i--){
        int b = (pref>>i)&1;
        if(b==0){
            if(curr->right){
                maxVal += (1<<i);
                curr=curr->right;
            }else{
                curr=curr->left;
            }
        }else{
            if(curr->left){
                maxVal += (1<<i);
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }
    }
    return maxVal;
}

struct Node{
    TrieNode* root;
    void leaf(int val){
        root = new TrieNode();
        insert(val,root);
    }
    void merge(Node l, Node r){
        combine(root, l.root, r.root);
    }
};
int a[MAXN];
Node tree[4*MAXN];

void build(int st , int en , int node) {
    if(st == en){
        tree[node].leaf(a[st]);
        return;
    }
    int mid = (st+en)/2;
    build(st , mid , 2*node);
    build(mid+1 , en , 2*node+1);
    tree[node].merge(tree[2*node] , tree[2*node+1]);
}

int query(int st , int en , int node , int left , int right, int pref) {
    if(st > right || en < left)
        return 0;
    if(left <= st && en <= right){
        return query(pref,tree[node].root);
    }else{
        int mid = (st+en)/2;
        int x1 = query(st , mid , 2*node , left , right, pref);
        int x2 = query(mid+1 , en , 2*node+1 , left , right, pref);
        return max(x1,x2);
    }
}

void print(TrieNode* root, int x=0){
    if(!root){
        return;
    }
    print(root->left, 0);
    cout<<x<<" ";
    print(root->right, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        l--;
        r--;
        cout<<query(0,n-1,1,l,r,x)<<endl;
    }
    return 0;
}
