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

	map<int,int> input;
	rep(i,n){
		int a;
		cin >> a;
		input[a]++;
	}
	//for(auto i : input){ cout << i.first << ' ' << i.second << endl; }

	vector<int> odd(100001,0), even(100001,0); //同値でマッチングできる:even
	for(auto i : input){
		if(i.second % 2){
			odd[i.first % m]++;
			i.second--;
		}
		even[i.first % m] += i.second;
	}


	int ans = odd[0] / 2 + even[0] / 2; //mod 0のカードのマッチング
	range(i,1,m){
		int j = m - i;
		if(i == j){
			ans += (odd[i] + even[i]) / 2; // mod m / 2のカードのマッチング
		}else if(i < j){
			if(odd[i] > odd[j]){
				swap(odd[i], odd[j]);
				swap(even[i], even[j]);
			}

			ans += odd[i];
			odd[j] -= odd[i]; //自分自身にマッチングできないカードを別カードにマッチング
			int p = min(odd[j], even[i]); //余ったカードをさらにマッチング
			ans += p;
			even[i] -= p;

			ans += even[i] / 2 + even[j] / 2; //自分とマッチング
		}
	}

	cout << ans << endl;
}
