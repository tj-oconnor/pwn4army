#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

__attribute__((constructor)) void ignore_me()
{
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

int car_server_socket;
struct sockaddr_in server_addr;

void die()
{
    close(car_server_socket);
    exit(0);
}

void car_server_connect()
{
    printf("<<< -----------------------------------------------------------------------------\n");
    printf("<<< Connecting to local car server...\n");
    printf("<<< -----------------------------------------------------------------------------\n");
    car_server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(31337);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("<<< Connected to local car server.\n");
    printf("<<< -----------------------------------------------------------------------------\n");

}

int send_command(char *cmd)
{
    printf("<<< Sending Command: %s\n", cmd);
    sendto(car_server_socket, cmd, 1, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

void logo()
{
    puts("uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu");
    printf("\n");
    printf("MMMMMMMMMMMMMMMMMMMMMMMMNKOxl:;'..            ...,:ldkKNWMMMMMMMMMMMMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMMMMMMMMMNOdc,.                            .':oOXWMMMMMMMMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMMMMMWKxc'                                      .:dKWMMMMMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMMMXx:.             ...,;::ccccc:;,'..             .;xXWMMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMW0l.           .;cdk0XNWWMMMMMMMMWWNXKOdl;.           .l0WMMMMMMMMMMM\n");
    printf("MMMMMMMMMW0c.         .:dOXWMMMMMMMMMMMMMMMMMMMMMMMMWXOd:.         .c0WMMMMMMMMM\n");
    printf("MMMMMMMWKl.        .:xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkc.        .lKWMMMMMMM\n");
    printf("MMMMMMNx'        'dKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKd,        .xNMMMMMM\n");
    printf("MMMMMKc.       'dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNk,        cKMMMMM\n");
    printf("MMMW0,       .oXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx'       ,0WMMM\n");
    printf("MMWO'       ,OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKc       'OWMM\n");
    printf("MMO'       :KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd.      'OMM\n");
    printf("MK;       :XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.      ;KM\n");
    printf("Nl        .:oxOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kdl,.       lN\n");
    printf("k.             .':ldkKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOxl:,..            .O\n");
    printf("c                    ..;cox0XWMMMMN0xdlllldx0NMMMMWX0koc;'.                    c\n");
    printf(".      ...                  .,:ldl,.        .,ldl:,..                 ...      .\n");
    printf("       lXKOdl:'.                                                .':ldkKXo       \n");
    printf("      .xMMMMMWNX0xoc;..                                  ..,:oxOKNWMMMMMk.      \n");
    printf("      .kMMMMMMMMMMMMWNKOdl:,.      PopulateX0      .';cdk0XWMMMMMMMMMMMMO'      \n");
    printf("      .kMMMMMMMMMMMMMMMMMMWWX0d.                .cOKNWMMMMMMMMMMMMMMMMMMO.      \n");
    printf("      .dWMMMMMMMMMMMMMMMMMMMMMWo.               cXMMMMMMMMMMMMMMMMMMMMMMk.      \n");
    printf(".      cNMMMMMMMMMMMMMMMMMMMMMMNx'            'dNMMMMMMMMMMMMMMMMMMMMMMWo      .\n");
    printf(",      'OMMMMMMMMMMMMMMMMMMMMMMMMXx;        ;xXMMMMMMMMMMMMMMMMMMMMMMMMK;      ,\n");
    printf("o       cNMMMMMMMMMMMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMMMMMMMMMMMWd.      o\n");
    printf("0,      .xWMMMMMMMMMMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMMMMMMMMMMMO'      ,K\n");
    printf("Wx.      .kWMMMMMMMMMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMMMMMMMMMM0,      .xW\n");
    printf("MNl       .kWMMMMMMMMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMMMMMMMMW0,       lNM\n");
    printf("MMXc       .dNMMMMMMMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMMMMMMMWk'       cXMM\n");
    printf("MMMXl       .cKWMMMMMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMMMMMMXl.       lXMMM\n");
    printf("MMMMNo.       .dXMMMMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMMMMNx'       .oNMMMM\n");
    printf("MMMMMWk,        'dXWMMMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMMMWXx,        ,kWMMMMM\n");
    printf("MMMMMMMXl.        .lONMMMMMMMMMMMMMO.      .OMMMMMMMMMMMMMW0o'        .lKMMMMMMM\n");
    printf("MMMMMMMMW0c.        .,oONWMMMMMMMMMO.      .OMMMMMMMMMWNOo;.        .:0WMMMMMMMM\n");
    printf("MMMMMMMMMMW0c.          ':dOKNWMMMMO.      .OMMMMMNXOd:'.         .cOWMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMWKo,            .':loxOo.      .oOxdl:,.            'o0WMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMMMMNOl,.                                         'lONMMMMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMMMMMMMN0d:'.                                 .:oONMMMMMMMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMMMMMMMMMMWN0xl:'..                     .';ldOXWMMMMMMMMMMMMMMMMMMMMM\n");
    printf("MMMMMMMMMMMMMMMMMMMMMMMMMMWX0xl:'..           .';cdOXWMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    puts("llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");
    printf("\n");
}

void authenticate()
{
    char contact[16];
    printf("<<< -----------------------------------------------------------------------------\n");
    printf("<<< Remote Controlled CTF v4.2: PopulateX0                                       \n");
    printf("<<< -----------------------------------------------------------------------------\n");
    printf("<<< We are sorry, but our car service is not available at this time. DriverMenu()\n");
    printf("<<< has been removed to prevent exploitation. Please provide your email contact  \n");
    printf("<<< info and we'll get back to you ASAP >>> ");
    read(0, &contact, 128);
    printf("<<< Thank you!\n");
    return;
}

int main(int argc, char **argv)
{
    logo();
    car_server_connect();
    authenticate();
    return 0;
}

void sub_31337() {
    __asm__(
"        ldp x0, x1, [sp], #0x10 \n" // Pops x0 & x1
"        ldp x29, x30, [sp], #0x10 \n" // Pops x29 & x30
"        ret \n"
    );
}
