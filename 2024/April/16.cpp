/*
Minimize the Difference

PROBLEM STATEMENT :
You are given an array arr of size n. You have to remove a subarray of size k , such that the difference between the maximum and minimum values of the remaining array is minimized.
Find the minimum value obtained after performing the operation of the removal of the subarray and return it.

EXAMPLE 1 :
Input:
n = 5
k = 3
arr = {1, 2, 3, 4, 5}
Output: 
1
Explanation: 
We can remove first subarray of length 3(i.e. {1, 2, 3}) then remaining array will be {4,5} and the difference of maximum and minimum element will be 1 i.e 5 - 4 = 1

EXAMPLE 2 :
Input:
n = 6
k = 3
arr = {2, 3, 1, 4, 6, 7}
Output: 
2
Explanation:
If we remove the subarray {2,3,1} then remaining array will be {4,6,7} and the difference  = 7-4 = 3
If we remove the subarray {3,1,4} then remaining array will be {2,6,7} and the difference  = 7-2 = 5
If we remove the subarray {1,4,6} then remaining array will be {2,3,7} and the difference  = 7-2 = 5
If we remove the subarray {4,6,7} then remaining array will be {2,3,1} and the difference  = 3-1 = 2
So the answer will be min(3,5,5,2) = 2

Your Task: 
You have to complete the function minimizeDifference( ), which takes two integers n and k and an integer array arr of size n. You have to return the minimum difference of maximum and minimum elements of the remaining array after removing one k length subarray of it.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
2 <= n <= 10^5
1 <= k <= n-1
0 <= arr[i] <= 10^9

CODE :
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};
// } Driver Code Ends

class Solution {
public:
    int minimizeDifference(int n, int k, vector<int>& arr) {
        // Arrays to store maximum and minimum elements from a certain position
        vector<int> post_max(n);
        vector<int> post_min(n);
        // Initializing the maximum and minimum elements from the last position
        post_min[n - 1] = arr[n - 1];
        post_max[n - 1] = arr[n - 1];
        // Loop to update the maximum and minimum elements from each position
        for (int i = n - 2; i >= 0; --i) {
            post_max[i] = max(arr[i], post_max[i + 1]);
            post_min[i] = min(arr[i], post_min[i + 1]);
        }
        // Initializing the minimum difference with elements at k
        int min_diff = post_max[k] - post_min[k];
        // Initializing variables to keep track of current minimum and maximum elements
        int p_min = arr[0];
        int p_max = arr[0];
        // Loop to update the minimum difference by considering each window of size k
        for (int i = 1; i < n - k; ++i) {
            int curr_min = max(p_max, post_max[i + k]) - min(p_min, post_min[i + k]);
            min_diff = min(min_diff, curr_min);
            p_max = max(arr[i], p_max);
            p_min = min(arr[i], p_min);
        }
        // Updating the minimum difference considering the remaining elements
        min_diff = min(min_diff, p_max - p_min);
        // Returning the final minimized difference
        return min_diff;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    scanf("%d ",&t);
    while(t--){       
        int n;
        scanf("%d",&n); 
        int k;
        scanf("%d",&k);
        vector<int> arr(n);
        Array::input(arr,n);
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        cout<<res<<endl;
    }
}
// } Driver Code Ends