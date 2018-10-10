#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    TreeNode * left = NULL;
    TreeNode * right = NULL;
    int val;
};

struct node{
    TreeNode * root;
    int level;
};

void levelorder(TreeNode* A, map<int, vector<int>> &m){
    queue<node> q;
    node root;
    root.root = A;
    root.level = 1;
    q.push(root);
    while(!q.empty()){
        if(q.front().root == NULL){
            q.pop();
            continue;
        }
        m[q.front().level].push_back(q.front().root->val);

        if(q.front().root->left){
            node l;
            l.root = q.front().root->left;
            l.level = q.front().level+1;
            q.push(l);
        }

        if(q.front().root->right){
            node r;
            r.root = q.front().root->right;
            r.level = q.front().level+1;
            q.push(r);
        }

        q.pop();
    }
}

int main(){
    //root
    TreeNode * root = new TreeNode();
    root->val = 1;
    
    //level - 1
    TreeNode * a = new TreeNode();
    a->val = 2;
    TreeNode * a1 = new TreeNode();
    a1->val = -9;

    //level - 2
    TreeNode * b  = new TreeNode();
    b->val = 3;
     
    TreeNode * c  = new TreeNode();
    c->val = 4;

    //level - 3
    TreeNode * d  = new TreeNode();
    d->val = 5;

    root->left = a1;
    root->right = a;

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = NULL;

    map<int, vector<int>> m;
    levelorder(root, m);

    for(auto x:m){
        if(x.first%2 == 1){
            cout << x.first <<"-->"; 
            for(auto y:x.second){
                cout << y << " ";
            }
        }
        else{
            cout << x.first <<"-->"; 
            for(auto it = x.second.rbegin(); it != x.second.rend(); it++){
                cout << *it << " ";
            }
        }
        cout << endl;
    }
    return 0;
}