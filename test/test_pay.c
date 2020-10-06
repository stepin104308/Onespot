#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <pay.h>
#include <string.h>
#define PROJECT_NAME "Payment"

/* Prototypes for all the test functions */
void test_balance(void);
void test_accounttype(void);


/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */

/* Add your test functions in this format for testing*/
  CU_add_test(suite, "checkbalance", test_balance);
  CU_add_test(suite, "getaccounttype", test_accounttype);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}
/* Write all the test functions */
void test_balance(void) {
  CU_ASSERT(950 == checkbalance(1000, 50));
  CU_ASSERT(-50 == checkbalance(100, 150));
  CU_ASSERT(-150 == checkbalance(-50, 100));
  CU_ASSERT(-50 == checkbalance(-50, 0));
  CU_ASSERT(100 == checkbalance(100, 0));

  /* Dummy fail*/
  CU_ASSERT(100 == checkbalance(100, 10));
}

void test_accounttype(void) {
  CU_ASSERT(1 == getaccounttype(1000, 50));
  CU_ASSERT(0 == getaccounttype(100, 150));
  CU_ASSERT(1 == getaccounttype(100, 0));
  CU_ASSERT(-1 == getaccounttype(-100, 0));

  /* Dummy fail*/
  CU_ASSERT(0 == getaccounttype(1000, 50));
}

