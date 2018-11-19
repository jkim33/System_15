#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

  srand(time(NULL));
  unsigned int random1 = 5 + rand()%16;
  unsigned int random2 = 5 + rand()%16;

  int f1 = fork();
  if (f1) {
    printf("%d: I am the parent!\n", getpid());
    int f2 = fork();
    if (f2) {
      int status;
      int fastest = wait(&status);
      printf("%d: Child %d slept for %d seconds\n", getpid(), fastest, WEXITSTATUS(status));
    }
    else {
      printf("%d: I am a child!\n", getpid());
      sleep(random1);
      printf("%d: I slept for %d seconds\n", getpid(), random1);
      return random1;
    }
  }
  else {
    printf("%d: I am a child!\n", getpid());
    sleep(random2);
    printf("%d: I slept for %d seconds\n", getpid(), random2);
    return random2;
  }
  return 0;
}
