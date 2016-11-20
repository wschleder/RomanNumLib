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

START_TEST (test_romanNumbersAdd_Add_cdl_Plus_li)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("cdl", "li", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "di");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_dcccl_Plus_lxxiii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("dcccl", "lxxiii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "cmxxiii");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_cml_Plus_li)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("cml", "li", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "mi");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_mmmdlv_Plus_cccxxxiii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("mmmdlv", "cccxxxiii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "mmmdccclxxxviii");
}
END_TEST

START_TEST (test_romanNumbersAdd_Add_0_Plus_mmmcmxcix)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("", "mmmcmxcix", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "mmmcmxcix");
}
END_TEST

START_TEST (test_romanNumbersAdd_GuardsAgainstOverflow)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("i", "mmmcmxcix", buffer);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersAdd_GuardsAgainstInvalidInputA)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("mmmcmicix", "i", buffer);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersAdd_GuardsAgainstInvalidInputB)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("i", "mmmcmzxcix", buffer);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersSub_GuardsAgainstNullInputA)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub(NULL, "", buffer);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersSub_GuardsAgainstNullInputB)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub("", NULL, buffer);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersSub_GuardsAgainstNullOutputBuffer)
{
	RomanNumLibResults result = romanNumbersSub("", "", NULL);
	ck_assert(result == eRomanNumLib_Error);
}
END_TEST

START_TEST (test_romanNumbersSub_Subtract_ii_Minus_i)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub("ii", "i", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "i");
}
END_TEST

START_TEST (test_romanNumbersSub_Subtract_viii_Minus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub("viii", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "v");
}
END_TEST

START_TEST (test_romanNumbersSub_Subtract_li_Minus_iii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub("li", "iii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "xlviii");
}
END_TEST

START_TEST (test_romanNumbersSub_Subtract_di_Minus_li)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub("di", "li", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "cdl");
}
END_TEST

START_TEST (test_romanNumbersSub_Subtract_mmmdccclxxxviii_Minus_cccxxxiii)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub("mmmdccclxxxviii", "cccxxxiii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "mmmdlv");
}
END_TEST

START_TEST (test_romanNumbersSub_Subtractration_With_Zero_Result)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersSub("mmmdccclxxxviii", "mmmdccclxxxviii", buffer);
	ck_assert(result == eRomanNumLib_NoError);
	ck_assert_str_eq(buffer, "");
}
END_TEST


START_TEST (test_romanNumbersSub_GuardsAgainstUnderflow)
{
	char buffer[80];
	RomanNumLibResults result = romanNumbersAdd("i", "mmmcmxcix", buffer);
	ck_assert(result == eRomanNumLib_Error);
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
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_cdl_Plus_li);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_dcccl_Plus_lxxiii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_cml_Plus_li);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_mmmdlv_Plus_cccxxxiii);
	tcase_add_test(tc_core, test_romanNumbersAdd_Add_0_Plus_mmmcmxcix);
	tcase_add_test(tc_core, test_romanNumbersAdd_GuardsAgainstOverflow);
	tcase_add_test(tc_core, test_romanNumbersAdd_GuardsAgainstInvalidInputA);
	tcase_add_test(tc_core, test_romanNumbersAdd_GuardsAgainstInvalidInputB);
	tcase_add_test(tc_core, test_romanNumbersSub_GuardsAgainstNullInputA);
	tcase_add_test(tc_core, test_romanNumbersSub_GuardsAgainstNullInputB);
	tcase_add_test(tc_core, test_romanNumbersSub_GuardsAgainstNullOutputBuffer);
	tcase_add_test(tc_core, test_romanNumbersSub_Subtract_ii_Minus_i);
	tcase_add_test(tc_core, test_romanNumbersSub_Subtract_viii_Minus_iii);
	tcase_add_test(tc_core, test_romanNumbersSub_Subtract_li_Minus_iii);
	tcase_add_test(tc_core, test_romanNumbersSub_Subtract_di_Minus_li);
	tcase_add_test(tc_core, test_romanNumbersSub_Subtract_mmmdccclxxxviii_Minus_cccxxxiii);
	tcase_add_test(tc_core, test_romanNumbersSub_Subtractration_With_Zero_Result);
	tcase_add_test(tc_core, test_romanNumbersSub_GuardsAgainstUnderflow);
	
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
