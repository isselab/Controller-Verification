include("${CMAKE_CURRENT_LIST_DIR}/satellite_attitudeTargets.cmake")
set(SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS_ALL
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common)
foreach(TOKDIR_LOOP IN LISTS SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS_ALL)
    if(IS_DIRECTORY ${TOKDIR_LOOP})
        list(APPEND SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS ${TOKDIR_LOOP})
    endif()
endforeach()
target_include_directories(satellite_attitude::satellite_attitude_objects INTERFACE ${SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS})
