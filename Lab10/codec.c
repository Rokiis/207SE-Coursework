#include "cache_reader.h"


int refill(cr_file* buff){
  //Refills a buffer
  //Only works when completely used buffer
  if(buff->usedbuffer!=buff->bufferlength)
    return 0;
  else{
    buff->usedbuffer=0;
    int len=read(buff->file, buff->buffer, buff->bufferlength); //reads bytes from file starting at buff.
    //If we didn't fill the buffer, fill up with EOF
    if(len<buff->bufferlength)
      for(int i=len;i<buff->bufferlength;i++)	
	buff->buffer[i]=EOF;  //Accessing like an array!
    return len;
  }
  
}

void cr_close(cr_file* f){
  free(f->buffer);
  close(f->file);
}


cr_file* cr_open(char * filename, int buffersize)
  {

  int f;
  if ((f = open(filename, O_RDONLY)) < 0){ //Opens a file in read_only, while oppening a file the value changes to non-negative.
    printf("Cannot open %s\n", filename);
    return 0;
  }

  cr_file* a=(cr_file*)malloc(sizeof(cr_file));
  a->file=f;
  a->bufferlength=buffersize;
  a->usedbuffer=buffersize; //Start off with no characters, so refill will work as expected
  a->buffer=(char*)malloc(sizeof(char)*buffersize);

  refill(a);
  return a;
}

//------------------------------------------------------------------
char cr_read_byte(cr_file* f){
  // your code goes here
  if (f->usedbuffer>= f->bufferlength)//Buffer check, if it's at the end of the buffer - refill
  {
    refill(f);
  }
  return f->buffer[f->usedbuffer++];//Returns the next character in the buffer
  // remember that this needs to return a char (a byte, put another way..)
  return EOF; // this is just so the compile works...
}



