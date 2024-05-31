#include <bits/stdc++.h>
using namespace std;


int solve(int arr[]){
    int sorr[20];
    sorr[0]=arr[0];
    int res =0;
    for(int i=1;i<20;i++){
        int pos=i-1;
        int test = false;
        while(pos>=0&&sorr[pos]>arr[i]){
            pos--;
            res++;
            test=true;
        }
        int y = arr[i];
        if(test)
            pos++;
        else
            sorr[i]=arr[i];
        while(test&&pos<=i){
            int x = sorr[pos];
            sorr[pos]=y;
            y = x;
            pos++;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        int arr[20];
        for(int j=0;j<20;j++){
            cin>>arr[j];
            
        }
        cout<<k<<" "<<solve(arr)<<endl;

    }
}
