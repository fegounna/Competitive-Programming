#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights.rbegin(), weights.rend());

    vector<pair<int, int>> mongers(m);
    for (int i = 0; i < m; i++) {
        cin >> mongers[i].first >> mongers[i].second;}
    sort(mongers.begin(), mongers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second == b.second ? a.first > b.first : a.second > b.second;});

    long long s = 0;
    int f = 0;
    for (auto& m : mongers) {
        while (m.first-- > 0 && f < n) {
            s += (long long)weights[f++] * m.second;
        }
    }

    cout << s << endl;
    return 0;
}
