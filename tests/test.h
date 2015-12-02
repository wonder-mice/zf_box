#pragma once

#include <zf_box.h>

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

#define SMALL_DATA(FIELD, _) \
	FIELD(_, UINT32, "small.value", value) \
	FIELD(_, DOUBLE, "small.duration", duration)
ZF_BOX_CLASS_DECL(SMALL_DATA)

#define BIG_DATA(FIELD, _) \
	FIELD(_, INSTANCE(SMALL_DATA), "improved.value", array_i) \
	FIELD(_, ARRAY(INSTANCE(SMALL_DATA), 10), "improved.value", array) \
	FIELD(_, ARRAY(DOUBLE, 10), "improved.value", array_d) \
	FIELD(_, UINT32, "improved.value", value) \
	FIELD(_, DOUBLE, "improved.duration", duration) \
	FIELD(_, STRING, "improved.caption", caption) \
	FIELD(_, BYTES(38), "improved.data", data)
ZF_BOX_CLASS_DECL(BIG_DATA)
