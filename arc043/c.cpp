#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

#define int long long

const int MAX_N = 100005;

//[1, n]
int bit[MAX_N + 1] = {0};

int sum(int i){
	int s = 0;
	while(i > 0){
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x){
	while(i <= MAX_N){
		bit[i] += x;
		//bit[i] = max(bit[i], x);
		i += i & - i;
	}
}

signed main(){
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	rep(i,n){ cin >> a[i]; }

	map<int,int> m;
	rep(i,n){
		cin >> b[i];
		m[b[i]] = i + 1;
	}

	vector<int> sa(n); //bの大小関係でaを置き換えたもの
	rep(i,n){
		sa[i] = m[a[i]];
	}

	vector<int> r(n,0);
	rep(i,n){
		r[i] = sum(n + 1) - sum(sa[i] + 1);
		add(sa[i] + 1, 1);
	}

	long long sum = accumulate(all(r), 0LL);
	if(sum % 2){
		cout << -1 << endl;
		return 0;
	}
	sum /= 2;

	//for(auto i : r){ cout << i << ' '; } cout << endl;
	//show(sum)

	vector<int> ridx(n + 1); // i = a[j] となるような j を返す
	rep(i,n){
		ridx[a[i]] = i;
	}

	vector<bool> used(n + 1,0);
	vector<int> ans;
	rep(i,n){
		int t = ridx[b[i]];
		if(sum >= r[t]){ //数列 a の b[i] を r[b[i]]回スワップすると、数列 b と同じ位置まで持っていける
			sum -= r[t];
			ans.emplace_back(b[i]);
			used[b[i]] = true;
		}else{
			r[t] -= sum; //sum回スワップできる == 前から r[i] - sum 番目にある

			int j = 0;
			while(r[t]){
				if(not used[a[j]]){
					r[t]--;
					ans.emplace_back(a[j]);
				}
				j++;
			}

			ans.emplace_back(b[i]);
			used[b[i]] = true;

			for(; j < n; j++){
				if(not used[a[j]]) ans.emplace_back(a[j]);
			}
			break;
		}
	}

	rep(i,n){
		if(i) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
}
