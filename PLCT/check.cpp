#include <iostream>
#include <vector>

struct Point {
    double x, y;
};

// 向量叉积
double crossProduct(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// 检查点是否在线段上
bool onSegment(const Point& P, const Point& Q, const Point& R) {
    if (Q.x <= std::max(P.x, R.x) && Q.x >= std::min(P.x, R.x) &&
        Q.y <= std::max(P.y, R.y) && Q.y >= std::min(P.y, R.y))
       return true;

    return false;
}

// 判断两线段是否相交
bool doIntersect(Point P1, Point P2, Point P3, Point P4) {
    // 计算四个方向的叉积
    double d1 = crossProduct(P3, P4, P1);
    double d2 = crossProduct(P3, P4, P2);
    double d3 = crossProduct(P1, P2, P3);
    double d4 = crossProduct(P1, P2, P4);

    // 一般情况
    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;

    // 特殊情况：一条线段的端点在另一条线段上
    if (d1 == 0 && onSegment(P3, P1, P4)) return true;
    if (d2 == 0 && onSegment(P3, P2, P4)) return true;
    if (d3 == 0 && onSegment(P1, P3, P2)) return true;
    if (d4 == 0 && onSegment(P1, P4, P2)) return true;

    return false;
}

int main(int argc, char* argv[]) {
    if (argc != 9) {
        std::cout << "FALSE" << std::endl;
        return 1;
    }

    Point P1, P2, P3, P4;
    try {
        P1.x = std::stod(argv[1]);
        P1.y = std::stod(argv[2]);
        P2.x = std::stod(argv[3]);
        P2.y = std::stod(argv[4]);
        P3.x = std::stod(argv[5]);
        P3.y = std::stod(argv[6]);
        P4.x = std::stod(argv[7]);
        P4.y = std::stod(argv[8]);
    } catch (...) {
        std::cout << "FALSE" << std::endl;
        return 1;
    }

    if (doIntersect(P1, P2, P3, P4)) {
        std::cout << "TRUE" << std::endl;
    } else {
        std::cout << "FALSE" << std::endl;
    }

    return 0;
}
