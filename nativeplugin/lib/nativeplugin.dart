
import 'dart:async';

import 'package:flutter/services.dart';

class Nativeplugin {
  static const MethodChannel _channel =
      const MethodChannel('nativeplugin');

  static String message;

  static Future<String> get platformVersion async {
    final String version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }

  static Future<String> get something async {
    String something = await _channel.invokeMethod('getSomething', {'text': message});
    return something;
  }

  static void setMethodCallHandler(Future<dynamic> handler(MethodCall call)) {
    _channel.setMethodCallHandler(handler);
  }
}
