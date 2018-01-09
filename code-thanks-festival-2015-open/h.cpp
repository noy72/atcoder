#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const int INF = 1e8;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template <class T> class CumulativeSum2D {
	public:
		vector<vector<T>> s;
		int h, w;
		CumulativeSum2D(const vector<vector<T>> &a) {
			h = a.size();
			w = a[0].size();
			s = vector<vector<T>>(h + 1, vector<T>(w + 1, 0));
			rep(i, h) rep(j, w) s[i + 1][j + 1] = a[i][j];
			rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
			rep(i, h) rep(j, w + 1) s[i + 1][j] += s[i][j];
		}

		int sum(int i, int j, int h, int w) {
			return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
		}

		int maximumSubMatrix(){
			int ret = -INF;
			rep(i,h + 1) rep(j,w + 1) range(k,1,h - i + 1) range(l,1,w - j + 1){
				ret = max(ret, sum(i,j,k,l));
			}
			return ret;
		}
};

int main(){
	//int h, w, k;
	//cin >> h >> w >> k;

	//vector<string> s(h);
	//rep(i,h){
	//	cin >> s[i];
	//}

	//auto in = vectors(h,w,-1);
	//auto n = vectors(10,h,w,0);
	//rep(i,h){
	//	rep(j,w){
	//		int a = s[i][j] - '0';
	//		in[i][j] = a;
	//		n[a - 1][i][j]++;
	//	}
	//}

	//CumulativeSum2D<int> sum(in);
	//vector<CumulativeSum2D<int>> num(10);
	//rep(i,10) num[i] = CumulativeSum2D<int>(n[i]);

	int h = 350 , w = 350;
	int k;
	cin >> k;
	vector<pair<int, int>> size;
	range(i,1,h + 1){
		range(j,1,w + 1){
			if(i * j * 9 >= k and i * j <= k){
				size.emplace_back(make_pair(i,j));
			}
		}
	}
	show(size.size())
}
