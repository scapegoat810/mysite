#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int N, M;
vector<string> vec;

const vector<int> dh ={1,0,-1,0, 1, -1, 1,-1};
const vector<int> dw = {0,1,0,-1, 1, 1, -1, -1};

void dfs(vector<vector<bool>> &seen, int &sh, int &sw){
  seen.at(sh).at(sw) = true;
  for(int i = 0; i < 8; i++){
    int nh = sh + dh.at(i);
    int nw = sw + dw.at(i);
    if(nh < 0 || N-1 < nh || nw < 0 || M-1 < nw){
      continue;
    }
    if(seen.at(nh).at(nw)){
      continue;
    }
    if(vec.at(nh).at(nw) == '.'){
      continue;
    }
    dfs(seen, nh, nw);
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    string s;
    cin >> s;
    vec.push_back(s);
  }
  vector<vector<bool>> seen(N, vector<bool>(M, false));
  int counter = 0;
  for(int j = 0; j < N; j++){
    for(int k = 0; k < M; k++){
      if(!(seen.at(j).at(k)) && vec.at(j).at(k) == 'W'){
        counter++;
        dfs(seen, j, k);
      }
    }
  }
  cout << counter << endl;
}
