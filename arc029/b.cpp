#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const double EPS = 1e10;
using namespace std;

int main(){
	double a, b;
	cin >> a >> b;

	int n;
	cin >> n;
	while(n--){
		double c, d;
		cin >> c >> d;
		if(a > b) swap(a, b);
		if(c > d) swap(c, d);

		if(a <= c + EPS && b <= d + EPS){
			cout << "YES" << endl;
			continue;
		}
		if(c < a - EPS){
			cout << "NO" << endl;
			continue;
		}

		double right = 90, left = 0;
		rep(i,100){
			double mid = (right + left ) / 2;
			if(a * cos(mid * M_PI / 180) + b * sin(mid * M_PI / 180) < c) left = mid;
			else right = mid;
		}
		if(abs(left - 90.0) < EPS){
			cout << "NO" << endl;
			continue;
		}
		double w = a * sin(left * M_PI / 180) + b * cos(left * M_PI / 180);
		cout << (w <= d + EPS ? "YES" : "NO") << endl;
	}
}
