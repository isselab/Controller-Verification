# Install script for directory: /mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/objects/UAV_objects" TYPE FILE FILES
    "mnt/c/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.o"
    "UAV.cpp.o"
    "UAV_data.cpp.o"
    "rt_nonfinite.cpp.o"
    "Observer.cpp.o"
    "ConcreteObserverStates.cpp.o"
    FILES_FROM_DIR "/mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw/CMakeFiles/UAV_objects.dir/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE OPTIONAL FILES "/mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw/UAV")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./UAV" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./UAV")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./UAV")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export" TYPE FILE FILES "/mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw/UAV.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets.cmake"
         "/mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw/CMakeFiles/Export/b4ade2d1b88064d160a7a3998ad23128/UAVTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export/UAVTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export" TYPE FILE FILES "/mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw/CMakeFiles/Export/b4ade2d1b88064d160a7a3998ad23128/UAVTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/UAV_grt_rtw/export" TYPE FILE FILES "/mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw/CMakeFiles/Export/b4ade2d1b88064d160a7a3998ad23128/UAVTargets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/c/users/soure/Desktop/Uni Sachen/CT-Verification/Implementations/UAV/UAV_grt_rtw/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
