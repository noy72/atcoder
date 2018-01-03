#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;

	vector<pair<long long, bool>> v(n + q); //地点、 false : 点、 true : クエリ
	rep(i,n){
		cin >> v[i].first;
		v[i].first += 1e9;
		v[i].second = false;
	}

	vector<long long> qv(q);
	rep(i,q){
		cin >> qv[i];
		qv[i] += 1e9;
		v[i + n].first = qv[i];
		v[i + n].second = true;
	}

	sort(all(v));

	long long left = (v[0].second ? 0 : 1), right = n - left; // left := x_i <= cur を満たす点の数
	long long sum = 0;
	rep(i,n + q){
		if(not v[i].second){
			sum += v[i].first - v[0].first;
		}
	}

	map<int,long long> ans;
	if(v[0].second) ans[v[0].first] =  sum;
	range(i,1,n + q){
		long long dis = v[i].first - v[i - 1].first;
		sum += left * dis;
		sum -= right * dis;
		if(v[i].second){
			ans[v[i].first] = sum;
		}else{
			left++;
			right--;
		}
	}

	for(auto i : qv){
		cout << ans[i] << endl;
	}
}
