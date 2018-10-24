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

int main(){
	int g;
	long long I, O, J, L;
	cin >> I >> O >> g >> J >> L >> g >> g;

	long long a = I / 2 + J / 2 + L / 2;
	a = a * 2 + O;

	long long b = 0;
	if(I >= 1 and J >= 1 and L >= 1){
		b += 3;
		I--;
		J--;
		L--;
	}
	b += (I / 2 + J / 2 + L / 2) * 2 + O;

	cout << max(a,b) << endl;

}
