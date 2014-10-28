@echo off

cls

call %~dp0config.bat

cocos new %PROJECT_FOLDER_NAME% -p %PACKAGE_NAME% -l cpp -d %PROJECT_ROOT_PATH%

cd %MAKE_PATH%