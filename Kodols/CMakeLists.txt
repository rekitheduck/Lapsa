project(kodols LANGUAGES CXX)

set(SOURCES
    Arch/i386/boot.s
    Arch/i386/GDT.cpp
    Arch/i386/IDT.cpp
    Arch/i386/ISRHandlers.cpp
    Arch/i386/Main.cpp
    Devices/Serial.cpp
    KSerde/KString.cpp
    Dmesg.cpp
)

set_source_files_properties(Arch/i386/ISRHandlers.cpp PROPERTIES COMPILE_FLAGS -mgeneral-regs-only)

set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/Arch/i386/linker.ld")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LINKER_SCRIPT}")

add_compile_options(-ffreestanding)
add_link_options(-nostdlib)

add_executable(kodols ${SOURCES})
# TODO: Make sure linker.ld is tracked by cmake
# set_target_properties(kodols PROPERTIES LINK_DEPENDS ${LINKER_SCRIPT})
target_include_directories(kodols PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(kodols PRIVATE gcc)
