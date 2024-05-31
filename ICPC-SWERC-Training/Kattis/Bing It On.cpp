#include <bits/stdc++.h>
using namespace std;
struct node {
    int nb =0;
    vector<node*> next;
    node() : next(26, nullptr) {}
};

int insert(string s,node* p,int j){
    int x = s[j]-'a';
    if(p->next[x]==nullptr){
        p->next[x] = new node();
    }
    p->next[x]->nb++;
    if(j==s.length()-1)
        return p->next[x]->nb;
    return insert(s,p->next[x],j+1);
}

int main(){
    int n;
    cin>>n;
    node* p = new node();
    while(n--){
        string s;
        cin>>s;
        cout<<insert(s,p,0)-1<<endl;
    }
}
