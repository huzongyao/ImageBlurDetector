package com.hzy.blur.detect.demo;

import android.app.Application;

import com.blankj.utilcode.util.Utils;

public class MainApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        Utils.init(this);
    }
}
