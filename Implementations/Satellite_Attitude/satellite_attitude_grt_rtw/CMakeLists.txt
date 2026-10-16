###########################################################################
# CMakeLists.txt generated for component satellite_attitude
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(satellite_attitude)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


# Set directory properties.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT satellite_attitude)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR .. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT "/mnt/c/Program Files/MATLAB/R2024b" CACHE PATH "")

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# When a CMakeLists.txt defines multiple targets that have a common set of 
# tool flags and preprocessor definitions, define variables containing 
# data that is common to all targets defined in the file.
set(SATELLITE_ATTITUDE_COMMON_DEFINES -DMODEL=satellite_attitude
    -DNUMST=1
    -DNCSTATES=7
    -DHAVESTDIO
    -DRT
    -DUSE_RTMODEL
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DMAT_FILE=1
    -DONESTEPFCN=1
    -DTERMFCN=1
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0)

# Definition of target "satellite_attitude_objects".
add_library(satellite_attitude_objects OBJECT "/mnt/c/Program Files/MATLAB/R2024b/rtw/c/src/rt_logging.c"
    ${START_DIR}/satellite_attitude_grt_rtw/rt_nonfinite.cpp
    ${START_DIR}/satellite_attitude_grt_rtw/satellite_attitude.cpp
    ${START_DIR}/satellite_attitude_grt_rtw/Observer.cpp
    ${START_DIR}/satellite_attitude_grt_rtw/ConcreteObserverStates.cpp)

# Set properties for target "satellite_attitude_objects".
set_target_properties(satellite_attitude_objects PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON)

# Specify language features required for target 
# "satellite_attitude_objects".
target_compile_features(satellite_attitude_objects PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target 
# "satellite_attitude_objects".
target_compile_definitions(satellite_attitude_objects PRIVATE ${SATELLITE_ATTITUDE_COMMON_DEFINES})

# Specify include directories for target "satellite_attitude_objects".
target_include_directories(satellite_attitude_objects PUBLIC $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${START_DIR}/satellite_attitude_grt_rtw>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/satellite_attitude_grt_rtw>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/simulink/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src/ext_mode/common>)

# Specify library link dependencies for target 
# "satellite_attitude_objects". CMake generator expressions are used to 
# create a CMakeLists.txt file that supports multiple platforms with 
# differently named system library dependencies.
target_link_libraries(satellite_attitude_objects PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)


# Definition of target "satellite_attitude". ${MATLAB_ROOT}/rtw/c/src/common/rt_cppclass_main.cpp
add_executable(satellite_attitude  /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude/satellite_attitude_grt_rtw/main.cpp)

# Set properties for target "satellite_attitude".
set_target_properties(satellite_attitude PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH_USE_LINK_PATH TRUE)

# Specify language features required for target "satellite_attitude".
target_compile_features(satellite_attitude PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target 
# "satellite_attitude".
target_compile_definitions(satellite_attitude PRIVATE ${SATELLITE_ATTITUDE_COMMON_DEFINES})

# Specify library link dependencies for target "satellite_attitude". CMake 
# generator expressions are used to create a CMakeLists.txt file that 
# supports multiple platforms with differently named system library 
# dependencies.
target_link_libraries(satellite_attitude PRIVATE satellite_attitude_objects
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:satellite_attitude>;--flat,"
                "true"
        >)
    add_custom_command(TARGET satellite_attitude
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS satellite_attitude.dwarf)
endif()


###########################################################################
## Target install rules
###########################################################################

# Install rule for objects of target "satellite_attitude_objects" to allow 
# support for SIL/PIL.
install(TARGETS satellite_attitude_objects
    EXPORT satellite_attitudeTargets
    OBJECTS DESTINATION "satellite_attitude_grt_rtw")

# Install rule for executable target "satellite_attitude". The "OPTIONAL" 
# keyword is required to support SIL/PIL when build of the final 
# executable is suppressed.
install(TARGETS satellite_attitude
    RUNTIME DESTINATION "."
    OPTIONAL)

# Install rule for Microsoft PDB debug symbols, if required.
if(CMAKE_C_LINKER_SUPPORTS_PDB)
    install(FILES $<TARGET_PDB_FILE:satellite_attitude>
        DESTINATION .
        OPTIONAL
        CONFIGURATIONS Debug RelWithDebInfo)
endif()

# Install rule for Apple DWARF debug symbols, if required.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    install(FILES $<TARGET_FILE_DIR:satellite_attitude>/satellite_attitude.dwarf
        DESTINATION .
        OPTIONAL
        CONFIGURATIONS Debug RelWithDebInfo)
endif()

# Write a rule that generates a wrapper around exported targets to 
# preserve tokenization of "special" directories (e.g., MATLAB_ROOT). This 
# avoids hard-coding absolute paths in the CMake file with the code used 
# to import the targets, and avoids errors when include paths that do not 
# exist in the current filesystem are defined, for example, after 
# relocating code using PackNGo.
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/satellite_attitude.cmake" [=[include("${CMAKE_CURRENT_LIST_DIR}/satellite_attitudeTargets.cmake")]=] \n)
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/satellite_attitude.cmake" [=[set(SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS_ALL]=] \n
    [=[    ${MATLAB_ROOT}/extern/include]=] \n
    [=[    ${MATLAB_ROOT}/simulink/include]=] \n
    [=[    ${MATLAB_ROOT}/rtw/c/src]=] \n
    [=[    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common)]=] \n
    [=[foreach(TOKDIR_LOOP IN LISTS SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS_ALL)]=] \n
    [=[    if(IS_DIRECTORY ${TOKDIR_LOOP})]=] \n
    [=[        list(APPEND SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS ${TOKDIR_LOOP})]=] \n
    [=[    endif()]=] \n
    [=[endforeach()]=] \n
    [=[target_include_directories(satellite_attitude::satellite_attitude_objects INTERFACE ${SATELLITE_ATTITUDE_OBJECTS_TOK_INC_DIRS})]=] \n)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/satellite_attitude.cmake"
    DESTINATION "satellite_attitude_grt_rtw/export")

# Generate and install a file that allows the targets generated from this 
# CMakeLists.txt file to be imported into another project.
install(EXPORT satellite_attitudeTargets NAMESPACE satellite_attitude:: DESTINATION satellite_attitude_grt_rtw/export)

###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET satellite_attitude POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:satellite_attitude>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(satellite_attitude)
endif()
