#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

void output(vector<long long> v){
    int k = 0;
    while(any_of(all(v), [](long long a) {return a >= 50; } )){
        int maxi = 0;
        int p;
        rep(i,v.size()){
            if(maxi < v[i]){
                maxi = v[i];
                p = i;
            }
        }
        rep(i,v.size()){
            if(p == i) v[i] -= 50;
            else v[i]++;
        }
        k++;
    }
    show(k)
}

int main(){
    long long k;
    cin >> k;

    if(k < 50LL){
        int a[2] = {1,1};
        rep(i,k){
            a[(i % 2) ^ 0] += 2;
            a[(i % 2) ^ 1] -= 1;
        }
        cout << 2 << endl;
        cout << a[0] << ' ' << a[1] << endl;
    }else{
        vector<long long> v;
        rep(i,50) v.emplace_back(50 - 1 + k / 50);

        rep(i,k % 50){
            v[i] += 50;
            rep(j,50){
                if(i != j) v[j]--;
            }
        }
        cout << 50 << endl;
        rep(i,50){
            cout << v[i] << (i == 49 ? '\n' : ' ');
        }
        //output(v);
    }
    return 0;
}
