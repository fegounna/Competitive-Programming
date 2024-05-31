#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            v[i][j] = s[j] - '0';
    }
    vector<vector<int>> visited(n, vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    while(q.size()){
        pair<pair<int,int>,int> p = q.front();
        pair<int,int >cur = p.first;
        int dis = p.second;
        int i = cur.first;
        int j = cur.second;
        q.pop();
        if(i == n-1 && j==m-1){
            cout << dis;
            return 0;
        }
        if(visited[i][j]) continue;
        visited[i][j] = true;
        if(i+ v[i][j] < n) q.push({{i+v[i][j],j}, dis + 1});
        if(i - v[i][j] >= 0) q.push({{i-v[i][j],j}, dis + 1});
        if(j+ v[i][j] < m) q.push({{i,j+v[i][j]}, dis + 1});
        if(j - v[i][j] >= 0) q.push({{i,j-v[i][j]}, dis + 1});

    }
   cout<<-1;
  }
