#include <bits/stdc++.h>

using namespace std;
   
int main() { 
    int n;
    double adad,adad2,summ,maxx,minn;
    cin >> n >> adad;
    summ = maxx = minn = adad;
    for (int i = 0; i < n-1; i++){
        cin >> adad2;
        maxx = max(adad2,maxx);
        minn = min(adad2,minn);
        summ += adad2;
    }
    printf("Max: %.3lf\nMin: %.3lf\nAvg: %.3lf",
    int((maxx*1000))* 0.001f,
    int((minn*1000))* 0.001f,
    int((summ/n*1000))* 0.001f);
    return 0; 
} 