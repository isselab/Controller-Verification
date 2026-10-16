set CMAKE_EXPORT_COMPILE_COMMANDS=TRUE
set PATH=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\bin;C:\Program Files\MATLAB\R2024b/toolbox/shared/coder/ninja/win64;%PATH%
"C:\Program Files\MATLAB\R2024b\bin\win64\cmake\bin\cmake.exe" -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="C:\Program Files\MATLAB\R2024b/toolbox/coder/compile/cmake/windows_mingw_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release -DENABLE_SSE2=1 -DCMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1 -DCMAKE_INSTALL_PREFIX=".." --no-warn-unused-cli
@if errorlevel 1 (
    @echo The cmake command returned an error of %errorlevel% 1>&2
    @exit /B 1
)

"C:\Program Files\MATLAB\R2024b\bin\win64\cmake\bin\cmake.exe" --build build
@if errorlevel 1 (
    @echo The cmake command returned an error of %errorlevel% 1>&2
    @exit /B 1
)

"C:\Program Files\MATLAB\R2024b\bin\win64\cmake\bin\cmake.exe" --install build --prefix ..
@if errorlevel 1 (
    @echo The cmake command returned an error of %errorlevel% 1>&2
    @exit /B 1
)

