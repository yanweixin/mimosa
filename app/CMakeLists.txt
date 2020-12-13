project(app C)

set(CMAKE_C_STANDARD 11)

message("app---${PROJECT_SOURCE_DIR}")

add_library(app
        main.h main.c)

# let the preprocessor know about the system name
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(app PUBLIC "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(app PUBLIC "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(app PUBLIC "IS_WINDOWS")
endif()