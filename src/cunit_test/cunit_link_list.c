#include <CUnit.h>
#include <Basic.h>
#include <Console.h>

#include "typedef.h"
#include "part3_list.h"
#include "cunit_test.h"


INT32 cunit_link_list_init(void)
{
    return 0;
}

INT32 cunit_link_list_cleanup(void)
{
    return 0;
}

/*********************************************
***
*** Test Func : link_list_is_empty
***
*********************************************/
void link_list_test_case1(void)
{
    BOOL retValue, expectValue;

    LINK_LIST_T pList = link_list_init();
    
    retValue = link_list_is_empty(pList);
    expectValue = TRUE;

    CU_ASSERT(retValue == expectValue);
}

void link_list_test_case2(void)
{
    BOOL retValue, expectValue;

    LINK_LIST_T pList = link_list_init();
    link_list_insert_at_tail(1, pList);
    
    retValue = link_list_is_empty(pList);
    expectValue = FALSE;    

    CU_ASSERT(retValue == expectValue);
}

/*********************************************
***
*** Test Func : link_list_is_last
***
*********************************************/
void link_list_test_case3(void)     
{
    BOOL retValue, expectValue;

    LINK_LIST_T pList = link_list_init();
    
    retValue = link_list_is_last(1, pList);
    expectValue = FALSE;    

    CU_ASSERT(retValue == expectValue);
}

void link_list_test_case4(void)     
{
    BOOL retValue, expectValue;

    LINK_LIST_T pList = link_list_init();
    link_list_insert_at_tail(1, pList);
    
    retValue = link_list_is_last(1, pList);
    expectValue = TRUE;    

    CU_ASSERT(retValue == expectValue);
}

void link_list_test_case5(void)     
{
    BOOL retValue, expectValue;

    LINK_LIST_T pList = link_list_init();
    link_list_insert_at_tail(2, pList);
    
    retValue = link_list_is_last(1, pList);
    expectValue = FALSE;    

    CU_ASSERT(retValue == expectValue);
}

/*********************************************
***
*** Test Func : link_list_insert_at_tail
***
*********************************************/
void link_list_test_case6(void)     
{
    INT32 retValue, expectValue;
    LINK_LIST_T pList = NULL;
    
    retValue = link_list_insert_at_tail(1, pList);
    expectValue = -1;    

    CU_ASSERT(retValue == expectValue);
}

void link_list_test_case7(void)     
{
    INT32 retValue, expectValue;
    LINK_LIST_T pList = link_list_init();
    link_list_insert_at_tail(1, pList);
    link_list_insert_at_tail(2, pList);
    link_list_insert_at_tail(3, pList);

    link_list_find_by_index(&retValue, 1, pList);
    expectValue = 1;    

    CU_ASSERT(retValue == expectValue);
}

void link_list_test_case8(void)     
{
    INT32 retValue, expectValue;
    LINK_LIST_T pList = link_list_init();
    link_list_insert_at_tail(1, pList);
    link_list_insert_at_tail(2, pList);
    link_list_insert_at_tail(3, pList);

    link_list_find_by_index(&retValue, 3, pList);
    expectValue = 3;    

    CU_ASSERT(retValue == expectValue);
}

CU_TestInfo link_list_test_case[] = {
    {"link_list_test_case1", link_list_test_case1},
    {"link_list_test_case2", link_list_test_case2},
    {"link_list_test_case3", link_list_test_case3},
    {"link_list_test_case4", link_list_test_case4},
    {"link_list_test_case5", link_list_test_case5},
    {"link_list_test_case6", link_list_test_case6},
    {"link_list_test_case7", link_list_test_case7},
    {"link_list_test_case8", link_list_test_case8},
    CU_TEST_INFO_NULL,
};

//suite info
CU_SuiteInfo suites[] = {
    { "addint long test", cunit_link_list_init, cunit_link_list_cleanup, NULL, NULL, link_list_test_case },
    CU_SUITE_INFO_NULL,
};


int cunit_test_main(void)
{
    if(CUE_SUCCESS != CU_initialize_registry())
    {
        printf("<CUnit Test> CU_initialize_registry fail!!!\n");
        return CU_get_error();
    }

    if(CUE_SUCCESS != CU_register_suites(suites)) 
    {
        printf("<CUnit Test> CU_register_suites fail!!!\n");
        CU_cleanup_registry();
        return CU_get_error();
    }    

#if 0
    //output file.xml
    CU_set_output_filename("link_list_test_result");
    CU_automated_run_tests();
#endif

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    
    return CU_get_error();
}
