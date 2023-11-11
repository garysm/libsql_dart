import 'dart:ffi';

import 'package:libsql_dart/src/bridge_generated.dart';

typedef ExternalLibrary = DynamicLibrary;

LibSQL createWrapperImpl(ExternalLibrary dylib) => LibSQLImpl(dylib);
