# Fehlende Dateien auskommentiert

###########################################################################
## Makefile generated for component 'satellite_attitude'. 
## 
## Makefile     : satellite_attitude.mk
## Generated on : Mon Apr 26 19:25:52 2021
## Modified on  : Tue June 28 11:51:32 2023 (Nils)
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/satellite_attitude
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = satellite_attitude
MAKEFILE                  = satellite_attitude.mk
##START_DIR                 = "/absolute-path/to/repo"
## For Linux VM on my WIN10 PC 
START_DIR				  = /mnt/c/Users/sebas/Dokumenty/GitHub/CT-Verification/Implementations/Satellite_Attitude
MATLAB_ROOT               = /mnt/c/Program\ Files/MATLAB/R2024b
#MATLAB_ROOT               = /usr/local/MATLAB/R2024b
MATLAB_BIN                = $(MATLAB_ROOT)/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = ISO_C++
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
##DIVINE_PATH				  = "/absolute-path/to/divine"
## For Linux VM on WIN10 PC
DIVINE_PATH 			  = /mnt/c/Users/sebas/divine-4.4.2
DIVINE_LIBS_PATH		  = $(DIVINE_PATH)/_build.release/divine
DIVINE_EXC 			  	  = $(DIVINE_PATH)/_build.release/tools/divine

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# DIVINE Compiler: C/C++ Compiler
DCC = $(DIVINE_EXC) cc

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"

#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------
# "Debug" Build Configuration
#--------------------------------

ARFLAGS              = ruvs \
                       $(ARDEBUG)
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O0 \
                       $(CDEBUG)
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O0 \
                       $(CPPDEBUG)
DCPPFLAGS             = $(CPP_STANDARD_OPTS) -fPIC \
                       -O0 \
                       $(CPPDEBUG)
CPP_LDFLAGS          = $(CPPLDDEBUG)
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         $(CPPLDDEBUG)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(LDDEBUG)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       $(LDDEBUG)

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/satellite_attitude
PRODUCT-DIV = $(RELATIVE_PATH_TO_ANCHOR)/satellite_attitude.bc
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/satellite_attitude_grt_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DMAT_FILE=1 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=1 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=satellite_attitude -DNUMST=2 -DNCSTATES=10 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################
#$(START_DIR)/satellite_attitude_grt_rtw/satellite_attitude_data.cpp $(START_DIR)/satellite_attitude_grt_rtw/rtGetInf.cpp  $(START_DIR)/satellite_attitude_grt_rtw/rtGetNaN.cpp
SRCS = $(MATLAB_ROOT)/rtw/c/src/rt_logging.c $(START_DIR)/satellite_attitude_grt_rtw/satellite_attitude.cpp $(START_DIR)/satellite_attitude_grt_rtw/rt_nonfinite.cpp $(START_DIR)/satellite_attitude_grt_rtw/Observer.cpp $(START_DIR)/satellite_attitude_grt_rtw/ConcreteObserverStates.cpp

MAIN_SRC = $(MATLAB_ROOT)/rtw/c/src/common/rt_cppclass_main.cpp

MAIN_DIV_SRC = ./main.cpp

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################
#satellite_attitude_data.o rtGetInf.o rtGetNaN.o
OBJS = rt_logging.o satellite_attitude.o rt_nonfinite.o

MAIN_OBJ = rt_cppclass_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS =

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

#-----------------
# DIVINE C++ Compiler
#-----------------

DCPPFLAGS_BASIC =  $(DEFINES) $(INCLUDES)

DCPPFLAGS += $(DCPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute divine-build divine-check

all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)

buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."

prebuild : 

download : $(PRODUCT)

execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."

########################################################################
## Provided by Ricardo
## I dont understand each command but according to the DIVINE manual the behavior is
## $(DCC) = $(DIVINE_EXE) cc import/links the divine math of the "compiler"?!
## Not sure what $(DCPPFLAGS) does exactly, maybe link the c++ compiler flags?
## $(MAIN_DIC_SRC) links the path to the main file
## $(SRCS) looks like it sets/links the path to the MATLAB files 
## -lm stands for "math library." It is used to link the standard math library (libm) into your program
## -o enables specifying name of the output file
## $(PRODUCT-DIV) set the .bc path
########################################################################

divine-build: 
	$(DCC) $(DCPPFLAGS) $(MAIN_DIV_SRC) $(SRCS) -lm -o $(PRODUCT-DIV)

#########################################################################
## Default divine command, plus optional options 
## $(PRODUCT-DIV) hols the path to .bc 
#########################################################################

divine-check:
	$(DIVINE_EXC) check --liveness --counterexample --report-unique  $(PRODUCT-DIV)

###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"

###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/satellite_attitude_grt_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/satellite_attitude_grt_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_logging.o : $(MATLAB_ROOT)/rtw/c/src/rt_logging.c
	$(CC) $(CFLAGS) -o "$@" "$<"


satellite_attitude.o : $(START_DIR)/satellite_attitude_grt_rtw/satellite_attitude.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


# satellite_attitude_data.o : $(START_DIR)/satellite_attitude_grt_rtw/satellite_attitude_data.cpp
# 	$(CPP) $(CPPFLAGS) -o "$@" "$<"


# rtGetInf.o : $(START_DIR)/satellite_attitude_grt_rtw/rtGetInf.cpp
# 	$(CPP) $(CPPFLAGS) -o "$@" "$<"


# rtGetNaN.o : $(START_DIR)/satellite_attitude_grt_rtw/rtGetNaN.cpp
# 	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/satellite_attitude_grt_rtw/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_cppclass_main.o : $(MATLAB_ROOT)/rtw/c/src/common/rt_cppclass_main.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"

###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)

###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : CPPFLAGS
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### DCPPFLAGS = $(DCPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(PRODUCT-DIV)
	$(RM) $(ALL_OBJS)
	$(RM) $(ALL_BCS) 
	$(RM) *.report
	$(RM) *.report.*
	$(ECHO) "### Deleted all derived files."


