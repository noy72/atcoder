#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int MAX_N = 200005;

//[1, n]
int bit[MAX_N + 1] = {0};

int sum(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x, int n){
    while(i <= MAX_N){
        bit[i] += x;
        //bit[i] = max(bit[i], x);
        i += i & - i;
    }
}

int main(){
    int q;
    cin >> q;

    rep(i,q){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            add(x, 1, q);
        }else{
            int right = MAX_N, left = 0;
            rep(i,50){
                int mid = (right + left ) / 2;
                if(sum(mid) < x) left = mid;
                else right = mid;
            }
            add(left + 1, -1, q);
            cout << left + 1 << endl;
        }
    }
}
