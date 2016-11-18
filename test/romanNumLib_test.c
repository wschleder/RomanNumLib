#include <stdlib.h>
#include <stdio.h>
#include <check.h>

#include "../src/romanNumLib.h"

/****************************************************************************************/
START_TEST (test_romanNumbersAdd_GuardsAgainstNullInputA)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd(NULL, "", buffer);
    ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersAdd_GuardsAgainstNullInputB)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("", NULL, buffer);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersAdd_GuardsAgainstNullOutputBuffer)
{
	RomanNumLibResults result = romanNumbersAdd("", "", NULL);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_i_Plus_i)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("i", "i", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "ii");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_i_Plus_ii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("i", "ii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "iii");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_ii_Plus_ii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("ii", "ii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "iv");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_iii_Plus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("iii", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "vi");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_iii_Plus_v)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("iii", "v", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "viii");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_v_Plus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("v", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "viii");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_viii_Plus_i)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("viii", "i", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "ix");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_iv_Plus_viii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("iv", "viii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "xii");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_xviii_Plus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("xviii", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "xxi");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_xxxviii_Plus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("xxxviii", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "xli");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_xliii_Plus_vi)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("xliii", "vi", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "xlix");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_xlviii_Plus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("xlviii", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "li");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_lxxxviii_Plus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("lxxxviii", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "xci");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_xciv_Plus_vii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("xciv", "vii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "ci");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_cccxc_Plus_xxxiii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("cccxc", "xxxiii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "cdxxiii");
}
END_TEST

/****************************************************************************************/
Suite * RomanNumberalLib_suite(void)
{
    Suite *s;
    TCase *tc_core;
    
    s = suite_create("RomanNumberalLibTest_suite");
    
    /* Core test case */
    tc_core = tcase_create("Core");
    
	tcase_add_test(tc_core, test_romanNumbersAdd_GuardsAgainstNullInputA);
	tcase_add_test(tc_core, test_romanNumbersAdd_GuardsAgainstNullInputB);
	tcase_add_test(tc_core, test_romanNumbersAdd_GuardsAgainstNullOutputBuffer);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_i_Plus_i);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_i_Plus_ii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_ii_Plus_ii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_iii_Plus_iii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_iii_Plus_v);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_v_Plus_iii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_viii_Plus_i);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_iv_Plus_viii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_xviii_Plus_iii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_xxxviii_Plus_iii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_xliii_Plus_vi);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_xlviii_Plus_iii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_lxxxviii_Plus_iii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_xciv_Plus_vii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_cccxc_Plus_xxxiii);
	
    suite_add_tcase(s, tc_core);
    
    return s;
}


int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;
    
    s = RomanNumberalLib_suite();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
