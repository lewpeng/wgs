#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>

static void sig_child(int signo);


int main()
{
    pid_t pid;
    signal(SIGCHLD,sig_child);

    while(1){

    pid = fork();
    if (pid < 0)
    {
        perror("fork error:");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("I am child process.I am exiting.\n");
        exit(0);
    }
    else
    {
    	printf("I am father process.I will sleep two seconds\n");
   	 //等待子进程先退出
    	sleep(2);
    	//输出进程信息
   	 system("ps -o pid,ppid,state,tty,command");
   	 printf("father process is exiting.\n");
	 
	 continue;
    }
    }

    return 0;
}

static void sig_child(int signo)
{
     pid_t        pid;
     int        stat;
     //处理僵尸进程
     while ((pid = waitpid(-1, &stat, WNOHANG)) >0)
            printf("child %d terminated.\n", pid);
}
