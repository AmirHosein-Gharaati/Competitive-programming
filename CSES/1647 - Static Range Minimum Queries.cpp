#include <bits/stdc++.h>

using namespace std;

#define int long long
#define DEFAULT 10e9
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) | 1)

struct segment
{
    int l, r;
    int val;
    segment(){};
    segment(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {}
} tree[1000000];

vector<int> arr;

int build(int left, int right, int id = 1) {
    if(left == right) {
        tree[id] = segment(left, right, arr[left]);
        return arr[left];
    }

    int mid = (left + right) >> 1;

    int res1 = build(left, mid, lc(id));
    int res2 = build(mid+1, right, rc(id));
    tree[id] = segment(left, right, min(res1, res2));
    
    return min(res1, res2);
}

int query(int left, int right, int id = 1) {
    if(tree[id].l >= left && tree[id].r <= right) return tree[id].val;
    if(tree[id].l > right || tree[id].r < left) return DEFAULT;
    return min(query(left, right, lc(id)), query(left, right, rc(id)));
}

signed main() {

    int n, q;
    cin >> n >> q;

    arr = vector<int>(n);

    for(int i = 0 ;i < n; i++) 
        cin >> arr[i];

    build(0, n-1);

    while(q--) {
        int a, b;
        cin >> a >> b;
        
        cout << query(a-1, b-1) << endl;
    }
    

    return 0;
}