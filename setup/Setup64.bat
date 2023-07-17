@echo off

REM Check if the script is run with administrative privileges
NET SESSION >NUL 2>&1
IF %ERRORLEVEL% NEQ 0 (
    echo This script requires administrative privileges to setup.
    echo Please run the script as an administrator.
    pause
    exit /b 1
)

REM Copy the file "../dist/cavg.exe" to a directory in PATH (e.g., C:\Windows\System32)
xcopy "dist\cavg\ \(64-bit\).exe" "C:\Windows\System32\" /Y

REM Add the file to the PATH environment variable
setx PATH "%PATH%;C:\Windows\System32"

echo CAVG has been set up.
echo You can now run 'cavg' from the terminal.
pause