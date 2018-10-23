#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define M 1000000007

using namespace std;



struct S {
    int p;
    int r;
};

int fin(S s[], int i)
{
    if (s[i].p != i)
        s[i].p = fin(s, s[i].p);

    return s[i].p;
}

void uni(S s[], int x, int y)
{
    int xP = fin(s, x);
    int yP = fin(s, y);

    if (s[xP].r < s[yP].r)
        s[xP].p = yP;
    else if (s[xP].r > s[yP].r)
        s[yP].p = xP;
    else
    {
        s[yP].p = xP;
        s[xP].r++;
    }
}

int fi(int parent[], int i)
{
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void un(int parent[], int x, int y)
{
    int xP = fi(parent, x);
    int yP = fi(parent, y);
    parent[xP] = yP;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    S s[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        s[i].p=i;
        s[i].r=0;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(__gcd(a[i], a[j])==1){
                uni(s,i,j);
            }
        }
    }
    unordered_set<int> myS;
    for(int i=0; i<n; i++){
        myS.insert(fin(s, i));
    }
    cout<<myS.size();
    return 0;
}