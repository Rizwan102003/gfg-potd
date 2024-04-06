/*
Maximize dot product

PROBLEM STATEMENT :
Given two arrays a and b of positive integers of size n and m where n >= m, the task is to maximize the dot product by inserting zeros in the second array but you cannot disturb the order of elements.

Dot product of array a and b of size n is a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].

EXAMPLE 1 :
Input: 
n = 5, a[] = {2, 3, 1, 7, 8} 
m = 3, b[] = {3, 6, 7}
Output: 
107
Explanation: 
We get maximum dot product after inserting 0 at first and third positions in second array.
Therefore b becomes {0, 3, 0, 6, 7}. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107.

EXAMPLE 2 :
Input: 
n = 3, a[] = {1, 2, 3}
m = 1, b[] = {4} 
Output: 
12 
Explanation: 
We get maximum dot product after inserting 0 at first and second positions in second array.
Therefore b becomes {0, 0, 4}. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12.

Your Task:  
You don't need to read input or print anything. Complete the function maxDotProduct() which takes n, m, array a and b as input parameters and returns the maximum value.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ m ≤n ≤ 10^3
1 ≤ a[i], b[i] ≤ 10^3

CODE :
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
		

	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Create 2D Matrix that stores dot product 
	    // dp[i+1][j+1] stores product considering b[0..i] 
	    // and a[0...j]. Note that since all m > n, we fill 
	    // values in upper diagonal of dp[][] 
	    int dp[m+1][n+1]; 
	    memset(dp, 0, sizeof(dp)); 
	  
	    // Traverse through all elements of B[] 
	    for (int i=1; i<=m; i++) 
	  
	        // Consider all values of a[] with indexes greater 
	        // than or equal to i and compute dp[i][j] 
	        for (int j=i; j<=n; j++) 
	  
	            // Two cases arise 
	            // 1) Include a[j] 
	            // 2) Exclude a[j] (insert 0 in b[])  
	            dp[i][j] = max((dp[i-1][j-1] + (a[j-1]*b[i-1])) , 
	                            dp[i][j-1]); 
	  
	    // return Maximum Dot Product 
	    return dp[m][n] ; 
	} 
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends