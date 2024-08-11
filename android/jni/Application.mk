CFLAGS_OPT :=  -O3 -fomit-frame-pointer -funsafe-math-optimizations -ftree-vectorize -fgraphite-identity -floop-interchange -floop-block -funsafe-loop-optimizations -finline-limit=1024
CFLAGS_OPT_ARM := -mthumb -mfpu=neon -mcpu=cortex-a9 -pipe -mvectorize-with-neon-quad -DVECTORIZE_SINCOS
CFLAGS_OPT_ARMv5 :=-march=armv6 -mfpu=vfp -marm -pipe
CFLAGS_OPT_X86 := -mtune=atom -march=atom -mssse3 -mfpmath=sse -funroll-loops -pipe -DVECTORIZE_SINCOS
CFLAGS_HARDFP := -D_NDK_MATH_NO_SOFTFP=1 -mhard-float -mfloat-abi=hard -DLOAD_HARDFP -DSOFTFP_LINK
CFLAGS_OPT_ARM64 := -mcpu=cortex-a53 -march=armv8-a -pipe -O3 -fomit-frame-pointer -funsafe-math-optimizations \
                    -ftree-vectorize -floop-interchange -finline-limit=256 -ffast-math -funroll-loops
APPLICATIONMK_PATH = $(call my-dir)

XASH3D_CONFIG := $(APPLICATIONMK_PATH)/bs_config.mk

APP_ABI := armeabi-v7a-hard arm64-v8a
APP_MODULES := menu client server
APP_PLATFORM := android-9
APP_STL := gnustl_static
