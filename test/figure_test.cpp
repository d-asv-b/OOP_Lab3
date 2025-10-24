#include <gtest/gtest.h>
#include <cmath>

#include "../include/Triangle.hpp"
#include "../include/Square.hpp"
#include "../include/Octagon.hpp"

// Triangle tests
TEST(TriangleTest, AreaCalculation) {
    Triangle t(Point{0,0}, Point{1,0}, Point{0.5, std::sqrt(3)/2});
    ASSERT_NEAR(t.Area(), 0.433, 0.001);
}

TEST(TriangleTest, GeometricCenter) {
    Triangle t(Point{0,0}, Point{3,0}, Point{1.5, 2});
    Point center = t.GeometricCenter();
    ASSERT_NEAR(center.x, 1.5, 0.001);
    ASSERT_NEAR(center.y, 0.667, 0.001);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle t1(Point{0,0}, Point{1,0}, Point{0.5, std::sqrt(3)/2});
    Triangle t2(Point{0,0}, Point{1,0}, Point{0.5, std::sqrt(3)/2});
    Triangle t3(Point{0,0}, Point{2,0}, Point{1, std::sqrt(3)});
    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 == t3);
}

// Square tests
TEST(SquareTest, AreaCalculation) {
    Square s(Point{0,0}, Point{1,0}, Point{1,1}, Point{0,1});
    ASSERT_NEAR(s.Area(), 1.0, 0.001);
}

TEST(SquareTest, GeometricCenter) {
    Square s(Point{0,0}, Point{2,0}, Point{2,2}, Point{0,2});
    Point center = s.GeometricCenter();
    ASSERT_NEAR(center.x, 1.0, 0.001);
    ASSERT_NEAR(center.y, 1.0, 0.001);
}

TEST(SquareTest, EqualityOperator) {
    Square s1(Point{0,0}, Point{1,0}, Point{1,1}, Point{0,1});
    Square s2(Point{0,0}, Point{1,0}, Point{1,1}, Point{0,1});
    Square s3(Point{0,0}, Point{2,0}, Point{2,2}, Point{0,2});
    ASSERT_TRUE(s1 == s2);
    ASSERT_FALSE(s1 == s3);
}

// Octagon tests
TEST(OctagonTest, AreaCalculation) {
    Octagon o(
        Point{1,0}, Point{2,0}, Point{3,1}, Point{3,2},
        Point{2,3}, Point{1,3}, Point{0,2}, Point{0,1}
    );
    ASSERT_NEAR(o.Area(), 4.828, 0.001);
}

TEST(OctagonTest, GeometricCenter) {
    Octagon o(
        Point{1,0}, Point{2,0}, Point{3,1}, Point{3,2},
        Point{2,3}, Point{1,3}, Point{0,2}, Point{0,1}
    );
    Point center = o.GeometricCenter();
    ASSERT_NEAR(center.x, 1.5, 0.001);
    ASSERT_NEAR(center.y, 1.5, 0.001);
}

TEST(OctagonTest, EqualityOperator) {
    Octagon o1(
        Point{1,0}, Point{2,0}, Point{3,1}, Point{3,2},
        Point{2,3}, Point{1,3}, Point{0,2}, Point{0,1}
    );
    Octagon o2(
        Point{1,0}, Point{2,0}, Point{3,1}, Point{3,2},
        Point{2,3}, Point{1,3}, Point{0,2}, Point{0,1}
    );
    Octagon o3(
        Point{2,0}, Point{4,0}, Point{6,2}, Point{6,4},
        Point{4,6}, Point{2,6}, Point{0,4}, Point{0,2}
    );
    ASSERT_TRUE(o1 == o2);
    ASSERT_FALSE(o1 == o3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
