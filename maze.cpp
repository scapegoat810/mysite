#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> vec;

const vector<int> dh = {1,0,-1,0};
const vector<int> dw = {0,1,0,-1};

int main(){
  cin >> N >> M;
  int shp, swp, ghp, gwp;
  bool scheck = true;
  bool gcheck = true;
  for(int i = 0; i < N; i++){
    string s;
    cin >> s;
    vec.push_back(s);
    if(scheck){
      for(int j = 0; j < M; j++){
        if(s.at(j) == 'S'){
          shp = i;
          swp = j;
          scheck = false;
          break;
        }
      }
    }
    if(gcheck){
      for(int j = 0; j < M; j++){
        if(s.at(j) == 'G'){
          ghp = i;
          gwp = j;
          gcheck = false;
          break;
        }
      }
    }
  }
  vector<vector<int>> seen(N, vector<int>(M, -1));
  queue<int> q;
  seen.at(shp).at(swp) = 0;
  q.push(shp*10+swp);
  while(seen.at(ghp).at(gwp) == -1){
    int sh = q.front()/10;
    int sw = q.front()%10;
    q.pop();
    for(int k = 0; k < 4; k++){
      int nh = sh + dh.at(k);
      int nw = sw + dw.at(k);
      if(nh < 0 || N-1 < nh || nw < 0 || M-1 < nw){
        continue;
      }
      if(seen.at(nh).at(nw) != -1){
        continue;
      }
      if(vec.at(nh).at(nw) == '#'){
        continue;
      }
      seen.at(nh).at(nw) = seen.at(sh).at(sw) + 1;
      q.push(nh*10+nw);
    }
  }
  cout << seen.at(ghp).at(gwp) << endl;
}
