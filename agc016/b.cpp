#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> v(n);
	int maxi = 0, mini = 1e8;
	rep(i,n){
		cin >> v[i];
		mini = min(mini, v[i]);
		maxi = max(maxi, v[i]);
	}


	if(maxi - mini >= 2){
		cout << "No" << endl;
	}else if(maxi - mini == 0){
		if(mini == n - 1 || mini * 2 <= n){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}else{
		//if(m[maxi] - 1 == n - 1 - mini){
		int mins = count(all(v),mini);
		int maxs = count(all(v),maxi);
		//if(mini == mins){
		if(mins < maxi && 2 * (maxi - mins) <= maxs){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}
