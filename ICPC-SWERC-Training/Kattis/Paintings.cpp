#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

long solution = 0;
vector<int> final;
void solve(int i, int &n, vector<vector<bool>> &hid,vector<int> &v,vector<bool> &test){
  if(i==n){
    solution ++;
    if(solution == 1){
      for(int k:v)  final.push_back(k);
    }
  }
  for(int k=0;k<n;k++){
    if(i==0||(!test[k]&&!hid[k][v[i-1]])){
      test[k]=true;
      v[i]=k;
      solve(i+1,n,hid,v,test);
      test[k]=false;
    }
  }
}


int main() 
{
  int nb;
  cin>>nb;
  for(int i=0;i<nb;i++){
    unordered_map<int,string> m;
    unordered_map<string,int> inv;
    int n;
    cin>>n;
    vector<vector<bool>> hid(n, vector<bool>(n, false));
    for(int j=0;j<n;j++){
      cin>>m[j];
      inv[m[j]]=j;
    }  
    int mi;
    cin>>mi;
    for(int j=0;j<mi;j++){
      string c1,c2;
      cin>>c1>>c2;
      hid[inv[c1]][inv[c2]] = true;
      hid[inv[c2]][inv[c1]] = true;
    }
    vector<int> v(n);
    vector<bool> test(n,false);
    solve(0,n,hid,v,test);
    cout<<solution<<endl;
    for(int k:final)  cout<<m[k]<<" ";
    cout<<endl;
    final.clear();
    solution=0;
  }
  
}
