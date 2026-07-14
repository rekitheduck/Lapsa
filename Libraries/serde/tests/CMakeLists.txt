project(serde_tests LANGUAGES CXX)

set(SOURCES
    TestScopePtr.cpp
)

add_executable(serde_tests ${SOURCES})
# TODO: Make sure linker.ld is tracked by cmake
# set_target_properties(kodols PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
target_include_directories(serde_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../)

