/*
Optimal Strategy For A Game

PROBLEM STATEMENT :
You are given an array arr of size n. The elements of the array represent n coin of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

EXAMPLE 1 :
Input:
n = 4
arr[] = {5, 3, 7, 10}
Output: 
15
Explanation: The user collects maximum
value as 15(10 + 5). It is guarantee that we cannot get more than 15 by any possible moves.

EXAMPLE 2 :
Input:
n = 4
arr[] = {8, 15, 3, 7}
Output: 
22
Explanation: The user collects maximum
value as 22(7 + 15). It is guarantee that we cannot get more than 22 by any possible moves.

Your Task:
Complete the function maximumAmount() which takes an array arr[] (represent values of n coins) and n as a number of coins as a parameter and returns the maximum possible amount of money you can win if you go first.

Expected Time Complexity : O(n*n)
Expected Auxiliary Space: O(n*n)

Constraints:
2 <= n <= 10^3
1 <= arr[i] <= 10^6

CODE :
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.

class Solution{
    public:
long long maximumAmount(int n, int arr[]) 
{ 
    //creating a table to store solutions of subproblems.
    int table[n][n]; 
  
    //filling table using above recursive formula. Note that the 
    //table is filled in diagonal fashion, from diagonal elements 
    //to table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) 
    { 
        for (int i = 0, j = gap; j < n; ++i, ++j) 
        { 
            //Here x is value of table[i + 2][j], y istable[i + 1][j - 1] and 
            // z is table[i][j - 2] in above recursive formula.
            
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
    //returning the result.
    return table[0][n - 1]; 
} 
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends