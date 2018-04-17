#include "types.h"
#include "user.h"

int main(int argc, char** argv)
{
  int pid = fork();
  if(pid > 0) {
    //parent
    printf(1, "in parent, child 1 fork successful\n");
    int pid2 = fork();
    if(pid2 > 0){
    //parent
      printf(1, "inparent, child 2 fork successful\n");
      if(waitpid(pid, NULL, 0) != -1) {
        printf(1,"parent waiting for process %d\n",pid); 	
      }
    }
    else if(pid2 == 0) {
      //child
      sleep(3);
      exit(1);
    }
    else{
      printf(1,"fork2 failed\n");
    }
    if(waitpid(pid2, NULL, 0) != -1) {
        printf(1,"parent waiting for process2 %d\n",pid2); 	
    } 
  }
  else if(pid == 0) {
    //child
    exit(1);
  }
  else{
    //fork failed
    printf(1,"fork1 failed\n");
  }
  printf(1, "end of test\n");

  exit(1);
}
