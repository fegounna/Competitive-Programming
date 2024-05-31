#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() 
{
  int n,m;
  cin>>n>>m;
  vector<int> entry(n),ext(m);
  for(int i=0;i<n;i++)
    cin>>entry[i];
  for(int i=0;i<m;i++)
    cin>>ext[i];
  unordered_map<int,int> mp;
  for(int i:entry)
    for(int j:ext)
      mp[j-i]++;
  int res = 0, mn = -1;
  for(auto u:mp){
    if(u.first >0 && u.second>mn){
      mn = u.second;
      res = u.first;
    }
    else if(u.first >0 && u.second==mn){
      if(res>u.first)
        res = u.first;
    }
  }
  cout<<res<<endl;
}
