#pragma once

#ifndef _ZF_BOX_H_
#define _ZF_BOX_H_

/* To detect incompatible changes you can define ZF_BOX_VERSION_REQUIRED to
 * the current value of ZF_BOX_VERSION before including this file (or via
 * compiler command line):
 *
 *   #define ZF_BOX_VERSION_REQUIRED 1
 *   #include <zf_box.h>
 *
 * In that case compilation will fail when included file has incompatible
 * version.
 */
#define ZF_BOX_VERSION 1
#if defined(ZF_BOX_VERSION_REQUIRED)
	#if ZF_BOX_VERSION_REQUIRED != ZF_BOX_VERSION
		#error different zf_box version required
	#endif
#endif

#include <stdint.h>
#include <stddef.h>

#define _ZF_BOX_UTIL_PASTE_2(_0,_1) _0 ## _1
#define _ZF_BOX_UTIL_PASTE_5(_0,_1,_2,_3,_4) _0 ## _1 ## _2 ## _3 ## _4

#define _ZF_BOX_UTIL_CONCAT_2(...) _ZF_BOX_UTIL_PASTE_2(__VA_ARGS__)
#define _ZF_BOX_UTIL_CONCAT_5(...) _ZF_BOX_UTIL_PASTE_5(__VA_ARGS__)

#define _ZF_BOX_UTIL_SWITCH_2_CASE_0(a, b) a
#define _ZF_BOX_UTIL_SWITCH_2_CASE_1(a, b) b
#define _ZF_BOX_UTIL_SWITCH_2(x, a, b) _ZF_BOX_UTIL_CONCAT_2(_ZF_BOX_UTIL_SWITCH_2_CASE_, x)(a, b)

#define _ZF_BOX_UTIL_NOT(x) _ZF_BOX_UTIL_SWITCH_2(x, 1, 0)

#define _ZF_BOX_UTIL_ARG_0(_0,...) _0
#define _ZF_BOX_UTIL_ARG_1(_0,_1,...) _1
#define _ZF_BOX_UTIL_ARG_16(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,...) _16
#define _ZF_BOX_UTIL_ARG_HEAD(...) _ZF_BOX_UTIL_ARG_0(__VA_ARGS__, ~)
#define _ZF_BOX_UTIL_ARG_TAIL(_, ...) __VA_ARGS__
#define _ZF_BOX_UTIL_ARG_ID(...) __VA_ARGS__

#define _ZF_BOX_UTIL_BLANK(...)
#define _ZF_BOX_UTIL_COMMA(...) ,
#define _ZF_BOX_UTIL_INVOKE_1(f, ...) f(__VA_ARGS__)
#define _ZF_BOX_UTIL_INVOKE_2(f, g, ...) f(g(__VA_ARGS__))

#define _ZF_BOX_UTIL_MARK() ~, 1,
#define _ZF_BOX_UTIL_IS_MARK(x) _ZF_BOX_UTIL_INVOKE_1(_ZF_BOX_UTIL_ARG_1, x(), 0, ~)
#define _ZF_BOX_UTIL_IS_NOT_MARK(x) _ZF_BOX_UTIL_NOT(_ZF_BOX_UTIL_IS_MARK(x))
#define _ZF_BOX_UTIL_IF_MARK(x, yes, no) _ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_MARK(x), no, yes)

/*
#define _ZF_BOX_UTIL_HAS_COMMA(...) _ZF_BOX_UTIL_ARG_16(__VA_ARGS__,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,~)
#define _ZF_BOX_UTIL_COMMA_FUNC(...) ,
*/
#define _ZF_BOX_UTIL_IS_SINGLE(...) _ZF_BOX_UTIL_IS_MARK(_ZF_BOX_UTIL_ARG_1(__VA_ARGS__, _ZF_BOX_UTIL_MARK, ~))
//#define _ZF_BOX_UTIL_HAS_COMMA(...) _ZF_BOX_UTIL_IS_NOT_MARK(_ZF_BOX_UTIL_ARG_1(__VA_ARGS__, _ZF_BOX_UTIL_MARK, ~))
#define _ZF_BOX_UTIL_HAS_COMMA(...) _ZF_BOX_UTIL_NOT(_ZF_BOX_UTIL_IS_SINGLE(__VA_ARGS__))
#define _ZF_BOX_UTIL_IS_EMPTY_CASE_0001 ,
#define _ZF_BOX_UTIL_IS_EMPTY(...) \
	_ZF_BOX_UTIL_HAS_COMMA( \
		_ZF_BOX_UTIL_CONCAT_5( \
			_ZF_BOX_UTIL_IS_EMPTY_CASE_, \
			_ZF_BOX_UTIL_HAS_COMMA(__VA_ARGS__), \
			_ZF_BOX_UTIL_HAS_COMMA(__VA_ARGS__ ()), \
			_ZF_BOX_UTIL_HAS_COMMA(_ZF_BOX_UTIL_COMMA __VA_ARGS__), \
			_ZF_BOX_UTIL_HAS_COMMA(_ZF_BOX_UTIL_COMMA __VA_ARGS__ ()) \
		) \
	)

#define _ZF_BOX_UTIL_NARGS(...) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY(__VA_ARGS__), \
			_ZF_BOX_UTIL_ARG_16(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0), 0)

#define _ZF_BOX_UTIL_EVAL_32(...) __VA_ARGS__
#define _ZF_BOX_UTIL_EVAL_16(...) _ZF_BOX_UTIL_EVAL_32(_ZF_BOX_UTIL_EVAL_32(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL_8(...) _ZF_BOX_UTIL_EVAL_16(_ZF_BOX_UTIL_EVAL_16(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL_4(...) _ZF_BOX_UTIL_EVAL_8(_ZF_BOX_UTIL_EVAL_8(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL_2(...) _ZF_BOX_UTIL_EVAL_4(_ZF_BOX_UTIL_EVAL_4(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL(...) _ZF_BOX_UTIL_EVAL_2(_ZF_BOX_UTIL_EVAL_2(__VA_ARGS__))

/*
#define _ZF_BOX_UTIL_ZIP_0(xs, ys)
#define _ZF_BOX_UTIL_ZIP_1(xs, ys) (_ZF_BOX_UTIL_ARG_HEAD xs, _ZF_BOX_UTIL_ARG_HEAD ys)
#define _ZF_BOX_UTIL_ZIP_2(xs, ys) _ZF_BOX_UTIL_ZIP_N(1, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_3(xs, ys) _ZF_BOX_UTIL_ZIP_N(2, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_4(xs, ys) _ZF_BOX_UTIL_ZIP_N(3, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_5(xs, ys) _ZF_BOX_UTIL_ZIP_N(4, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_6(xs, ys) _ZF_BOX_UTIL_ZIP_N(5, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_7(xs, ys) _ZF_BOX_UTIL_ZIP_N(6, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_8(xs, ys) _ZF_BOX_UTIL_ZIP_N(7, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_9(xs, ys) _ZF_BOX_UTIL_ZIP_N(8, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_10(xs, ys) _ZF_BOX_UTIL_ZIP_N(9, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_11(xs, ys) _ZF_BOX_UTIL_ZIP_N(10, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_12(xs, ys) _ZF_BOX_UTIL_ZIP_N(11, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_13(xs, ys) _ZF_BOX_UTIL_ZIP_N(12, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_14(xs, ys) _ZF_BOX_UTIL_ZIP_N(13, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_15(xs, ys) _ZF_BOX_UTIL_ZIP_N(14, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_16(xs, ys) _ZF_BOX_UTIL_ZIP_N(15, xs, ys)((_ZF_BOX_UTIL_ARG_TAIL xs), (_ZF_BOX_UTIL_ARG_TAIL ys))
#define _ZF_BOX_UTIL_ZIP_N(N, xs, ys) _ZF_BOX_UTIL_ZIP_1(xs, ys), _ZF_BOX_UTIL_CONCAT_2(_ZF_BOX_UTIL_ZIP_, N)
#define _ZF_BOX_UTIL_ZIP(xs, ys) _ZF_BOX_UTIL_CONCAT_2(_ZF_BOX_UTIL_ZIP_, _ZF_BOX_UTIL_NARGS xs)(xs, ys)
*/

#define _ZF_BOX_UTIL_MAP_SEP(f, sep, y, ...) \
	sep(y) _ZF_BOX_UTIL_MAP_ONE _ZF_BOX_UTIL_BLANK() (f, sep, y, __VA_ARGS__)
#define _ZF_BOX_UTIL_MAP_ONE(f, sep, x, y, ...) \
	f(x) _ZF_BOX_UTIL_IF_MARK(y, _ZF_BOX_UTIL_BLANK, _ZF_BOX_UTIL_MAP_SEP) _ZF_BOX_UTIL_BLANK() (f, sep, y, __VA_ARGS__)
#define _ZF_BOX_UTIL_MAP(f, sep, xs) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY(_ZF_BOX_UTIL_ARG_ID xs), \
		_ZF_BOX_UTIL_INVOKE_2(_ZF_BOX_UTIL_EVAL, _ZF_BOX_UTIL_MAP_ONE, f, sep, _ZF_BOX_UTIL_ARG_ID xs, _ZF_BOX_UTIL_MARK, ~),)

#define LIST_MAP_SEP(f, xs) LIST_MAP_ONE _ZF_BOX_UTIL_BLANK() (f, xs)
#define LIST_MAP_ONE(f, xs) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY xs, \
		_ZF_BOX_UTIL_INVOKE_1(f, _ZF_BOX_UTIL_ARG_HEAD xs), \
	) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_SINGLE xs, \
		LIST_MAP_SEP, _ZF_BOX_UTIL_BLANK \
	) \
	_ZF_BOX_UTIL_BLANK() (f, (_ZF_BOX_UTIL_ARG_TAIL _ZF_BOX_UTIL_BLANK() xs))
#define LIST_MAP(f, xs) \
	_ZF_BOX_UTIL_EVAL(LIST_MAP_ONE(f, xs))

#define LIST_ZIP_SEP(f, xs, ys) LIST_ZIP_ONE _ZF_BOX_UTIL_BLANK() (f, xs, ys)
#define LIST_ZIP_ONE(f, xs, ys) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY xs, \
		(_ZF_BOX_UTIL_INVOKE_1(f, _ZF_BOX_UTIL_ARG_HEAD xs, _ZF_BOX_UTIL_ARG_HEAD ys)), \
	) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_SINGLE xs, \
		LIST_ZIP_SEP, _ZF_BOX_UTIL_BLANK \
	) \
	_ZF_BOX_UTIL_BLANK() (f, (_ZF_BOX_UTIL_ARG_TAIL _ZF_BOX_UTIL_BLANK() xs), (_ZF_BOX_UTIL_ARG_TAIL _ZF_BOX_UTIL_BLANK() ys))
#define LIST_ZIP(f, xs, ys) \
	_ZF_BOX_UTIL_EVAL(LIST_ZIP_ONE(f, xs, ys))

typedef struct zf_box_ivar_t
{
	const char *const name;
	const uint16_t type;
	const uint16_t flags;
	const uint32_t offset;
}
zf_box_ivar_t;

typedef struct zf_box_class_base_t
{
	const char *const name;
	const uint16_t size;
	const uint16_t ivar_count;
}
zf_box_class_base_t;

typedef struct zf_box_class_t
{
	const zf_box_class_base_t base;
	const zf_box_ivar_t ivar_list[1];
}
zf_box_class_t;

#define _ZF_BOX_CLASS_TYPE_NAME(CLASS) _zf_box_class_type_##CLASS
#define _ZF_BOX_INSTANCE_TYPE_NAME(CLASS) _zf_box_instance_type_##CLASS
#define _ZF_BOX_CLASS_OBJECT_NAME(CLASS) _zf_box_class_object_##CLASS
#define _ZF_BOX_IVAR_NAME(VAR) VAR

#ifdef __cplusplus
	#define _ZF_BOX_CLASS_TYPE(CLASS) \
		struct _ZF_BOX_INSTANCE_TYPE_NAME(CLASS)::_ZF_BOX_CLASS_TYPE_NAME(CLASS)
	#define _ZF_BOX_INSTANCE_TYPE(CLASS) \
		struct _ZF_BOX_INSTANCE_TYPE_NAME(CLASS)
#else
	#define _ZF_BOX_CLASS_TYPE(CLASS) \
		struct _ZF_BOX_CLASS_TYPE_NAME(CLASS)
	#define _ZF_BOX_INSTANCE_TYPE(CLASS) \
		struct _ZF_BOX_INSTANCE_TYPE_NAME(CLASS)
#endif

#define _ZF_BOX_IVAR_COUNT_CALLBACK(_, TYPE, NAME, VAR) +1
#define _ZF_BOX_IVAR_COUNT(CLASS) \
	(0 CLASS(_ZF_BOX_IVAR_COUNT_ITER, _))

#define _ZF_BOX_IVAR_OFFSET(CLASS, VAR) \
	offsetof(_ZF_BOX_INSTANCE_TYPE(CLASS), _ZF_BOX_IVAR_NAME(VAR))

#define ZF_BOX_CLASS_DECL(CLASS)

#endif
