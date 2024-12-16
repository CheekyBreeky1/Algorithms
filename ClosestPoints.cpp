#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

//change this value if u want to test it in various count of points in hard case
#define POINTS_COUNT 1000000

using namespace std;

class Point {
public:
    double x, y;
};

//find distance between 2 points
double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double closestPair(vector<Point>& pointsX, vector<Point>& pointsY) {
    // basic case when 3 or less points
    if (pointsX.size() <= 3) {
        double minDist = INFINITY;
        for (int i = 0; i < pointsX.size(); ++i) {
            for (int j = i + 1; j < pointsX.size(); ++j) {
                minDist = min(minDist, distance(pointsX[i], pointsX[j]));
            }
        }
        return minDist;
    }

    // find point which divide field on 2 round parts
    unsigned mid = pointsX.size() / 2;
    Point midPoint = pointsX[mid];

    //divide vector pointsX
    vector<Point> leftX(pointsX.begin(), pointsX.begin() + mid);
    vector<Point> rightX(pointsX.begin() + mid, pointsX.end());

    //divide vector pointsY
    vector<Point> leftY, rightY;
    for (auto p : pointsY) {
        if (p.x <= midPoint.x) leftY.push_back(p);
        else rightY.push_back(p);
    }

    double d1 = closestPair(leftX, leftY);
    double d2 = closestPair(rightX, rightY);
    double d = min(d1, d2);

    // check strip on divide line
    vector<Point> strip;
    for (auto p : pointsY) {
        if (abs(p.x - midPoint.x) < d) {
            strip.push_back(p);
        }
    }

    // check points on strip
    double minDist = d;
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size(); ++j) {
            if (strip[j].y - strip[i].y){
                minDist = min(minDist, distance(strip[i], strip[j]));
            }
        }
    }
    return minDist;
}

double findClosestPair(vector<Point>& points) {

    vector<Point> pointsX = points;
    vector<Point> pointsY = points;

    sort(pointsX.begin(), pointsX.end(), [](const Point& p1, const Point& p2) {
        return p1.x < p2.x;
        });

    sort(pointsY.begin(), pointsY.end(), [](const Point& p1, const Point& p2) {
        return p1.y < p2.y;
        });

    return closestPair(pointsX, pointsY);
}

void fillPointsVector(vector<Point>& vec) {
    srand(time(NULL));
    for (int i = 0; i < POINTS_COUNT; i++) {
        Point p = { p.x = rand(), p.y = rand() };
        vec.push_back(p);
    }
}

void findClosestPairTest() {

    vector<Point> points = { {0, 0}, {1, 1}, {2, 2}, {3, 3} };
    vector<Point> points2;
    fillPointsVector(points2);
    cout << "Closest distance easy case: " << findClosestPair(points) << endl;
    cout << "Closest distance hard case: " << findClosestPair(points2) << endl;
}

int main() {
    findClosestPairTest();
    return 0;
}