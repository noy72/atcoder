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

typedef complex<double> Point;
typedef Point Vector;
struct Segment{					//線分を表す構造体
	Point p1, p2;
	Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};
typedef Segment Line;			//直線を表す構造体
typedef vector<Point> Polygon;	//多角形を表す構造体

namespace std{
	bool operator < (const Point &a, const Point &b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
	bool operator == (const Point &a, const Point &b){
		return a.real() == b.real() && a.imag() == b.imag();
	}
}

class Circle{
	public:
		Point p;
		double r;
		Circle(Point p = Point(), double r = 0.0): p(p), r(r) {}
};

// 許容する誤差
#define EPS (1e-10)
#define INF (1e10)

// ベクトルaの絶対値を求める
//double length = abs(a);

// 2点a,b間の距離を求める
//double distance = abs(a-b);

/*
// ベクトルaの単位ベクトルを求める
Point b = a / abs(a);

// ベクトルaの法線ベクトルn1,n2を求める
Point n1 = a * Point(0, 1);
Point n2 = a * Point(0, -1);
*/

int ccw(Point, Point, Point);

// 2つのスカラーが等しいかどうか
bool EQ(double a, double b){
	return (abs(a - b) < EPS);
}

// 2つのベクトルが等しいかどうか
bool EQV(Vector a, Vector b){
	return ( EQ(a.real(), b.real()) && EQ(a.imag(), b.imag()) );
}

// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(Point a, Point b) {
	return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積 (cross product) : a×b = |a||b|sinΘ
double cross(Point a, Point b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}

// 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
	return EQ( dot(a1-a2, b1-b2), 0.0 );
}
bool isOrthogonal(Line s1, Line s2) { return isOrthogonal(s1.p1, s1.p2, s2.p1, s2.p2); }

// 2直線の平行判定 : a//b <=> cross(a, b) = 0
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
	return EQ( cross(a1-a2, b1-b2), 0.0 );
}
bool isParallel(Line s1, Line s2) { return isParallel(s1.p1, s1.p2, s2.p1, s2.p2); }

// 点cが直線a,b上にあるかないか
bool isPointOnLine(Point a, Point b, Point c) {
	return EQ( cross(b-a, c-a), 0.0 );
}
bool isPointOnLine(Line s, Point c) { return isPointOnLine(s.p1, s.p2, c); }

// 点a,bを通る直線と点cとの距離
double distanceLPoint(Point a, Point b, Point c) {
	return abs(cross(b-a, c-a)) / abs(b-a);
}
double distanceLPoint(Line s, Point c) { return distanceLPoint(s.p1, s.p2, c); }

// 点a,bを端点とする線分と点cとの距離
double distanceLsPoint(Point a, Point b, Point c) {
	if ( dot(b-a, c-a) < EPS ) return abs(c-a);
	if ( dot(a-b, c-b) < EPS ) return abs(c-b);
	return abs(cross(b-a, c-a)) / abs(b-a);
}
double distanceLsPoint(Segment s, Point c) { return distanceLsPoint(s.p1, s.p2, c); }

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
// 端点が重なる場合も、線分が交差しているとみなす
bool isIntersectedLs(Point a1, Point a2, Point b1, Point b2) {
	return ( ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
			ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0 );
}
bool isIntersectedLs(Segment s1, Segment s2) { return isIntersectedLs(s1.p1, s1.p2, s2.p1, s2.p2); }

// 端点が重なっているかを検出する
bool isContainSamePoints(Segment s1, Segment s2){
	if(abs(s1.p1 - s2.p1) < EPS) return true;
	if(abs(s1.p1 - s2.p2) < EPS) return true;
	if(abs(s1.p2 - s2.p1) < EPS) return true;
	if(abs(s1.p2 - s2.p2) < EPS) return true;
	return false;
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算
Point intersectionLs(Point a1, Point a2, Point b1, Point b2) {
	Vector base = b2 - b1;
	double d1 = abs(cross(base, a1 - b1));
	double d2 = abs(cross(base, a2 - b1));
	double t = d1 / (d1 + d2);

	return Point(a1 + (a2 - a1) * t);
}
Point intersectionLs(Segment s1, Segment s2) { return intersectionLs(s1.p1, s1.p2, s2.p1, s2.p2); }

// a1,a2を通る直線とb1,b2を通る直線の交差判定
bool isIntersectedL(Point a1, Point a2, Point b1, Point b2) {
	return !EQ( cross(a1-a2, b1-b2), 0.0 );
}
bool isIntersectedL(Line l1, Line l2) { return isIntersectedL(l1.p1, l1.p2, l2.p1, l2.p2); }

// a1,a2を通る直線とb1,b2を通る直線の交点計算
Point intersectionL(Point a1, Point a2, Point b1, Point b2) {
	Point a = a2 - a1; Point b = b2 - b1;
	return a1 + a * cross(b, b1-a1) / cross(b, a);
}
Point intersectionL(Line l1, Line l2) { return intersectionL(l1.p1, l1.p2, l2.p1, l2.p2); }

// 線分s1と線分s2の距離
double distanceLL(Segment s1, Segment s2){
	if(isIntersectedLs(s1.p1, s1.p2, s2.p1, s2.p2) ) return 0.0;
	return min(
			min(distanceLsPoint(s1.p1, s1.p2, s2.p1),
				distanceLsPoint(s1.p1, s1.p2, s2.p2)),
			min(distanceLsPoint(s2.p1, s2.p2, s1.p1),
				distanceLsPoint(s2.p1, s2.p2, s1.p2)) );
}
double distanceLL(Point p0, Point p1, Point p2, Point p3){
	Segment s1 = Segment{p0, p1}, s2 = Segment{p2, p3};
	return distanceLL(s1, s2);
}

// 線分sに対する点pの射影
Point project(Segment s, Point p){
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / norm(base);
	return Point(s.p1 + base * r);
}

//線分sを対象軸とした点pの線対称の点
Point reflect(Segment s, Point p){
	return Point(p + (project(s, p) - p) * 2.0);
}

//点pをangle分だけ時計回りに回転
Point rotation(Point p, double angle){
	double x, y;
	x = p.real() * cos(angle) - p.imag() * sin(angle);
	y = p.real() * sin(angle) + p.imag() * cos(angle);
	return Point(x, y);
}

//円cと線分lの交点
pair<Point, Point> getCrossPoints(Circle c, Line l){
	Vector pr = project(l, c.p);
	Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
	double base = sqrt(c.r * c.r - norm(pr - c.p));
	return make_pair(pr + e * base, pr - e * base);
}

//円c1と円c2の交点
double arg(Vector p) { return atan2(p.imag(), p.real()); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) *a); }

pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
	double d = abs(c1.p - c2.p);
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.p - c1.p);
	return make_pair(Point(c1.p + polar(c1.r, t + a)), Point(c1.p + polar(c1.r, t - a)));
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
	if( cross(a, b) < -EPS ) return CLOCKWISE;
	if( dot(a, b) < -EPS ) return ONLINE_BACK;
	if( abs(a) < abs(b) ) return ONLINE_FRONT;

	return ON_SEGMENT;
}

Polygon convexHull( Polygon s ){
	Polygon u;
	if( s.size() < 3 ) return s;
	sort(s.begin(), s.end());

	range(i,0,s.size()){
		//== COUNTER_CLOCKWISEだと内角は180以下（一直線上に並んでいても、頂点として数える）
		//!= CLOCKWISEだと内角は180未満（一直線上の頂点は数えない）
		for(int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], s[i]) == COUNTER_CLOCKWISE; n--){
			u.pop_back();
		}
		u.emplace_back(s[i]);
	}

	for(int i = s.size() - 2; i >= 0; i--){
		//ここも == と != を変更する
		for(int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], s[i]) == COUNTER_CLOCKWISE; n--){
			u.pop_back();
		}
		u.emplace_back(s[i]);
	}

	reverse(u.begin(), u.end());
	u.pop_back();

	//最も下にある点の中で最も右にある点から反時計回りに並び替え
	/*
	   int i = 0;
	   while(i < u.size() - 1){
	   if(u[i].imag() > u[i + 1].imag()){
	   u.emplace_back(u[i]);
	   u.erase(u.begin());
	   continue;
	   }else if(u[i].imag() == u[i + 1].imag() && u[i].real() > u[i + 1].real()){
	   u.emplace_back(u[i]);
	   u.erase(u.begin());
	   continue;
	   }
	   break;
	   }
	   */

	return u;
}

//弧度法から度数法の変換
double radianToDegree(double rad){
	return 180 * rad / M_PI;
}

//度数法から変弧度法の換
double degreeToRadian(double deg){
	return M_PI * deg / 180;
}

//2つのベクトルからなる角度を求める
double angleOf2Vector(Vector a, Vector b){
	return acos( dot(a,b) / (abs(a) * abs(b)) );
}


int main(){
	int n;
	cin >> n;

	vector<Point> ps(n);
	map<Point, int> m;
	rep(i,n){
		double a, b;
		cin >> a >> b;
		ps[i] = Point(a,b);
		m[Point(a,b)] = i;
	}

	if(n == 2){
		cout << 0.5 << endl;
		cout << 0.5 << endl;
		return 0;
	}

	Polygon hull = convexHull(ps);

	int h = hull.size();
	vector<double> ans(n,0);
	rep(i,h){
		Point a = hull[i], b = hull[(i + 1) % h], c = hull[(i + 2) % h];
		double th = M_PI - angleOf2Vector(a - b, c - b);
		ans[m[b]] = th / (2 * M_PI);
	}

	for(auto i : ans) cout << fixed << setprecision(20) << i << endl;
}
