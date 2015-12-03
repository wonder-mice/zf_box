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
#define _ZF_BOX_UTIL_ARG_HEAD(...) _ZF_BOX_UTIL_ARG_0(__VA_ARGS__, ~)
#define _ZF_BOX_UTIL_ARG_TAIL(_, ...) __VA_ARGS__
#define _ZF_BOX_UTIL_ARG_ID(...) __VA_ARGS__

#define _ZF_BOX_UTIL_BLANK(...)
#define _ZF_BOX_UTIL_COMMA(...) ,
#define _ZF_BOX_UTIL_INVOKE_1(f, ...) f(__VA_ARGS__)

#define _ZF_BOX_UTIL_MARK() ~, 1,
#define _ZF_BOX_UTIL_IS_MARK(x) _ZF_BOX_UTIL_INVOKE_1(_ZF_BOX_UTIL_ARG_1, x(), 0, ~)
#define _ZF_BOX_UTIL_IS_NOT_MARK(x) _ZF_BOX_UTIL_NOT(_ZF_BOX_UTIL_IS_MARK(x))
#define _ZF_BOX_UTIL_IF_MARK(x, yes, no) _ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_MARK(x), no, yes)

#define _ZF_BOX_UTIL_IS_SINGLE(...) _ZF_BOX_UTIL_IS_MARK(_ZF_BOX_UTIL_ARG_1(__VA_ARGS__, _ZF_BOX_UTIL_MARK, ~))
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

/* Unused */
#if 0
#define _ZF_BOX_UTIL_ARG_16(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,...) _16
#define _ZF_BOX_UTIL_INVOKE_2(f, g, ...) f(g(__VA_ARGS__))
#define _ZF_BOX_UTIL_HAS_COMMA(...) _ZF_BOX_UTIL_ARG_16(__VA_ARGS__,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,~)
#define _ZF_BOX_UTIL_HAS_COMMA(...) _ZF_BOX_UTIL_IS_NOT_MARK(_ZF_BOX_UTIL_ARG_1(__VA_ARGS__, _ZF_BOX_UTIL_MARK, ~))
#define _ZF_BOX_UTIL_NARGS(...) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY(__VA_ARGS__), \
			_ZF_BOX_UTIL_ARG_16(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0), 0)

#define _ZF_BOX_UTIL_MAP_SEP(f, sep, y, ...) \
	sep(y) _ZF_BOX_UTIL_MAP_ONE _ZF_BOX_UTIL_BLANK() (f, sep, y, __VA_ARGS__)
#define _ZF_BOX_UTIL_MAP_ONE(f, sep, x, y, ...) \
	f(x) _ZF_BOX_UTIL_IF_MARK(y, _ZF_BOX_UTIL_BLANK, _ZF_BOX_UTIL_MAP_SEP) _ZF_BOX_UTIL_BLANK() (f, sep, y, __VA_ARGS__)
#define _ZF_BOX_UTIL_MAP(f, sep, xs) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY(_ZF_BOX_UTIL_ARG_ID xs), \
		_ZF_BOX_UTIL_INVOKE_2(_ZF_BOX_UTIL_EVAL, _ZF_BOX_UTIL_MAP_ONE, f, sep, _ZF_BOX_UTIL_ARG_ID xs, _ZF_BOX_UTIL_MARK, ~),)
#endif

#define _ZF_BOX_UTIL_EVAL_64(...) __VA_ARGS__
#define _ZF_BOX_UTIL_EVAL_32(...) _ZF_BOX_UTIL_EVAL_64(_ZF_BOX_UTIL_EVAL_64(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL_16(...) _ZF_BOX_UTIL_EVAL_32(_ZF_BOX_UTIL_EVAL_32(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL_8(...) _ZF_BOX_UTIL_EVAL_16(_ZF_BOX_UTIL_EVAL_16(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL_4(...) _ZF_BOX_UTIL_EVAL_8(_ZF_BOX_UTIL_EVAL_8(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL_2(...) _ZF_BOX_UTIL_EVAL_4(_ZF_BOX_UTIL_EVAL_4(__VA_ARGS__))
#define _ZF_BOX_UTIL_EVAL(...) _ZF_BOX_UTIL_EVAL_2(_ZF_BOX_UTIL_EVAL_2(__VA_ARGS__))

#define _ZF_BOX_UTIL_MAP_SEP(f, sep, xs) \
	_ZF_BOX_UTIL_INVOKE_1(sep, _ZF_BOX_UTIL_ARG_HEAD xs) \
	_ZF_BOX_UTIL_MAP_ONE _ZF_BOX_UTIL_BLANK() (f, sep, xs)
#define _ZF_BOX_UTIL_MAP_ONE(f, sep, xs) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY xs, \
		_ZF_BOX_UTIL_INVOKE_1(f, _ZF_BOX_UTIL_ARG_HEAD xs), \
	) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_SINGLE xs, \
		_ZF_BOX_UTIL_MAP_SEP, _ZF_BOX_UTIL_BLANK \
	) \
	_ZF_BOX_UTIL_BLANK() (f, sep, (_ZF_BOX_UTIL_ARG_TAIL _ZF_BOX_UTIL_BLANK() xs))
#define _ZF_BOX_UTIL_MAP(f, sep, xs) \
	_ZF_BOX_UTIL_EVAL(_ZF_BOX_UTIL_MAP_ONE(f, sep, xs))

#define _ZF_BOX_UTIL_ZIP_SEP(f, sep, xs, ys) \
	_ZF_BOX_UTIL_INVOKE_1(sep, _ZF_BOX_UTIL_ARG_HEAD xs, _ZF_BOX_UTIL_ARG_HEAD ys) \
	_ZF_BOX_UTIL_ZIP_ONE _ZF_BOX_UTIL_BLANK() (f, sep, xs, ys)
#define _ZF_BOX_UTIL_ZIP_ONE(f, sep, xs, ys) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_EMPTY xs, \
		(_ZF_BOX_UTIL_INVOKE_1(f, _ZF_BOX_UTIL_ARG_HEAD xs, _ZF_BOX_UTIL_ARG_HEAD ys)), \
	) \
	_ZF_BOX_UTIL_SWITCH_2(_ZF_BOX_UTIL_IS_SINGLE xs, \
		_ZF_BOX_UTIL_ZIP_SEP, _ZF_BOX_UTIL_BLANK \
	) \
	_ZF_BOX_UTIL_BLANK() (f, sep, (_ZF_BOX_UTIL_ARG_TAIL _ZF_BOX_UTIL_BLANK() xs), (_ZF_BOX_UTIL_ARG_TAIL _ZF_BOX_UTIL_BLANK() ys))
#define _ZF_BOX_UTIL_ZIP(f, sep, xs, ys) \
	_ZF_BOX_UTIL_EVAL(_ZF_BOX_UTIL_ZIP_ONE(f, sep, xs, ys))

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

typedef struct zf_box_instance_t
{
	const zf_box_class_t *isa;
}
zf_box_instance_t;

enum
{
	ZF_BOX_TYPE_CHAR = 1,
	ZF_BOX_TYPE_INT32 = 2,
	ZF_BOX_TYPE_UINT32 = 3,
	ZF_BOX_TYPE_DOUBLE = 4,
	ZF_BOX_TYPE_STRING = 5,
	ZF_BOX_TYPE_INSTANCE = 6,
};

enum
{
	ZF_BOX_FLAG_ARRAY = 1 << 0,
	ZF_BOX_FLAG_BUFFER = 1 << 1,
};

#define _ZF_BOX_CLASS_TYPE_NAME(CLASS) _zf_box_class_type_##CLASS
#define _ZF_BOX_INSTANCE_TYPE_NAME(CLASS) _zf_box_instance_type_##CLASS
#define _ZF_BOX_CLASS_OBJECT_NAME(CLASS) _zf_box_class_object_##CLASS
#define _ZF_BOX_CLASS_OBJECT_PTR(CLASS)  ((zf_box_class_t *)&_ZF_BOX_CLASS_OBJECT_NAME(CLASS))
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

#define _ZF_BOX_VAR_NAME(NAME) NAME;
#define _ZF_BOX_VAR_DECL__CHAR(NAME) char _ZF_BOX_VAR_NAME(NAME)
#define _ZF_BOX_VAR_DECL__INT32(NAME) int32_t _ZF_BOX_VAR_NAME(NAME)
#define _ZF_BOX_VAR_DECL__UINT32(NAME) uint32_t _ZF_BOX_VAR_NAME(NAME)
#define _ZF_BOX_VAR_DECL__DOUBLE(NAME) double _ZF_BOX_VAR_NAME(NAME)
#define _ZF_BOX_VAR_DECL__INSTANCE(CLASS) _ZF_BOX_INSTANCE_TYPE(CLASS) _ZF_BOX_VAR_NAME
#define _ZF_BOX_VAR_DECL__ARRAY(TYPE, N) struct { size_t len; _ZF_BOX_VAR_DECL__##TYPE(xs[N]) } _ZF_BOX_VAR_NAME
#define _ZF_BOX_VAR_DECL__BUFFER(TYPE) struct { size_t len; size_t offset; _ZF_BOX_VAR_DECL__##TYPE(*xs) } _ZF_BOX_VAR_NAME

#define _ZF_BOX_IVAR_COUNT_ONE(_, TYPE, NAME, VAR) +1
#define _ZF_BOX_IVAR_COUNT(CLASS) \
	(0 CLASS(_ZF_BOX_IVAR_COUNT_ONE, _))
#define _ZF_BOX_IVAR_OFFSET(CLASS, VAR) \
	offsetof(_ZF_BOX_INSTANCE_TYPE(CLASS), _ZF_BOX_IVAR_NAME(VAR))

#define _ZF_BOX_IVAR_DECL_ONE(_, TYPE, NAME, VAR) \
	_ZF_BOX_VAR_DECL__##TYPE(_ZF_BOX_IVAR_NAME(VAR))

#define ZF_BOX_CLASS_DECL(CLASS) \
	struct _ZF_BOX_INSTANCE_TYPE_NAME(CLASS) { \
		struct _ZF_BOX_CLASS_TYPE_NAME(CLASS) { \
			const zf_box_class_base_t base; \
			const zf_box_ivar_t ivar_list[_ZF_BOX_IVAR_COUNT(CLASS)]; \
		} *_isa; \
		CLASS(_ZF_BOX_IVAR_DECL_ONE, ~) \
	}

#define _ZF_BOX_TYPE__CHAR ZF_BOX_TYPE_CHAR
#define _ZF_BOX_TYPE__INT32 ZF_BOX_TYPE_INT32
#define _ZF_BOX_TYPE__UINT32 ZF_BOX_TYPE_UINT32
#define _ZF_BOX_TYPE__DOUBLE ZF_BOX_TYPE_DOUBLE
#define _ZF_BOX_TYPE__INSTANCE(CLASS) ZF_BOX_TYPE_INSTANCE
#define _ZF_BOX_TYPE__ARRAY(TYPE, N) _ZF_BOX_TYPE__##TYPE
#define _ZF_BOX_TYPE__BUFFER(TYPE) _ZF_BOX_TYPE__##TYPE

#define _ZF_BOX_FLAGS__CHAR 0
#define _ZF_BOX_FLAGS__INT32 0
#define _ZF_BOX_FLAGS__UINT32 0
#define _ZF_BOX_FLAGS__DOUBLE 0
#define _ZF_BOX_FLAGS__INSTANCE(CLASS) 0
#define _ZF_BOX_FLAGS__ARRAY(TYPE, N) ZF_BOX_FLAG_ARRAY
#define _ZF_BOX_FLAGS__BUFFER(TYPE) ZF_BOX_FLAG_BUFFER

#define _ZF_BOX_IVAR_DEF_ONE(CLASS, TYPE, NAME, VAR) \
	{NAME, _ZF_BOX_TYPE__##TYPE, _ZF_BOX_FLAGS__##TYPE, _ZF_BOX_IVAR_OFFSET(CLASS, VAR)},

#define ZF_BOX_CLASS_DEF(CLASS) \
	_ZF_BOX_CLASS_TYPE(CLASS) _ZF_BOX_CLASS_OBJECT_NAME(CLASS) = { \
		{#CLASS, _ZF_BOX_IVAR_COUNT(CLASS), sizeof(_ZF_BOX_INSTANCE_TYPE(CLASS))}, \
		{CLASS(_ZF_BOX_IVAR_DEF_ONE, CLASS)}, \
	}

#define _ZF_BOX_CLASS_LIST_ONE(CTX, TYPE, NAME, IVAR) (CTX, TYPE, NAME, IVAR),
#define _ZF_BOX_CLASS_LIST(CLASS, CTX) CLASS(_ZF_BOX_CLASS_LIST_ONE, CTX)

#define _ZF_BOX_CLASS_ZIP_ONE(VALUE, DECL) VALUE, _ZF_BOX_UTIL_ARG_ID DECL
#define _ZF_BOX_CLASS_ZIP(CLASS, VAR, ...) \
	_ZF_BOX_UTIL_ZIP(_ZF_BOX_CLASS_ZIP_ONE, _ZF_BOX_UTIL_COMMA, \
		(__VA_ARGS__), (_ZF_BOX_CLASS_LIST(CLASS, VAR)))

#define _ZF_BOX_VAR_ASSIGN__CHAR(VALUE, VAR, TYPE, IVAR) VAR->IVAR = (VALUE);
#define _ZF_BOX_VAR_ASSIGN__INT32(VALUE, VAR, TYPE, IVAR) VAR->IVAR = (VALUE);
#define _ZF_BOX_VAR_ASSIGN__UINT32(VALUE, VAR, TYPE, IVAR) VAR->IVAR = (VALUE);
#define _ZF_BOX_VAR_ASSIGN__DOUBLE(VALUE, VAR, TYPE, IVAR) VAR->IVAR = (VALUE);
#define _ZF_BOX_VAR_ASSIGN__INSTANCE(CLASS) copy//VALUE, VAR, TYPE, IVAR) VAR->IVAR = (VALUE);
#define _ZF_BOX_VAR_ASSIGN__ARRAY(TYPE, N) //VALUE, VAR, TYPE, IVAR) VAR->IVAR = (VALUE);
#define _ZF_BOX_VAR_ASSIGN__BUFFER(TYPE) //

#define _ZF_BOX_IVAR_ASSIGN_(VALUE, VAR, TYPE, NAME, IVAR) _ZF_BOX_VAR_ASSIGN__##TYPE(VALUE, VAR, TYPE, IVAR)
#define _ZF_BOX_IVAR_ASSIGN_ONE(PARAMS) _ZF_BOX_IVAR_ASSIGN_ PARAMS

#define ZF_BOX_INSTANCE_ASSIGN(CLASS, VAR, ...) \
	do { \
		_ZF_BOX_INSTANCE_TYPE(CLASS) *const _p = (VAR); \
		((zf_box_instance_t *)_p)->isa = _ZF_BOX_CLASS_OBJECT_PTR(CLASS); \
		_ZF_BOX_UTIL_MAP(_ZF_BOX_IVAR_ASSIGN_ONE, _ZF_BOX_UTIL_BLANK, \
			(_ZF_BOX_CLASS_ZIP(CLASS, _p, __VA_ARGS__))) \
	} while(0)

#endif
