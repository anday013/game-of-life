#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#include "point.h"

void test_point_value(void)
{
    Point A = {0,0};
    Point B = {10,50};
    Point C = {20,10};
    Point D = {20,20};

    CU_ASSERT_TRUE(check_point(A, SIZE, SIZE));
    CU_ASSERT_FALSE(check_point(B, SIZE, SIZE));
    CU_ASSERT_FALSE(check_point(C, SIZE, SIZE));
    CU_ASSERT_FALSE(check_point(D, SIZE, SIZE));


}



int main(){
    if(CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite pS1 = CU_add_suite("Testing points", NULL, NULL);
    CU_ADD_TEST(pS1, test_point_value);



    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    return CU_get_number_of_failures();
}