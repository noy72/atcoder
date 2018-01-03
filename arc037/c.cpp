#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

long long n, k;
vector<long long> a, b;

bool C(long long mid){
	long long cnt = 0;
	rep(i,n){
		cnt += distance(a.begin(), upper_bound(all(a), mid / b[i]));
	}
	return cnt < k;
}

int main(){
	cin >> n >> k;

	a = vector<long long>(n);
	b = vector<long long>(n);
	rep(i,n){
		cin >> a[i];
	}
	sort(all(a));
	rep(i,n){
		cin >> b[i];
	}

	long long right = LONG_MAX, left = 0;
	rep(i,100){
		long long mid = (right + left) / 2;
		if(C(mid)) left = mid;
		else right = mid;
	}

	cout << left + 1 << endl;
}
