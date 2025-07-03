#include<bits/stdc++.h>

const double EPS = 0.0000000001;
int sgn(const double a) {
    if(a < -EPS) return -1;
    else if(a > EPS) return 1;
    return 0;
}

struct Point {
    double x, y;

    Point() : x(0.0), y(0.0) {}

    Point(const double& x,const double& y) : x(x), y(y) {}

    Point operator +() const {
        return *this;
    }

    Point operator -() const {
        return {-x, -y};
    }

    Point operator +(const Point& other) const {
        return {x + other.x, y + other.y};
    }

    Point operator -(const Point& other) const {
        return {x - other.x, y - other.y};
    }

    Point operator *(const double& scalar) const {
        return {x * scalar, y * scalar};
    }

    Point operator /(const double& scalar) const {
        return {x / scalar,y / scalar};
    }

    Point& operator +=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point& operator -=(const Point& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    
    Point& operator *=(const double& scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Point& operator /=(const double& scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    double norm() const {
        return x * x + y * y;
    }

    double abs() const {
        return std::sqrt(norm());
    }

    double dot(const Point& other) const {
        return x * other.x + y * other.y;
    }

    double det(const Point& other) const {
        return x * other.y - y * other.x;
    }

    bool is_orthogonal(const Point& other) const {
        return sgn(dot(other)) == 0;
    }

    bool is_parallel(const Point& other) const {
        return sgn(det(other)) == 0;
    }

    double arg() const {
        return std::atan2(y, x);
    }

    inline bool operator <(const Point& other) {
        if(sgn(x - other.x) != 0) return sgn(x - other.x) < 0;
        return sgn(y - other.y) < 0;
    }

    inline bool operator >(const Point& other) {
        if(sgn(x - other.x) != 0) return sgn(x - other.x) > 0;
        return sgn(y - other.y) > 0;
    }

    inline bool operator ==(const Point& other) {
        return sgn(x - other.x) == 0 && sgn(y - other.y) == 0;
    }

    inline bool operator !=(const Point& other) {
        return !(*this == other);
    }
};

double dot(const Point& a, const Point& b) {
    return a.dot(b);
}

double det(const Point& a, const Point& b) {
    return a.det(b);
}

int iSP(const Point& a, const Point& b, const Point& c) {
    if(sgn(det(b - a, c - a)) != 0) return sgn(det(b - a, c - a));

    if(sgn(dot(b - a, c - a)) < 0) return -2;
    if(sgn(dot(a - b, c - b)) < 0) return 2;
    else return 0;
}

typedef Point Vec2;

struct Line {
    Point begin, end;

    Line() : begin(Point()), end(Point()) {}

    Line(const Point& begin, const Point& end) : begin(begin), end(end) {}

    Line(double a, double b, double c) {
        assert(!(sgn(a) == 0 && sgn(b) == 0));

        if(sgn(b) == 0) {
            begin = Point(-c / a, 0.0);
            end = Point(-c / a, 1.0);
        }
        else {
            begin = Point(0.0, c / b);
            end = Point(1.0, (a + c) / b);
        }
    }

    Point vec() const {
        return end - begin;
    }

    Point countervec() const {
        return begin - end;
    }

    bool is_orthogonal(const Line& other) const {
        return sgn(vec().dot(other.vec())) == 0;
    }

    bool is_parallel(const Line& other) const {
        return sgn(vec().det(other.vec())) == 0;
    }
    
    Point project(const Point& p) const {
        double ratio = (p - begin).dot(vec()) / vec().norm();
        return begin + vec() * ratio;
    }

    Point reflect(const Point& p) const {
        return p + (project(p) - p) * 2.0;
    }

    std::pair<bool, std::optional<Point>> line_intersection(const Line& other) const {
        if(is_parallel(other)) {
            if(iSP(begin, end, other.begin) == -2 || iSP(begin, end, other.begin) == 0 || iSP(begin, end, other.begin) == 2) return {true,std::nullopt};
            else return {false,std::nullopt};
        }
        return {true, begin + vec() * abs((other.end - begin).det(other.vec()) / vec().det(other.vec()))};
    }

    std::pair<bool, std::optional<Point>> segment_intersection(const Line& other) const {
        if(iSP(begin, end, other.begin) * iSP(begin, end, other.end) <= 0 && iSP(other.begin, other.end, begin) * iSP(other.begin, other.end, end) <= 0) {
            if(is_parallel(other)) return {true, std::nullopt};
            else return {true, line_intersection(other).second};
        }
        else return {false, std::nullopt};
    }

    double distance_between_point_and_line(const Point& p) const {
        return abs(vec().det(p - begin) / vec().abs());
    }

    double distance_between_point_and_ray(const Point& p) const {
        if(sgn(vec().dot(p - begin)) < 0) return (p - begin).abs();
        else return distance_between_point_and_line(p);
    }

    double distance_between_point_and_segment(const Point& p) const {
        if(sgn(vec().dot(p - begin)) < 0 || sgn(countervec().dot(p - end)) < 0) {
            return std::min((p - begin).abs(), (p - end).abs());
        }
        else return distance_between_point_and_line(p);
    }

    double distance_between_segment_and_segment(const Line& other) const {
        if(segment_intersection(other).first) return 0;
        else {
            double ret = distance_between_point_and_segment(other.begin);
            ret = std::min(ret, distance_between_point_and_segment(other.end));
            ret = std::min(ret, other.distance_between_point_and_segment(begin));
            ret = std::min(ret, other.distance_between_point_and_segment(end));
            return ret;
        }
    }
};

typedef Line Segment;
typedef Line Ray;

bool is_orthogonal(const Line& l1, const Line& l2) {
    return l1.is_orthogonal(l2);
}

bool is_parallel(const Line& l1, const Line& l2) {
    return l1.is_parallel(l2);
}

Point project(const Point& p, const Line& l) {
    return l.project(p);
}

Point reflect(const Point& p, const Line& l) {
    return l.reflect(p);
}

std::pair<bool, std::optional<Point>> line_intersection(const Line& l1, const Line& l2) {
    return l1.line_intersection(l2);
}

std::pair<bool, std::optional<Point>> segment_intersection(const Segment& s1, const Segment& s2) {
    return s1.segment_intersection(s2);
}

double distance_between_point_and_line(const Point& p, const Line& l) {
    return l.distance_between_point_and_line(p);
}

double distance_between_point_and_ray(const Point& p, const Ray& r) {
    return r.distance_between_point_and_ray(p);
}

double distance_between_point_and_segment(const Point& p, const Segment& s) {
    return s.distance_between_point_and_segment(p);
}

double distance_between_segment_and_segment(const Segment& s1, const Segment& s2) {
    return s1.distance_between_segment_and_segment(s2);
}

struct Circle {
    Point center;
    double radius;

    Circle() : center(Point()), radius(0.0) {}

    Circle(Point center, double radius) : center(center), radius(radius) {}

    std::pair<std::optional<Point>, std::optional<Point>> circle_and_line_intersection(const Line& l) const {
        if(sgn(distance_between_point_and_line(center, l) - radius) > 0) return {std::nullopt, std::nullopt};
        Point pr = project(center, l);
        Point e = l.vec() / l.vec().abs();
        double base = std::sqrt(std::max(0.0, radius * radius - (center - pr).norm()));
        return {pr + e * base, pr - e * base};
    }

    std::pair<std::optional<Point>, std::optional<Point>> circle_intersection(const Circle& other) const {
        if(sgn((center - other.center).abs() - radius - other.radius) > 0) return {std::nullopt, std::nullopt};

    }
};

std::pair<std::optional<Point>, std::optional<Point>> circle_and_line_intersection(const Circle& c, const Line& l) {
    return c.circle_and_line_intersection(l);
}

struct Polygon {
    std::vector<Point> points;

    Polygon() {}

    Polygon(std::vector<Point> points) : points(points) {}

    void add(Point p) {
        points.push_back(p);
    }

    void pop() {
        points.pop_back();
    }

    size_t size() {
        return points.size();
    }

    double area() const {
        double ret = 0;
        for(size_t i = 0;i < points.size();i++) {
            ret += points[i].det(points[(i + 1) % points.size()]) / 2.0;
        }
        return ret;
    }

    Point center() const {
        Point ret = {0,0};
        for(size_t i = 0;i < points.size();i++) {
            ret += (points[i] + points[(i + 1) % points.size()]) / 3.0 * points[i].det(points[(i + 1) % points.size()]);
        }
        return ret;
    }

    bool inside_outside_judgement(Point p) const {
        int count = 0;
        for(size_t i = 0;i < points.size();i++) {
            Point begin = points[i];
            Point end = points[(i + 1) % points.size()];
            if((sgn(begin.y - p.y) <= 0 && sgn(end.y - p.y) > 0) || (sgn(begin.y - p.y) > 0 && sgn(end.y - p.y) <= 0)) {
                auto [iscross, intersection] = line_intersection(Line(p, p + Point(1, 0)), Line(begin, end));
                assert(!intersection);
                if(sgn(p.x - intersection.value().x) < 0) count++;
            }
        }
        if(count % 2 == 1) return true;
        else return false;
    }

    Point operator [](int i) {
        return points[i];
    }
};

bool inside_outside_judgement(Polygon polygon, Point p) {
    return polygon.inside_outside_judgement(p);
}

Polygon convex_hull(std::vector<Point> points) {
    if(points.size() < 3) return points;
    std::sort(points.begin(), points.end());

    Polygon up,bottom;
    up.add(points[0]);
    up.add(points[1]);
    bottom.add(points[points.size() - 1]);
    bottom.add(points[points.size() - 2]);

    for(size_t i = 2;i < points.size();i++) {
        for(size_t n = up.size();n >= 2 && iSP(up[n - 2], up[n - 1], points[i]) != 1;n--) {
            up.pop();
        }
        up.add(points[i]);
    }

    for(size_t i = points.size() - 3;i >= 0;i--) {
        for(size_t n = bottom.size();n >= 2 && iSP(bottom[n - 2], bottom[n - 1], points[i]) != 1;n--) {
            bottom.pop();
        }
        bottom.add(points[i]);
    }

    for(size_t i = 1;i < bottom.size() - 1;i++) up.add(bottom[i]);

    return up;
}