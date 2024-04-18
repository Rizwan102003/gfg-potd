/*
Two Repeated Elements

PROBLEM STATEMENT :
You are given an integer n and an integer array arr of size n+2. All elements of the array are in the range from 1 to n. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers, and X's second appearance comes before second appearance of Y, then the order should be (X, Y).

EXAMPLE 1 :
Input:
n = 4
arr[] = {1,2,1,3,4,3}
Output: 
1 3
Explanation: 
In the given array, 1 and 3 are repeated two times and as 1's second appearance occurs before 2's second appearance, so the output should be 1 3.

EXAMPLE 2 :
Input:
n = 2
arr[] = {1,2,2,1}
Output: 
2 1
Explanation: 
In the given array, 1 and 2 are repeated two times and second occurence of 2 comes before 1. So the output is 2 1.

Your Task:
The task is to complete the function repeatedElements() which takes an integer array arr[] and an integer n as inputs (the size of the array is n + 2 and elements are in the range [1, n]) and finds the two repeated elements in the array and return them in an array.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1). 

Constraints:
2 ≤ n ≤ 10^5
1 ≤ arr[i] ≤ n

CODE :
*/

//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated(int a[], int n)
    {    
        vector<int> res(2);
        bool first = false;
        //iterating over the array elements.
        for(int i=0;i<n+2;i++)
        {
            //making the visited elements negative.
            if(a[abs(a[i])]>0)
                a[abs(a[i])]=-a[abs(a[i])];
            //if the number is negative, it was visited previously
            //so this would be the repeated element.
            else
            {
                //storing first and second repeated element accordingly.
                if(first == false)
                {
                    res[0] = abs(a[i]);
                    first = true;
                }
                else
                {
                    res[1] = abs(a[i]);
                    break;
                }
            }
        }
        //returning the result.
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n+2];
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends