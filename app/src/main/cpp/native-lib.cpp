#include <jni.h>
#include <string>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

}

extern "C" JNIEXPORT jstring JNICALL
Java_tj_com_ffmpegtest2_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    return env->NewStringUTF(av_version_info());
}

extern "C" JNIEXPORT jint JNIIMPORT
Java_tj_com_ffmpegtest2_MainActivity_intOpenInput(
        JNIEnv *env,
        jobject /* this */,
        jstring url) {
    av_register_all();
    AVFormatContext *pFormatCtx = avformat_alloc_context() ;
    avformat_open_input(&pFormatCtx,  env->GetStringUTFChars(url, JNI_FALSE), NULL, NULL);
    return avformat_find_stream_info(pFormatCtx, NULL);
}