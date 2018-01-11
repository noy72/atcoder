#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int MAX_N = 100005;

class segTree{
    public:
        int n, dat[4 * MAX_N];
        virtual int query(int, int, int, int, int) = 0;
        void init(int n_){}
        void init(int a[MAX_N], int n_){
            n = 1;
            while(n <= n_) n *= 2;
            for(int i = n; i < n * n; i++){
                dat[i] = a[i - n];
            }
            for(int i = n - 1; i >= 1; i--){
                dat[i] = min(dat[i * 2], dat[i * 2 + 1]);
            }
        }
};

class rangeAddQuery : public segTree{
    private:
        int dat_add[4 * MAX_N];
        int query(int a, int b, int k, int l, int r){
            if(b <= l || r <= a) return 0;
            else if(a <= l && r <= b) return dat[k] * (r - l) + dat_add[k];
            else{
                int res = (min(b, r) - max(a, l)) * dat[k];
                res += query(a, b, k * 2, l, (l + r) / 2);
                res += query(a, b, k * 2 + 1, (l + r) / 2, r);
                return res;
            }
        }
        void add(int a, int b, int k, int l, int r, int x){
            if(a <= l && r <= b){
                dat[k] += x;
            }else if(l < b && a < r){
                dat_add[k] += (min(b, r) - max(a, l)) * x;
                add(a, b, k * 2, l, (l + r) / 2, x);
                add(a, b, k * 2 + 1, (l + r) / 2, r, x);
            }
        }
    public:
        void init(int n_){
            n = 1;
            while(n <= n_) n *= 2;
            rep(i,2 * n) dat[i] = dat_add[i] = 0;
        }

        void update(int i, int x){
            add(i, i + 1, 1, 0, n, x);
        }
        int query(int a, int b){
            return query(a,b,1,0,n);
        }
        void add(int s, int t, int x){
            add(s, t, 1, 0, n, x);
        }
        int get(int a){ return query(a, a + 1); }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v[100005]; //v[区間の長さ] = (l, r)
    rep(i,n){
        int l, r;
        cin >> l >> r;
        v[r - l + 1].emplace_back(make_pair(l, r));
    }

    rangeAddQuery seg;
    seg.init(m);

    int segment_num = n;
    range(i,1,m + 1){
        int ret = 0;
        for(int j = i; j <= m; j+=i) ret += seg.get(j);
        //show(i)
        //show(ret)
        //show(seg.get(3))
        for(auto e : v[i]){
            //show(i)
            //cout << e.first << ' ' << e.second << endl;
            seg.add(e.first, e.second + 1, 1);
        }
        cout << segment_num + ret << endl;
        segment_num -= v[i].size();
    }
}
