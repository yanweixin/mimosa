project(libmimosa VERSION 0.1)

set(CMAKE_C_STANDARD 11)

set(LOG_LIB log)
set(UTILS_LIB utils)

file(GLOB HEADERS_UTILS *.h)
file(GLOB SOURCES_UTILS *.c)

option(BUILD_SHARED_AND_STATIC_LIBS "Build both shared and static libraries" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

if ((BUILD_SHARED_AND_STATIC_LIBS) AND (BUILD_SHARED_LIBS))
    set(LIBRARY_TYPE SHARED)
else ()
    set(LIBRARY_TYPE STATIC)
endif ()

message("library---${PROJECT_SOURCE_DIR}")
add_library("${LOG_LIB}"
        log.h log.c)
add_library("${UTILS_LIB}" "${LIBRARY_TYPE}" "${HEADERS_UTILS}" "${SOURCES_UTILS}")