LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := vietgameplay_shared

LOCAL_MODULE_FILENAME := libvietgameplay

LOCAL_SRC_FILES := vietgameplay/main.cpp \
                   ../../Classes/VGPLib/VGPArmature.cpp \
                   ../../Classes/VGPLib/VGPLabel.cpp \
                   ../../Classes/VGPLib/VGPLib.cpp \
                   ../../Classes/VGPLib/VGPProgressTimer.cpp \
                   ../../Classes/VGPLib/VGPSprite.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Bubble.cpp \
                   ../../Classes/Bullet.cpp \
                   ../../Classes/CommonObject.cpp \
                   ../../Classes/Defines.cpp \
                   ../../Classes/FileOperation.cpp \
                   ../../Classes/GameOverScene.cpp \
                   ../../Classes/GameState.cpp \
                   ../../Classes/InGameScene.cpp \
                   ../../Classes/LogoScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)

$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
