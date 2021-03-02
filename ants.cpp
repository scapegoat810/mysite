#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){
  int L, n;
  cin >> L >> n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++){
    cin >> vec.at(i);
  }
  int maxp = 10000000;
  int d = 0;
  long double center = L/2;
  for(int j = 0; j < n; j++){
    if(abs(vec.at(j)-center) < abs(maxp- center)){
      d = vec.at(j) -center;
      maxp = vec.at(j);
    }
  }
  int ansmin = min(maxp, L-maxp);
  sort(vec.begin(), vec.end());
  int ansmax = max(max(vec.at(0), L-vec.at(0)), max(vec.at(n-1), L-vec.at(n-1)));
  cout << ansmin << ansmax << endl;
}
