#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    int k=0;
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) k++;
        }
    }

    cout<<k<<"\n";
}