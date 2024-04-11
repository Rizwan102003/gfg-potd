/*
Gray to Binary equivalent

PROBLEM STATEMENT :
Given an integer number n, which is a decimal representation of Gray Code. Find the binary equivalent of the Gray Code & return the decimal representation of the binary equivalent.

EXAMPLE 1 :
Input: 
n = 4
Output: 
7
Explanation:
Given 4, its gray code =  110.
Binary equivalent of the gray code 110 is 100.
Return 7 representing gray code 100.

EXAMPLE 2 :
Input: 
n = 15
Output: 
10
Explanation:
Given 15 representing gray code 1000.
Binary equivalent of gray code 1000 is 1111.
Return 10 representing gray code 1111 
ie binary 1010.

Your Task: 
You don't need to read input or print anything. Your task is to complete the function grayToBinary() which accepts an integer n as an input parameter and returns decimal representation of the binary equivalent of the given gray code.

Expected Time Complexity: O(log (n)).
Expected Auxiliary Space: O(1).

Constraints:
0 <= n <= 10^8

CODE :
*/

//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        int b=0;
        //We use a loop and Right shift n everytime until it becomes 0.
        for(n=n;n>0;n=n>>1)
            //We use XOR operation which stores the result of conversion in b.
            b^=n;
            
        //returning the Binary equivalent.
        return b;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}
// } Driver Code Ends