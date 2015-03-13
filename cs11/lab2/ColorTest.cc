#include "color.h"
#include <gtest/gtest.h>

using namespace RTracer;

TEST(Color, Ctor) {
    Color c1;
    EXPECT_FLOAT_EQ(c1.get_red(), 0.0f);
    EXPECT_FLOAT_EQ(c1.get_green(), 0.0f);
    EXPECT_FLOAT_EQ(c1.get_blue(), 0.0f);

    Color c2(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(c2.get_red(), 1.0f);
    EXPECT_FLOAT_EQ(c2.get_green(), 2.0f);
    EXPECT_FLOAT_EQ(c2.get_blue(), 3.0f);
}

TEST(Color, Set) {
    Color c;
    c.set_red(1.0f);
    c.set_green(1.0f);
    c.set_blue(1.0f);
    EXPECT_FLOAT_EQ(c.get_red(), 1.0f);
    EXPECT_FLOAT_EQ(c.get_green(), 1.0f);
    EXPECT_FLOAT_EQ(c.get_blue(), 1.0f);
}

TEST(Color, Add) {
    Color c1;
    Color c2(1.0f, 2.0f, 3.0f);
    Color cAdd = c1 + c2;
    EXPECT_FLOAT_EQ(cAdd.get_red(), 1.0f);
    EXPECT_FLOAT_EQ(cAdd.get_green(), 2.0f);
    EXPECT_FLOAT_EQ(cAdd.get_blue(), 3.0f);

    Color cAdd2;
    cAdd2 += c2;
    EXPECT_FLOAT_EQ(cAdd2.get_red(), 1.0f);
    EXPECT_FLOAT_EQ(cAdd2.get_green(), 2.0f);
    EXPECT_FLOAT_EQ(cAdd2.get_blue(), 3.0f);
}

TEST(Color, Sub) {
    Color c1;
    Color c2(1.0f, 2.0f, 3.0f);
    Color cSub = c1 - c2;
    EXPECT_FLOAT_EQ(cSub.get_red(), -1.0f);
    EXPECT_FLOAT_EQ(cSub.get_green(), -2.0f);
    EXPECT_FLOAT_EQ(cSub.get_blue(), -3.0f);

    Color cSub2;
    cSub2 -= c2;
    EXPECT_FLOAT_EQ(cSub2.get_red(), -1.0f);
    EXPECT_FLOAT_EQ(cSub2.get_green(), -2.0f);
    EXPECT_FLOAT_EQ(cSub2.get_blue(), -3.0f);
}

TEST(Color, Mul) {
    Color mul1(1.0f, 1.0f, 1.0f);
    mul1 *= 3.0f;
    EXPECT_FLOAT_EQ(mul1.get_red(), 3.0f);
    EXPECT_FLOAT_EQ(mul1.get_green(), 3.0f);
    EXPECT_FLOAT_EQ(mul1.get_blue(), 3.0f);

    Color mul2 = 2.0f * mul1;
    EXPECT_FLOAT_EQ(mul2.get_red(), 6.0f);
    EXPECT_FLOAT_EQ(mul2.get_green(), 6.0f);
    EXPECT_FLOAT_EQ(mul2.get_blue(), 6.0f);

    Color mul3 = mul2 * 2.0f;
    EXPECT_FLOAT_EQ(mul3.get_red(), 12.0f);
    EXPECT_FLOAT_EQ(mul3.get_green(), 12.0f);
    EXPECT_FLOAT_EQ(mul3.get_blue(), 12.0f);

    Color mul4(2.0f, 2.0f, 2.0f);
    mul4 *= mul1;
    EXPECT_FLOAT_EQ(mul4.get_red(), 6.0f);
    EXPECT_FLOAT_EQ(mul4.get_green(), 6.0f);
    EXPECT_FLOAT_EQ(mul4.get_blue(), 6.0f);

    Color mul5 = mul1 * mul2;
    EXPECT_FLOAT_EQ(mul5.get_red(), 18.0f);
    EXPECT_FLOAT_EQ(mul5.get_green(), 18.0f);
    EXPECT_FLOAT_EQ(mul5.get_blue(), 18.0f);
}

TEST(Color, Div) {
    Color div1(3.0f, 3.0f, 3.0f);
    div1 /= 3.0f;
    EXPECT_FLOAT_EQ(div1.get_red(), 1.0f);
    EXPECT_FLOAT_EQ(div1.get_green(), 1.0f);
    EXPECT_FLOAT_EQ(div1.get_blue(), 1.0f);

    Color div2(3.0f, 3.0f, 3.0f);
    div2 = div2 / 3.0f;
    EXPECT_FLOAT_EQ(div2.get_red(), 1.0f);
    EXPECT_FLOAT_EQ(div2.get_green(), 1.0f);
    EXPECT_FLOAT_EQ(div2.get_blue(), 1.0f);
}


