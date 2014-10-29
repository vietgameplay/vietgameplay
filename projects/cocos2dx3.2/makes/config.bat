@echo off

rem path need change on each PC or Laptop
set ANT_ROOT=C:\DevTools\apache-ant-1.8.2
set ANDROID_SDK_ROOT=C:\DevTools\android-sdk-windows
set NDK_ROOT=C:\DevTools\android-ndk-r10c
set JAVA_HOME=C:\DevTools\jdk1.6.0

set TARGET_API_LEVEL=20

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


