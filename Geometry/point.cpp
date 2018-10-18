struct point {
	int x, y;
	point() {}
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	point(point a, point b) { //construct vector from point a to b
		x = b.x - a.x;
		y = b.y - a.y;
	}
	point operator-(const point &o) const { //return vector for point a to b
		return point(o.x-x, o.y-y);
	}
	int operator*(const point &o) const { //dot product
		return x * o.x + y * o.y;
	}
	point operator+(const point &o) const { //add two vectors
		return point(x + o.x, y + o.y);
	}
	int operator|(const point &o) const { //cross product
		return x * o.y - y * o.x;
	}
	double len() { //return length of vector
		return sqrt(x*x + y * y);
	}
	double angle() { //return angle of vector to positive x-axis from -pi to pi
		return atan2(y, x);
	}
	double dist(point &o) { //return distance between this point and point o
		return sqrt(pow(x - o.x, 2) + pow(y - o.y, 2));
	}
	double norm_sq() { //return normal sequare of vector
		return x * x + y * y;
	}
	bool operator<(const point &o) const {
		if(x!=o.x) return x < o.x;
		return y < o.y;
	}
	bool operator==(const point &o) const {
		return x==o.x && y==o.y;
	}
};

/*
(right hand side)
return 0 if two vector is to same or opposite direction
return 1 if v1 to right of vector v2
return -1 if v1 to left of vector v2
*/
int direction(point v1,point v2) { 
	int c = v1 | v2;
	if(c > 0) return 1;
	if(c < 0) return -1;
	return 0;
}

//return true if v1 is perpindicular to v2
bool isPerpendicular(point v1,point v2) {
	return (v1 * v2) == 0;
}

//return true if angle between v1 and v2 is between -pi/2 and pi/2
bool within(point v1,point v2) {
	return (v1 * v2) >= 0;
}

//return distance between point p and segment [a,b]
double distToSegment(point p, point a, point b) {
	point v1 = point(a, p);
	point v2 = point(a, b);
	if (v1*v2 < 0) return dist(a);
	if (point(b, p)*point(b, a) < 0) return dist(b);
	double u = (v1*v2) / v2.norm_sq();
	point c = a + (v2*u);
	return dist(c);
}

vector<point> convexHull(vector<point> p) { //graham scan algorithm O(N log N)
	vector<point> ch;
	int at = 0;
	for (int i = 1; i < n; i++) 
		if (p[i].y < p[at].y || (p[i].y == p[at].y && p[i].x > p[at].x))
			at = i;
	swap(p[at], p[0]);
	sort(p + 1, p + n, [](point a, point b) {
		if (point(p[0], a) | (point(p[0], b)) == 0) //cross product
			return p[0].dist(a) < p[0].dist(b);
		double d1x = a.x - p[0].x, d1y = a.y - p[0].y;
		double d2x = b.x - p[0].x, d2y = b.y - p[0].y;
		return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
	});
	if (n <= 3) {
		for (int i = 0; i < n; i++)
			ch.push_back(p[i]);
		if (abs(p[0].x - p[n - 1].x) > eps || abs(p[0].y - p[n - 1].y) > eps)
			ch.push_back(p[0]);
	}
	else {
		ch.push_back(p[n - 1]);
		ch.push_back(p[0]);
		ch.push_back(p[1]);
		int i = 2;
		while (i < n) {
			int j = ch.size() - 1;
			if (point(ch[j - 1], ch[j]).cross(point(ch[j - 1], p[i])) > 0) ch.push_back(p[i++]);
			else ch.pop_back();
		}
	}
	return ch;
}