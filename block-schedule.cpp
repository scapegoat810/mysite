#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<vector<int>> vec(N,vector<int>(2));
  for(int i = 0; i < N; i++){
    cin >> vec.at(i).at(0) >> vec.at(i).at(1);
  }
  sort(vec.begin(),vec.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[1] < beta[1];});
  int counter = 1;
  int finish = vec.at(0).at(1);
  for(int j = 1; j < N; j++){
    if(finish < vec.at(j).at(0)){
      counter++;
      finish = vec.at(j).at(1);
    }
  }
  cout << counter << endl;
}
