@echo off

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio 12.0
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio 11.0
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio 10.0
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio 13.0
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio 14.0
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")

SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")

SET VC_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")

SET VC_PATH=C:\Program Files\Microsoft Visual Studio\2022\Professional
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")

SET VC_PATH=C:\Program Files\Microsoft Visual Studio\18\Community
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")

SET VC_PATH=C:\Program Files\Microsoft Visual Studio\18\Professional
IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvars64.bat")
