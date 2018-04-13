#include "types.h"
#include "user.h"

int main(int argc, char** argv)
{
  int pid = fork();
  if(pid > 0) {
    //parent
    int pid2 = fork();
    if(pid2 > 0){
    //parent
    
      if(waitpid(pid, NULL, 0) != -1) {
        printf(1,"parent waiting for process %d",pid); 	
      }
    }
    else if(pid == 0) {
      //child
      exit(1);
    }
    else{
      printf(1,"fork2 failed");
    }
  }
  else if(pid == 0) {
    //child
    exit(1);
  }
  else{
    //fork failed
    printf(1,"fork1 failed");
  }
  return 0;
}
