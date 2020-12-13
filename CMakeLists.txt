cmake_minimum_required(VERSION 3.17)
project(mimosa VERSION 0.0.1)

set(CMAKE_C_STANDARD 11)

enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(USE_LIB TRUE)

if (USE_LIB)
    add_subdirectory(library)
    list(APPEND EXTRA_LIBS log utils)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/library")
endif ()
if (USE_EXT)
    add_subdirectory(external)
    list(APPEND EXTRA_LIBS data wrapper)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/external")
endif ()
add_subdirectory(business)
add_subdirectory(app)
add_subdirectory(tests)

add_executable(mimosa app/main.c)

target_link_libraries(mimosa PUBLIC business ${EXTRA_LIBS})

target_include_directories(mimosa PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/business"
        ${EXTRA_INCLUDES}
        )