#include <bits/stdc++.h>

using namespace std;



int arr[1000001];
int n;

int  max_area(int p,int r){
    if(p==r){
        return arr[p];
    }
    int q = (p+r)>>1;
    int m1 = max_area(p,q);
    int m2 = max_area(q+1,r);

    int cur_h = min(arr[q],arr[q+1]);
    int m3 = cur_h*2;
    int li = q;
    int ri = q+1;
    while(li>p || ri<r){
        for(;li>p && arr[li-1]>=cur_h;li--){
        }
        for(;ri<r && arr[ri+1]>=cur_h;ri++){
        }
        m3 = max(m3,cur_h * (ri-li+1));
        if(li==p){
            cur_h = arr[ri+1];
        }else if(ri==r){
            cur_h = arr[li-1];
        }else{
            cur_h = max(arr[li-1],arr[ri+1]);
        }
    }

    return max(max(m1,m2),m3);
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",arr + i);
    }

    
    printf("%d\n",max_area(0,n-1));
    return 0;
}