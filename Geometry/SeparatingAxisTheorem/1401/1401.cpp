#include <bits/stdc++.h>
using namespace std;

class Vector2D
{
public:
    double x, y;

    Vector2D(double _x, double _y)
        : x(_x), y(_y) 
    {}

    double dot(const Vector2D& other) const
    {
        return this->dot(*this, other);
    }

    double dot(const Vector2D& a, const Vector2D& b) const
    {
        return a.x * b.x + a.y * b.y;
    }

    Vector2D operator-(const Vector2D& other) const
    {
        return Vector2D(this->x - other.x, this->y - other.y);
    }

    Vector2D normalize() const
    {
        double len = sqrt(this->x * this->x + this->y * this->y);
        Vector2D normVec(*this);
        normVec.x /= len;
        normVec.y /= len;

        return normVec;
    }
};

using Point = Vector2D;

class Poly
{
public:
    vector<Point> points;
    
    Poly(const vector<Point>& _points)
        : points(_points)
    {
    }
};

class Circle
{
public:
    Point center;
    double r;

    Circle(const Point& _center, double _r)
        : center(_center), r(_r)
    {}
};

// 算這個多邊形在目標軸的的min、max
std::pair<double, double> getPolyProjection(const vector<Point>& poly, const Vector2D& axis)
{
    double minProj = poly[0].dot(axis);
    double maxProj = minProj;
    for (int i = 1; i < poly.size(); ++i)
    {
        double proj = poly[i].dot(axis);
        minProj = min(minProj, proj);
        maxProj = max(maxProj, proj);
    }

    return {minProj, maxProj};
}

std::pair<double, double> getCircleProjection(const Circle& circle, const Vector2D& axis)
{
    double p = circle.center.dot(axis);
    return {p - circle.r, p + circle.r};
}

// 圓形與多邊形的SAT檢測
bool isCirrclePolyOverlap(const Circle& circle, const Poly& poly)
{
    vector<Vector2D> axes;

    int n = poly.points.size();

    // 收集所有poly的邊法向量
    for (int i = 0; i < n; ++i)
    {
        const Point& p1 = poly.points[i];
        const Point& p2 = poly.points[(i + 1) % n];
        Vector2D dirVec = p2 - p1; // 方向向量
        // 方向向量轉法向量 -> 交換加負號
        axes.emplace_back(Vector2D(-dirVec.y, dirVec.x).normalize());
    }

    // 收集所有多邊形頂點到圓心的向量 (檢測圓形碰到角的情況)
    for (int i = 0; i < n; ++i)
    {
        Vector2D dirVec = circle.center - poly.points[i];
        // 跳過完全與圓心重合的點
        if (sqrt(dirVec.x * dirVec.x + dirVec.y * dirVec.y) > 1e-9)
            axes.emplace_back(dirVec.normalize());
    }

    // 一個個軸看看有沒有重疊
    for (const Vector2D& axis: axes)
    {
        auto [minPoly, maxPoly] = getPolyProjection(poly.points, axis);
        auto [minCircle, maxCircle] = getCircleProjection(circle, axis);

        // 有一個軸分得開就不是碰撞
        if (maxPoly < minCircle || maxCircle < minPoly)
            return false;
    }

    return true; // 所有軸都重疊，碰撞
}

class Solution 
{
public:
    // 練習用SAT解圓形與多邊形碰撞
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) 
    {
        Circle circle(Point(xCenter, yCenter), radius);
        Poly poly({
            Point(x1, y1),
            Point(x2, y1),
            Point(x2, y2),
            Point(x1, y2)
        });

        return isCirrclePolyOverlap(circle, poly);
    }
};