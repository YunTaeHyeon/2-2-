#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_BUF 128

int main(int argc, char* argv[])
{
    char ch;
	char buf[MAX_BUF];
    int fd, fd1; //기존 파일에 대한 fd와 새로 생성할 파일에 대한 fd
	struct stat st; //st는 파일의 정보
	
    if( argc != 3 )  //인자 에러 처리
    {
        printf("cannot execute mycp argument error\n");
		exit(-1);
    }
	
	stat(argv[1],&st); //argv[1]의 파일 정보를 st에
	
    fd = open( argv[1], O_RDONLY ); // 읽기 전용으로 열기 
	
	if(fd<0){ //argv[1]이 존재하지 않을 때 에러 처리
		printf("cannot open %s \n", argv[1]);
		exit(-1);
	}
	
	fd1 = open( argv[2], O_RDWR | O_CREAT | O_EXCL, st.st_mode ); // 파일이 없으면 생성하고 이미 존재하는 파일이면 생성하지 않기
	if(errno==17){
      printf("%s is already Exists \n", argv[2]);
      exit(-1);	
	}
	
	
    while( read( fd, &ch, 1 )) //fd에서 문자를 하나씩 읽어올 때마다 
        write( fd1, &ch, 1 ); //fd1에 하나씩 문자를 입력

    close( fd );
    close( fd1 );
    return 0;
}