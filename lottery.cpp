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
  bool ans = false;
  for(int j = 0; j < n; j++){
    for(int k = 0; k < n; k++){
      for(int l = 0; l < n; l++){
        for(int m = 0; m < n; m++){
          int counter = vec.at(j) + vec.at(k) + vec.at(l) + vec.at(m);
          if(counter == m) {
          	ans = true;
            goto A;
          }
        }
      }
    }
  }
  A:
  if(ans){
    cout << Yes << endl;
  }
  else{
    cout << No << endl;
  }
}
