#include "vector3f.h"
#include <gtest/gtest.h>

using namespace RTracer;

TEST(Vector3fTest, Ctor)
{
    Vector3F v1;
    EXPECT_FLOAT_EQ(v1[0], 0.0f);
    EXPECT_FLOAT_EQ(v1[1], 0.0f);
    EXPECT_FLOAT_EQ(v1[2], 0.0f);


    Vector3F v2(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(v2[0], 1.0f);
    EXPECT_FLOAT_EQ(v2[1], 2.0f);
    EXPECT_FLOAT_EQ(v2[2], 3.0f);
}
