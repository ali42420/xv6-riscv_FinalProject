#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void
do_heavy_computation(void)
{
 
  volatile int x = 0;
  for(int i = 0; i < 80000000; i++){
    x += i * 2;
  }
}

int
main(void)
{
  int priorities[] = {90, 50, 10, 9, 8, 7, 6, 5}; 
  int n = 8;

  printf("Starting Priority Scheduling Test...\n");

  for(int i = 0; i < n; i++){
    int pid = fork();
    if(pid < 0){
      printf("Fork failed!\n");
      exit(1);
    } 
    else if(pid == 0){
  
      int my_pid = getpid();
      setpriority(my_pid, priorities[i]);
      
      printf("Child %d started with priority %d\n", my_pid, priorities[i]);
      do_heavy_computation();
      printf(">>> Child %d (Priority %d) FINISHED!\n", my_pid, priorities[i]);
      exit(0);
    }
  }

 
  for(int i = 0; i < n; i++){
    wait(0);
  }

  printf("All test processes finished. Scheduler test complete.\n");
  exit(0);
}
