#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 128

int main(int argc, char *argv[]){
    int fd, read_size, write_size;
    char buf[MAX_BUF];
 
    if(argc != 2){ //인자에 대한 에러 처리
        printf("Cannot execute mycat argument error\n");
        exit(-1);
    }

    fd = open(argv[1], O_RDONLY);
			
    if(fd < 0){ //argv[1]이 존재하지 않을 때 에러 처리
        printf("Cannot Open \" %s \" \n", argv[1]);
        exit(-1);
    }
	
	while(1){
        read_size=read(fd, buf, MAX_BUF); //buf만큼 fd에서 읽어오기
		if(read_size==0) //더이상 읽어올 것이 없을 때까지 반복의 의미
			break;
        write_size=write(STDOUT_FILENO,buf,read_size); //터미널에 read_size만큼 write
	}
	
		close(fd);
        return 0;

}



    while(1){
		read_size=read(fd,buf,MAX_BUF); //fd에서 읽어오기
		if(read_size==0); //더이상 읽어올 것이 없을 때까지 반복
			break;
		
		write(fd1,buf,read_size); //fd1에다가 쓰기
	}