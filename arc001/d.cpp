#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

const int MAX_N = 100010;

class segTree{
    private:
        //セグメントツリーを持つ配列
        int n, dat[4 * MAX_N];
        int query(int a, int b, int k, int l, int r){
            //[a, b) と[l, r)が交差しなければ、INT_MAX
            if(r <= a || b <= l) return INT_MAX;

            //[a,b)が[l,r)を完全に含んでいれば、この節点の値
            if(a <= l && r <= b) return dat[k];
            else{
                //そうでなければ、２つのこの最小値
                int vl = query(a, b, k * 2, l, ( l + r) / 2);
                int vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
                return min(vl, vr);
            }
        }
    public:
        void init(int n_){
            n = 1;
            while(n < n_) n *= 2;
            rep(i,2 * n) dat[i] = INT_MAX;
        }
        void init(int a[MAX_N], int n_){ //配列aでの初期化
            n = 1;
            while(n < n_) n *= 2;
            for(int i = n; i < n * n; i++){
                dat[i] = a[i - n];
            }
            for(int i = n - 1; i >= 1; i--){
                dat[i] = min(dat[i * 2], dat[i * 2 + 1]);
            }
        }
        void update(int i, int x){
            i += n; //葉の節点
            dat[i] = x;
            while(i > 0){ //登りながら更新
                dat[i / 2] = min(dat[i], dat[i^1]);
                i = i / 2;
            }
        }
        //[a, b)の最小値を求める
        int query(int a, int b){
            return query(a,b,1,0,n);
        }
};

int main(){
    int n, start, goal;
    cin >> n >> start >> goal;

    vector<int> l(n), r(n);
    rep(i,n){
        cin >> l[i] >> r[i];
    }
}
