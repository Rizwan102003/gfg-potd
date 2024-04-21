/*
Three way partitioning

PROBLEM STATEMENT :
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that the array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.

Note: The generated output is 1 if you modify the given array successfully.

Geeky Challenge: Solve this problem in O(n) time complexity.

EXAMPLE 1 :
Input: 
n = 5
array[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 
1
Explanation: 
One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be 1.

EXAMPLE 2 :
Input: 
n = 6 
array[] = {1, 4, 3, 6, 2, 1}
[a, b] = [1, 3]
Output: 
1
Explanation: 
One possible arrangement is: {1, 3, 2, 1, 4, 6}. If you return a valid arrangement, output will be 1.

Your Task:
You don't need to read input or print anything. The task is to complete the function threeWayPartition() which takes the array array, a, and b as input parameters and modifies the array in place according to the given conditions.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 10^6
1 <= array[i], a, b <= 10^9

CODE :
*/

//{ Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// } Driver Code Ends

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void threeWayPartition(int arr[], int n, int a, int b)
{
    //Using two pointers which help in finding the index with which
    //the elements need to be swapped if they are not in correct position. 
    int start = 0, end = n-1;
    for (int i=0; i<=end;)
    {
        //If current element is smaller than lower range, we swap 
        //it with value on next available smallest position. 
        if (arr[i] < a)
            swap(&arr[i++], &arr[start++]);
        //If current element is greater than higher range, we swap 
        //it with value on next available greatest position. 
        else if (arr[i] > b)
            swap(&arr[i], &arr[end--]);
        //Else we just move ahead in the array.
        else
            i++;
    }
}

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> array(N);
        unordered_map<int,int> ump;
        for(int i=0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        int a,b;
        cin>>a>>b;
        vector<int> original = array;
        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }
        Solution ob;
        ob.threeWayPartition(array,a,b);
        for(int i=0;i<k1;i++)
        {
            if(array[i]<b)
            kk1++;
        }
        for(int i=k1;i<k1+k2;i++)
        {
            if(array[i]<=b and array[i]>=a)
            kk2++;
        }
        for(int i=k1+k2;i<k1+k2+k3;i++)
        {
            if(array[i]>b)
            kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;
        for(int i=0;i<array.size();i++)
            ump[array[i]]--;
        for(int i=0;i<array.size();i++)
            if(ump[array[i]]!=0)
                ok=0;
        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
// } Driver Code Ends