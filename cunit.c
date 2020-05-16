#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#include "point.h"

void test_point_value(void)
{
    Point A = {0, 0};
    Point B = {10, 50};
    Point C = {20, 10};
    Point D = {SIZE, SIZE};

    CU_ASSERT_TRUE(check_point(A, SIZE, SIZE));
    CU_ASSERT_FALSE(check_point(B, SIZE, SIZE));
    CU_ASSERT_FALSE(check_point(C, SIZE, SIZE));
    CU_ASSERT_FALSE(check_point(D, SIZE, SIZE));

    CU_ASSERT_EQUAL(create_point(A.row, A.col).row, A.row);
    CU_ASSERT_EQUAL(create_point(A.row, A.col).col, A.col);
    CU_ASSERT_EQUAL(create_point(B.row, B.col).row, B.row);
    CU_ASSERT_EQUAL(create_point(B.row, B.col).col, B.col);

    CU_ASSERT_TRUE(is_critical(A));
    CU_ASSERT_FALSE(is_critical(D));
    CU_ASSERT_FALSE(is_critical(C));
    CU_ASSERT_FALSE(is_critical(B));
}

void test_point_neighbors(void)
{
    Point A = {3, 3};
    Point B = {2, 2};
    Point C = {2, 4};
    Point D = {4, 2};
    Point E = {4, 3};
    Point F = {3, 5};

    // CU_ASSERT_EQUAL(live_neighbors(A, ), A);
}

void test_critical_point_neighbors(void)
{
    Point A = {5, 0};
    Point B = {4, 0};
    Point C = {6, 0};
    Point D = {5, SIZE};
}

int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pS1 = CU_add_suite("Testing points", NULL, NULL);
    CU_ADD_TEST(pS1, test_point_value);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    return CU_get_number_of_failures();
}