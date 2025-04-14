#include <jni.h>
#include <string>
#include <unistd.h>

extern "C" JNIEXPORT jint JNICALL
Java_check_env_MainActivity_isPathReallyExist(JNIEnv *env, jobject, jstring path) {
    // Convert the Java string to a C-style string
    const char *cpath = env->GetStringUTFChars(path, nullptr);
    if (cpath == nullptr) {
        return -1; // Return error if the conversion fails
    }

    // Check if the path exists using access
    int result = access(cpath, F_OK);

    // Release the memory allocated for the C-style string
    env->ReleaseStringUTFChars(path, cpath);

    return result; // Return 0 if the path exists, -1 otherwise
}