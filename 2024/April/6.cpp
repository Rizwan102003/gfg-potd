/*
Count ways to N'th Stair

PROBLEM STATEMENT :
There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).

EXAMPLE 1 :
Input:
n = 4
Output: 
3
Explanation: 
You can reach 4th stair in 3 ways.
3 possible ways are:
1, 1, 1, 1
1, 1, 2
2, 2
Here, note that {1, 1, 2}, {1, 2, 1} and {2, 1, 1} are considered same as their order does not matter. 

EXAMPLE 2 :
Input:
n = 5
Output: 
3
Explanation:
You may reach the 5th stair in 3 ways.
The 3 possible ways are:
1, 1, 1, 1, 1
1, 1, 1, 2
1, 2, 2

Your Task:
Your task is to complete the function countWays() which takes a single argument n and returns the answer.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= N <= 10^6

CODE :
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        long long res[n + 1];

        // base cases
        res[0] = 1;
        res[1] = 1;

        // storing number of ways to reach the ith index as
        // number of ways to reach (i-2)th index +1.
        for (int i = 2; i <= n; i++)
            res[i] = (res[i - 2] + 1);

        // returning the result.
        return res[n];
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends