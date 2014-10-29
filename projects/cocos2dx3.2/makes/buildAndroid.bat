@echo off

cls

call %~dp0config.bat

REM cocos new %PROJECT_FOLDER_NAME% -p %PACKAGE_NAME% -l cpp -d %PROJECT_ROOT_PATH%
cocos compile -s %PROJECT_ROOT_PATH%/%PROJECT_FOLDER_NAME% -p android --ap %TARGET_API_LEVEL%

cd %MAKE_PATH%