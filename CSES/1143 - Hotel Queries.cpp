#include <bits/stdc++.h>

using namespace std;

#define int long long
#define DEFAULT 0
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) | 1)

int ans;
int n, q;

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
    int res2 = build(mid+1 ,right, rc(id));
    tree[id] = segment(left, right, max(res1, res2));
    return tree[id].val;
}

int update(int &val, int id = 1) {

    if(tree[id].l == tree[id].r) {
        if(tree[id].val >= val) {
            tree[id].val -= val;
            ans = tree[id].l + 1;
            return val;
        }
    }

    if(tree[id].l >= 0 && tree[id].r <= n-1) {
        if(tree[id].val >= val) {
            if(tree[lc(id)].val >= val) {
                int res = update(val, lc(id));
                if(res > 0) {
                    tree[id].val = max(tree[rc(id)].val, tree[lc(id)].val);
                    return val;
                }
            }
            if(tree[rc(id)].val >= val) {
                int res = update(val, rc(id));
                if(res > 0){
                    tree[id].val = max(tree[rc(id)].val, tree[lc(id)].val);
                    return val;
                }
            }
        } else return 0;
    }
    return 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    arr = vector<int>(n);

    for(int i = 0 ;i < n; i++)
        cin >> arr[i];


    build(0, n-1);

    while(q--) {
        int h;
        cin >> h;
        if(update(h)) {
            cout << ans << " ";
        } else {
            cout << 0 << " ";
        }

    }

    return 0;
}