//
// Created by Administrator on 2019/9/6.
//

#ifndef OPENCVSTUDY_OPENCVAPI_H
#define OPENCVSTUDY_OPENCVAPI_H

#include <jni.h>

#define JNI_FUNC(x) Java_com_hzy_blur_detector_DetectorApi_##x

#ifdef __cplusplus
extern "C" {
#endif

#define DETECT_FILE 1

#ifdef NDEBUG
#define LOGD(...) do{}while(0)
#define LOGI(...) do{}while(0)
#define LOGW(...) do{}while(0)
#define LOGE(...) do{}while(0)
#define LOGF(...) do{}while(0)
#else
#define LOG_TAG "NATIVE.LOG"

#include <android/log.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG,__VA_ARGS__)
#endif

JNIEXPORT jstring JNICALL
JNI_FUNC(getVersionString)(JNIEnv *env, jclass type);

JNIEXPORT jdouble JNICALL
JNI_FUNC(detectFromPath)(JNIEnv *env, jclass type, jstring imgPath_);

JNIEXPORT jdouble JNICALL
JNI_FUNC(detectFromBmp)(JNIEnv *env, jclass type, jobject bmp);

#ifdef __cplusplus
}
#endif

#endif //OPENCVSTUDY_OPENCVAPI_H
