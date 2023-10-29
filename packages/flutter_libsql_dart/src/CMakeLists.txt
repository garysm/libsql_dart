# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(flutter_libsql_dart_library VERSION 0.0.1 LANGUAGES C)

add_library(flutter_libsql_dart SHARED
  "flutter_libsql_dart.c"
)

set_target_properties(flutter_libsql_dart PROPERTIES
  PUBLIC_HEADER flutter_libsql_dart.h
  OUTPUT_NAME "flutter_libsql_dart"
)

target_compile_definitions(flutter_libsql_dart PUBLIC DART_SHARED_LIB)
