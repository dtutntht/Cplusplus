#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "termios.h"
//#include <linux/termios.h>

int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop)
{
  struct termios newtio, oldtio;     //com struct
  
  if (tcgetattr( fd, &oldtio) != 0) { 
    perror("SetupSerial 1");
    return -1;
  }
  
  bzero( &newtio, sizeof( newtio ) );          //sizeof n set to zero
  newtio.c_cflag |= CLOCAL | CREAD; 
  newtio.c_cflag &= ~CSIZE; 

  switch( nBits )
  {
  case 7:
    newtio.c_cflag |= CS7;
    break;
  case 8:
    newtio.c_cflag |= CS8;
    break;
  }

  switch( nEvent )
  {
  case 'O':
    newtio.c_cflag |= PARENB;
    newtio.c_cflag |= PARODD;
    newtio.c_iflag |= (INPCK | ISTRIP);
    break;
  case 'E': 
    newtio.c_iflag |= (INPCK | ISTRIP);
    newtio.c_cflag |= PARENB;
    newtio.c_cflag &= ~PARODD;
    break;
  case 'N': 
    newtio.c_cflag &= ~PARENB;
    break;
  }

switch( nSpeed )
  {
  case 4800:
    cfsetispeed(&newtio, B4800);
    cfsetospeed(&newtio, B4800);
    break;
  case 9600:
    cfsetispeed(&newtio, B9600);
    cfsetospeed(&newtio, B9600);
    break;
  case 38400:
    cfsetispeed(&newtio, B38400);
    cfsetospeed(&newtio, B38400);
    break;
  case 115200:
    cfsetispeed(&newtio, B115200);
    cfsetospeed(&newtio, B115200);
    break;
  default:
    cfsetispeed(&newtio, B9600);
    cfsetospeed(&newtio, B9600);
    break;
  }
  if( nStop == 1 )
    newtio.c_cflag &= ~CSTOPB;
  else if ( nStop == 2 )
	newtio.c_cflag |= CSTOPB;

  newtio.c_cc[VTIME] = 0;
  newtio.c_cc[VMIN] = 0;
  tcflush(fd,TCIFLUSH);     //clear buff
  
  printf("CCflag: 0x%04X\n", newtio.c_cflag);
  
  
  if((tcsetattr(fd,TCSANOW,&newtio))!=0)
  {
    perror("com set error");
    return -1;
  }
  printf("set done!\n");
  return 0;
}

int open_port(int fd,int comport)
{
  char *dev[]={"/dev/ttyS0","/dev/ttyS1","/dev/ttyACM0","/dev/ttyUSB0"};
  printf("device is: %s\n", dev[2]);

  if (comport==1)
  { fd = open( dev[2], O_RDWR|O_NOCTTY|O_NONBLOCK);   
    //noctty如果欲打开的文件为终端机设备时,则不会将该终端机当成进程控制终端机
    if (-1 == fd)
	{
      perror("Can't Open Serial Port");
      return(-1);
    }
    else 
      printf("open ttyS0 .....\n");
  }

  if(fcntl(fd, F_SETFL, 0)<0)            // F_SETFL  设置文件状态标识
    printf("fcntl failed!\n");
  else
    printf("fcntl=%d\n",fcntl(fd, F_SETFL,0));

  //查看開啟指定Terminal後，STDIN_FILENO是否還是預設的0而不是open回傳的fd(file descriptor)，如果是0則表示目前Standard input沒有被Terminal device取代
  if(isatty(STDIN_FILENO)==0)
    printf("standard input is not a terminal device\n");
  else
    printf("isatty success!\n");

  printf("fd-open=%d\n",fd);
  return fd;
}

int main(void)
{
  int fd;
  int nread,nwrite,i,j;
  char send_buf[]="E-2-16-0-F", recv_buf[100];
	char *ptr = NULL;
	int total = 0;
  
  if((fd=open_port(fd,1))<0)
  {
    perror("open_port error");
    return;
  }
  
  if((i=set_opt(fd,9600,8,'N',1))<0)
  {
    perror("set_opt error");
    return;
  }
  
//wait for option take active
  sleep(1);
  
  printf("fd=%d\n",fd);


for (j=0;j<10;j++)
{
  nwrite=write(fd, send_buf, sizeof(send_buf));
  sleep(5);
  
  nread=read(fd, recv_buf, sizeof(recv_buf));
	if(nread>0)
		printf("nread=%d,%s\n",nread,recv_buf);
	else	
		printf("read fail!\n");
}	
  close(fd);
  return;
}

