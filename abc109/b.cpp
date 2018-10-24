#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

int n;
vector<string> s(100);
unordered_set<string> t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	t.emplace(s[0]);
	for (auto it = ++s.begin(); it != s.end(); it++){
		if(t.count(*it) or (*prev(it,1)).back() != (*it).front()){
			cout << "No" << '\n';
			return 0;
		}
		t.emplace(*it);
	}
	cout << "Yes" << '\n';
}
