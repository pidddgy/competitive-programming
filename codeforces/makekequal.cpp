// https://codeforces.com/contest/1328/problem/F

#include <bits/stdc++.h>
    #define int long long
    #define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

int n;
int minVal(int x, int y) { return (x < y)? x: y; }  
  
// A utility function to get the  
// middle index from corner indexes.  
int getMid(int s, int e) { return s + (e -s)/2; }  
  
/* A recursive function to get the 
minimum value in a given range  
of array indexes. The following  
are parameters for this function.  
  
    st --> Pointer to segment tree  
    index --> Index of current node in the  
           segment tree. Initially 0 is  
           passed as root is always at index 0  
    ss & se --> Starting and ending indexes  
                of the segment represented  
                by current node, i.e., st[index]  
    qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)  
{  
    // If segment of this node is a part  
    // of given range, then return  
    // the min of the segment  
    if (qs <= ss && qe >= se)  
        return st[index];  
  
    // If segment of this node 
    // is outside the given range  
    if (se < qs || ss > qe)  
        return INT_MAX;  
  
    // If a part of this segment 
    // overlaps with the given range  
    int mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}  
  
// Return minimum of elements in range 
// from index qs (query start) to  
// qe (query end). It mainly uses RMQUtil()  
int RMQ(int *st, int n, int qs, int qe)  
{  
    // Check for erroneous input values  

    // watch(qs)
    // watch(qe)
    // watch(qe > n-1)
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input" << endl;  
        return -1;  
    }  
  
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}  
  
// A recursive function that constructs 
// Segment Tree for array[ss..se].  
// si is index of current node in segment tree st  
int constructSTUtil(int arr[], int ss, int se, 
                                int *st, int si)  
{  
    // If there is one element in array, 
    // store it in current node of  
    // segment tree and return  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    // If there are more than one elements,  
    // then recur for left and right subtrees  
    // and store the minimum of two values in this node  
    int mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),  
                    constructSTUtil(arr, mid+1, se, st, si*2+2));  
    return st[si];  
}  
  
/* Function to construct segment tree  
from given array. This function allocates 
memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
int *constructST(int arr[], int n)  
{  
    // Allocate memory for segment tree  
  
    //Height of segment tree  
    int x = (int)(ceil(log2(n)));  
  
    // Maximum size of segment tree  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    int *st = new int[max_size];  
  
    // Fill the allocated memory st  
    constructSTUtil(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
}  
  


signed main() {

    int k;
    cin >> n >> k;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int *st = constructST(a, n);

    int l = 0;
    int r = l+k-1;

    int sum = 0;
    int smallest = INT_MAX;
    int best = INT_MAX;

    for(int i = l; i <= r; i++) {
        sum += a[i];
        // watch(a[i])
        smallest = min(smallest, a[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    watch(sum)
    while(r < n) {

        cout << "ans for " << l << " " << r << " is " << sum - ((k-1)*smallest) << endl;
        watch(sum)
        watch(smallest)
        best = min(best, sum - (k*smallest));

        sum -= a[l];
        l++;
        r++;
        sum += a[r];

        if(r != n)
        smallest = RMQ(st, n, l, r);


        cerr << endl;
    }

    cout << best << endl;
}