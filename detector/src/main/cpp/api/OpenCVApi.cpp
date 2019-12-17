//
// Created by huzongyao on 2019/9/6.
//

#include "OpenCVApi.h"
#include <android/bitmap.h>
#include "DetectUtils.h"

#if DETECT_FILE

#include <opencv2/imgcodecs.hpp>

#endif

using namespace cv;

JNIEXPORT jstring JNICALL
JNI_FUNC(getVersionString)(JNIEnv *env, jclass type) {
    return env->NewStringUTF(CV_VERSION);
}

JNIEXPORT jdouble JNICALL
JNI_FUNC(detectFromBmp)(JNIEnv *env, jclass type, jobject bmp) {
    AndroidBitmapInfo info;
    double level = 0;
    try {
        if (AndroidBitmap_getInfo(env, bmp, &info) >= 0 &&
            info.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
            void *pixels = nullptr;
            if (AndroidBitmap_lockPixels(env, bmp, &pixels) >= 0) {
                auto image = Mat(info.height, info.width, CV_8UC4, pixels);
                Mat gray;
                cvtColor(image, gray, COLOR_RGBA2GRAY);
                AndroidBitmap_unlockPixels(env, bmp);
                level = DetectUtils::detectBlur(gray);
            }
        }
    } catch (...) {
    }
    return level;
}

JNIEXPORT jdouble JNICALL
JNI_FUNC(detectFromPath)(JNIEnv *env, jclass type, jstring imgPath_) {
    const char *imgPath = env->GetStringUTFChars(imgPath_, nullptr);
    double level = 0;
    try {
#if DETECT_FILE
        auto gray = imread(imgPath, IMREAD_GRAYSCALE);
        level = DetectUtils::detectBlur(gray);
#endif
        env->ReleaseStringUTFChars(imgPath_, imgPath);
    } catch (...) {
    }
    return level;
}