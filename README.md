# Pwn My Ride (Pwn4Army)

Repository for lesson "Pwn 4 Army" Taught at US Military Academy on October 24, 2023.

This instruction block introduces students to [return-oriented programming](https://ctf101.org/binary-exploitation/return-oriented-programming/) on the [aarch64](https://en.wikipedia.org/wiki/AArch64) architecture. Lesson materials follow:

1. [Slides](slides/Pwn-My-Ride.pptx)
2. [Example Binary](toy_binary/)

# Challenges

|  Challenge  |  Key Concepts                					| Solution |  
--------------|-------------------------------------------------|---------|
| [Ret2Drive](Rop1_Ret2Drive/)   | Familiarizes student with hijacking *PC* using a stack-based buffer overflow. | [solution](Rop1_Ret2Drive/solve) |
| [PopulateXO](Rop2_PopulateX0/)  | Familiarizes student with populating function parameters by a ROP chain to load registers using *immeidate offsets*. | [solution](Rop2_PopulateX0/solve) |
| [Rop2Drive](Rop3_Rop2Drive/)   | Familiarizes student with chaining multiple function calls by *jumping to an offset* past the function prologue. | [solution](Rop3_Rop2Drive/solve) |

# Dockerhub Images

The pre-built images are deployed to dockerhub to support the activity.

## Ret2Drive 
1. [web ttyd session](https://hub.docker.com/repository/docker/tjoconnor/web-pwn-1)
2. [vulnerable service](https://hub.docker.com/repository/docker/tjoconnor/serice-pwn-1)

## PopulateX0
1. [web ttyd session](https://hub.docker.com/repository/docker/tjoconnor/web-pwn-2)
2. [vulnerable service](https://hub.docker.com/repository/docker/tjoconnor/serice-pwn-2)

## Rop2Drive
1. [web ttyd session](https://hub.docker.com/repository/docker/tjoconnor/web-pwn-3)
2. [vulnerable service](https://hub.docker.com/repository/docker/tjoconnor/serice-pwn-3)

# References

Arm Developer, *[Procedure Standard Call Documentation](https://developer.arm.com/documentation/102374/0100/Procedure-Call-Standard)*. 2022

CTF101.org, *[Return Oriented Programming](https://ctf101.org/binary-exploitation/return-oriented-programming/)*. 2022.

Arm Developer, *[The ARM Instruction Set Architecture](https://users.ece.utexas.edu/~valvano/EE345M/Arm_EE382N_4.pdf)*. 2022.

MITRE, CWE-121: *[Stack Based Buffer Overflow](https://cwe.mitre.org/data/definitions/121.html)*. 2022.

Perfect Blue, *[ROP-ing on Aarch64](https://blog.perfect.blue/ROPing-on-Aarch64) - The CTF Style*. 2019.
