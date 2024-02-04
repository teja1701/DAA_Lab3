#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { 
	return (a > b) ? a : b; 
} 

int max(int a, int b, int c) { 
	return max(max(a, b), c); 
} 


int maxCrossingSum(int a[], int l, int m, int h) { 

	int sum = 0; 
	int left_sum = INT_MIN; 
	for (int i = m; i >= l; i--) { 
		sum = sum + a[i]; 
		if (sum > left_sum) 
			left_sum = sum; 
	} 

	sum = 0; 
	int right_sum = INT_MIN; 
	for (int i = m; i <= h; i++) { 
		sum = sum + a[i]; 
		if (sum > right_sum) 
			right_sum = sum; 
    }
	return max(left_sum + right_sum - a[m], left_sum, right_sum); 
} 

int maxSubArraySum(int arr[], int l, int h) { 
	
	if (l > h) return INT_MIN; 
	if (l == h) return arr[l]; 

	int m = (l + h)/2; 

	return max(maxSubArraySum(arr, l, m - 1),maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h)); 
} 


int main() { 
	const int n = 1000;
    ofstream inputfile("input.txt");
    inputfile << n << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100 - 50;
        inputfile << num << " ";
    }
    inputfile << endl;
    inputfile.close();

    ifstream inputFile("input.txt");
    for (int i = 0; i < n; i++) inputFile >> a[i];
    inputFile.close();

    int max_sum = maxSubArraySum(a, 0, n - 1);
    ofstream outputfile("output.txt");
    outputfile << "Maximum contiguous sum is " << max_sum; 
	return 0; 
}