#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<bool> infection(n,0);
	infection[0] = true;
	vector<int> ball(n,1);

	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;

		ball[a]--;
		ball[b]++;
		infection[b] = infection[b] or infection[a];

		if(ball[a] == 0) infection[a] = false;
	}

	int sum = 0;
	for_each(all(infection), [&](const bool f){ if(f) sum++; });
	cout << sum << endl;
}
