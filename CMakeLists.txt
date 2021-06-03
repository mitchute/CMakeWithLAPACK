cmake_minimum_required(VERSION 3.16)
project(FakeEPlusWithLAPACK)

set(CMAKE_CXX_STANDARD 17)

find_package(LAPACK)
find_package(BLAS)

message("LAPACK Libraries: ${LAPACK_LIBRARIES}")
message("BLAS Libraries: ${BLAS_LIBRARIES}")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message("Running on Mac")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("Running on Linux")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message("Running on Windows")
endif ()

# Build C++ application
add_executable(FakeEPlusWithLAPACK cpp/main.cpp)

target_link_libraries(FakeEPlusWithLAPACK ${LAPACK_LIBRARIES})
target_link_libraries(FakeEPlusWithLAPACK ${BLAS_LIBRARIES})

# Packaging of C++ application
# option(BUILD_PACKAGE "Build package" OFF)
set(CPACK_PACKAGE_NAME "FakeEPlusWithLAPACK")
set(CPACK_PACKAGE_VENDOR "MyComp")
set(CPACK_VERBATIM_VARIABLES true)
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 1)
set(CPACK_PACKAGE_VERSION_PATCH 0)
include(CPack)
install(TARGETS FakeEPlusWithLAPACK)
