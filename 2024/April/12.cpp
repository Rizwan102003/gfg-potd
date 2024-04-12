/*
Sum of Products

PROBLEM STATEMENT :
Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.

EXAMPLE 1 :
Input:
n = 3
arr = {5, 10, 15}
Output:
15
Explanation:
The bitwise Ands of all pairs where i<j are (5&10) = 0, (5&15) = 5 and (10&15) = 10.
Therefore, the total sum = (0+5+10) = 15.

EXAMPLE 2 :
Input:
n = 4
arr = {10, 20, 30, 40}
Output:
46
Explanation:
The sum of bitwise Ands 
of all pairs = (0+10+8+20+0+8) = 46.

Your Task:
You don't need to read input or print anything.Your Task is to complete the function pairAndSum() which takes an Integer n and an array arr[]  of size n as input parameters and returns the sum of bitwise Ands of all pairs.

Expected Time Complexity:O(n)
Expected Auxillary Space:O(1)

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= 10^8

CODE :
*/

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        long long ans = 0; // Initialize result
        // Traverse over all bits
        for (int i = 0; i < 32; i++) {
            // Count number of elements with i'th bit set
            long long k = 0; // Initialize the count
            for (int j = 0; j < n; j++)
                if ((arr[j] & (1 << i))) k++;
            ans += (1 << i) * (k * (k - 1) / 2);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends