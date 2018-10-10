#include <bits/stdc++.h>
using namespace std;

int cal(int val, int sttop, int i, bool empty){
  if(empty){
    return val*i;
  }
  else
    return val*(i - sttop - 1);
}

int maxArea(int arr[], int n){
  stack<int> st;
  int ans = INT_MIN;

  int i;
  for(i=0;i<n;){
    if(st.empty() || arr[st.top()] <= arr[i]){
      st.push(i++);
    }
    else{
      while(!st.empty() && arr[st.top()] > arr[i]){
        int top = st.top();
        st.pop();
        int tempArea;

        if(st.empty()){
          tempArea = arr[top]*(i);
        }
        else{
          tempArea = arr[top]*(i - st.top()-1);
        }
        ans = max(ans, tempArea);
      }
    }
  }

  while(!st.empty()){
    int top = st.top();
    st.pop();
    int tempArea;

    if(st.empty()){
      tempArea = arr[top]*(i);
    }
    else{
      tempArea = arr[top]*(i - st.top()-1);
    }
    ans = max(ans, tempArea);
  }

  return ans;
}

int main() {
  int arr[] = {2,1,2,3,1};
  int n = 5;

  cout << maxArea(arr, n);

  return 0;
}
