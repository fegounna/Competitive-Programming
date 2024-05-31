#include <bits/stdc++.h>
using namespace std;

int main(){
    int f ,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    queue<pair<int,int>> q;
    q.push({s,0});
    vector<bool> visited(f+1,false);
    while(q.size()){
        auto [cur, dis] = q.front();
        q.pop();
        if(cur == g){
            cout << dis;
            return 0;
        }
        if(visited[cur]) continue;
        visited[cur] = true;
        if(cur + u <= f) q.push({cur + u, dis + 1});
        if(cur - d >= 1) q.push({cur - d, dis + 1});
    }
    cout<<"use the stairs"<<endl;
}
