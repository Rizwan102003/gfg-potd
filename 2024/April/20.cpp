/*
Union of Two Sorted Arrays

PROBLEM STATEMENT :
Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays. 

EXAMPLE 1 :
Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 5, arr2 [] = {1, 2, 3, 6, 7}
Output: 
1 2 3 4 5 6 7
Explanation: 
Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

EXAMPLE 2 :
Input: 
n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 
1 2 3 4 5
Explanation: 
Distinct elements including both the arrays are: 1 2 3 4 5.

EXAMPLE 3 :
Input:
n = 5, arr1[] = {1, 1, 1, 1, 1}
m = 5, arr2[] = {2, 2, 2, 2, 2}
Output: 
1 2
Explanation: 
Distinct elements including both the arrays are: 1 2.

Your Task: 
You do not need to read input or print anything. Complete the function findUnion() that takes two arrays arr1[], arr2[], and their size n and m as input parameters and returns a list containing the union of the two arrays.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).

Constraints:
1 <= n, m <= 10^5
-109 <= arr1[i], arr2[i] <= 10^9

CODE :
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution{
    public:
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i = 0, j = 0; 
        vector<int> ans;
        //Using two pointers i and j over the two arrays which helps
        //in storing the smaller element.
        while (i < n && j < m) 
        { 
            //Updating the pointer i until we have identical 
            //elements at consecutive position in arr1.
            while(  i+1<n  &&  arr1[i]==arr1[i+1]  )
                i++;
            //Updating the pointer j until we have identical 
            //elements at consecutive position in arr2.
            while(  j+1<m  &&  arr2[j]==arr2[j+1]  )
                j++;
            //Comparing element of the arrays arr1 and arr2 at pointers
            //i and j and accordingly storing the smaller element
            //and updating the pointers.
            if (arr1[i] < arr2[j]) 
                ans.push_back(arr1[i++]);
            else if (arr2[j] < arr1[i]) 
                ans.push_back(arr2[j++]);   
            else
            {
                //If arr1[i] is same as arr2[j], we update both pointers.
                ans.push_back(arr2[j++]);
                i++;
            }
        } 
        //Storing the remaining elements of first array (if there are any).
        while(i < n)
        {
            //Updating the pointer i until we have identical 
            //elements at consecutive position in arr1.
            while(  i+1<n  &&  arr1[i]==arr1[i+1]  )
                i++;
            //Storing the elements.
            ans.push_back(arr1[i++]);
        }
        //Storing the remaining elements of second array (if there are any).
        while(j < m)
        {
            //Updating the pointer j until we have identical 
            //elements at consecutive position in arr2.
            while(  j+1<m  &&  arr2[j]==arr2[j+1]  )
                j++;
             //Storing the elements
            ans.push_back(arr2[j++]);
        } 
        //returning the list containing the union of the two arrays. 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int T;
	cin >> T;
	while(T--){
	    int N, M;
	    cin >>N >> M;
	    int arr1[N];
	    int arr2[M];
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends