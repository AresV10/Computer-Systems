#include "challenge.h"

// goal: copy nlines lines from rfile to wfile
// param rfile: name of file to read from
// param wfile: name of file to write to
// param nlines: number lines to copy
// return: error code
//   0 if no issues
//   -1 if error in opening or closing file
//
// TODO: complete the function
//   1. open files. do NOT open wfile in append mode (don't forget error checking)
//   2. copy the n lines (beware nline > number of lines in rfile)
//   3. close files
int copy(const char* rfile, const char* wfile, int nlines)
{
  FILE *fileR;
  FILE *fileW;
  fileR = fopen(rfile,"r");
  fileW = fopen(wfile,"w");

  if(fileR == NULL || fileW == NULL){
    return -1;
  }
  char ch = fgetc(fileR);
  int countLines = 0;

  while(ch != EOF & countLines<nlines){
    if(ch == '\n')
      countLines++;
    putc(ch,fileW);
    ch = getc(fileR);
  }

  //fputs(buffer, fileR);

  fclose(fileR);
  fclose(fileW);

  return 0;
}
