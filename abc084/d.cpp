#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int kN = 100005;
void primeNumber(bool prime[kN]){
	rep(i,kN) prime[i] = 1;
	prime[0] = prime[1] = 0;
	rep(i,kN){
		if(prime[i]){
			for(int j = i + i; j < kN; j+=i){
				prime[j] = 0;
			}
		}
	}
}

int main(){
	bool p[kN];
	primeNumber(p);

	bool like[kN] = {0};
	for(int i = 3; i < kN; i+=2){
		if(p[i] and p[(i + 1) / 2]) like[i] = true;
	}



	vector<int> s(100005, 0);
	range(i,1,100001){
		s[i] = like[i] + s[i - 1];
	}

	int q;
	cin >> q;

	rep(i,q){
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}
}
