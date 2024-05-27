# Source files
LINK    = linker/link.ld
ASM_SRC = src/kernel.asm
C_SRC   = src/kernel.c 

# Object files
C_OBJ   = build/kc.o
ASM_OBJ = build/kasm.o

# Kernel output file
KERNEL  = build/kernel

# Compiling tools
LD   = ld
NASM = nasm
GCC  = gcc

# Compile flags 
GCCFLAGS  = -m32 -c -fno-stack-protector
LDFLAGS   = -m elf_i386 -T $(LINK)
NASMFLAGS = -f elf32

# Creating the build directory if it does not exist
$(shell mkdir -p build)

# Creating the kernel
all: $(KERNEL)

# Linking object files to create the kernel
$(KERNEL): $(ASM_OBJ) $(C_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

# Compiling the ASM source file
$(ASM_OBJ): $(ASM_SRC)
	$(NASM) $(NASMFLAGS) -o $@ $<

# Compiling the C source file
$(C_OBJ): $(C_SRC)
	$(GCC) $(GCCFLAGS) -o $@ $<

# Cleaning all files
clean:
	rm -f build/*

.PHONY: all clean
