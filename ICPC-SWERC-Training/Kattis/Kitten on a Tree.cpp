#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string dummy;
    getline(cin,dummy);
    int v[101]={0};
    vector<int> branch(101,false);
    string line,word;
    while(getline(cin,line)){
        istringstream iss(line);
        iss>>word;
        int root = stoi(word);
        if(root==-1) break;
        while(iss>>word){
          int i = stoi(word);
          branch[i]=true;
          v[i]=root;
        }
    }
    int g=0;
    for(int i=1;i<=101;i++){
        if(!branch[i]){
            g = i;
            break;
        }
    }
    while(n !=0){
      cout<<n<<" ";
      n=v[n];
    }
}
