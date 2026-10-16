#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "UAV::UAV_objects" for configuration "Release"
set_property(TARGET UAV::UAV_objects APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(UAV::UAV_objects PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_OBJECTS_RELEASE "${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/C_/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.obj;${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/UAV.cpp.obj;${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/UAV_data.cpp.obj;${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/rt_nonfinite.cpp.obj"
  )

list(APPEND _cmake_import_check_targets UAV::UAV_objects )
list(APPEND _cmake_import_check_files_for_UAV::UAV_objects "${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/C_/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.obj;${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/UAV.cpp.obj;${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/UAV_data.cpp.obj;${_IMPORT_PREFIX}/UAV_grt_rtw/objects-Release/UAV_objects/rt_nonfinite.cpp.obj" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
