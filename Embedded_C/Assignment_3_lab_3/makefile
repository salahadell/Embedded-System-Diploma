CC=arm-none-eabi
INCS=-I .
LIBS=
CFLAGS=-gdwarf-2 -mcpu=cortex-m4 -g
PROJECT_NAME=learn-in-depth-cortex-m4
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
	
ALL:$(PROJECT_NAME).bin
	@echo "DONE"

$(PROJECT_NAME).bin:$(PROJECT_NAME).elf
	$(CC)-objcopy.exe -O binary $< $@

$(PROJECT_NAME).elf:$(OBJ) $(ASOBJ)
	$(CC)-ld.exe -T linker.ld -Map=map.o $(LIBS) $(ASOBJ) $(OBJ) -o $@
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf
	
%.o:%.c
	$(CC)-gcc.exe -c $(INCS) $(CFLAGS)  $< -o $@

%.o:%.s
	$(CC)-as.exe $(CFLAGS) $< -o $@
	 
clean:
	rm *.bin *.elf
clean_all:
	rm *.bin *.elf *.o 	


