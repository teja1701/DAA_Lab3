#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> input()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for ( int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    return v;
}

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[1] != b[1])
        return a[1] < b[1];
    return a[2] > b[2];
}

pair<int, vector<int>> getMaxProfit(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), comp);
    vector<int> jobId;
    int profit = 0, preJob = -1, n = jobs.size();
    for ( int i = 0; i < n; i++)
    {
        if (jobs[i][1] == preJob)
            continue;
        preJob = jobs[i][1];
        jobId.push_back(jobs[i][0]);
        profit += jobs[i][2];

    }
    return {profit, jobId};
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    vector<vector<int>> v = input();
    pair<int, vector<int>> jobs = getMaxProfit(v);
    
    cout << "Maximum Profit: " << jobs.first << "\n";
    cout << "Jobs done:" << "\n";
    for (int c : jobs.second) cout << c << ' ';
    return 0;
}

