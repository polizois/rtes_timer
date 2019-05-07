#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// NO COMPENSATION
int main(int argc, char *argv[])
{
	// Check Arguement Number
  if(argc != 3)
  {
    printf("Unexpected Arguement Number!\n");
    printf("Please provide the following arguements:\n");
    printf("\tArg1: sampling duration (t) in seconds\n");
    printf("\tArg2: sampling step (dt) in seconds\n");
    return 1;
  }

	// Variable Definitions
	float dt = atof(argv[2]);
  float t = atof(argv[1]);
	int sampleNum = (int)(t/dt)+1;
	int i;
	float timeStamp[sampleNum];
  struct timeval t0, t1;

	// First Sample
  gettimeofday(&t0, NULL);
  timeStamp[0] = 0.0;

	// Sampling Loop
  for(i=1;i<sampleNum;i++)
  {
    usleep(dt*1000000);
    gettimeofday(&t1, NULL);
    timeStamp[i] = (float)(t1.tv_sec-t0.tv_sec)+(float)(t1.tv_usec-t0.tv_usec)/1000000;
  }

	// Print Gathered Samples
  for(i=0;i<sampleNum;i++)
  {
    printf("%f\n",timeStamp[i]);
  }

  printf("\nExpected Duration = %f\n", t);
  printf("Last Timestamp = %f\n", timeStamp[sampleNum-1]);
}
