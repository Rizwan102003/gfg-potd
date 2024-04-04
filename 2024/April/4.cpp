/*
Sum of all substrings of a number

PROBLEM STATEMENT :
Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo 109+7. 

Note: The number may have leading zeros.

EXAMPLE 1 :
Input:
s = "1234"
Output: 
1670
Explanation: 
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670

EXAMPLE 2 :
Input:
s = "421"
Output: 
491
Explanation: 
Sum = 4 + 2 + 1 + 42 + 21 + 421 = 491

Your Task:
You only need to complete the function sumSubstrings that takes s as an argument and returns the answer modulo 109+7.

Expected Time Complexity: O(|s|).
Expected Auxiliary Space: O(|s|).

Constraints:
1 <= |s| <= 10^5

CODE : 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s)
    {
        //dp[] array to store sum till ith index.
        long long dp[s.size()];
        dp[0]=int(s[0]-'0');
        long long res=0, p=1000000007;
        res=dp[0]; 
        
        //iterating over all the digits.
        for(int i=1;i<s.length();i++)
        {
            //getting the integer value of current digit from string.
            int cur_digit=(int)(s[i]-'0');
            
            //storing [current digit*(i+1)+dp[i-1]*10] at dp[i].
            dp[i]=(((i+1)*(cur_digit))%p+(dp[i-1]*10)%p)%p; 
            
            //res stores the sum of all values in dp[].
            res = (res+dp[i])%p;                            
        }
        //returning the result.
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends