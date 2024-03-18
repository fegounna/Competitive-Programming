#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comparator(const string& a, const string& b, const unordered_map<string, int>& countMap) {
    if (countMap.at(a) != countMap.at(b)) {
        return countMap.at(a) > countMap.at(b); 
    } else {
        return a < b; 
    }
}

int main() {
    unordered_map<string, int> m;
    unordered_map<string, int> count;
    unordered_map<string, set<string>> user;
    vector<string> res;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string line, u="", w="";
        getline(cin, line);
        int j=0;
        while(line[j]!=' '){
            u+=line[j];
            j++;
        }
        while(j<line.length()-1) {
            j++;
            if(line[j]==' '){
                user[u].insert(w);
                count[w]++;
                w = "";
            }   
            else{
                w+=line[j];
            }
        }
        user[u].insert(w);
        count[w]++;

    }
    int len = user.size();
    for (auto it = user.begin(); it != user.end(); ++it) {
        for (auto j = it->second.begin(); j != it->second.end(); ++j) {
            m[*j]++;
            //cout<<it->first<<' '<<*j<<' '<<m[*j]<<endl;
            if (m[*j] == len) {
                res.push_back(*j);
            }
        }
    }
    if (res.empty()) {
        cout << "ALL CLEAR" << endl;
    } 
    else {
      sort(res.begin(), res.end(), [&count](const string& a, const string& b) {
          return Comparator(a, b, count);
      });
        for (int i=0;i<res.size();i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
