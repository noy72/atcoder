#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int M = 1000000007;

map<int, int> m;

void prime_factor(int n){
	for(int i = 2; i * i <= n; i++){
		while(n % i == 0){
			++m[i];
			n /= i;
		}
	}
	if(n != 1) m[n]++;
}

int main(){
	int a, b;
	cin >> a >> b;

	range(i,b + 1,a + 1){
		prime_factor(i);
	}

	long long cnt = 1;
	for(auto i : m){
		cnt *= (i.second + 1);
		cnt %= M;
		//cout << i.first << ' ' << i.second << endl;
	}

	cout << cnt << endl;
}
