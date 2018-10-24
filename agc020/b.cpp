#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const long long INF = (1LL << 60);
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<long long> a(n);
	rep(i,n){
		cin >> a[i];
	}

	long long maxi = 2, mini = 2;
	auto f = [](long long t, long long num){ return t - t % num; };
	for(auto i = a.rbegin(); i != a.rend(); i++){
		auto num = *i;
		{
			long long right = INF, left = num;
			rep(i,100){
				long long mid = (right + left) / 2;
				if(mini <= f(mid, num)) right = mid;
				else left = mid;
			}
			mini = right;
		}
		if(mini > maxi){
			cout << -1 << endl;
			return 0;
		}
		{
			long long right = INF, left = num;
			rep(i,100){
				long long mid = (right + left) / 2;
				if(maxi >= f(mid, num)) left = mid;
				else right = mid;
			}
			maxi = left;
		}
		//cout << mini << ' ' << maxi << endl;
	}
	cout << mini << ' ' << maxi << endl;
}
