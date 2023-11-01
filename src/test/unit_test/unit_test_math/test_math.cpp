#include "kos_engine/math/vector.hpp"
#include "../unit_test.h"
#include "kos_engine/math/matrix.hpp"

void KEUnitTest::KETVectorConstruct0()
{
    KEVector<2> v = {0.0f, 0.0f};
    KE_EXPECT_VALUES_EQUAL(v.x, 0.0f);
    KE_EXPECT_VALUES_EQUAL(v.y, 0.0f);
    KE_EXPECT_VALUES_EQUAL(v.DIM, 2);
}

void KEUnitTest::KETVectorConstruct1()
{
    KEVector<0> v = {};
    KE_EXPECT_VALUES_EQUAL(v.DIM, 0);
}

void KEUnitTest::KETVectorConstruct2()
{
    KE_EXPECT_EXPRESSION_THROW_TYPE(([](){KEVector<2> v = {0.0f, 0.0f, 0.0f};}), std::invalid_argument);
}

void KEUnitTest::KETVectorConstruct3()
{
    KEVector<4> v = {0.0f, 1.0f, 0.02f, 3.0f};
    KE_EXPECT_VALUES_EQUAL(v, KEVector<4>({0.0f, 1.0f, 0.02f, 3.0f}));
}

void KEUnitTest::KETVectorToString0()
{
    KEVector<2> v = {0.0f, 0.0f};
    KE_EXPECT_STRINGS_EQUAL((KEString)v, CGSTR("KEVector<2>(0.000000, 0.000000)"));
}
void KEUnitTest::KETVectorToString1()
{
    KEVector<5> v = {1.0f, 0.5f, 0.33f, 0.25f, 0.2f};
    KE_EXPECT_STRINGS_EQUAL((KEString)v, CGSTR("KEVector<5>(1.000000, 0.500000, 0.330000, 0.250000, 0.200000)"));
}
void KEUnitTest::KETVectorToString2()
{
    KEVector<1> v = {3.0f};
    KE_EXPECT_STRINGS_EQUAL((KEString)v, CGSTR("KEVector<1>(3.000000)"));
}
void KEUnitTest::KETVectorToString3()
{
    KEVector<0> v = {};
    KE_EXPECT_STRINGS_EQUAL((KEString)v, CGSTR("KEVector<0>()"));
}

void KEUnitTest::KETVectorCross0()
{
    KEVector<3> v1 = {0.0f, 0.0f, 0.0f};
    KEVector<3> v2 = {0.0f, 0.0f, 0.0f};
    KE_EXPECT_VALUES_EQUAL(KECross(v1, v2), KEVector<3>({0.0f, 0.0f, 0.0f}));
}

void KEUnitTest::KETVectorCross1()
{
    KEVector<3> v1 = {1.0f, 0.0f, 0.0f};
    KEVector<3> v2 = {0.0f, 0.0f, 1.0f};
    KE_EXPECT_VALUES_EQUAL(KECross(v1, v2), KEVector<3>({0.0f, 1.0f, 0.0f}));
}

void KEUnitTest::KETVectorCross2()
{
    KEVector<3> v1 = {1.0f, 0.0f, 0.0f};
    KEVector<3> v2 = {0.0f, 1.0f, 0.0f};
    KE_EXPECT_VALUES_EQUAL(KECross(v1, v2), KEVector<3>({0.0f, 0.0f, -1.0f}));
}

void KEUnitTest::KETVectorCross3()
{
    KEVector<2> v1 = {1.0f, 0.0f};
    KEVector<2> v2 = {0.0f, 1.0f};
    KE_EXPECT_VALUES_EQUAL(KECross(v1, v2), -1.0f);
}

void KEUnitTest::KETVectorCross4()
{
    KEVector<2> v1 = {1.0f, 0.0f};
    KEVector<2> v2 = {0.0f, 0.0f};
    KE_EXPECT_VALUES_EQUAL(KECross(v1, v2), 0.0f);
}

void KEUnitTest::KETMatrixConstruct0()
{
    KEMatrix<3> mat = {{1.0f, 0.0f, 0.0f}, 
                       {0.0f, 1.0f, 0.0f}, 
                       {0.0f, 0.0f, 1.0f}};
    KE_EXPECT_VALUES_EQUAL(KEMatrix<3>(
        {{1.0f, 0.0f, 0.0f}, 
         {0.0f, 1.0f, 0.0f}, 
         {0.0f, 0.0f, 1.0f}}), mat);
}

void KEUnitTest::KETMatrixConstruct1()
{
    KEMatrix<0> mat = {};
    KE_EXPECT_VALUES_EQUAL(mat.DIM, 0);
}

void KEUnitTest::KETMatrixConstruct2()
{
    KEMatrix<2> mat = {1.0f, 2.0f,
                       3.0f, 4.0f};
    KE_EXPECT_VALUES_EQUAL(mat[0][0], 1.0f);
    KE_EXPECT_VALUES_EQUAL(mat[0][1], 2.0f);
    KE_EXPECT_VALUES_EQUAL(mat[1][0], 3.0f);
    KE_EXPECT_VALUES_EQUAL(mat[1][1], 4.0f);
    KE_EXPECT_VALUES_EQUAL(mat.DIM, 2);
}

void KEUnitTest::KETMatrixConstruct3()
{
    KE_EXPECT_EXPRESSION_THROW_TYPE(([](){
        KEMatrix<2> mat = {{1.0f, 2.0f},
                    {3.0f, 4.0f},
                    {1.0f, 3.0f}};
    }), std::invalid_argument);
}

void KEUnitTest::KETMatrixToString0()
{
    KEMatrix<3> mat = {{1.0f, 0.0f, 0.0f}, 
                       {0.0f, 1.0f, 0.0f}, 
                       {0.0f, 0.0f, 1.0f}};
    KE_EXPECT_STRINGS_EQUAL((KEString)mat, 
        CGSTR("KEMatrix<3>({1.000000, 0.000000, 0.000000}{0.000000, 1.000000, 0.000000}{0.000000, 0.000000, 1.000000})"));
}
void KEUnitTest::KETMatrixToString1()
{
    KEMatrix<0> mat = {};
    KE_EXPECT_STRINGS_EQUAL((KEString)mat, CGSTR("KEMatrix<0>()"));

}
void KEUnitTest::KETMatrixToString2()
{
    KEMatrix<2> mat = {{1.0f, 2.0f}, {3.0f, 4.0f}};
    KE_EXPECT_STRINGS_EQUAL((KEString)mat, CGSTR("KEMatrix<2>({1.000000, 2.000000}{3.000000, 4.000000})"));
}
void KEUnitTest::KETMatrixToString3()
{
    KEMatrix<1> mat = {1.0f};
    KE_EXPECT_STRINGS_EQUAL((KEString)mat, CGSTR("KEMatrix<1>({1.000000})"));
}