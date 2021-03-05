#include <bits/stdc++.h>
using namespace std;
int main(){
  int A;
  vector<int> coin(6);
  for(int j = 0; j < 6; j++){
    cin >> coin.at(j);
  }
  cin >> A; 
  reverse(coin.begin(), coin.end());
  vector<int> value = {500, 100, 50, 10, 5, 1};
  int counter = 0;
  for(int i = 0; i < value.size(); i++){
    int n = min(A/value.at(i), coin.at(i));
    counter += n;
    A -= n*value.at(i);
  }
  cout << counter << endl;
}
