#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int i=0;
    int res=0;
    while(i<n){
        int mn=v[i];
        int j =i;
        res++;
        while(j<n&&v[j]-mn<=d)
            j++;
        i=j;
    }
    cout<<res<<endl;
}
