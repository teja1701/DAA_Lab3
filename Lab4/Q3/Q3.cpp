#include <bits/stdc++.h>
using namespace std;

int main(){
    
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    int k;
    cin>>k;

    // Initializing the array
    for(int i=0;i<n;i++){
        cin>>a[i];
    }     
    sort(a,a+n);

    // kth largest element in the array
    cout<<a[n-k]<<endl; 
}