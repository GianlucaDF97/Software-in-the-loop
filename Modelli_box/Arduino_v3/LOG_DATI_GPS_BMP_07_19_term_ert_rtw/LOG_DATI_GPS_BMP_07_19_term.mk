###########################################################################
## Makefile generated for component 'LOG_DATI_GPS_BMP_07_19_term'. 
## 
## Makefile     : LOG_DATI_GPS_BMP_07_19_term.mk
## Generated on : Wed Sep 01 16:29:37 2021
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/LOG_DATI_GPS_BMP_07_19_term.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = LOG_DATI_GPS_BMP_07_19_term
MAKEFILE                  = LOG_DATI_GPS_BMP_07_19_term.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2020b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/SUBTEAMS_2020_2021/SOFTWARE/AUTOPILOTA/drive1/Load_hardware/Arduino_v2_1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Arduino ARM
# Supported Version(s):    
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ARDUINO_ROOT
# ARDUINO_PACKAGES_TOOLS_ROOT
# ARDUINO_PORT
# ARDUINO_MCU
# ARDUINO_BAUD
# ARDUINO_PROTOCOL
# ARDUINO_F_CPU

#-----------
# MACROS
#-----------

SHELL                       = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN                 = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
ARDUINO_TOOLS               = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin
SLIB_PATH                   = C:/Users/LAPIS-~1/DOCUME~1/MATLAB/R2020b/ARDUIN~1/ARDUIN~1/FASTER~1

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -Wl,--end-group -lm -gcc -lcomm -lcore

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino ARM Assembler
AS_PATH = $(ARDUINO_TOOLS)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: Arduino ARM C Compiler
CC_PATH = $(ARDUINO_TOOLS)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: Arduino ARM Linker
LD_PATH = $(ARDUINO_TOOLS)
LD = "$(LD_PATH)/arm-none-eabi-gcc"

# C++ Compiler: Arduino ARM C++ Compiler
CPP_PATH = $(ARDUINO_TOOLS)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: Arduino ARM C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-gcc"

# Archiver: Arduino ARM Archiver
AR_PATH = $(ARDUINO_TOOLS)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPY_PATH = $(ARDUINO_PACKAGES_TOOLS_ROOT)/tools/arm-none-eabi-gcc/4.8.3-2014q1/bin
OBJCOPY = "$(OBJCOPY_PATH)/arm-none-eabi-objcopy"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
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
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -std=gnu11 \
                       -Os \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" 
CPPFLAGS             = -std=gnu++11 -fno-threadsafe-statics -fno-rtti -fno-exceptions  \
                       -Os \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -nostdlib  \
                       --param max-inline-insns-single=500  \
                       -Dprintf=iprintf  \
                       -DARDUINO=10801  \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@" 
CPP_LDFLAGS          =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -Os -Wl,-Map="$(PRODUCT_NAME).map" -Wl,--gc-sections
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/LOG_DATI_GPS_BMP_07_19_term.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/ARDUIN~2/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/shared/svd/include -I$(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/system/libsam -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/system/CMSIS/CMSIS/Include -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/system/CMSIS/Device/ATMEL -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/cores/arduino -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/cores/arduino/avr -I$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/ARDUIN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/ARDUIN~1/SCHEDU~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/shared/EXTERN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/ARMCOR~1/SCHEDU~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/toolbox/target/SUPPOR~1/ARMCOR~1/xcp/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/3P778C~1.INS/ARDUIN~4.INS/LIBRAR~1/Servo/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/3P778C~1.INS/ARDUIN~4.INS/portable/packages/arduino/hardware/sam/16E81D~1.12/LIBRAR~1/Wire/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/3P778C~1.INS/ARDUIN~4.INS/portable/packages/arduino/hardware/sam/16E81D~1.12/LIBRAR~1/SPI/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2020b/3P778C~1.INS/ARDUIN~4.INS/LIBRAR~1/Servo/src/sam

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_TIMERID=8 -DMW_TIMERCOUNT=13125 -DMW_SAM_CLOCKID=TC_CMR_TCCLKS_TIMER_CLOCK4 -D_RTT_BAUDRATE_SERIAL0_=57600 -D_RTT_BAUDRATE_SERIAL1_=9600 -D_RTT_BAUDRATE_SERIAL2_=57600 -D_RTT_BAUDRATE_SERIAL3_=115200 -D_RTT_ANALOG_REF_=0
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=LOG_DATI_GPS_BMP_07_19_term -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/MW_SerialRead.cpp C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/MW_SerialWrite.cpp C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/MW_arduinoI2C.cpp $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/LOG_DATI_GPS_BMP_07_19_term.c $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/LOG_DATI_GPS_BMP_07_19_term_data.c $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/rtGetInf.c $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/rtGetNaN.c $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/rt_nonfinite.c $(START_DIR)/Mti_wrapper.cpp $(START_DIR)/Seriale_mav_wrapper.cpp $(START_DIR)/calc_T_wrapper.c $(START_DIR)/calc_p_wrapper.c $(START_DIR)/receive_MAVLink_v4_6_beta_AL_HITL_HOME_wrapper.c $(START_DIR)/send_MAVLink_v4_4_2_beta_3_HOME_wrapper.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arm_m3_cortex_handler.c C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinotarget/registry/../src/MW_ArduinoHWInit.cpp C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arduinoARMScheduler.cpp C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c

MAIN_SRC = $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_SerialRead.o MW_SerialWrite.o MW_arduinoI2C.o LOG_DATI_GPS_BMP_07_19_term.o LOG_DATI_GPS_BMP_07_19_term_data.o rtGetInf.o rtGetNaN.o rt_nonfinite.o Mti_wrapper.o Seriale_mav_wrapper.o calc_T_wrapper.o calc_p_wrapper.o receive_MAVLink_v4_6_beta_AL_HITL_HOME_wrapper.o send_MAVLink_v4_4_2_beta_3_HOME_wrapper.o arm_m3_cortex_handler.o MW_ArduinoHWInit.o io_wrappers.o arduinoARMScheduler.o m3m4m4f_multitasking.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(SLIB_PATH)/MW_RebuildSrc_Comm.o $(SLIB_PATH)/libcomm.a $(SLIB_PATH)/MW_RebuildSrc_Core.o $(SLIB_PATH)/libcore.a

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

CFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_ -DARDUINO_NUM_SERIAL_PORTS=4 -DARDUINO_ARM -DARDUINO_ARM_CORTEX_M3
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -MD -mcpu=cortex-m3 -fpermissive -DF_CPU=84000000L -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Due\"" -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_DUE_ -DARDUINO_NUM_SERIAL_PORTS=4 -DARDUINO_ARM -DARDUINO_ARM_CORTEX_M3
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_ = -L"$(SLIB_PATH)"
LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
SHAREDLIB_LDFLAGS_SKIPFORSIL = -T$(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/linker_scripts/gcc/flash.ld -mcpu=cortex-m3 -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group -u _sbrk -u link -u _close -u _fstat -u _isatty -u _lseek -u _read -u _write -u _exit -u kill -u _getpid $(ARDUINO_SAM_ROOT)/hardware/sam/$(SAM_LIB_VERSION)/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(OBJS) $(MAIN_OBJ) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/Users/Lapis_dSpace2/Desktop/Tesi_Sensolini/MATLAB/Autopilota_v2_1/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : C:/Users/Lapis_dSpace2/Desktop/Tesi_Sensolini/MATLAB/Autopilota_v2_1/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : C:/Users/Lapis_dSpace2/Desktop/Tesi_Sensolini/MATLAB/Autopilota_v2_1/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/Users/Lapis_dSpace2/Desktop/Tesi_Sensolini/MATLAB/Autopilota_v2_1/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/Users/Lapis_dSpace2/Desktop/Tesi_Sensolini/MATLAB/Autopilota_v2_1/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/Users/Lapis_dSpace2/Desktop/Tesi_Sensolini/MATLAB/Autopilota_v2_1/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/Users/Lapis_dSpace2/Desktop/Tesi_Sensolini/MATLAB/Autopilota_v2_1/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/SUBTEAMS 2020-2021/SOFTWARE/AUTOPILOTA/Autopilota_20210518/TEST_TELEMETRIA/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : C:/SUBTEAMS 2020-2021/SOFTWARE/AUTOPILOTA/Autopilota_20210518/TEST_TELEMETRIA/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : C:/SUBTEAMS 2020-2021/SOFTWARE/AUTOPILOTA/Autopilota_20210518/TEST_TELEMETRIA/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/SUBTEAMS 2020-2021/SOFTWARE/AUTOPILOTA/Autopilota_20210518/TEST_TELEMETRIA/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/SUBTEAMS 2020-2021/SOFTWARE/AUTOPILOTA/Autopilota_20210518/TEST_TELEMETRIA/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/SUBTEAMS 2020-2021/SOFTWARE/AUTOPILOTA/Autopilota_20210518/TEST_TELEMETRIA/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/SUBTEAMS 2020-2021/SOFTWARE/AUTOPILOTA/Autopilota_20210518/TEST_TELEMETRIA/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.S.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_SerialRead.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/MW_SerialRead.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_SerialWrite.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/MW_SerialWrite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_arduinoI2C.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/MW_arduinoI2C.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


LOG_DATI_GPS_BMP_07_19_term.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/LOG_DATI_GPS_BMP_07_19_term.c
	$(CC) $(CFLAGS) -o "$@" "$<"


LOG_DATI_GPS_BMP_07_19_term_data.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/LOG_DATI_GPS_BMP_07_19_term_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/LOG_DATI_GPS_BMP_07_19_term_ert_rtw/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Mti_wrapper.o : $(START_DIR)/Mti_wrapper.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Seriale_mav_wrapper.o : $(START_DIR)/Seriale_mav_wrapper.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calc_T_wrapper.o : $(START_DIR)/calc_T_wrapper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


calc_p_wrapper.o : $(START_DIR)/calc_p_wrapper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


receive_MAVLink_v4_6_beta_AL_HITL_HOME_wrapper.o : $(START_DIR)/receive_MAVLink_v4_6_beta_AL_HITL_HOME_wrapper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


send_MAVLink_v4_4_2_beta_3_HOME_wrapper.o : $(START_DIR)/send_MAVLink_v4_4_2_beta_3_HOME_wrapper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


arm_m3_cortex_handler.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arm_m3_cortex_handler.c
	$(CC) $(CFLAGS) -o "$@" "$<"


MW_ArduinoHWInit.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinotarget/registry/../src/MW_ArduinoHWInit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


io_wrappers.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


arduinoARMScheduler.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/arduinotarget/registry/../scheduler/src/arduinoARMScheduler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


m3m4m4f_multitasking.o : C:/ProgramData/MATLAB/SupportPackages/R2020b/toolbox/target/supportpackages/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


