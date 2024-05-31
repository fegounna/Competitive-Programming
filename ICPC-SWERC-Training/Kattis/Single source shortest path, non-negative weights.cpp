#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;

vector<int> dijkstra(int s,int n,vector<vector<pair<int,int>>> v){
    priority_queue< pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>> >pq;
    vector<int> dist(n,INF);
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto x:v[u]){
            int v = x.first;
            int w = x.second;
            if (dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    int n,m,q,s;
    while(cin>>n>>m>>q>>s&&n||m||q||s){
        vector<vector<pair<int,int>>> v(n);
        for(int i=0;i<m;i++){
            int u,x,w;
            cin>>u>>x>>w;
            v[u].push_back({x,w});
            //v[x].push_back({u,w});
        }
        vector<int> dist = dijkstra(s,n,v);
        for(int i=0;i<q;i++){
            int x;
            cin>>x;
            if(dist[x]==INF)
                cout<<"Impossible"<<endl;
            else
                cout<<dist[x]<<endl;
        }
        cout<<endl;
    }
}
