#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<long long> nico;

bool nicoVector(long long& k){
	bool res = false;
	for(auto i : nico){
		while(k % i == 0){
			res = true;
			k /= i;
		}
	}
	return false;
}

int main(){
	long long n;
	cin >> n;

	long long a = 0, b = 0;
	rep(i,17){
		a *= 10;
		b *= 10;
		if(i % 2){
			a += 2;
			b += 5;
		}else{
			a += 5;
			b += 2;
		}
		nico.emplace_back(a);
		nico.emplace_back(b);
	}

	sort(all(nico));

	int ans = 0;
	while(true){
		ans++;
		if(not nicoVector(n)) break;
	}
	cout << ans + n << endl;
}
