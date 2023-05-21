#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	int n;
	cin >> n;
	
	vector<int> arr = vector<int>(n);

	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
	}
	
	int counter = 0;
	for(int i = 1; i < n; i++){
		if(arr[i] < arr[i-1]) {
			int diff = abs(arr[i] - arr[i-1]);
			counter += diff;
			arr[i] += diff;
		}
	}

	cout << counter;
	
	return 0;

}
