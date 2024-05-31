#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> m;
/*
int solve(int r,int c,int i,int prev){
    if(i==c)
        return 1;
    if(map)
    //cout<<i<<' '<<prev<<endl;
    int res = 0;
    for(int k=0;k<r;k++){
        if(k==prev)
            continue;
        res+=solve(r,c,i+1,k)%998244353; 
    }
    return res%998244353;
}*/
int main(){
    ios_base::sync_with_stdio(false);
    int r,c;
    cin>>r>>c;
    long long dp[51][51];
    for(int i=0;i<=c;i++)
        for(int j=0;j<=r;j++)
            dp[i][j]=0;
    for(int i=1;i<=r;i++)
        dp[1][i]=1;
    for(int i=2;i<=c;i++){
        for(int j=1;j<=r;j++){
            for(int k=1;k<=r;k++){
                if(k==j)
                    continue;
                dp[i][j]+=dp[i-1][k]%998244353;
            }
        }
    }


    long long res =0;
    for(int i=1;i<=r;i++)
        res+=dp[c][i]%998244353;
    cout<<res%998244353;
}
