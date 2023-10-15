from os import system

for i in range(1,4):
  cmd1="docker tag web-pwn-%i tjoconnor/web-pwn-%i" %(i,i)
  cmd2="docker push tjoconnor/web-pwn-%i" %i
  cmd3="docker tag service-pwn-%i tjoconnor/service-pwn-%i" %(i,i)
  cmd4="docker push tjoconnor/service-pwn-%i" %i
  system(cmd1)
  system(cmd2)
  system(cmd3)
  system(cmd4)


