package com.example.nativeplugin;

import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Future;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;
import io.flutter.plugin.common.PluginRegistry.Registrar;

import static android.content.ContentValues.TAG;


/** NativepluginPlugin */
public class NativepluginPlugin implements FlutterPlugin, MethodCallHandler {
  /// The MethodChannel that will the communication between Flutter and native Android
  ///
  /// This local reference serves to register the plugin with the Flutter Engine and unregister it
  /// when the Flutter Engine is detached from the Activity
  private MethodChannel channel;
  private static int count =0;
  // This is the class where I load
  private NativeLibrary nativeLibrary;

  @Override
  public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
    channel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), "nativeplugin");
    channel.setMethodCallHandler(this);

    nativeLibrary = new NativeLibrary();


    //channel.invokeMethod("callback", "This is a callback to android"+count++);

  }

  @Override
  public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
    if (call.method.equals("getSomething")){
      String text = call.argument("text");
      Log.d(TAG, "onMethodCall: "+text);
      String stringFromJNI = nativeLibrary.stringFromJNI(text);
      result.success(stringFromJNI);
    }
    else if (call.method.equals("getPlatformVersion")) {
      result.success("Android " + android.os.Build.VERSION.RELEASE);
    } else {
      result.notImplemented();
    }
  }

  @Override
  public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
    channel.setMethodCallHandler(null);
  }
}
