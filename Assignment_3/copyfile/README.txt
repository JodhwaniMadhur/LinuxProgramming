This program is used to copy contents from one file to another and it takes instructions strictly through command line arguments where:
argv[1]=source file (contents to be copied from)
argv[2]=destination file (Contents to be copied to)
this file uses write and read function and i have used buffer of 10 to transport data from source to destination
I have opened source file in Read Mode and dest file in Write+Append mode which sets offset to end of file and
starts writing from there incase there is data that is already present in the dest file.
These programs are Linux specific and I used Ubuntu Linux 18.04 to execute them and can be used by you for modification or making copy and distribution of it.
Thank You. 
