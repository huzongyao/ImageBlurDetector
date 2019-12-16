package com.hzy.blur.detector;

import android.graphics.Bitmap;

public class DetectorApi {

    public static native String getVersionString();

    public static native double detectFromPath(String imgPath);

    public static native double detectFromBmp(Bitmap bmp);

    static {
        System.loadLibrary("blurdetector");
    }
}
