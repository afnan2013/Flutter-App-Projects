#include <jni.h>
#include <string>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet//in.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_nativeplugin_NativeLibrary_sendRequestToServer(JNIEnv *env, jobject thiz, jint portNumber) {

    jint port = 4499;
    int sockfd;
    char buffer[1024];

    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    socklen_t addr_size;

    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(port);
    servaddr.sin_family = AF_INET;

    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0){
        std::string error = "Socket Creation Failed";
        std::cout << error << std::endl;
        return env->NewStringUTF(error.c_str());
    }
    fgets(buffer, 1024, stdin);

    int sd = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    std::string hello = "Yup.... I have linked it";
    if(sd < 0){
        hello = "Cannot send the data to the server";
        std::cout << hello << std::endl;
    }else{
        hello = "Data received successfully : ";
        std::cout << hello << std::endl;
    }

    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_nativeplugin_NativeLibrary_stringFromJNI(JNIEnv *env, jobject thiz, jstring text) {

    jint port = 4499;
    int sockfd;
    char buffer[1024];
    //char buffer[12] = {'H', 'E', 'L', 'L', 'O', 's', 'd', 'd', 'd', 'd', 'd', 's'};
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    socklen_t addr_size;

    servaddr.sin_addr.s_addr = inet_addr("157.230.41.161");
    servaddr.sin_port = htons(port);
    servaddr.sin_family = AF_INET;

    if((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0){
        std::string error = "Socket Creation Failed";
        std::cout << error << std::endl;
        return env->NewStringUTF(error.c_str());
    }
    //fgets(buffer, 1024, stdin);
    const char *message = env->GetStringUTFChars(text, NULL);
    int size = strlen(message);
    int sd = sendto(sockfd, message, size, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    env->ReleaseStringUTFChars(text, message);

    std::string hello;
    if(sd < 0){
        hello = "Cannot send the data to the server";
        std::cout << hello << std::endl;
    }else{
        hello = "Data Send successfully : ";
        std::cout << hello << std::endl;
    }

    addr_size = sizeof(servaddr);
    bzero(&buffer, sizeof(buffer));
    int rc = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&servaddr, &addr_size);
    buffer[rc] = NULL;
    if(rc < 0){
        std::cout << "[-]Can't receive data from the server" <<std::endl;
    }else{
        std::cout << buffer<<std::endl;
    }
    close(sockfd);

    return env->NewStringUTF(buffer);
    //std::string message="Yup.... I have linked it";
    //return env->NewStringUTF(message.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_nativeplugin_NativeLibrary_passingDataToJni(JNIEnv *env, jobject thiz,
                                    jdoubleArray tmp_array,
                                        jint tmp_int, jfloat tmp_float) {
    jdouble *tmpArray = env->GetDoubleArrayElements(tmp_array,NULL);

    int ret =1;
    ret = (tmpArray[0]==1 && tmpArray[1] == 2 && tmpArray[2]== 3)? 0: -1;

    env->ReleaseDoubleArrayElements(tmp_array, tmpArray, 0);
    return ret;
}
/*
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_nativeplugin_NativeLibrary_passObjectToJNI(JNIEnv *env, jobject thiz,
                                                                jobject sample_data_obj) {

    // Get jclass of the object
    jclass sampleDataOBJClass = env->GetObjectClass(sample_data_obj);

    // Get data field IDs of the object
    jfieldID sampIntField = env->GetFieldID(sampleDataOBJClass, "sampleInt", "I");
    jfieldID sampBoolField = env->GetFieldID(sampleDataOBJClass, "sampleBoolean", "Z");
    jfieldID sampStringField = env->GetFieldID(sampleDataOBJClass, "sampleString",
                                               "Ljava/lang/String;");

    // Get individual Data
    jint sampleInt = env->GetIntField(sample_data_obj, sampIntField);
    jboolean sampleBoolean = env->GetBooleanField(sample_data_obj, sampBoolField);

    // Update data
    const char *successString = "SUCCESS";
    env->SetObjectField(sample_data_obj, sampStringField, env->NewStringUTF(successString));

    // return error code (in this case, return the int value form the object)
    return sampleInt;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_nativeplugin_NativeLibrary_getObjectFromJNI(JNIEnv *env, jobject instance){
    // Create a jclass from actual Java object class path
    jclass sampleObjClass = env->FindClass(
            "com/example/nativeappexample/SampleDataObj");
    jmethodID methodId = env->GetMethodID(sampleObjClass, "<init>", "()V");
    jobject sampleObj = env->NewObject(sampleObjClass, methodId);

    //Update fields of object
    const char *successString = "Hi...I am an object";
    jfieldID sampStringField = env->GetFieldID(sampleObjClass, "sampleString",
                                               "Ljava/lang/String;");
    env->SetObjectField(sampleObj, sampStringField, env->NewStringUTF(successString));

    //Update int data field
    int data = 10;
    jfieldID sampIntField = env->GetFieldID(sampleObjClass, "sampleInt", "I");
    env->SetIntField(sampleObj, sampIntField, data);

    return sampleObj;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_nativeappexample_NativeLibrary_callTheCallBackMethod(JNIEnv *env, jobject instance) {
    // Get jclass of the instance
    jclass jClassInstance = env->GetObjectClass(instance);

    // Get java callback method
    jmethodID callBackJava = env->GetMethodID(jClassInstance, "callBack", "(ILjava/lang/String;)V");

    // If method not found
    if (NULL == callBackJava) return;

    // create string data to pass
    const char *successString = "SUCCESS     ";

    // integer value to pass
    int data = 10;

    // Call back Java method with parameters
    env->CallVoidMethod(instance, callBackJava, data, env->NewStringUTF(successString));
}

*/