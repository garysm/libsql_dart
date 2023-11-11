import 'package:libsql_dart/src/bridge_generated.dart';
import 'package:flutter_rust_bridge/flutter_rust_bridge.dart';

typedef ExternalLibrary = WasmModule;

LibSQL createWrapperImpl(ExternalLibrary module) => LibSQLImpl.wasm(module);
