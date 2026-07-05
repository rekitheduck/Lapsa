project(kodols LANGUAGES CXX)

set(SOURCES
    arch/i386/boot.s
    arch/i386/gdt.cpp
    arch/i386/main.cpp
)

set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/arch/i386/linker.ld")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LINKER_SCRIPT}")

add_compile_options(-ffreestanding)
add_link_options(-nostdlib)

add_executable(kodols ${SOURCES})
# TODO: Make sure linker.ld is tracked by cmake
# set_target_properties(kodols PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})

target_link_libraries(kodols PRIVATE gcc)
