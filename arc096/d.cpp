#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

vector<long long> getRSum(vector<long long> v){
	reverse(all(v));
	vector<long long> res(v.size() + 1);
	rep(i,v.size()){
		res[i + 1] = res[i] + v[i];
	}
	return res;
}

vector<long long> getSum(vector<long long> v){
	vector<long long> res(v.size() + 1);
	rep(i,v.size()){
		res[i + 1] = res[i] + v[i];
	}
	return res;
}

const long long INF = (1LL << 60);

int main(){
	int n;
	long long c;
	cin >> n >> c;

	vector<long long> x(n), v(n);
	rep(i,n){
		cin >> x[i] >> v[i];
	}
	long long last = x.back();
	for(int i = n - 1; i >= 1; i--){
		x[i] = x[i] - x[i - 1];
	}

	vector<long long> fx, bx;
	fx = getSum(x);

	vector<long long> cx(n);
	rep(i,n - 1){
		cx[i] = x[i + 1];
	}
	cx.back() = c - last;
	bx = getRSum(cx);
	//cout << cx << endl;
	//cout << bx << endl;

	vector<long long> fp, bp;
	fp = getSum(v);
	bp = getRSum(v);
	//cout << fx  << endl;
	//cout << bx  << endl;

	long long ans = 0;
	rep(i,n + 1){
		ans = max(ans, fp[i] - fx[i]);
	}
	rep(i,n + 1){
		ans = max(ans, bp[i] - bx[i]);
	}

	vector<long long> fr(n + 1), br(n + 1);
	rep(i,n + 1){
		//'cout << fp[i + 1] - fx[i + 1] * 2 << endl;
		fr[i] = fp[i] - fx[i] * 2;
	}
	rep(i,n + 1){
		br[i] = bp[i] - bx[i] * 2;
	}

	vector<long long> fmax(n + 1), bmax(n + 1);
	long long fmaxi = -INF, bmaxi = -INF;
	rep(i,n + 1){
		//cout << fp[i + 1] << ' ' << fx[i + 1] << endl;
		fmaxi = max(fmaxi, fp[i] - fx[i]);
		fmax[i] = fmaxi;
	}
	rep(i,n + 1){
		bmaxi = max(bmaxi, bp[i] - bx[i]);
		bmax[i] = bmaxi;
	}
	//cout << fr << endl;
	//cout << br << endl;
	//cout << fmax << endl;
	//cout << bmax << endl;

	rep(i,n + 1){
		//cout << fr[i] << ' ' << bmax[ n - i] << endl;
		ans = max(ans, fr[i] + bmax[n - i]);
	}
	rep(i,n){
		ans = max(ans, br[i] + fmax[n - i]);
	}
	cout << ans << endl;
}
