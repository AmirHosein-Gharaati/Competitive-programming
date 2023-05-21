#include <bits/stdc++.h>

using namespace std;

#define int long long
#define DEFAULT 0
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) | 1)

struct segment
{
    int l, r;
    int val, pro, len;
    segment(){};
    segment(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {}
} tree[1000000];

vector<int> arr;

int build(int left, int right, int id = 1)
{
    if (left == right)
    {
        tree[id] = segment(left, right, arr[left]);
        tree[id].len = 1;
        return arr[left];
    }

    int mid = (left + right) >> 1;
    int res = 0;
    res += build(left, mid, lc(id));
    res += build(mid + 1, right, rc(id));

    tree[id] = segment(left, right, res);
    tree[id].len = (right - left + 1);
    return res;
}

int query(int left, int right, int id = 1) {
    if(tree[id].l >= left && tree[id].r <= right) return tree[id].val;
    if(tree[id].l > right || tree[id].r < left) return DEFAULT;
    return query(left, right, lc(id)) + query(left, right, rc(id));
}

int update(int left, int right, int &new_val, int id = 1) {
    if(tree[id].l >= left && tree[id].r <= right) {
        tree[id].val = new_val * tree[id].len;
        return tree[id].val;
    }

    if(tree[id].l > right || tree[id].r < left) return tree[id].val;

    int res = 0;
    res += update(left, right, new_val, lc(id));
    res += update(left, right, new_val, rc(id));
    tree[id].val = res;
    return tree[id].val;
}

signed main()
{

    int n, q;

    cin >> n >> q;

    arr = vector<int>(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, n - 1);

    while (q--)
    {
        int type, a, b;

        cin >> type >> a >> b;

        if (type == 1) // update
        {
            update(a-1, a-1, b);
        }
        else // sum
        {
            cout << query(a-1, b-1) << endl;
        }
    }

    return 0;
}