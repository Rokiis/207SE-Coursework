#include <stdio.h>
#include <stdlib.h>
//-----------------------------
#include<sys/types.h>
#include<sys/stat.h>  //Includes needed for open() to work in C
#include <fcntl.h> 
//------------------------
#include <unistd.h> //Include needed for read() and write() to work in C

//The internals of this struct aren't important
//from the user's point of view
typedef struct{
  int file;        //File being read(int is being used on open())
  int bufferlength;  //Fixed buffer length
  int usedbuffer;    //Current point in the buffer
  char* buffer;      //A pointer to a piece of memory
} cr_file;




//Open a file with a given size of buffer to cache with
cr_file* cr_open(char* filename, int buffersize);


//Close an open file
void cr_close(cr_file* f);

//Read a byte.  Will return EOF if empty.
char cr_read_byte(cr_file* f);


