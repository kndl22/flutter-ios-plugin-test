#import "TransmitTestPlugin.h"
#if __has_include(<transmit_test_plugin/transmit_test_plugin-Swift.h>)
#import <transmit_test_plugin/transmit_test_plugin-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "transmit_test_plugin-Swift.h"
#endif

@implementation TransmitTestPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftTransmitTestPlugin registerWithRegistrar:registrar];
}
@end
