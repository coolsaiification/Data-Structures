#include<bits/stdc++.h>
using namespace std;

struct trieNode{
  trieNode* left;
  trieNode* right;
};

void insert(int x, trieNode* root){
    trieNode* curr = root;
    for(int i=31; i>=0; i--){
        int b = (x>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr = curr->left;
        }else{
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

int query(int pref, trieNode* root){
    int maxVal = 0;
    trieNode* curr = root;
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

void print(trieNode* root, int x=0){
  if(!root){
    return;
  }
  print(root->left, 0);
  cout<<x<<endl;
  print(root->right, 1);
}

int main() {
  int t;
  cin>>t;
  for(int tit=1; tit<=t; tit++){
    int n;
    cin>>n;
    trieNode* root = new trieNode();
    int prefix=0;
    int maxXor=0;
    for(int i=0; i<n; i++){
      int x;
      cin>>x;
      prefix = prefix ^ x;
      maxXor = max(maxXor, prefix);
      //cout<<prefix<<endl;
      insert(prefix, root);
      //print(root);
      //cout<<query(prefix, root)<<endl;
      //cout<<endl;
      maxXor = max(maxXor, query(prefix, root));
    }
    cout<<"Case "<<tit<<": "<<maxXor%<<endl;
  }
}