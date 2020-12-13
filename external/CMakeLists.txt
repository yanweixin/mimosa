project(libexternal C)

set(CMAKE_C_STANDARD 11)

set(DATA_LIB data)
set(EXT_UTILS_LIB wrapper)

file(GLOB HEADERS_DATA data/redis.h data/mysql.h)
set(SOURCES_DATA data/redis.c data/mysql.c)
file(GLOB HEADERS_EXT_UTILS codec.h http_curl.h http_socket.h)
set(SOURCES_EXT_UTILS codec.c http_curl.c http_socket.c)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

if (BUILD_SHARED_LIBS)
    message(STATUS "Build shared libraries: ${DATA_LIB} ${EXT_UTILS_LIB}")
    set(LIBRARY_TYPE SHARED)
else ()
    message(STATUS "Build static libraries: ${DATA_LIB} ${EXT_UTILS_LIB}")
    set(LIBRARY_TYPE STATIC)
endif ()

message("external---${PROJECT_SOURCE_DIR}")

find_package(cJSON REQUIRED)

add_library("${DATA_LIB}" "${LIBRARY_TYPE}" "${HEADERS_DATA}" "${SOURCES_DATA}")
add_library("${EXT_UTILS_LIB}" "${LIBRARY_TYPE}" "${HEADERS_EXT_UTILS}" "${SOURCES_EXT_UTILS}")