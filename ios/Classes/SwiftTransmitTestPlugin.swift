import Flutter
import UIKit
import TransmitSDK3
import TransmitSDKUILayer

public class SwiftTransmitTestPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "transmit_test_plugin", binaryMessenger: registrar.messenger())
    let instance = SwiftTransmitTestPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    if (call.method == "init") {
        let sdk = TSXTransmitSDKXm.sharedInstance()
        let realm = ""
        let settings = TSXSDKConnectionSettings.create(withServerAddress: "", appId: "", tokenName: "", token: "")
        
        settings.realm = realm
        sdk.setConnectionSettings(settings)
        let transportProvider = TSXHTTPTransportProvider()
        transportProvider.timeoutInterval = 30
        sdk.setTransportProvider(transportProvider)
        sdk.initializeAsynchronously { (success, error) in
            if let error = error {
                NSLog("Transmit SDK init failed: \(error.description)")
                result(
                    FlutterError(
                        code: "1",
                        message: "error",
                        details: "error"
                    )
                )
            } else {
                result(1)
            }
        }
    }
  }
}
