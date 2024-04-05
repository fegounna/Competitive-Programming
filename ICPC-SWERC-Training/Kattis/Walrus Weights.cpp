#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
    int n; 
    cin >> n;
  int dp[2001]; 
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0; 

    for (int i = 0; i < n; ++i) {
        for (int j = 2000; j >= 0; --j) {
            if (dp[j]!=-1 && j + w[i] <= 2000) {
                dp[j + w[i]] = max(dp[j + w[i]], dp[j] + w[i]);
            }
        }
    }

    int s = 0;
    for (int i = 0; i <= 2000; ++i) {
        if (dp[i] != -1) {
            if (abs(i-1000) < abs(s-1000) || 
                (abs(i-1000) == abs(s-1000) && i > s)) {
                s = i;
            }
        }
    }

    cout<<s<<endl;
    

}
