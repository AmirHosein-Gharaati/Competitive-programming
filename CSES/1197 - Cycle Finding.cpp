#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, m;
typedef pair<ll ,ll> ii;

struct Edge {
    int a, b;
    ll cost;
};

vector<Edge> edges;
const ll INF = 1e15;
vector<ll> d;
vector<ll> p;



void solve(){

    d = vector<ll>(n+1, INF);
    p = vector<ll>(n+1, -1);

    ll x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<ll> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}


int main(){

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        Edge e;
        e.a = a;
        e.b = b;
        e.cost = w;
        edges.push_back(e);
    }

    solve();

    return 0;
}