/*
Count Pairs in an Array

PROBLEM STATEMENT :
Given an array arr of n integers, count all pairs (arr[i], arr[j]) in it such that i*arr[i] > j*arr[j] and 0 ≤ i < j < n.

Note: 0-based Indexing is followed.

EXAMPLE 1 :
Input :
n = 4
arr[] = {8, 4, 2, 1}
Output :
2
Explanation:
If we see the array after operations
[0*8, 1*4, 2*2, 3*1] => [0, 4, 4, 3]
Pairs which hold the condition i*arr[i] > j*arr[j] are (4,1) and (2,1), so in total 2 pairs are available.

EXAMPLE 2 :
Input :
n = 7
arr[] = {5, 0, 10, 2, 4, 1, 6}
Output:
5
Explanation :
Pairs which hold the condition i*arr[i] > j*arr[j] are (10,2), (10,4), (10,1), (2,1) and (4,1), so in total 5 pairs are there.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function countPairs() which takes the array arr[] and its size n as inputs and returns the required result.

Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n*log(n))

Constraints:
1 ≤ n ≤ 10^4
0 ≤ arr[i] ≤ 10^4

CODE :
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    public:
    // Return count of pair in given array 
    // such that  i*arr[i] > j*arr[j] 
    int merge(int arr[], int temp[], int left, 
                           int mid, int right) 
    { 
        int inv_count = 0;     
        int i = left; /* index for left subarray*/
        int j = mid;  /* index for right subarray*/
        int k = left; /* ndex for resultant subarray*/
        while ((i <= mid - 1) && (j <= right)) 
        { 
            if (arr[i] <= arr[j]) 
                temp[k++] = arr[i++]; 
            else
            { 
                temp[k++] = arr[j++]; 
      
                inv_count = inv_count + (mid - i); 
            } 
        }     
        /* Copy the remaining elements of left 
         subarray (if there are any) to temp*/
        while (i <= mid - 1) 
            temp[k++] = arr[i++];      
        /* Copy the remaining elements of right 
         subarray (if there are any) to temp*/
        while (j <= right) 
            temp[k++] = arr[j++];      
        /* Copy back the merged elements to original 
          array*/
        for (i=left; i <= right; i++) 
            arr[i] = temp[i]; 
        return inv_count; 
    }     
    /* An auxiliary recursive function that sorts 
       the input array and returns the number of 
       inversions in the array. */
    int _mergeSort(int arr[], int temp[], int left, 
                                          int right) 
    { 
        int mid, inv_count = 0; 
        if (right > left) 
        { 
            /* Divide the array into two parts and call 
              _mergeSortAndCountInv() for each of 
              the parts */
            mid = (right + left)/2; 
            /* Inversion count will be sum of inversions in 
               left-part, right-part and number of inversions 
               in merging */
            inv_count  = _mergeSort(arr, temp, left, mid); 
            inv_count += _mergeSort(arr, temp, mid+1, right); 
      
            /*Merge the two parts*/
            inv_count += merge(arr, temp, left, mid+1, right); 
        } 
        return inv_count; 
    } 
    /* This function sorts the input array and 
       returns the number of inversions in the 
       array */
    int countPairs(int arr[], int n) 
    { 
        // Modify the array so that problem reduces to 
        // count inversion problem. 
        for (int i=0; i<n; i++) 
            arr[i] = i*arr[i]; 
      
        // Count inversions using same logic as 
        // below post 
        // https://www.geeksforgeeks.org/counting-inversions/ 
        int temp[n]; 
        return _mergeSort(arr, temp, 0, n - 1); 
    } 
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends