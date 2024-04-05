#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double f;
    cin>>n>>f;
    vector<double> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    double buy[n+1];
    double sell[n+1];
    sell[0]=100;
    buy[0]=0;
    for(int i=1;i<=n;i++){
        sell[i]=max(buy[i-1]*v[i-1]-f,sell[i-1]);
        buy[i]=max(buy[i-1],(sell[i-1]-f)/v[i-1]);
    }
    cout<<sell[n];
    
}
