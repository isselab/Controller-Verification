#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "satellite_attitude::satellite_attitude_objects" for configuration "Release"
set_property(TARGET satellite_attitude::satellite_attitude_objects APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(satellite_attitude::satellite_attitude_objects PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_OBJECTS_RELEASE "${_IMPORT_PREFIX}/satellite_attitude_grt_rtw/objects-Release/satellite_attitude_objects/C_/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.obj;${_IMPORT_PREFIX}/satellite_attitude_grt_rtw/objects-Release/satellite_attitude_objects/rt_nonfinite.cpp.obj;${_IMPORT_PREFIX}/satellite_attitude_grt_rtw/objects-Release/satellite_attitude_objects/satellite_attitude.cpp.obj"
  )

list(APPEND _cmake_import_check_targets satellite_attitude::satellite_attitude_objects )
list(APPEND _cmake_import_check_files_for_satellite_attitude::satellite_attitude_objects "${_IMPORT_PREFIX}/satellite_attitude_grt_rtw/objects-Release/satellite_attitude_objects/C_/Program_Files/MATLAB/R2024b/rtw/c/src/rt_logging.c.obj;${_IMPORT_PREFIX}/satellite_attitude_grt_rtw/objects-Release/satellite_attitude_objects/rt_nonfinite.cpp.obj;${_IMPORT_PREFIX}/satellite_attitude_grt_rtw/objects-Release/satellite_attitude_objects/satellite_attitude.cpp.obj" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
