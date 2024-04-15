/*
Count the elements

PROBLEM STATEMENT :
Given two arrays a and b both of size n. Given q queries in an array query each having a positive integer x denoting an index of the array a. For each query, your task is to find all the elements less than or equal to a[x] in the array b.

EXAMPLE 1 :
Input:
n = 3
a[] = {4,1,2}
b[] = {1,7,3}
q = 2
query[] = {0,1}
Output : 
2
1
Explanation: 
For 1st query, the given index is 0, a[0] = 4. There are 2 elements(1 and 3) which are less than or equal to 4.
For 2nd query, the given index is 1, a[1] = 1. There exists only 1 element(1) which is less than or equal to 1.

EXAMPLE 2 :
Input:
n = 4
a[] = {1,1,5,5}
b[] = {0,1,2,3}
q = 4
query[] = {0,1,2,3}
Output : 
2
2
4
4
Explanation: 
For 1st query and 2nd query, the given index is 0 and 1 respectively, a[0] = a[1] = 1. There are 2 elements(0 and 1) which are less than or equal to 1. 
For 3rd query and 4th query, the given index is 2 and 3 respectively, a[2] = a[3] = 5. All the 4 elements are less than or equal to 5.   

Your Task:
You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countElements() that takes array a and b of size n, and array query of size q as parameters and returns an array that contains the answer to the corresponding queries. 

Expected Time Complexity: O(n+q+maximum of a and b).

Expected Auxiliary Space: O(maximum of a and b).

Constraints:
1 ≤ q ≤ n ≤ 10^5
1 ≤ a[i], b[i] ≤ 10^5
0 ≤ query[i] < n

CODE :
*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        int max = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
            }
        }
        int max2 = max;
        for (int i = 0; i < n; i++) {
            if (b[i] > max2) {
                max2 = b[i];
            }
        }
        int h[max2 + 1];
        memset(h, 0, sizeof(h));
        for (int i = 0; i < n; i++) {
            int m = b[i];
            h[m]++;
        }
        for (int i = 1; i <= max; i++) {
            h[i] += h[i - 1];
        }
        vector<int> ans;
        for (int i = 0; i < q; i++) {
            int k = query[i];
            ans.push_back(h[a[k]]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends