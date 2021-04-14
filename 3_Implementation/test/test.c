#include "unity.h"
#include "unity_internals.h"
#include "fun.h"
void setUp(){}
void tearDown(){}
void i_run()
{
    TEST_ASSERT_EQUAL(2,i_value(1));
    TEST_ASSERT_EQUAL(3,i_value(2));
    TEST_ASSERT_EQUAL(4,i_value(3));
    TEST_ASSERT_EQUAL(3,i_value(4));
    TEST_ASSERT_EQUAL(3,i_value(5));
    TEST_ASSERT_EQUAL(5,i_value(6));
    TEST_ASSERT_EQUAL(5,i_value(7));
}
void j_run()
{
    TEST_ASSERT_EQUAL(2,j_value(1));
    TEST_ASSERT_EQUAL(2,j_value(2));
    TEST_ASSERT_EQUAL(2,j_value(3));
    TEST_ASSERT_EQUAL(1,j_value(4));
    TEST_ASSERT_EQUAL(3,j_value(5));
    TEST_ASSERT_EQUAL(1,j_value(6));
    TEST_ASSERT_EQUAL(3,j_value(7));
}
int main()
{
    UNITY_BEGIN();
    RUN_TEST(i_run);
    RUN_TEST(j_run);
    return UNITY_END();
}
