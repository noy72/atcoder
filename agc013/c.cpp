#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	long long n, l, t;
	cin >> n >> l >> t;

	vector<long long> d(n); //移動後の位置（番号は無視）
	long long fx, fw;
	long long c = 0; //衝突回数
	rep(i,n){
		long long x, w;
		cin >> x >> w;
		d[i] = (((w == 1 ? t : -t) + x) % l + l) % l;

		if(i && fw != w){
			long long dis = x - fx;
			if(fw == 2) dis = l - dis;

			if(dis > t * 2){
				//一度も交差しない
				continue;
			}

			show(t)
				show(dis)
			c += (t * 2 - dis + l) / l;
		}else{
			fx = x;
			fw = w;
		}
	}

	long long X = d[0];
	sort(all(d));
	//for(auto i : d){ out << i << endl; }
	//show(c)

	int offset = distance(d.begin(), upper_bound(all(d), X));
	for(int i = 0, p = fw == 1 ? c : n - c % n; i < n; i++, p++){
		cout << d[(offset - 1 + n - c + i) % n] << endl;
	}
}
