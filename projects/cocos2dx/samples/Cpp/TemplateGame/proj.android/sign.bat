@echo off
call config.bat

%JARSIGNER% -verbose -keystore %KEY_STORE%.keystore %OUTPUT_PATH%\%GAME_NAME%.apk %KEY_STORE%

%JARSIGNER% -verify -verbose -certs %OUTPUT_PATH%\%GAME_NAME%.apk > sign_log.txt
%JARSIGNER% -verify -verbose -certs %OUTPUT_PATH%\%GAME_NAME%.apk >> sign_log.txt