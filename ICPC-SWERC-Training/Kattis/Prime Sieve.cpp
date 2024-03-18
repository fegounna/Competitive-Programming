#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    vector<bool> arr(n+1, true);
    arr[0] = arr[1] = false;
    for(int i=2;i<=(int)sqrt(n);i++){
        if(arr[i]){
            for(int j=i*i;j<=n;j+=i){
                arr[j]=false;
            }
        }
    }
    int sum=0;
    for(int p : arr){
        sum+=p;
    }
    cout<<sum<<endl;
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        cout<<arr[k]<<endl;
    }
}
