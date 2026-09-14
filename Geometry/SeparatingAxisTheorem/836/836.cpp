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
};

using Point = Vector2D;

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

class Solution 
{
public:
    // 水題，但用分離軸定理解
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        vector<Point> poly1 = {
            Point(rec1[0], rec1[1]),
            Point(rec1[2], rec1[1]),
            Point(rec1[2], rec1[3]),
            Point(rec1[0], rec1[3])
        };

        vector<Point> poly2 = {
            Point(rec2[0], rec2[1]),
            Point(rec2[2], rec2[1]),
            Point(rec2[2], rec2[3]),
            Point(rec2[0], rec2[3])
        };

        auto checkAxes = [&](const vector<Point>& poly)
        {
            int n = poly.size();
            for (int i = 0; i < n; ++i)
            {
                const Point& p1 = poly[i];
                const Point& p2 = poly[(i + 1) % n];

                // 方向向量
                Vector2D dirVec = p2 - p1;
                // 法向量，交換加負號
                Vector2D norm = Vector2D(-dirVec.y, dirVec.x);

                auto [minA, maxA] = getPolyProjection(poly1, norm);
                auto [minB, maxB] = getPolyProjection(poly2, norm);

                // 這題貼合也不算重疊
                if (maxA <= minB || maxB <= minA)
                    return false;
            }

            return true;
        };

        return checkAxes(poly1) && checkAxes(poly2);
    }
};