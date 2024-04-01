#include <bits/stdc++.h>

using namespace std;
int main() {
    
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });
    
    multiset<int,greater<int>> ed;
    for(int i=0;i<k;i++){
      ed.insert(0);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        auto j = ed.lower_bound(v[i].first);
        if( j != ed.end() ){
          ed.erase(j);
          ed.insert(v[i].second+1);
          ans++;
        }
    }
    cout<<ans;
}
