cmake_minimum_required(VERSION 3.28)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(CI-CD-HelloWorld VERSION ${PROJECT_VERSION})

if(MINGW)
    link_libraries(ws2_32 wsock32)
endif()

include(CTest)
enable_testing()

add_executable(CI-CD-HelloWorld main.cpp)
add_library(CI-CD-HelloWorld_lib lib.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties(CI-CD-HelloWorld PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(CI-CD-HelloWorld_lib
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(CI-CD-HelloWorld PRIVATE
CI-CD-HelloWorld_lib
)

if (MSVC)
    target_compile_options(CI-CD-HelloWorld PRIVATE
        /W4
    )
    target_compile_options(CI-CD-HelloWorld_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(CI-CD-HelloWorld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(CI-CD-HelloWorld_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

install(TARGETS CI-CD-HelloWorld RUNTIME DESTINATION bin)

enable_testing()

add_test(test_version test_version)