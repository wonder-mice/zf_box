cmake_minimum_required(VERSION 3.2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
if(NOT DEFINED CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")
endif()

project(zf_box)

set(INSTALL_INCLUDE_DIR include CACHE PATH
	"Installation directory for header files")
set(INSTALL_LIB_DIR lib CACHE PATH
	"Installation directory for libraries")
set(INSTALL_CMAKE_DIR lib/cmake/zf_queue CACHE PATH
	"Installation directory for CMake files")
option(ZF_BOX_CONFIGURE_IDE_SOURCES "Add zf_box sources to IDE project" ON)
option(ZF_BOX_CONFIGURE_INSTALL "Generate install target" ON)
option(ZF_BOX_EXAMPLES "Build examples" OFF)
option(ZF_BOX_TESTS "Build tests" OFF)

add_subdirectory(zf_box)

if(ZF_BOX_EXAMPLES)
	add_subdirectory(examples)
endif()
if(ZF_BOX_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()

if(ZF_BOX_CONFIGURE_INSTALL)
	export(EXPORT zf_box)
	install(EXPORT zf_box
		DESTINATION ${INSTALL_CMAKE_DIR})
	configure_file(zf_box-config.cmake.in zf_box-config.cmake @ONLY)
	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/zf_box-config.cmake
		DESTINATION ${INSTALL_CMAKE_DIR})
endif()
