project(c LANGUAGES CXX)


add_library(c STATIC
  "${CMAKE_CURRENT_SOURCE_DIR}/stdio.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/unistd.cpp"
)
