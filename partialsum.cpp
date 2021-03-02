#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, k;
vector<int> vec;

bool dfs(int i, int sum){
  if(i == n){
    return sum == k;
  }
  if(dfs(i+1, sum)){
    return true;
  }
  if(dfs(i+1, sum+vec.at(i))){
    return true;
  }
  return false;
}
 
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    vec.push_back(a);
  }
  cin >> k;
  if(dfs(0,0)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
