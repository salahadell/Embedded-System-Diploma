MEMORY
{
	flash(rx) : o = 0x00000000,   l = 500M
	sram(rwx) : o = 0x20000000,    l = 500M
}

SECTIONS
{
	.text :{

		*(.vectors*)
		*(.text*)	
		*(.rodata)
		E_text = . ;
	}> flash

    .data :{

    	S_data = . ;
        *(.data)
        . = ALIGN(4) ;
   		E_data = . ;

    }> sram AT> flash

    .bss :{

       	S_bss = . ;
		*(.bss*)
		. = ALIGN(4) ;
    	E_bss = . ;

    }> sram
    
}