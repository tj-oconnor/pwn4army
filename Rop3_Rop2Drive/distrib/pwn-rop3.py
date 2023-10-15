from pwn import *

binary = args.BIN
HOST = args.HOST

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary)
r = ROP(e)

gs = '''
continue
'''


def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote(HOST, 1337)
    else:
        return process(e.path)

'''
0044afc4  e04f40f9   ldr     x0, [sp, #0x98 {var_28}]  {0x0}
0044afc8  fd7bcca8   ldp     x29, x30, [sp], #0xc0 {__saved_x29} {__saved_x30}
0044afcc  c0035fd6   ret
'''

p = start()

'''
Build your chain here
'''

p.interactive()
