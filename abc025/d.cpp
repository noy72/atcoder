#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;


//#define int long long 
const int M = 1000000007;

int dp[1 << 25];
vector<bool> used_number(25,0);
vector<bool> vacant_space(25,0);
pair<int, int> p[25];

bool getBit(int num, int i){
	return ((num & (1 << i)) != 0);
}

int setBit(int num, int i){
	return num | (1 << i);
}

bool check(pair<int, int> p, int s){
	int y = p.first;
	int x = p.second;

	bool xf, yf;
	if(x == 0 || x == 4){ //端に置くケース
		xf = true;
	}else{
		bool left_bit = getBit(s, (x - 1) + y * 5);
		bool right_bit = getBit(s, (x + 1) + y * 5);
		xf = not (left_bit xor right_bit);
	}
	
	if(y == 0 || y == 4){
		yf = true;
	}else{
		bool up_bit = getBit(s, x + (y - 1) * 5);
		bool down_bit = getBit(s, x + (y + 1) * 5);
		yf = not (up_bit xor down_bit);
	}

	return xf and yf;
}


int dfs(int s, int num){ //s = 埋められた場所の集合
	if(dp[s] != -1) return dp[s];

	if(used_number[num]){ //あらかじめ数字が置かれている場合
		int y = p[num].first;
		int x = p[num].second;
		int next = setBit(s, x + y * 5);

		if(check(p[num],s)){
			return dfs(next, num + 1);
		}else{
			return dp[next] = 0;
		}
	}

	int res = 0;
	rep(i,25){ // num を置ける場所を探す
		if(not getBit(s,i) && vacant_space[i]){
			if(check(make_pair(i / 5, i % 5), s)){
				res += dfs(setBit(s,i), num + 1);
				res %= M;
			}
		}
	}

	return dp[s] = res;
}

signed main(){
	memset(dp, -1, sizeof(dp));
	dp[(1 << 25) - 1] = 1; //全部埋まったら1通り

	rep(i,5) rep(j,5){
		int a;
		cin >> a;
		if(a == 0) vacant_space[i * 5 + j] = true;
		else used_number[a - 1] = true;
		p[a - 1] = make_pair(i,j);
	}

	cout << dfs(0,0) << endl;
}
