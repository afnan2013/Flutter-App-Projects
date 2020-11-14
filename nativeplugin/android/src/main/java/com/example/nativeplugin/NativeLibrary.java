package com.example.nativeplugin;

import java.util.concurrent.Future;

public class NativeLibrary {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI(String text);

    public native int passingDataToJni(double[] tmpArray, int tmpInt, float tmpFloat);

    //public native int passObjectToJNI(SampleDataObj sampleDataObj);

    //public native SampleDataObj getObjectFromJNI();
}
