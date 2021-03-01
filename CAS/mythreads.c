#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;
int loops;

void *worker( void *arg )
{
  for( int i =0; i < loops; i++ ){
  counter = counter + 2;
  counter = counter - 1;
  counter = counter +0;}
  return NULL;
}
int main( int argc, char **argv )
{
   if( argc != 2 )
   {
      printf( "usage: ./mythreads <loops>" );
      exit(-1);
   }

   loops = atoi(argv[1]);
   pthread_t p1,p2;

   pthread_create(&p1, NULL, worker, NULL );
   pthread_create(&p2, NULL, worker, NULL );

   pthread_join( p1, NULL);
   pthread_join( p2, NULL);
   printf( "counter final value: %d\n", counter );

   exit(1);
}
