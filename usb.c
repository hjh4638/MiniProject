#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <termios.h>
#include <fcntl.h>

int main( void)
{
    int fd;

    char buf[128];
    char cha = 0;

    struct termios newtio;



    //fd = open( "/dev/tts/1", O_RDWR | O_NOCTTY | O_NONBLOCK ); 

    fd = open( "/dev/ttyACM0", O_RDWR | O_NOCTTY );
    memset( &newtio, 0, sizeof(newtio) );

    if(fd == -1){
	printf("failed\n");
    }
    else printf("sueecss\n");

    newtio.c_cflag = B115200;
    newtio.c_cflag |= CS8;
    newtio.c_cflag |= CLOCAL;
    newtio.c_cflag |= CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 1;

    tcflush (fd, TCIFLUSH );
    tcsetattr(fd, TCSANOW, &newtio );

    read(fd,&cha,1);
    printf("buf is [%c]\n",cha);
	cha = 'b';
    printf("test is  [%c]\n",cha);
   // write( fd, "forum.falinux.com", 17);

    close( fd);
    return 0;
}
