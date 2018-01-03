#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
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
		//bit[i] = max(bit[i], x);
		i += i & - i;
	}
}

int main(){
	int n;
	cin >> n;

	vector<int> s(n), t(n);
	rep(i,n){
		cin >> s[i] >> t[i];
		add(s[i] + 1, 1);
	}

	rep(i,n){
		cout << sum(t[i] + 1) - sum(s[i] + 1) << endl;
	}
}
