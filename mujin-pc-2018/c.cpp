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

vector<vector<char>> rotation(const vector<vector<char>>& a){
	vector<vector<char>> res(a[0].size(), vector<char>(a.size()));
	rep(j,a[0].size()){
		rep(i,a.size()){
			res[j][i] = a[i][a[0].size() - 1 - j];
		}
	}
	return res;
}


vector<vector<long long>> cumulativeSumVer(vector<vector<char>>& a){
	vector<vector<long long>> s(a.size(), vector<long long>(a[0].size(), 0));
	rep(w, a[0].size()){
		for(int h = a.size() - 1; h >= 0; h--){
			if(h == a.size() - 1){
				s[h][w] = a[h][w] == '#' ? -1 : 0;
			}else{
				s[h][w] = a[h][w] == '#' ? -1 : s[h + 1][w] + 1;
			}
		}
	}
	return s;
}

vector<vector<long long>> cumulativeSumHol(vector<vector<long long>>& s){
	vector<vector<long long>> res(s.size(), vector<long long>(s[0].size(), 0));
	rep(h,s.size()){
		range(w,1,s[0].size()){
			res[h][w] = s[h][w] == -1 ? 0 : s[h][w];
		}
	}

	rep(h,res.size()){
		for(int w = res.size() - 1; w > 0; w--){
			res[h][w - 1] += res[h][w];
		}
	}
	return res;
}

long long solve(vector<vector<char>> a){
	vector<vector<long long>> s = cumulativeSumVer(a);
	//rep(i,s.size()){
	//	rep(j,s[0].size()){
	//		cout << s[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//	cout << endl;

	long long sum = 0;
	rep(i,s.size()){
		long long k = 0;
		range(j,0,s[0].size()){
			if(s[i][j] == -1){
				k = 0;
				continue;
			}else{
				k++;
			}
			if(j == 0 or k == 1) continue;

			//cout << i << ' ' << j << ' ' << s[i][j] << ' ' << k - 1 << endl;
			sum += s[i][j] * (k - 1);
		}
	}

	//show(sum)
	return sum;
}

void test(){
	vector<vector<char>> c = {
		{'.', '.', '#'},
		{'.', '.', '.'},
		{'#', '.', '#'},
	};

	//rep(i,4){
	//	c = rotation(c);
	//	rep(h,c.size()){
	//		rep(w,c[0].size()){
	//			cout << c[h][w] << ' ';
	//		}
	//		cout << endl;
	//	}
	//		cout << endl;
	//}
	//
	vector<vector<long long>> s = cumulativeSumVer(c);
	vector<long long> tmp, correct = {1, 2, -1, 0, 1, 0, -1, 0, -1};
	rep(i,3){
		rep(j,3){
			tmp.emplace_back(s[i][j]);
		}
	}
	cout << tmp << endl;
	assert(tmp == correct);

	s = cumulativeSumHol(s);
	tmp.clear();
	rep(i,3){
		rep(j,3){
			tmp.emplace_back(s[i][j]);
		}
	}
	cout << tmp << endl;
	correct = {2, 2, 0, 1, 1, 0, 0, 0, 0};
	assert(tmp == correct);
}

void test2(){
	vector<vector<char>> c = {
		{'.', '.', '#'},
		{'.', '.', '.'},
		{'#', '.', '#'},
	};
	c = rotation(c);

	vector<vector<long long>> s = cumulativeSumVer(c);
	vector<long long> tmp, correct = {-1, 2, -1, 1, 1, 0, 0, 0, -1};
	rep(i,3){
		rep(j,3){
			tmp.emplace_back(s[i][j]);
		}
	}
	cout << tmp << endl;
	assert(tmp == correct);

	s = cumulativeSumHol(s);
	tmp.clear();
	rep(i,3){
		rep(j,3){
			tmp.emplace_back(s[i][j]);
		}
	}
	cout << tmp << endl;
	correct = {2, 2, 0, 1, 1, 0, 0, 0, 0};
	assert(tmp == correct);
}

int main(){
	//test2();

	int h, w;
	cin >> h >> w;

	vector<vector<char>> a(h, vector<char>(w));
	rep(i,h) rep(j,w) cin >> a[i][j];

	long long ans = 0;
	rep(i,4){
		ans += solve(a);
		a = rotation(a);
	}
	cout << ans << endl;
}
