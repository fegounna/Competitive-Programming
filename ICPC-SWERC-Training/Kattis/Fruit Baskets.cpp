#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long inv = 0;
void solve(int i,int j,int s,int n,vector<int> &v) {
  if(i == n||j==3){
    return;
  }
  for(int k=i;k<n;k++){
    if(s+v[k]<200){
      inv += s+v[k];
      solve(k+1,j+1,s+v[k],n,v);
    }
  }
}

int main() 
{
  int n;
  cin>>n;
  vector<int> v(n);
  long long res = 0;
  long p = 1L<<(n-1);
  for(int i=0;i<n;i++){
      cin>>v[i];
      res += p*v[i];
  }
  solve(0,0,0,n,v);
  cout<<res-inv<<endl;
}
