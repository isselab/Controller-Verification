include("${CMAKE_CURRENT_LIST_DIR}/UAVTargets.cmake")
set(UAV_OBJECTS_TOK_INC_DIRS_ALL
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common)
foreach(TOKDIR_LOOP IN LISTS UAV_OBJECTS_TOK_INC_DIRS_ALL)
    if(IS_DIRECTORY ${TOKDIR_LOOP})
        list(APPEND UAV_OBJECTS_TOK_INC_DIRS ${TOKDIR_LOOP})
    endif()
endforeach()
target_include_directories(UAV::UAV_objects INTERFACE ${UAV_OBJECTS_TOK_INC_DIRS})
