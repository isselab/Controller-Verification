# Install script for directory: /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/objects/satellite_attitude_objects" TYPE FILE FILES
    "mnt/c/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.o"
    "rt_nonfinite.cpp.o"
    "satellite_attitude.cpp.o"
    "Observer.cpp.o"
    "ConcreteObserverStates.cpp.o"
    FILES_FROM_DIR "/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/satellite_attitude_objects.dir/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/satellite_attitude")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./satellite_attitude" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./satellite_attitude")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./satellite_attitude")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/export" TYPE FILE FILES "/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/satellite_attitude.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/export/satellite_attitudeTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/export/satellite_attitudeTargets.cmake"
         "/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/Export/b81305ddd76f0d27c0d1ff37b5cb307f/satellite_attitudeTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/export/satellite_attitudeTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/export/satellite_attitudeTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/export" TYPE FILE FILES "/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/Export/b81305ddd76f0d27c0d1ff37b5cb307f/satellite_attitudeTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/satellite_attitude_grt_rtw/export" TYPE FILE FILES "/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/CMakeFiles/Export/b81305ddd76f0d27c0d1ff37b5cb307f/satellite_attitudeTargets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
