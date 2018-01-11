#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

const int M = 1000000007;

int main(){
	int n;
	cin >> n;

	vector<pair<int, bool>> p(n * 2); //1 : PC, 0 : power supply
	rep(i,n){
		int a;
		cin >> a;
		p[i] = make_pair(a, true);
	}
	rep(i,n){
		int b;
		cin >> b;
		p[i + n] = make_pair(b, false);
	}

	sort(all(p));

	int pc = 0, power = 0;
	long long ans = 1;
	for(auto i : p){
		if(i.second){
			if(power != 0){
				ans *= power;
				power--;
			}else{
				pc++;
			}
		}else{
			if(pc != 0){
				ans *= pc;
				pc--;
			}else{
				power++;
			}
		}
		ans %= M;
	}
	cout << ans << endl;
}
