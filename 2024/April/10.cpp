/*
Party of Couples

PROBLEM STATEMENT :
You are given an integer array arr[] of size n, representing n number of people in a party, each person is denoted by an integer. Couples are represented by the same number ie: two people have the same integer value, it means they are a couple. Find out the only single person in the party of couples.

NOTE: It is guarantee that there exist only one single person in the party.

EXAMPLE 1 :
Input: 
n = 5
arr = {1, 2, 3, 2, 1}
Output: 
3
Explaination: Only the number 3 is single.

EXAMPLE 2 :
Input: 
n = 11 
arr = {1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6} 
Output: 
4 
Explaination: 4 is the only single.

Your Task:
You do not need to read input or print anything. Your task is to complete the function findSingle() which takes the size of the array n and the array arr[] as input parameters and returns the only single person.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 10^4
1 ≤ arr[i] ≤ 10^6

CODE :
*/

//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h> 
using namespace std; 
// } Driver Code Ends

// Back-end complete function Template for C++

class Solution{
    public:
    // Function to find the single element in the array
    int findSingle(int n, int arr[]){
        int ans = 0;
        
        // loop to find the single element
        for(int i = 0;i < n;i++){
            ans ^= arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends