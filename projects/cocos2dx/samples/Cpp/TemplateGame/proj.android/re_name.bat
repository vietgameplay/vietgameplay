@echo off
call .\config.bat
copy /y %OUTPUT_PATH%\vietgameplay-release-unsigned.apk %OUTPUT_PATH%\%GAME_NAME%.apk

