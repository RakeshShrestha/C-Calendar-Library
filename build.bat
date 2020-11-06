set WINDOWS_SDK=C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0

@echo Generate C++/WinRT header files
cppwinrt.exe @cppwinrt_plat.rsp

@echo Create output folder
if not exist build mkdir build

@echo Compile with Clang >= 11.0.0
clang -v

@echo Create binary
clang -I "cppwinrt" -D_WINDOWS -DUNICODE -D_UNICODE main.cpp -Xclang -std=c++17 -Xclang -Wno-delete-non-virtual-dtor -fcoroutines-ts -o build\mysample.exe -L "%WINDOWS_SDK%\um\x64" -Wl,kernel32.lib,user32.lib,windowsapp.lib

@echo Embed manifest
:: https://docs.microsoft.com/en-us/cpp/build/how-to-embed-a-manifest-inside-a-c-cpp-application?view=vs-2019
"C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x64\mt.exe" -manifest cppwinrt.manifest -outputresource:build\mysample.exe;1