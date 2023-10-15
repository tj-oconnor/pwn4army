from os import system

for i in range(1,4):
  cmd1="docker pull tjoconnor/web-pwn-%i" %i
  cmd2="docker pull tjoconnor/service-pwn-%i" %i
  system(cmd1)
  system(cmd2)


