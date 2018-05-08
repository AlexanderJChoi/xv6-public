#include "types.h"
#include "user.h"

int PScheduler(void);

int main(int argc, char *argv[])
{
    PScheduler();

    exit(0);
}    
      
int PScheduler(void){
		 
    // Use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority. All processes have a default priority of 10
    // You can use your own priority range/value setup

    int pid, ret_pid, exit_status;
    int i;
  
    printf(1, "Testing the priority aging:\n");
    printf(1, "This is parent with PID %d, running with priority 0\n", getpid());
    setpriority(0); // Use your own setpriority interface
    for (i = 0; i < 2; i++) {
	pid = fork();
	if (pid > 0) {
            continue;
        } else if ( pid == 0) {
            if(i == 0) {
              printf(1, "This is child with PID %d, running with priority 5\n", getpid());
              setpriority(5);
              sleep(500);
              
              printf(1, "This is the child with PID %d, exiting\n", getpid());
              exit(0);
            } else {
              printf(1, "This is the child with PID %d, running with priority 20\n", getpid());
              setpriority(20);
              sleep(500);
              printf(1, "This is the child with PID %d, exiting\n", getpid());
              exit(0);
            } 
            	
            exit(0);
        } else {
            printf(2," \n Error fork() \n");
            exit(-1);
        }
    }

    if(pid > 0) {
        for (i = 0; i < 2; i++) {
            ret_pid = wait(&exit_status);
            printf(1, " - This is the parent: child with PID# %d has finished with status %d \n", ret_pid, exit_status);
        }
    }
			
    return 0;
}

