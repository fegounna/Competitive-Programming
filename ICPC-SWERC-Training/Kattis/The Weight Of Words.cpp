#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, w;
    cin >> l >> w;
    vector<vector<int>> dp(l + 1, vector<int>(w + 1, 0));

    dp[0][0] = 1;

    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= w; j++){
            for(int o = 1; o <= 26; o++){ 
                if(j - o >= 0 && dp[i - 1][j - o]){
                    dp[i][j] = 1;
                    break; 
                }
            }
        }
    }
    
    if(dp[l][w]) {
        int ans = w;
        string s = "";
        for(int i = l; i > 0; i--){
            for(int o = 1; o <= 26; o++){
                if(ans - o >= 0 && dp[i - 1][ans - o]){ 
                    ans -= o;
                    s += 'a' + (o - 1); 
                    break;
                }
            }
        }
        cout << s << endl;
    } else {
        cout << "impossible" << endl;
    }
}
