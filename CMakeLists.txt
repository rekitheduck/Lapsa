cmake_minimum_required(VERSION 3.14)

project(Lapsa
  DESCRIPTION "Lapsa Operating System"
  LANGUAGES NONE
)

# Lapsa toolchain
set(CMAKE_SYSTEM_NAME Lapsa)
set(CMAKE_SYSROOT ${CMAKE_BINARY_DIR}/i386/systemroot)
set(CMAKE_C_COMPILER ${CMAKE_SOURCE_DIR}/meta/toolchain/bin/i586-elf-lapsa-gcc)
set(CMAKE_CXX_COMPILER  ${CMAKE_SOURCE_DIR}/meta/toolchain/bin/i586-elf-lapsa-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

add_subdirectory(libraries)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Release cxx: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "Debug cxx: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS " ")

if(BUILD_TYPE STREQUAL "release")
  message(STATUS "Complete cxx: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
  message(STATUS "Complete ld: ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
else()
  message(STATUS "Complete cxx: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
  message(STATUS "Complete ld: ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
endif()
