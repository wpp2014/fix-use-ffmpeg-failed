## build ffmpeg

```shell
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
vcpkg install ffmpeg[bzip2,drawtext,freetype,lzma,nvcodec,opencl,opengl,openh264,vpx,webp,x264,x265,zlib,iconv] --triplet=x64-windows-static
```

## build test

```shell
git clone https://github.com/wpp2014/fix-use-ffmpeg-failed.git
cd fix-use-ffmpeg-failed
md build
set CMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake
cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DVCPKG_TARGET_TRIPLET=x64-windows-static
cmake --build build --config Debug
```

`cmake -S . -B build -G "Visual Studio 17 2022" -A x64 -DVCPKG_TARGET_TRIPLET=x64-windows-static`
will report an error because bug:

```
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.26100.
-- The C compiler identification is MSVC 19.42.34436.0
-- The CXX compiler identification is MSVC 19.42.34436.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Enterprise/VC/Tools/MSVC/14.42.34433/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Enterprise/VC/Tools/MSVC/14.42.34433/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMake Error at C:/Self/vcpkg/installed/x64-windows-static/share/ffmpeg/FindFFMPEG.cmake:73 (find_library):
  Could not find FFMPEG_DEPENDENCY_cfgmgr32_RELEASE using the following
  names: cfgmgr32
Call Stack (most recent call first):
  C:/Self/vcpkg/installed/x64-windows-static/share/ffmpeg/FindFFMPEG.cmake:147 (append_dependencies)
  C:/Self/vcpkg/installed/x64-windows-static/share/ffmpeg/vcpkg-cmake-wrapper.cmake:27 (_find_package)
  C:/Self/vcpkg/scripts/buildsystems/vcpkg.cmake:813 (include)
  CMakeLists.txt:10 (find_package)


-- Configuring incomplete, errors occurred!
```

If apply fix-use-ffmpeg-failed.patch, the error can be resolved.
