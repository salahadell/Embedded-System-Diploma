.global reset
reset:
      ldr sp,=stack_address
      bl main
stop: b stop
