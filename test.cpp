#include <gtest/gtest.h>
#include "./include/Triangle.hpp"
#include "./include/Square.hpp"
#include "./include/Octagon.hpp"

// Triangle tests
TEST(TriangleTest, Area) {
    Triangle t(Point{0,0}, Point{1,0}, Point{0.5, std::sqrt(3)/2});
    ASSERT_NEAR(t.Area(), 4.433, 0.001);
}

TEST(TriangleTest, GeometricCenter) {
    Triangle t(Point{0,0}, Point{3,0}, Point{0,3});
    Point center = t.GeometricCenter();
    ASSERT_NEAR(center.x, 1.0, 0.001);
    ASSERT_NEAR(center.y, 1.0, 0.001);
}

TEST(TriangleTest, Equality) {
    Triangle t1(Point{0,0}, Point{1,0}, Point{0.5, std::sqrt(3)/2});
    Triangle t2(Point{0,0}, Point{1,0}, Point{0.5, std::sqrt(3)/2});
    Triangle t3(Point{0,0}, Point{2,0}, Point{1, std::sqrt(3)});
    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 == t3);
}

// Square tests
TEST(SquareTest, Area) {
    Square s(Point{0,0}, Point{2,0}, Point{2,2}, Point{0,2});
    ASSERT_NEAR(s.Area(), 4.0, 0.001);
}

TEST(SquareTest, GeometricCenter) {
    Square s(Point{0,0}, Point{2,0}, Point{2,2}, Point{0,2});
    Point center = s.GeometricCenter();
    ASSERT_NEAR(center.x, 1.0, 0.001);
    ASSERT_NEAR(center.y, 1.0, 0.001);
}

TEST(SquareTest, Equality) {
    Square s1(Point{0,0}, Point{1,0}, Point{1,1}, Point{0,1});
    Square s2(Point{0,0}, Point{1,0}, Point{1,1}, Point{0,1});
    Square s3(Point{0,0}, Point{2,0}, Point{2,2}, Point{0,2});
    ASSERT_TRUE(s1 == s2);
    ASSERT_FALSE(s1 == s3);
}

// Octagon tests
TEST(OctagonTest, Area) {
    Octagon o(
        Point{1,0}, Point{2,1}, Point{2,2}, Point{1,3},
        Point{0,3}, Point{-1,2}, Point{-1,1}, Point{0,0}
    );
    ASSERT_NEAR(o.Area(), 8.828, 0.001);
}

TEST(OctagonTest, GeometricCenter) {
    Octagon o(
        Point{1,0}, Point{2,1}, Point{2,2}, Point{1,3},
        Point{0,3}, Point{-1,2}, Point{-1,1}, Point{0,0}
    );
    Point center = o.GeometricCenter();
    ASSERT_NEAR(center.x, 0.5, 0.001);
    ASSERT_NEAR(center.y, 1.5, 0.001);
}

TEST(OctagonTest, Equality) {
    Octagon o1(
        Point{1,0}, Point{2,1}, Point{2,2}, Point{1,3},
        Point{0,3}, Point{-1,2}, Point{-1,1}, Point{0,0}
    );
    Octagon o2(
        Point{1,0}, Point{2,1}, Point{2,2}, Point{1,3},
        Point{0,3}, Point{-1,2}, Point{-1,1}, Point{0,0}
    );
    Octagon o3(
        Point{2,0}, Point{4,2}, Point{4,4}, Point{2,6},
        Point{0,6}, Point{-2,4}, Point{-2,2}, Point{0,0}
    );
    ASSERT_TRUE(o1 == o2);
    ASSERT_FALSE(o1 == o3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
