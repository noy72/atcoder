#include<bits/stdc++.h>
#define range(i,a,b) for(long long i = (a); i < (b); i++)
#define rep(i,b) for(long long i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const long long INF = 1e8;
using namespace std;


typedef unsigned long long ull;
const ull M = 1000000007;

//べき乗 x^n mod M
ull power(ull x, ull n){
	ull res = 1;
	if(n > 0){
		res = power(x, n / 2);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) % M;
	}
	return res;
}

//階乗
ull memo[1005];
ull factorial(ull n){
	if(memo[n]) return memo[n];
	ull res = 1;
	range(i,1,n + 1){
		res*= i;
		res%= M;
		memo[i] = res;
	}
	return res;
}

//nCr コンビネーション (1,1)から(w,h)だと、引数は(w - 1, h - 1, M)
ull combination(ull n, ull r){
	ull a = factorial(n);
	ull b = factorial(r) * factorial(n - r) % M;
	return a * power(b, M - 2) % M;
}

//完全順列（a[i] != iとなるような順列）の数を返す
ull derangement(ull n /*長さ*/){
	ull dp[1000000] = {0};
	dp[2] = 1;
	range(i,3,n + 1){
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
		dp[i] %= M;
	}
	return dp[n];
}

int main(){
	ull n, a, b, c ,d;
    cin >> n >> a >> b >> c >> d;

	range(i,1,n) factorial(n);

    ull dp[1005][1005] = {{0}}; //dp[人数][グループ人数]
    dp[0][0] = 1;
	range(i,1,n + 1){
		range(member,a,b + 1){
			(dp[i][member] += dp[i][member - 1]) %= M;

			for(int group = c; c <= d && i - member * group >= 0; group++){
				if(dp[i - member * group][member - 1] == 0) continue;
				ull person = n - (i - member * group);
				ull com = combination(person, member);
				ull inv = power(factorial(member), M - 2);
				//ull c = factorial(person - group * member) * power(factorial(member), group) % M * factorial(group) % M;
				//cout << i << ' ' << member << ' ' << group << endl;
				//cout << i - member * group << ' ' << member - 1 << endl;
				//show(p * power(c, M - 2) % M)
				dp[i][member] += dp[i - member * group][member - 1] * com % M * inv % M;
			}
			//cout << i << ' ' << member << endl;
			//show(dp[i][member])
		}
	}
	cout << dp[n][b] << endl;
}
