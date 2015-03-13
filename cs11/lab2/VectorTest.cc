#include "vector3f.h"
#include <gtest/gtest.h>

using namespace RTracer;

TEST(Vector3fTest, Ctor) {
    Vector3F v1;
    EXPECT_FLOAT_EQ(v1[0], 0.0f);
    EXPECT_FLOAT_EQ(v1[1], 0.0f);
    EXPECT_FLOAT_EQ(v1[2], 0.0f);


    Vector3F v2(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v2[0], 1.0f);
    EXPECT_FLOAT_EQ(v2[1], 2.0f);
    EXPECT_FLOAT_EQ(v2[2], 3.0f);
}

TEST(Vector3fTest, Set) {
    Vector3F v;
    v[0] = 1.0f;
    v[1] = 2.0f;
    v[2] = 3.0f;

    EXPECT_FLOAT_EQ(v[0], 1.0f);
    EXPECT_FLOAT_EQ(v[1], 2.0f);
    EXPECT_FLOAT_EQ(v[2], 3.0f);
}

TEST(Vector3fTest, Add) {
    Vector3F v1;
    Vector3F v2(1.0f, 2.0f, 3.0f);
    Vector3F vAdd = v1 + v2;

    EXPECT_FLOAT_EQ(vAdd[0], 1.0f);
    EXPECT_FLOAT_EQ(vAdd[1], 2.0f);
    EXPECT_FLOAT_EQ(vAdd[2], 3.0f);

    Vector3F vAdd2;
    vAdd2 += v2;
    EXPECT_FLOAT_EQ(vAdd2[0], 1.0f);
    EXPECT_FLOAT_EQ(vAdd2[1], 2.0f);
    EXPECT_FLOAT_EQ(vAdd2[2], 3.0f);
}

TEST(Vector3fTest, Sub) {
    Vector3F v1;
    Vector3F v2(1.0f, 2.0f, 3.0f);
    Vector3F vSub = v1 - v2;

    EXPECT_FLOAT_EQ(vSub[0], -1.0f);
    EXPECT_FLOAT_EQ(vSub[1], -2.0f);
    EXPECT_FLOAT_EQ(vSub[2], -3.0f);

    Vector3F vSub2;
    vSub2 -= v2;
    EXPECT_FLOAT_EQ(vSub2[0], -1.0f);
    EXPECT_FLOAT_EQ(vSub2[1], -2.0f);
    EXPECT_FLOAT_EQ(vSub2[2], -3.0f);
}

TEST(Vector3fTest, Mul) {
    Vector3F vMul1(1.0f, 1.0f, 1.0f);
    vMul1 *= 2.0f;

    EXPECT_FLOAT_EQ(vMul1[0], 2.0f);
    EXPECT_FLOAT_EQ(vMul1[1], 2.0f);
    EXPECT_FLOAT_EQ(vMul1[2], 2.0f);

    Vector3F vMul2 = vMul1 * 2.0f;
    EXPECT_FLOAT_EQ(vMul2[0], 4.0f);
    EXPECT_FLOAT_EQ(vMul2[1], 4.0f);
    EXPECT_FLOAT_EQ(vMul2[2], 4.0f);

    Vector3F vMul3 = 2.0f * vMul2;
    EXPECT_FLOAT_EQ(vMul3[0], 8.0f);
    EXPECT_FLOAT_EQ(vMul3[1], 8.0f);
    EXPECT_FLOAT_EQ(vMul3[2], 8.0f);
}

TEST(Vector3fTest, Div) {
    Vector3F vDiv1(4.0f, 4.0f, 4.0f);
    vDiv1 /= 2.0f;

    EXPECT_FLOAT_EQ(vDiv1[0], 2.0f);
    EXPECT_FLOAT_EQ(vDiv1[1], 2.0f);
    EXPECT_FLOAT_EQ(vDiv1[2], 2.0f);

    Vector3F vDiv2 = vDiv1 / 2.0f;
    EXPECT_FLOAT_EQ(vDiv2[0], 1.0f);
    EXPECT_FLOAT_EQ(vDiv2[1], 1.0f);
    EXPECT_FLOAT_EQ(vDiv2[2], 1.0f);
}

TEST(Vector3fTest, Minus) {
    Vector3F v(1.0f, 1.0f, 1.0f);
    v = -v;
    EXPECT_FLOAT_EQ(v[0], -1.0f);
    EXPECT_FLOAT_EQ(v[1], -1.0f);
    EXPECT_FLOAT_EQ(v[2], -1.0f);
}

TEST(Vector3fTest, DotProduct) {
    Vector3F v1(1.0f, 2.0f, 3.0f);
    Vector3F v2(1.0f, 2.0f, 3.0f);
    float result = v1 * v2;
    EXPECT_FLOAT_EQ(result, 14.0f);
}

TEST(Vector3fTest, CrossProduct) {
    Vector3F v1(1.0f, 2.0f, 3.0f);
    Vector3F v2(1.0f, 2.0f, 3.0f);
    Vector3F result = v1 % v2;
    EXPECT_FLOAT_EQ(result[0], 0.0f);
    EXPECT_FLOAT_EQ(result[1], 0.0f);
    EXPECT_FLOAT_EQ(result[2], 0.0f);
}

TEST(Vector3fTest, Magnitude) {
    Vector3F v(1.0f, 2.0f, 3.0f);
    float result = v.magnitude();
    EXPECT_FLOAT_EQ(result, sqrtf(14.0f));
}

TEST(Vector3fTest, Normalize) {
    Vector3F v(1.0f, 2.0f, 3.0f);
    v.normalize();
    float result = v.magnitude();
    EXPECT_FLOAT_EQ(result, 1.0f);
}
