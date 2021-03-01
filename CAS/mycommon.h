#ifndef _common_h__
#define _common_h__

#include <sys/time.h>
#include <assert.h>

double GetTime()
{
  struct timeval t;
  assert( gettimeofday(&t,NULL) == 0 );
  return (double)t.tv_sec + (double)t.tv_usec/1e6;

}

void Spin( int secs )
{
  double t = GetTime();
  while( GetTime() - t < (double)secs );
} 

#endif
