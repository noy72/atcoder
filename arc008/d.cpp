#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;

const int MAX_N = 1 << 17;

//セグメントツリーを持つ配列
long long n;
pair<double, double> dat[2 * MAX_N - 1];

void init(long long n_){
    n = 1;
    while(n < n_) n *= 2;
    rep(i,2 * n - 1) dat[i] = make_pair(1,0);
}

void update(long long k, double a, double b){
    //葉の節点
    k += n - 1;
    dat[k] = make_pair(a,b);
    //登りながら更新
    while(k > 0){
        k = (k - 1) / 2;
        long long r = k * 2 + 1, l = k * 2 + 2;
        //show(k) cout << dat[r].first << ' ' << dat[r].second<< endl;
        dat[k] = make_pair(dat[r].first * dat[l].first, dat[r].second * dat[l].first + dat[l].second);
    }
}

void compress(vector<long long> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}

long long lb(vector<long long> v, long long num){
    return lower_bound(all(v), num) - v.begin();
}

int main(){
    long long m;
    cin >> n >> m;

    pair<long long, pair<double, double>> inp[100005];
    vector<long long> x;
    rep(i,m){
        cin >> inp[i].first >> inp[i].second.first >> inp[i].second.second;
        x.emplace_back(inp[i].first);
    }
    compress(x);
    n = x.size();
    init(n);

    double mini = 1, maxi = 1;

    rep(i,m){
        update(lb(x, inp[i].first), inp[i].second.first, inp[i].second.second);
        mini = min(mini, dat[0].first + dat[0].second);
        maxi = max(maxi, dat[0].first + dat[0].second);
    }
    cout <<fixed << setprecision(8) <<  mini << endl << maxi << endl;
}
