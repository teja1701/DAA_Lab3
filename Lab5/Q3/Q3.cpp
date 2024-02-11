#include<bits/stdc++.h>
using namespace std;

bool clique(vector<vector<bool>> v){
	int n=v.size();
	vector<int> col(n,0);
	queue<int> q;
	q.push(0);
	col[0]=1;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(v[i][k]==1){
				if(col[k]==1){
					if(col[i]==0){col[i]=2;q.push(i);}
					else if(col[i]==1){return 0;}
				}else{
					if(col[i]==0){col[i]=1;q.push(i);}
					else if(col[i]==2){return 0;}
				}
			}
		}
	}
	return 1;

}

int main(){

    freopen("input3.txt","r",stdin);
    freopen("output3.txt","w",stdout);

    int n;
	cin>>n;
	vector<vector<bool>> v(n,vector<bool>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool k;
			cin>>k;
			v[i][j]=!k;
			if(i==j){v[i][j]=0;}
		}
	}
	if(clique(v)){cout<<"YES"<<endl;}
	else{cout<<"NO"<<endl;}
	return 0;
    
}