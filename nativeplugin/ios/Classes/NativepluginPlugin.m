#import "NativepluginPlugin.h"
#if __has_include(<nativeplugin/nativeplugin-Swift.h>)
#import <nativeplugin/nativeplugin-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "nativeplugin-Swift.h"
#endif

@implementation NativepluginPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftNativepluginPlugin registerWithRegistrar:registrar];
}
@end
