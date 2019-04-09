#include <fcntl.h> //Define header files
#include <stdlib.h>
#include <unistd.h>  
#include <stdio.h>

#define BUF_SIZE 500    	//Define Buffer size as 500.
#define OUTPUT_MODE 0700	//Define file permission.

int main(int argc, char *argv[]) //Main function
{
  int in_fd, out_fd; // define input and output files
  int rd_size = 1, wr_size; //Declare read and write sizes
  char buf[BUF_SIZE];  //Declare buffer.
  int characters = 0;
  int x;
  int word_count = 0;
  int sent_count = 0
  int times_filled = 0;
  int max = 0;


  if (argc != 3)// if argumet size is not 3 - exit the program
  {
    printf("No three arguments were found!\n");
	  exit(1);
  }


  in_fd = open(argv[1], O_RDONLY); //Open input file
    if (in_fd < 0)//If the output file cannot be oppened, in_fd will be negative, hence display error and exit
    {
      printf("Input file not found!\n");
      exit(2);
    }


  out_fd = creat(argv[2], OUTPUT_MODE); //Create output file.
    if (out_fd < 0)//If the file cannot be created, the out_fd will fall to negative
    {
      printf("Cannot create output file!\n");
      exit(3);


  while (rd_size > 0)// While read size is higher than none, do loop
  { 


    rd_size = read(in_fd, buf, BUF_SIZE);// Read from input file into buffer.

      if (rd_size<0)//if there is nothing to read:
      {
        printf("There is nothing to read!\n");
        exit(4);
      }


    wr_size = write(out_fd, buf, rd_size); // Write from buffer into output file.
      if (wr_size<=0)//if there are nothing to write:
      { 
        close(in_fd); //Close input file
        close(out_fd); //Close output file
        printf("File was succesfully created!\n")
        exit(5); //Exit the program
      }

  }



}
