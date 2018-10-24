#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	long long n;
	cin >> n;

	vector<long long> a(n);
	rep(i,n){
		cin >> a[i];
	}

	int p = 0;
	vector<long long> right(n), left(n);
	rep(i,n){
		if(a[p] + (i - p) * (i - p) > a[i]){
			p = i;
			left[i] = a[p];
		}else{
			left[i] = a[p] + (i - p) * (i - p);
		}
	}

	p = n - 1;
	for(long long i = n - 1; i >= 0; i--){
		if(a[p] + (i - p) * (i - p) > a[i]){
			p = i;
			right[i] = a[p];
		}else{
			right[i] = a[p] + (i - p) * (i - p);
		}
	}

	rep(i,n){
		cout << min(left[i], right[i]) << endl;
	}
}
