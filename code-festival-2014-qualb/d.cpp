#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> h(n + 2);
	rep(i,n){
		cin >> h[i + 1];
	}
	h[0] = h[n + 1] = INF;

	vector<int> l(n + 2, 0), r(n + 2, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	range(i,1,n + 2){
		while(not q.empty() and q.top().first < h[i]){
			r[q.top().second] = i;
			q.pop();
		}
		q.push(make_pair(h[i], i));
	}

	while(not q.empty()) q.pop();
	for(int i = n; i >= 0; i--){
		while(not q.empty() and q.top().first < h[i]){
			l[q.top().second] = i;
			q.pop();
		}
		q.push(make_pair(h[i], i));
	}

	//for(auto i : r){ cout << i << ' '; } cout << endl;
	//for(auto i : l){ cout << i << ' '; } cout << endl;
	rep(i,n){
		cout << r[i + 1] - l[i + 1] - 2 << endl;
	}
}
