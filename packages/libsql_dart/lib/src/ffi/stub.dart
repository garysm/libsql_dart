import 'package:libsql_dart/src/bridge_generated.dart';

/// Represents the external library for $LIBNAME
///
/// Will be a DynamicLibrary for dart:io or WasmModule for dart:html
typedef ExternalLibrary = Object;

LibSQL createWrapperImpl(ExternalLibrary lib) => throw UnimplementedError();
