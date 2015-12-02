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

#define _ZF_BOX_UTIL_ARG_0(_0,...) _0
#define _ZF_BOX_UTIL_ARG_15(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,...) _15
#define _ZF_BOX_UTIL_ARG_HEAD(...) _ZF_BOX_UTIL_ARG_0(__VA_ARGS__, ~)
#define _ZF_BOX_UTIL_ARG_TAIL(_, ...) __VA_ARGS__

#define _ZF_BOX_UTIL_HAS_COMMA(...) _ZF_BOX_UTIL_ARG_15(__VA_ARGS__,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,~)
#define _ZF_BOX_UTIL_COMMA_FUNC(...) ,

#define _ZF_BOX_UTIL_IS_EMPTY_CASE_0001 ,

#define _ZF_BOX_UTIL_IS_EMPTY(...) \
	_ZF_BOX_UTIL_HAS_COMMA( \
		_ZF_BOX_UTIL_CONCAT_5( \
			_ZF_BOX_UTIL_IS_EMPTY_CASE_, \
			_ZF_BOX_UTIL_HAS_COMMA(__VA_ARGS__), \
			_ZF_BOX_UTIL_HAS_COMMA(__VA_ARGS__ ()), \
			_ZF_BOX_UTIL_HAS_COMMA(_ZF_BOX_UTIL_COMMA_FUNC __VA_ARGS__), \
			_ZF_BOX_UTIL_HAS_COMMA(_ZF_BOX_UTIL_COMMA_FUNC __VA_ARGS__ ()) \
		) \
	)

#define _ZF_BOX_UTIL_NARGS_CASE_1(...) 0
#define _ZF_BOX_UTIL_NARGS_CASE_0(...) _ZF_BOX_UTIL_ARG_15(__VA_ARGS__)

#define _ZF_BOX_UTIL_NARGS(...) \
	_ZF_BOX_UTIL_CONCAT_2(_ZF_BOX_UTIL_NARGS_CASE_, \
		_ZF_BOX_UTIL_IS_EMPTY(__VA_ARGS__)) \
	(__VA_ARGS__,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

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
