#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string result(n, '?');
        bool impossible = false;

        vector<string> suffixes(m);
        vector<int> positions(m);

        for (int i = 0; i < m; ++i) {
            cin >> positions[i] >> suffixes[i];
            positions[i]--; 
        }

        for (int i = 0; i < m; ++i) {
            int pos = positions[i];
            const string &suffix = suffixes[i];
            bool h = false;

            for (int j = 0; j < suffix.size(); ++j) {
                int index = pos + j;
                if (index >= n) break;
                if (suffix[j] == '*') {
                    h = true;
                    break;
                }
                if (result[index] != '?' && result[index] != suffix[j]) {
                    impossible = true;
                    break;
                }
                result[index] = suffix[j];
            }

            if (impossible) break;

            if (h) {
                for (int j = suffix.size() - 1, k = n - 1; j >= 0; --j, --k) {
                    if (suffix[j] == '*') break;
                    if (k < 0) break;
                    if (result[k] != '?' && result[k] != suffix[j]) {
                        impossible = true;
                        break;
                    }
                    result[k] = suffix[j];
                }
            }

            if (impossible) break;
        }

        if (!impossible) {
            for (char c : result) {
                if (c == '?') {
                    impossible = true;
                    break;
                }
            }
        }

        if (impossible) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
