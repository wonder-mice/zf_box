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

#endif
