project(business C)

set(CMAKE_C_STANDARD 11)

set(BUSINESS_LIB business)

file(GLOB HEADERS_BUSINESS model.h)
set(SOURCES_BUSINESS model.c)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
if (BUILD_SHARED_LIBS)
    set(LIBRARY_TYPE SHARED)
else ()
    set(LIBRARY_TYPE STATIC)
endif ()

message("business---${PROJECT_SOURCE_DIR}")

add_library("${BUSINESS_LIB}" "${LIBRARY_TYPE}" "${HEADERS_BUSINESS}" "${SOURCES_BUSINESS}")
