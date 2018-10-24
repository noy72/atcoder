#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	vector<int> ab(26,0), bb(26,0);
	rep(i,n){
		cin >> a[i];
		for(int j = 0; a[i] != 0; j++, a[i] >>= 1){
			if(a[i] bitand 1) ab[j]++;
		}
	}
	rep(i,n){
		cin >> b[i];
		for(int j = 0; b[i] != 0; j++, b[i] >>= 1){
			if(b[i] bitand 1) bb[j]++;
		}
	}

	vector<int> c(27,0);
	string bit;
	rep(i,26){
		bit += (ab[i] * (n - bb[i]) + bb[i] * (n - ab[i]) + c[i]) % 2 + '0';
		c[i + 1] = min(ab[i], bb[i]) % 2;
		show(c[i + 1])
	}
	show(bit)
	//cout << ans << endl;
}
