ENTRY(reset)
MEMORY
{
	memory (rwx): o = 0x00000000, l = 64M
}

SECTIONS
{
    . = 0x10000 ;
	.reset . :
	{
	  startup.o(.text)

	}>memory
    .text :
    {

     *(.text)
     
    }>memory
   .data :
    {
    
     *(.data)

    }>memory
    .bss :
    {
    
     *(.bss)

    }>memory
    . = . + 0x1000;
    stack_address = .;


}