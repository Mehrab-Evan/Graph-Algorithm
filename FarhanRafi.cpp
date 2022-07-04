//Floyd Warshal
#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
#define mod 1000000007
#define ll long long
#define dd double
#define pb push_back
#define mp make_pair
#define ff first
#define se second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define sp ' ' 
#define nl endl 
#define vi vector<int> 
#define vs vector<string> 
#define mai map<ll,int> 
#define mas map<string ,int> 
#define ss  string 
#define INF 999
#define nV 4
void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}


int main(){
    
    int graph[nV][nV]={{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};;
    floydWarshall(graph);

return 0;
}


//Heapsort
// C++ program for implementation of Heap Sort
#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver code
int main()
{
    int n;cin>>n;

    int arr[n] ;
    for(int i=0;i<n;i++)cin>>arr[i];
   // int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr,n);
    return 0;
}


//LCS
#include<bits/stdc++.h>
#define ll long long
#define ss string
#define nl endl
#define sp " "
//#define sort(ar) sort(ar,ar+n);
#define vso() sort(v.begin(),v.end());
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
using namespace std;

void lcsAlgo(string S1, string  S2, int m, int n) {
  int LCS_table[m + 1][n + 1];


  // Building the mtrix in bottom-up way
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
   cout<<index<<nl;

  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
      i--;
    else
      j--;
  }

  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}

int main() {
  string s1,s2;cin>>s1>>s2;
  int m = s1.size();
  int n = s2.size();

  lcsAlgo(s1, s2, m, n);
}


//Matrics Chain Multiplication

#include <bits/stdc++.h>
#define pi (3.141592653589)
#define mod 1000000007
#define ll long long
#define dd double
#define pb push_back
#define mp make_pair
#define ff first
#define se second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define sp ' ' 
#define nl endl 
#define vi vector<int> 
#define vs vector<string> 
#define mai map<ll,int> 
#define mas map<string ,int> 
#define ss  string 
using namespace std;
int MatrixChainOrder(int p[], int n)
{
	int m[n][n];
	int i, j, k, L, q;
	for (i = 1; i < n; i++)m[i][i] = 0;

	// L is chain length.
	for (L = 2; L < n; L++){
		for (i = 1; i < n - L + 1; i++){
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++){
				// q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}

	return m[1][n - 1];
}
int main()
{
	int arr[] = { 30, 35,15,5,10,20,25 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of multiplications is "<< MatrixChainOrder(arr, size);

	getchar();
	return 0;
}



//Merge Sort

#include<bits/stdc++.h>
#define ll long long
#define ss string
#define nl endl
#define sp " "
#define sort(ar) sort(ar,ar+n);
#define vso() sort(v.begin(),v.end());
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
using namespace std;
void merge(int ar[],int l,int m,int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = ar[l + i];
    for (int j = 0; j < n2; j++)
        M[j] = ar[m + 1 + j];
    int i=0, j=0, k=l;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            ar[k] = L[i];
            i++;
        } else {
            ar[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        ar[k] = M[j];
        j++;
        k++;
    }

     return;
}
void mergesort(int ar[],int left,int right){
	if(left>=right)return;
	int mid=left+(right-left)/2;
	mergesort(ar,left,mid);
	mergesort(ar,mid+1,right);
	merge(ar,left,mid,right);
	return;
}
int main(){


    op();
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
    	cin>>ar[i];
      }
    mergesort(ar,0,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<sp;
        }
   return 0;

}


//Quick Sort
#include<bits/stdc++.h>
#define ll long long
#define ss string
#define nl endl
#define sp " "
//#define sort(ar) sort(ar,ar+n);
#define vso() sort(v.begin(),v.end());
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
using namespace std;
int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}






int main(){
    op();

    int n;cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    quickSort(ar,0,n-1);

    for(int i=0;i<n;i++){
        cout<<ar[i]<<sp;
    }

   return 0;

}

