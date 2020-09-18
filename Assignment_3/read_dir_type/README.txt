This C program is used for identifying what type of a file it is
This program strictly takes input through command line argument
It takes directory name through cmd line argument and returns file names and their types,e.g:pipe or FIFO,regular file,socket,etc.
Here i have used Stat structure i.e internally provided in OS and used the readir() to read the directory name and opendir(0 to open the directory specified by user
Then taking name from the readdir using d_name we pass it to the function recursively through loop and print the file name and its type.
There is probably a bug or mistake done here by me that i have removed default case for switch which was file not recognized coz it always entered default.
For recognising the file type we use stat structures st_mode and S_IFMT to get bit for mode value and print according to it if the bit masks are for the specified file like S_IFIFO or S_IFSOCK and if they return 1 then print the corresponding printf
These programs are Linux specific and I used Ubuntu Linux 18.04 to execute them and can be used by you for modification or making copy and distribution of it.
Thank You. 
