
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int v[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(v[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int n,W;
    cin>>n>>W;
	int wt[n],v[n];
	for(int i=0;i<n;i++) cin>>wt[i];
	for(int i=0;i<n;i++) cin>>v[i];
    cout << knapSack(W, wt, v, n);

}
