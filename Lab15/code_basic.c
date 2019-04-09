//critical_example2.c
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "se207_sems.h"

int main(int argc, char argv[]){
int id;  
//Use our source file as the "key"
  id=se207_semget("critical_example2.c",1);

  int pid=fork();  
  if(pid){
    //P1

    while(1){

      se207_wait(id);
      rsleep();
      printf("\n");
      se207_signal(id);

      se207_wait(id);
      printf("Yes,Liza!\n");
      se207_signal(id);

      se207_wait(id);
      printf("Don't fetch the water..\n");
      printf("\n");
      printf("There's a hole in the bucket, dear Liza, dear Liza,\n");
      printf("There's a hole in the bucket, dear Liza, a hole.\n");
      se207_signal(id);

      se207_wait(id);
      printf("With what shall I fix it, dear Liza, dear Liza?\n");
      printf("With what shall I fix it, dear Liza, with what?\n");
      se207_signal(id);

      se207_wait(id);
      printf("But the straw is too long, dear Liza, dear Liza,\n");
      printf("The straw is too long, dear Liza, too long.\n");
      se207_signal(id);

      se207_wait(id);
      printf("With what shall I cut it, dear Liza, dear Liza?\n");
      printf("With what shall I cut it, dear Liza, with what?\n");
      se207_signal(id);

      se207_wait(id);
      printf("The axe is too dull, dear Liza, dear Liza,\n");
      printf("The axe is too dull, dear Liza, too dull.\n");
      se207_signal(id);

      se207_wait(id);
      printf("On what shall I sharpen it, dear Liza, dear Liza?\n");
      printf("On what shall I hone it, dear Liza, with what?\n");
      se207_signal(id);

      se207_wait(id);
      printf("But the stone is too dry, dear Liza, dear Liza,\n");
      printf("The stone is too dry, dear Liza, too dry.\n");
      se207_signal(id);

      se207_wait(id);
      printf("With what shall I wet it, dear Liza, dear Liza?\n");
      printf("With what shall I wet it, dear Liza, with what?\n");
      se207_signal(id);

      se207_wait(id);
      printf("In what shall I fetch it, dear Liza, dear Liza?\n");
      printf("In what shall I fetch it, dear Liza, in what?\n");
      se207_signal(id);

      se207_wait(id);
      printf("There's a hole in the bucket, dear Liza, dear Liza,\n");
      printf("There's a hole in the bucket, dear Liza, a hole. \n");
      se207_signal(id);

    }
  }else{
    //P2
    while(1){
      se207_wait(id);
      rsleep();
      printf("Henry?\n");
      printf("Oh, Henry?\n");
      se207_signal(id);

      se207_wait(id);
      printf("Did you fetch the water?\n");
      se207_signal(id);

      se207_wait(id);
      printf("Well, fix it, dear Henry, dear Henry, dear Henry,\n");
      printf("Well, fix it, dear Henry, dear Henry, fix it.\n");
      se207_signal(id);

      se207_wait(id);
      printf("With a straw, dear Henry, dear Henry, dear Henry,\n");
      printf("With a straw, dear Henry, dear Henry, with a straw.\n");
      se207_signal(id);

      se207_wait(id);
      printf("Cut it, dear Henry, dear Henry, dear Henry,\n");
      printf("Well, cut it, dear Henry, dear Henry, cut it.\n");
      se207_signal(id);

      se207_wait(id);
      printf("With an axe, dear Henry, dear Henry, dear Henry,\n");
      printf("With an axe, dear Henry, dear Henry, an axe.\n");
      se207_signal(id);

      se207_wait(id);
      printf("Sharpen it, dear Henry, dear Henry, dear Henry,\n");
      printf("Well, sharpen it, dear Henry, dear Henry, hone it.\n");
      se207_signal(id);

      se207_wait(id);
      printf("On a stone, dear Henry, dear Henry, dear Henry,\n");
      printf("On a stone, dear Henry, dear Henry, on a stone.\n");
      se207_signal(id);

      se207_wait(id);
      printf("Well, wet it, dear Henry, dear Henry, dear Henry,\n");
      printf("Well, wet it, dear Henry, dear Henry, wet it.\n");
      se207_signal(id);

      se207_wait(id);
      printf("Try water, dear Henry, dear Henry, dear Henry,\n");
      printf("Try water, dear Henry, dear Henry, use water.\n");
      se207_signal(id);

      se207_wait(id);
      printf("In a bucket, dear Henry, dear Henry, dear Henry,\n");
      printf("In a bucket, dear Henry, dear Henry, in a bucket.\n");
      se207_signal(id);
      
    }
    
  }
  
}

