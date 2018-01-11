#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

//i番目のビットを返す
bool getBit(int num, int i){
	return ((num & (1 << i)) != 0);
}

//i番目を1にする
int setBit(int num, int i){
	return num | (1 << i);
}

//i番目を0にする
int clearBit(int num, int i){
	int mask = ~(1 << i);
	return num & mask;
}

//i番目をvで置き換える
int updateBit(int num, int i, int v){
	int mask = ~(1 << i);
	return (num & mask) | (v << i);
}

vector<vector<int>> w;
int n, k;

long long dp[1 << 17] = {0};
long long dfs(int used){
	long long res = 0;
	show(used)
	range(i,1,1 << n){
		if((i bitand used) != 0) continue;

		long long tmp = k;
		rep(j,n){
			if(not getBit(i,j) || getBit(used,j)) continue;
			rep(k,n){
				if(getBit(i,k)) continue;
				tmp -= w[j][k];
			}
		}
		if(tmp > 0 && tmp != k){
		show(tmp)
			res = max(res, tmp + dfs(i bitor used) + dfs((~i) bitor used));
		}
	}
	return res;
}

int main(){
	show(2)
	show(~2)
	cin >> n >> k;

	w = vector<vector<int>>(n,vector<int>(n));
	long long sum = 0;
	rep(i,n){ rep(j,n){ cin >> w[i][j]; sum += w[i][j]; } }
	sum /= 2;

	cout << dfs(0) << endl;
}
