cmake_minimum_required(VERSION 3.2)

# zf_box target (required)
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_library(zf_box INTERFACE)
target_include_directories(zf_box INTERFACE $<BUILD_INTERFACE:${HEADERS_DIR}>)

# install (optional)
if(ZF_BOX_CONFIGURE_INSTALL)
	if(NOT DEFINED INSTALL_INCLUDE_DIR)
		set(INSTALL_INCLUDE_DIR include)
	endif()
	if(NOT DEFINED INSTALL_LIB_DIR)
		set(INSTALL_LIB_DIR lib)
	endif()
	install(TARGETS zf_box EXPORT zf_box
		INCLUDES DESTINATION ${INSTALL_INCLUDE_DIR}
		ARCHIVE DESTINATION ${INSTALL_LIB_DIR})
	install(DIRECTORY ${HEADERS_DIR}/
		DESTINATION ${INSTALL_INCLUDE_DIR}
		FILES_MATCHING PATTERN "zf_*.h*")
endif()

# dummy target to add headers to IDE project (optional)
if(ZF_BOX_CONFIGURE_IDE_SOURCES)
	set(HEADERS zf_box.h)
	add_custom_target(zf_box_sources SOURCES ${HEADERS})
endif()
