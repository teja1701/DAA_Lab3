#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matadd(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size(); 
    vector<vector<int>> C(n,vector<int>(n)); 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)  C[i][j] = A[i][j] + B[i][j];
    }
    return C; 
}

vector<vector<int>> matmul(vector<vector<int>>& A,vector<vector<int>>& B)
{
    int n = A.size();
    if (n == 1) return {{A[0][0] * B[0][0]}};

    int half = n / 2;

    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));
    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));
    for (int i = 0; i < half; ++i)
    {
        for (int j = 0; j < half; ++j)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }
    vector<vector<int>> C11 = matadd(matmul(A11, B11),matmul(A12, B21));
    vector<vector<int>> C12 = matadd(matmul(A11, B12),matmul(A12, B22));
    vector<vector<int>> C21 = matadd(matmul(A21, B11),matmul(A22, B21));
    vector<vector<int>> C22 = matadd(matmul(A21, B12),matmul(A22, B22));
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < half; ++i)
    {
        for (int j = 0; j < half; ++j)
        {
            result[i][j] = C11[i][j];
            result[i][j + half] = C12[i][j];
            result[i + half][j] = C21[i][j];
            result[i + half][j + half] = C22[i][j];
        }
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    int n; cin>>n; 
    int sz = __bit_ceil(n); 
    vector<vector<int>> A(sz,vector<int>(sz));
    vector<vector<int>> B(sz,vector<int>(sz));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin>>A[i][j]; 
    } 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cin>>B[i][j]; 
    } 

    vector<vector<int>> C = matmul(A,B); 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cout<<C[i][j]<<" ";
        cout<<"\n";
    }
}