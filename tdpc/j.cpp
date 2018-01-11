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

double dp[1 << 16] = {0};

int main(){
	int n;
	cin >> n;

	vector<int> a;
	int s = 0;
	rep(i,n){
		int x;
		cin >> x;
		s = setBit(s,x);
		a.emplace_back(x);
	}
	
	rep(i,1 << 16) dp[i] = 1e9;
	dp[0] = 0;
	rep(i,1 << 16){
		if(i == 0) continue;
		if((~s & i) != 0) continue;
		double mini = 1e8;
		range(j,1,15){
			vector<int> tmp;
			if(getBit(i, j - 1)){
				tmp.emplace_back(clearBit(i, j - 1));
			}
			if(getBit(i, j - 0)){
				tmp.emplace_back(clearBit(i, j));
			}
			if(getBit(i, j + 1)){
				tmp.emplace_back(clearBit(i, j + 1));
			}

			double sum = 1.0;
			rep(i,tmp.size()){
				sum += dp[tmp[i]] / 3;
			}
			if(tmp.size() == 2){
				sum = sum * 3 / 2;
			}else if(tmp.size() == 1){
				sum *= 3;
			}else if(tmp.size() == 0){
				sum = 1e8;
			}

			mini = min(mini, sum);
		}
		dp[i] = mini;
	}

	//rep(i,1 << 16){ rep(j,n + 1){ cout << dp[i][j] << endl; } cout << endl; }
	cout <<fixed << setprecision(8)<< dp[s] << endl;
}
