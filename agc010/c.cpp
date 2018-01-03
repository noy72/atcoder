#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

vector<vector<int>> g;
vector<long long> a;
vector<bool> used;
bool ans;
int loot;

long long requirePairNumber(vector<long long> v){
	sort(all(v), greater<long long>());

	long long sum = 0;
	sum += v[1];
	v[0] -= v[1];

	long long remainder = 0;
	range(i,2,v.size()){
		sum += v[i] / 2;
		if(v[i] % 2){
			if(v[0] > 0){
				v[0]--;
				sum++;
			}else{
				remainder++;
			}
		}
	}

	sum += remainder / 2;
	return sum;
}

long long dfs(int cur){
	used[cur] = true;

	vector<long long> v;
	for(auto to : g[cur]){
		if(used[to]) continue;
		v.emplace_back(dfs(to));
	}

	//show(cur) for(auto i : v){ cout << i << ' ' ; } cout << endl;

	if(v.empty()){
		//cout << "return " << a[cur] << endl;
		return a[cur];
	}else{
		long long childSum = accumulate(all(v), 0);
		if(childSum < a[cur]){ //どのようにしても石が取りきれない
			ans = false;
			return 0;
		}

		long long maximumPair = min(childSum - *max_element(all(v)), childSum / 2);
		//show(maximumPair)
		if(loot == cur and maximumPair != a[cur]){
			ans = false;
			return 0;
		}

		long long needPair = childSum - a[cur];
		if(maximumPair >= needPair){
			return a[cur] - needPair;
		}else{
			ans = false;
		}

		return 0;
	}
}

int main(){
	int n;
	cin >> n;

	a = vector<long long>(n);
	rep(i,n){
		cin >> a[i];
	}

	g = vector<vector<int>>(n);
	rep(i,n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;

		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	if(n == 2){
		ans = a[0] == a[1];
	}else{
		loot = 0;
		while(g[loot].size() == 1) loot++; //葉ではない頂点を探す

		used = vector<bool>(n,0);
		ans = true;
		dfs(loot);
	}

	cout << (ans ? "YES" : "NO") << endl;
}
