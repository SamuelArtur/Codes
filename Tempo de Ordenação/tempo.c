#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  struct rusage usage;
  struct timeval start, end;
  int i, j, k = 0;

  getrusage(RUSAGE_SELF, &usage);
  start = usage.ru_stime;
  for (i = 0; i < 10000; i++) {
    for (j = 0; j < 10000; j++) {
      k += 20; 
    }
  }
  printf("Hello there");
  getrusage(RUSAGE_SELF, &usage);
  end = usage.ru_stime;

  printf("Started at: %ld.%lds\n", start.tv_sec, start.tv_usec);
  printf("Ended at: %ld.%lds\n", end.tv_sec, end.tv_usec);
  return 0;
}
