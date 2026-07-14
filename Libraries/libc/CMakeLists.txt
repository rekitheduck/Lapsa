project(c LANGUAGES CXX)

target_compile_options(c PRIVATE -ffreestanding)

add_library(c STATIC
  "${CMAKE_CURRENT_SOURCE_DIR}/stdio.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/unistd.cpp"
)
