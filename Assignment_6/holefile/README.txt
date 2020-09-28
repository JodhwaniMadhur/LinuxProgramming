this C program is used to demonstrate the concept of hole in the file,here we create a hole of one kb inside the file and write a letter after that hole because if we don't write at the end of it then it is not a whole,though after executing this program on Ubuntu Linux the file can't be opened so u can use the command cat <file name> or od -c <file Name> to print the file on terminal and see '\0' or your data and then the last letter written after hole,in this case it is 'z' and the file size increases if u see it in properties of the file.
input parameters:file name
input type:command line
output type:file

This program was compiled and executed on September 28 2020 on Linux(ubuntu 18.04LTS) and is available for free use and distribution.
