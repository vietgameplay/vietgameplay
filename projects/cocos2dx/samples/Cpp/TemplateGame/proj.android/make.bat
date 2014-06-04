@echo off
call .\config.bat

rem build apk
call .\make_ant.bat

rem copy
call .\re_name.bat

rem sign
call .\sign.bat

echo ------------------------------Press to install--------------
call .\install.bat
