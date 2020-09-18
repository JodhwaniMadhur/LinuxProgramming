This C program is used for used for deleting the files that have zero bytes i.e are empty files inside a directory.
Here i have used opendir() function to open directory and then readdir(0 function to read the directory through D_name which gives file names from directory.
Also using stat structure and using it's internal function of st_size which return size of the file i have used system call of unlink to unlink i.e rm function internally,
to delete the file that has st_size == 0 inside loop,if file has more than 1 link then it deletes 1 link of it.
These programs are Linux specific and I used Ubuntu Linux 18.04 to execute them and can be used by you for modification or making copy and distribution of it.
Thank You. 
