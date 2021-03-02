#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec.at(i);
  }
  vector<int> vec2;
  for(int p = 0; p < n; p++){
    for(int q = p; q < n; q++){
      vec2.push_back(p+q);
    }
  }
  sort(vec2.begin(), vec2.end());
  bool ans = false;
  for(int j = 0; j < n; j++){
    for(int k = 0; k < n; k++){
      if(binary_search(vec2.begin(), vec2.end(), m-vec.at(j)-vec.at(k))){
        ans = true;
        goto A;
      }
    }
  }
  A:
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
