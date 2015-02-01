@echo off
call .\config.bat

%ANDROID_HOME%\tools\zipalign.exe -v 4 %OUTPUT_PATH%\%GAME_NAME%.apk %OUTPUT_PATH%\%GAME_NAME%_ALIGN.apk