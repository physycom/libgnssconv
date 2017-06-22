cmake_minimum_required (VERSION 3.1)
project (gnssconv)

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_USE_MATH_DEFINES)
endif()

include_directories(${CMAKE_SOURCE_DIR}/..)

add_executable (example "${CMAKE_SOURCE_DIR}/src/example")

install (TARGETS example DESTINATION ${CMAKE_SOURCE_DIR}/bin/)
