#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
map<long,long> m;

long trans(string s){
    long rep = 0;
    long p = 1;
    for(int i=0;i<23;i++){
        if(s[i]=='o'){
            rep+=p;
        }
        p = p<<2;
    }
    return rep;
}


int solve(string arr,int res){
    bool test = false;
    long rep = trans(arr);
    if(m.find(rep)!=m.end()){
        return m[rep];
    }
    for(int i=0;i<21;i++){
        if(arr[i]=='-'&&arr[i+1]=='o'&&arr[i+2]=='o'){
            test=true;
            arr[i]='o';
            arr[i+1]='-';
            arr[i+2]='-';
            res = min(solve(arr,res),res);
            arr[i]='-';
            arr[i+1]='o';
            arr[i+2]='o';
        }
        if(arr[i]=='o'&&arr[i+1]=='o'&&arr[i+2]=='-'){
            test=true;
            arr[i]='-';
            arr[i+1]='-';
            arr[i+2]='o';
            res = min(solve(arr,res),res);
            arr[i]='o';
            arr[i+1]='o';
            arr[i+2]='-';
        }
    }
    if(!test){
        int count=0;
        for(int i=0;i<23;i++){
            if(arr[i]=='o')
                count++;
        }
        return count;
    }
    m[rep]=res;
    return res;
}

int main(){
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    while(n--){
        string s;
        getline(cin,s);
        cout<<solve(s,1e9)<<endl;
    }
}
