#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#include "point.h"
#include "game.h"
#include "helper.h"

void test_point_value(void)
{
    Point A = {0, 0};
    Point B = {10, 50};
    Point C = {20, 10};
    Point D = {_size, _size};

    CU_ASSERT_TRUE(check_point(A, _size, _size));
    CU_ASSERT_FALSE(check_point(B, _size, _size));
    CU_ASSERT_FALSE(check_point(C, _size, _size));
    CU_ASSERT_FALSE(check_point(D, _size, _size));

    CU_ASSERT_TRUE(is_critical(A));
    CU_ASSERT_FALSE(is_critical(D));
    CU_ASSERT_FALSE(is_critical(C));
    CU_ASSERT_FALSE(is_critical(B));
}

void test_point_neighbors(void)
{
    short field[_size][_size];
    initialize_field(field);
    Point A = create_point(3, 3);
    Point B = create_point(2, 2);
    Point C = create_point(2, 4);
    Point D = create_point(4, 2);
    Point E = create_point(4, 3);
    Point F = create_point(3, 5);
    Point G = create_point(LIMIT, LIMIT);
    Point points[] = {A, B, C, D, E, F, G};
    int points_length = sizeof points / sizeof points[0];

    locate_points(points, points_length, field);

    // Number of neighbors check
    CU_ASSERT_EQUAL(live_neighbors(A, field, 1), 4); // CLipped
    CU_ASSERT_EQUAL(live_neighbors(A, field, 0), 4); // Circular

    // alive or dead
    CU_ASSERT_TRUE(alive_or_dead(A, field));
    CU_ASSERT_TRUE(alive_or_dead(B, field));
    CU_ASSERT_FALSE(alive_or_dead(create_point(0, 0), field));
}

void test_critical_point_neighbors(void)
{
    short field[_size][_size];
    initialize_field(field);
    Point A = create_point(0, 0);
    Point B = create_point(1, 0);
    Point C = create_point(1, 1);
    Point D = create_point(0, 1);
    Point E = create_point(LIMIT, LIMIT);
    Point points[] = {A, B, C, D, E};
    int points_length = sizeof points / sizeof points[0];

    locate_points(points, points_length, field);
    // Number of neighbors check
    CU_ASSERT_EQUAL(live_neighbors(A, field, 1), 3); // CLipped
    CU_ASSERT_EQUAL(live_neighbors(A, field, 0), 4); // Circular

    //will live or die
    CU_ASSERT_TRUE(live_or_die(A, field, 1));  // CLipped
    CU_ASSERT_FALSE(live_or_die(A, field, 0)); // Circular
}

void test_game_functions(void)
{
    short field[_size][_size];
    initialize_field(field);
    Point A = create_point(0, 0);
    CU_ASSERT_TRUE(change_state(A, field));
    CU_ASSERT_TRUE(field[A.row][A.col]);
    CU_ASSERT_TRUE(kill(A, field));
    CU_ASSERT_FALSE(field[A.row][A.col]);
    CU_ASSERT_TRUE(born(A, field));
    CU_ASSERT_TRUE(field[A.row][A.col]);
}

void test_helper_functions()
{
    short field[_size][_size];
    initialize_field(field);
    Point A = create_point(0, 0);
    Point B = create_point(1, 0);
    Point C = create_point(2, 0);
    Point points[] = {A, B, C};
    int points_length = sizeof points / sizeof points[0];

    locate_points(points, points_length, field);
    CU_ASSERT_TRUE(alive_or_dead(A, field));
    CU_ASSERT_TRUE(alive_or_dead(B, field));
    CU_ASSERT_TRUE(alive_or_dead(C, field));
}

int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    _size = 20;
    CU_pSuite pS1 = CU_add_suite("Testing points", NULL, NULL);
    CU_ADD_TEST(pS1, test_point_value);
    CU_ADD_TEST(pS1, test_critical_point_neighbors);

    CU_pSuite pS2 = CU_add_suite("Testing game", NULL, NULL);
    CU_ADD_TEST(pS2, test_game_functions);

    CU_pSuite pS3 = CU_add_suite("Helper functions", NULL, NULL);
    CU_ADD_TEST(pS3, test_helper_functions);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    return CU_get_number_of_failures();
}