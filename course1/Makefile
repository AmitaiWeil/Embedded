#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# makefile that can compile multiple source files 
# and support two platform targets
#
# make build PLATFORM=MSP432, make build PLATFORM=HOST
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       <FILE>.i 		: builds preprocessor output (E flag)
#		<FILE>.asm  :  builds assembly output (S flag)
#		<FILE>.o		: builds object output, without linking
#		compile-all	: compile all object files, without linking (.PHONY protection)
#		build				: Compile all object files and link into a final executable. (.PHONY protection)
#		clean				: remove all but source files. (.PHONY protection)
#
# Platform Overrides:
#        CPU  	: ARM Cortex architecture (cortex-m4
#		?ARCH   : ARM Architecture (arm, thumb)
#		?SPECS  :  Specs file to give the linker (nosys.specs, nano.specs)
#------------------------------------------------------------------------------
include sources.mk


ifeq ($(PLATFORM), MSP432)
  LINKER_FILE = msp432p401r.lds
  CPU = Cortex-m4
  ARCH = thumb
  SPECS = nosys.specs
  LDFLAGS_ARCH = -T $(LINKER_FILE)
  CFLAGS_ARCH = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -I/some/dircect -DCOURSE1 #-DMSP432

  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
endif

ifeq ($(PLATFORM), HOST)
#	LINKER_FILE = msp432p401r.lds
#	CPU = 
#	ARCH = 
#	SPECS = 	
  CFLAGS_ARCH = -DCOURSE1 # -DHOST
	
  CC = gcc
  LD = ld
endif

TARGET = C1m1
LDFLAGS = -wl, -map=$(TARGET).map $(LDFLAGS_ARCH)
CFLAGS = $(CFLAGS_ARCH) -wall -Werror -g -o0 -std=c99
#CPPFLAGs = 

#OBJS = $(SRCS:.c=.o)?

#------------------------------------------------------------------
# Targets list
.PHONY: build
build: all 
#build: $(TARGET).out

.PHONY: all
#all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC)  $(OBJS)  $(CFLAGS)  $(LDFLAGS) -o $@
		
.PHONY: clean
	rm -f $(OBJS) $(TARGET) $(TARGET).map
	%.o : %.c
	$(CC) -c  $<  $(CFLAGS) -o  $@
	OBJS = $(SOURCES:.c=.o)
	
$(TARGET).out: $(OBJS)
    $(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@	
