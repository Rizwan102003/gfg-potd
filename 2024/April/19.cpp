/*
Find missing in second array

PROBLEM STATEMENT :
Given two integer arrays a of size n and b of size m, the task is to find the numbers which are present in the first array a, but not present in the second array b.

EXAMPLE 1 :
Input: 
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 10}
b[] = {2, 3, 1, 0, 5}
Output: 
4 10
Explanation: 
4 and 10 are present in first array, but not in second array.

EXAMPLE 2 :
Input: 
n = 5, m = 5
a[] = {4, 3, 5, 9, 11}
b[] = {4, 9, 3, 11, 10}
Output: 
5  
Explanation: 
Second array does not contain element 5.

Your Task:
You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function findMissing() that takes an integer array a, an integer array b, an integer n, and an integer m as input parameters and returns an array that contains the missing elements and the order of the elements should be the same as they are in array a.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(m).

Constraints:
1 ≤ n, m ≤ 10^5
-109 ≤ A[i], B[i] ≤ 10^9

CODE :
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
	public:
	vector<int> findMissing(int a[], int b[],  
                 int n, int m) 
	{ 
	    // Store all elements of  
	    // second array in a hash table 
	    unordered_set <int> s;
	    vector<int> ans;
	    for (int i = 0; i < m; i++) 
	        s.insert(b[i]); 
	    // Print all elements of  
	    // first array that are not 
	    // present in hash table 
	    for (int i = 0; i < n; i++) 
	        if (s.find(a[i]) == s.end()) 
	            ans.push_back(a[i]);
	    return ans;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    cout << "\n";
    }
    return 0;
}
// } Driver Code Ends