@echo off

rem path need change on each PC or Laptop
set ANT_ROOT=D:\DevTools\apache-ant-1.8.0
set ANDROID_SDK_ROOT=D:\DevTools\android-sdk-windows
set NDK_ROOT=D:\DevTools\android-ndk-r10c
set JAVA_HOME=D:\DevTools\jdk1.6.0

rem path for cocos
set PRJ_DIR=%~dp0..
set TOOL_PATH=%PRJ_DIR%\tools
set MAKE_PATH=%PRJ_DIR%\makes
set PROJECT_ROOT_PATH=%PRJ_DIR%\projects
set COCOS_CONSOLE_ROOT=%PRJ_DIR%\cocos2d-console\bin

rem config your project
set PROJECT_FOLDER_NAME=exampleCocos2dx
set PROJECT_FOLDER_PATH=%PROJECT_ROOT_PATH%\%PROJECT_FOLDER_NAME%
set PACKAGE_NAME=com.vietgameplay.%PROJECT_FOLDER_NAME%


