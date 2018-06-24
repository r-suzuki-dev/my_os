PREFIX	= /usr/local
ARCH	= h8300-elf
BINDIR	= $(PREFIX)/bin
ADDNAME	= $(ARCH)-

# Tools to use
AR		= $(BINDIR)/$(ADDNAME)ar
AS		= $(BINDIR)/$(ADDNAME)as
CC		= $(BINDIR)/$(ADDNAME)gcc
LD		= $(BINDIR)/$(ADDNAME)ld
NM		= $(BINDIR)/$(ADDNAME)nm
OBJCOPY = $(BINDIR)/$(ADDNAME)objcopy
OBJDUMP	= $(BINDIR)/$(ADDNAME)objdump
RANLIB	= $(BINDIR)/$(ADDNAME)ranlib
STRIP	= $(BINDIR)/$(ADDNAME)strip

# Flash ROM writing tool
H8WRITE = ../../tools/h8write/h8write

# Serial connection destination
H8WRITE_SERDEV = /dev/ttyUSB0

# Source code group to be compiled
OBJS = vector.o startup.o main.o
OBJS += lib.o serial.o

# Filename of executable to be generated
TARGET = kzload

# Compile option
CFLAGS = -Wall -mh -nostdinc -nostdlib -fno-builtin
#CFLAGS += mint32 # When int is set to 32 bits, multiplication / division can not be performed
CFLAGS += -I.
#CFLAGS += -g
CFLAGS += -Os
CFLAGS += -DKZLOAD

# Link option
LFLAGS = -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

all:		$(TARGET)

# Execution format generation rule
$(TARGET) :	$(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
		cp $(TARGET) $(TARGET).elf
		$(STRIP) $(TARGET)

# *.c File compiling rules
.c.o :		$<
		$(CC) -c $(CFLAGS) $<

# Assembler file assembly rules
.s.o :		$<
		$(CC) -c $(CFLAGS) $<

# Rules for conversion to Motorola S record format
$(TARGET).mot :	$(TARGET)
		$(OBJCOPY) -O srec $(TARGET) $(TARGET).mot

image :		$(TARGET).mot

# Transfer to flash ROM
write :		$(TARGET).mot
		$(H8WRITE) -3069 -f20 $(TARGET).mot $(H8WRITE_SERDEV)

# Cleaning folders
clean :
		rm -f $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).mot
