#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

int n;
vector<double> t, v;
int idx;
double pos, sp;

bool speedUp(){
	range(i,idx,n){
		if((sp + 0.5) - (t[i] - pos - 0.5) > v[i + 1]){
			return false;
		}
	}
	return true;
}

bool keep(){
	range(i,idx,n){
		if(sp - (t[i] - pos - 0.5) > v[i + 1]){
			return false;
		}
	}
	return true;
}

int main(){
	cin >> n;

	t = vector<double>(n);
	v = vector<double>(n);
	cin >> t >> v;
	range(i,1,n) t[i] += t[i - 1];
	v.emplace_back(0);

	double ans = 0;
	while(idx < n){
		if(speedUp()){
			sp = min(v[idx], sp + 0.5);
		}else if(keep()){
			;
		}else{
			sp -= 0.5;
		}
		pos += 0.5;
		ans += sp;
		//cout << sp << ' ' << pos << endl;
		if(t[idx] <= pos) idx++;
	}
	cout << fixed << setprecision(10) << ans / 2 << endl;
}
