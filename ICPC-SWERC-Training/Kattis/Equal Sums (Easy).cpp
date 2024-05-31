#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve(int i,int v[]){
       for (int j = 0; j < 20; j++) {
         if ((i & (1 << j)) != 0) {
          cout<<v[j]<<" ";
         }
       }
       cout<<endl;
}

int main() 
{
  int n;
  cin>>n;
  for(int k=0;k<n;k++){
    cout<<"Case #"<<k+1<<':'<<endl;
    int v[20];
    int h;
    cin>>h;
    for(int j=0;j<20;j++)
      cin>>v[j];
    unordered_map<long,long> mp;
    for(long i = 0; i < (1 << 20); i++){
      long sum=0;
       for (int j = 0; j < 20; j++) {
         if ((i & (1 << j)) != 0) {
            sum += v[j];
         }
       }
       if(mp.find(sum)!=mp.end()){
         solve(mp[sum],v);
         solve(i,v);
         break;
       }
       else
        mp[sum]=i;
    }
    mp.clear();
  }
}
