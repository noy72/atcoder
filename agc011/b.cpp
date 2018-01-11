#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;


int n;

bool C(int mid, vector<int> v){
    long long sum = v[mid];
    rep(i,n){
        if(i == mid) continue;
        if(sum * 2 < v[i]) return false;
        sum += v[i];
    }
    return true;
}


int main(){
    cin >> n;

    vector<int> v(n);
    rep(i,n) cin >> v[i];
    sort(all(v));

    int right = n - 1, left = 0;
    rep(i,50){
        int mid = (right + left ) / 2;
        if(C(mid,v)) right = mid;
        else left = mid;
    }
    cout << n - right << endl;
}
