
import 'dart:async';

import 'package:flutter/services.dart';

class TransmitTestPlugin {
  static const MethodChannel _channel =
      const MethodChannel('transmit_test_plugin');

  static Future<void> initializeTransmitSDK() async {
    return _channel.invokeMethod("init", {});
  }
}
