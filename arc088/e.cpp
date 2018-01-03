#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

const int MAX_N = 200005;

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
		i += i & - i;
	}
}

bool impossible(vector<vector<int>> v){
	int odd = 0;
	rep(i,26){
		if(v[i].size() % 2) odd++;
	}
	return odd >= 2;
}

int main(){
	string s;
	cin >> s;

	vector<vector<int>> v(26);
	rep(i,s.size()){
		v[s[i] - 'a'].emplace_back(i);
	}
	if(impossible(v)){
		cout << -1 << endl;
		return 0;
	}

	pair<int, int> p[26];
	rep(i,26) p[i] = make_pair(0, v[i].size() - 1); //front, back

	int len = s.size() - 1;
	long long ans = 0;
	rep(i,s.size() / 2){
		int t;
		int minCost = INF;
		rep(j,26){
			if(v[j].size() <= 1) continue;

			int front, back;
			tie(front, back) = p[j];
			if(front >= back) continue;

			int front_p = v[j][front];
			int back_p = v[j][back];

			int left = front_p - sum(front_p + 1);
			int right = back_p - sum(back_p + 1);
			//show(j)
			//cout << v[j][u.first] << ' ' << v[j][u.second] << endl;
			//cout << left << ' ' << right << endl;

			int cost = left + (len - right);
			if(minCost > cost){
				minCost = cost;
				t = j;
			}
		}
		//cout << static_cast<char>(t+'a') << endl;
		//show(minCost)

		ans += minCost;
		add(v[t][p[t].first] + 1, 1);
		add(v[t][p[t].second] + 1, 1);
		p[t].first++;
		p[t].second--;
		len-=2;
	}

	cout << ans << endl;
}
