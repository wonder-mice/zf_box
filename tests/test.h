#pragma once

#include <string.h>
#include <stdio.h>
#include <zf_box.h>

#define TEST_0 T0
#define TEST_1 T1
#define TEST_2 T2
#define TEST_3 T3
#define TEST_4 T4
#define TEST_NO 0
#define TEST_YES 1
#define TEST_BLANK

#define _STR(...) #__VA_ARGS__
#define STR(...) _STR(__VA_ARGS__)

/* paste */
#if T0T1 != _ZF_BOX_UTIL_PASTE_2(T0, T1)
	#error Invalid paste
#endif
#if TEST_0TEST_1 != _ZF_BOX_UTIL_PASTE_2(TEST_0, TEST_1)
	#error Invalid paste
#endif
#if T0T1T2T3T4 != _ZF_BOX_UTIL_PASTE_5(T0, T1, T2, T3, T4)
	#error Invalid paste
#endif
#if TEST_0TEST_1TEST_2TEST_3TEST_4 != _ZF_BOX_UTIL_PASTE_5(TEST_0, TEST_1, TEST_2, TEST_3, TEST_4)
	#error Invalid paste
#endif

/* concat */
#if T0T1 != _ZF_BOX_UTIL_CONCAT_2(T0, T1)
	#error Invalid concat
#endif
#if T0T1 != _ZF_BOX_UTIL_CONCAT_2(TEST_0, TEST_1)
	#error Invalid concat
#endif
#if T0T1T2T3T4 != _ZF_BOX_UTIL_CONCAT_5(T0, T1, T2, T3, T4)
	#error Invalid concat
#endif
#if T0T1T2T3T4 != _ZF_BOX_UTIL_CONCAT_5(TEST_0, TEST_1, TEST_2, TEST_3, TEST_4)
	#error Invalid concat
#endif

/* switch */
#if T0 != _ZF_BOX_UTIL_SWITCH_2(TEST_NO, T0, T1)
	#error Invalid switch
#endif
#if T1 != _ZF_BOX_UTIL_SWITCH_2(TEST_YES, T0, T1)
	#error Invalid switch
#endif
#if T0 != _ZF_BOX_UTIL_SWITCH_2(TEST_NO, TEST_0, TEST_1)
	#error Invalid switch
#endif
#if T1 != _ZF_BOX_UTIL_SWITCH_2(TEST_YES, TEST_0, TEST_1)
	#error Invalid switch
#endif

/* not */
#if 1 != _ZF_BOX_UTIL_NOT(TEST_NO)
	#error Invalid not
#endif
#if 0 != _ZF_BOX_UTIL_NOT(TEST_YES)
	#error Invalid not
#endif

/* arg */
#if T0 != _ZF_BOX_UTIL_ARG_0(TEST_0, TEST_1, TEST_2)
	#error Invalid arg
#endif
#if T1 != _ZF_BOX_UTIL_ARG_1(TEST_0, TEST_1, TEST_2)
	#error Invalid arg
#endif
#if T0 != _ZF_BOX_UTIL_ARG_HEAD(TEST_0)
	#error Invalid arg
#endif
#if T0 != _ZF_BOX_UTIL_ARG_HEAD(TEST_0, TEST_1, TEST_2)
	#error Invalid arg
#endif
#if T1 != _ZF_BOX_UTIL_ARG_TAIL(TEST_0, TEST_1)
	#error Invalid arg
#endif
#if T0 != _ZF_BOX_UTIL_ARG_ID(TEST_0)
	#error Invalid arg
#endif

/* mark */
#if 0 != _ZF_BOX_UTIL_IS_MARK(TEST_0)
	#error Invalid mark
#endif
#if 1 != _ZF_BOX_UTIL_IS_MARK(_ZF_BOX_UTIL_MARK)
	#error Invalid mark
#endif
#if 1 != _ZF_BOX_UTIL_IS_NOT_MARK(TEST_0)
	#error Invalid mark
#endif
#if 0 != _ZF_BOX_UTIL_IS_NOT_MARK(_ZF_BOX_UTIL_MARK)
	#error Invalid mark
#endif
#if T2 != _ZF_BOX_UTIL_IF_MARK(TEST_0, TEST_1, TEST_2)
	#error Invalid mark
#endif
#if T1 != _ZF_BOX_UTIL_IF_MARK(_ZF_BOX_UTIL_MARK, TEST_1, TEST_2)
	#error Invalid mark
#endif

/* is_single */
#if 1 != _ZF_BOX_UTIL_IS_SINGLE()
	#error Invalid is_single
#endif
#if 1 != _ZF_BOX_UTIL_IS_SINGLE(())
	#error Invalid is_single
#endif
#if 1 != _ZF_BOX_UTIL_IS_SINGLE((,))
	#error Invalid is_single
#endif
#if 1 != _ZF_BOX_UTIL_IS_SINGLE(TEST_0)
	#error Invalid is_single
#endif
#if 0 != _ZF_BOX_UTIL_IS_SINGLE(,)
	#error Invalid is_single
#endif
#if 0 != _ZF_BOX_UTIL_IS_SINGLE(TEST_0, TEST_1)
	#error Invalid is_single
#endif
#if 0 != _ZF_BOX_UTIL_IS_SINGLE((), ())
	#error Invalid is_single
#endif

/* has_comma */
#if 0 != _ZF_BOX_UTIL_HAS_COMMA()
	#error Invalid has_comma
#endif
#if 0 != _ZF_BOX_UTIL_HAS_COMMA(())
	#error Invalid has_comma
#endif
#if 0 != _ZF_BOX_UTIL_HAS_COMMA((,))
	#error Invalid has_comma
#endif
#if 0 != _ZF_BOX_UTIL_HAS_COMMA(TEST_0)
	#error Invalid has_comma
#endif
#if 1 != _ZF_BOX_UTIL_HAS_COMMA(,)
	#error Invalid has_comma
#endif
#if 1 != _ZF_BOX_UTIL_HAS_COMMA(TEST_0, TEST_1)
	#error Invalid has_comma
#endif
#if 1 != _ZF_BOX_UTIL_HAS_COMMA((), ())
	#error Invalid has_comma
#endif

/* is_empty */
#if 1 != _ZF_BOX_UTIL_IS_EMPTY()
	#error Invalid is_empty
#endif
#if 1 != _ZF_BOX_UTIL_IS_EMPTY(TEST_BLANK)
	#error Invalid is_empty
#endif
#if 0 != _ZF_BOX_UTIL_IS_EMPTY(())
	#error Invalid is_empty
#endif
#if 0 != _ZF_BOX_UTIL_IS_EMPTY(TEST_0)
	#error Invalid is_empty
#endif
#if 0 != _ZF_BOX_UTIL_IS_EMPTY(,)
	#error Invalid is_empty
#endif


/* unused */
#if 0
#if 0 != _ZF_BOX_UTIL_NARGS()
	#error Number of arguments is not 0
#endif
#if 1 != _ZF_BOX_UTIL_NARGS(1)
	#error Number of arguments is not 1
#endif
#if 2 != _ZF_BOX_UTIL_NARGS(1, 2)
	#error Number of arguments is not 2
#endif
#if 3 != _ZF_BOX_UTIL_NARGS(1, 2, 3)
	#error Number of arguments is not 3
#endif
#endif

static int test_equal(const char *const expected, const char *const actual,
					  const char *const file, const unsigned line)
{
	if (0 == strcmp(expected, actual))
	{
		return 0;
	}
	fprintf(stderr, "%s:%u: error: not equal:\n", file, line);
	fprintf(stderr, "    expected: \"%s\"\n", expected);
	fprintf(stderr, "      actual: \"%s\"\n", actual);
	return -1;
}

#define TEST_EQUAL(expected, actual) \
	do { \
		if (0 != test_equal(expected, STR(actual), __FILE__, __LINE__)) {\
			return -1; \
		} \
	} while(0)

static int test_run()
{
	int a[2];//[2]);
	(void)a;
	/* map */
	#undef F
	#define F(x) int x;
	TEST_EQUAL("",
			   _ZF_BOX_UTIL_MAP(F, _ZF_BOX_UTIL_BLANK, ()));
	TEST_EQUAL("int a;",
			   _ZF_BOX_UTIL_MAP(F, _ZF_BOX_UTIL_BLANK, (a)));
	TEST_EQUAL("int a; int b; int c;",
			   _ZF_BOX_UTIL_MAP(F, _ZF_BOX_UTIL_BLANK, (a, b, c)));

	/* zip */
	#undef F
	#define F(x, y) x, y
	TEST_EQUAL("",
			   _ZF_BOX_UTIL_ZIP(F, _ZF_BOX_UTIL_COMMA, (), ()));
	TEST_EQUAL("(1, a)",
			   _ZF_BOX_UTIL_ZIP(F, _ZF_BOX_UTIL_COMMA, (1), (a)));
	TEST_EQUAL("(1, a) , (2, b) , (3, c)",
			   _ZF_BOX_UTIL_ZIP(F, _ZF_BOX_UTIL_COMMA, (1, 2, 3), (a, b, c)));

	/* eval */
	#undef F_SEP
	#undef F_ONE
	#define F_SEP() F_ONE _ZF_BOX_UTIL_BLANK() ()
	#define F_ONE() 1 F_SEP _ZF_BOX_UTIL_BLANK() ()
	TEST_EQUAL("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 "
			   "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 "
			   "1 F_SEP ()",
			   _ZF_BOX_UTIL_EVAL(F_ONE()));
	return 0;
}

#define SMALL_DATA(FIELD, _) \
	FIELD(_, UINT32, "small.value", value) \
	FIELD(_, DOUBLE, "small.duration", duration)
	//FIELD(_, ARRAY(CHAR, 16), "small.duration", text)
ZF_BOX_CLASS_DECL(SMALL_DATA);
static ZF_BOX_CLASS_DEF(SMALL_DATA);

#define BIG_DATA(FIELD, _) \
	FIELD(_, INSTANCE(SMALL_DATA), "improved.value", small) \
	FIELD(_, ARRAY(CHAR, 4), "improved.value", char_array) \
	FIELD(_, ARRAY(INSTANCE(SMALL_DATA), 4), "improved.value", small_array) \
	FIELD(_, BUFFER(CHAR), "improved.value", char_buffer)
ZF_BOX_CLASS_DECL(BIG_DATA);
static ZF_BOX_CLASS_DEF(BIG_DATA);

static void test_init()
{
	_ZF_BOX_INSTANCE_TYPE(SMALL_DATA) small;
	ZF_BOX_INSTANCE_ASSIGN(SMALL_DATA, &small, 1, 2.0f);
	(void)small;
}

/*
#define BIG_DATA(FIELD, _) \
	FIELD(_, INSTANCE(SMALL_DATA), "improved.value", array_i) \
	FIELD(_, ARRAY(INSTANCE(SMALL_DATA), 10), "improved.value", array) \
	FIELD(_, ARRAY(DOUBLE, 10), "improved.value", array_d) \
	FIELD(_, UINT32, "improved.value", value) \
	FIELD(_, DOUBLE, "improved.duration", duration) \
	FIELD(_, STRING, "improved.caption", caption) \
	FIELD(_, BYTES(38), "improved.data", data)
ZF_BOX_CLASS_DECL(BIG_DATA)
*/
