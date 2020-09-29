#include<stdio.h>

int main(int argc,char *argv[]) {
  char buffer[50]; // Buffer to store data
  FILE * stream;
  int i=argv[1]-'0';
  buffer[i+1]='\0';
  
  stream = fopen("new.txt", "r");
  int count = fread(&buffer, sizeof(char), argv[1], stream);
  fclose(stream);
  // Printing data to check validity
  printf("Data read from file: %s \n", buffer);
  return 0;
}
