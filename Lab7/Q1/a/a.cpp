#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    double p1=double(a.first/a.second);
    double p2=double(b.first/b.second);
    if(p1!=p2)
    return p1>p2;
    return a.first>b.first;
}

int knp(int W,pair<int,int> p[],int n){
    sort(p,p+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        if(W>=p[i].second){
            ans+=p[i].first;
            W-=p[i].second;
        }
        else break;
    }
    return ans;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,W;
    cin>>n>>W;
    pair<int,int> p[n];
    int values[n],weights[n];
   
    for(int i=0;i<n;i++) cin>>values[i];
    for(int i=0;i<n;i++) cin>>weights[i];
   
    for(int i=0;i<n;i++){
        p[i]=make_pair(values[i],weights[i]);
    }

    cout<<knp(W,p,n);
}    