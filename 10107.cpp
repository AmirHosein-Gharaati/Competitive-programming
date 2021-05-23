#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a;
    int x,len=0;
    int median;
    while (scanf("%d",&x)!=EOF){
        a.push_back(x);
        len++;
        sort(a.begin(),a.end());
        median = a[len/2];

        if (len%2 == 0){
            median += a[len/2 - 1];
            median /= 2;
        }
        printf("%d\n",median);
    }

    return 0;
}