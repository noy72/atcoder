#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<long long> w, d;
long long n, k;

bool C(long long mid){
	long long f = 0;

	rep(i,n){
		if(mid - w[i] >= 0){
			f++;
			f+=(mid - w[i]) / d[i];
		}
	}

	return k <= f;
}

int main(){
	cin >> n >> k;

	w = vector<long long>(n);
	d = vector<long long>(n);
	rep(i,n){
		cin >> w[i] >> d[i];
	}

	long long right = (1LL << 61), left = 0;
	rep(i,100){
		long long mid = (right + left ) / 2;
		if(C(mid)) right = mid;
		else left = mid;
	}
	cout << right << endl;
}
