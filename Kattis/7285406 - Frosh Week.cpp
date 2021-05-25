#include<bits/stdc++.h>

using namespace std;

long long counter = 0;

vector<int> arr; 

void swapping(int &a, int &b) {     
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void merge(int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays

   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays

   for(i = 0; i<nl; i++)
      larr[i] = arr[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = arr[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real arr

   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
         counter += nl-i;
      }
      k++;
   }
   while(i<nl) {       //extra element in left arr
      arr[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right arr
      arr[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort( int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort( l, m);
      mergeSort( m+1, r);
      merge( l, m, r);
   }
}

int main() {
    
    int n;
    cin >> n;
    int number;
    for(int i=0;i<n;i++){
        cin>>number;
        arr.push_back(number);
    }
    mergeSort(0, n-1);
    cout << counter;


    return 0;
}