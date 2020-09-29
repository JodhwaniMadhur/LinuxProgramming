This C program is used to demonstrate cat or od -c <file name> command of terminal,here i have performed the read file program through read argument and read it until EOF.
here we read from the file into buffer and from the buffer we print it on the screen through write system call of file i/o.
Input parameter:file name
input type:Command Line Argument
Output Type:Through write function
prototype:read(file name,buffer_name,sizeof(buffer))
		    write(1,buffer_name,sizeof(buffer));
		    
Here read call reads from the file into the buffer and reads sizeof(buffer) bytes into the buffer.
Write system call has been given parameter 1 i.e to write on Monitor i.e standard output and write from buffer and write sizeof(buffer) bytes on the screen and after this we clean buffer with 
memset and do the same task until read system call doesn't return 0;
read:returns no. of bytes read on success or -1 if failure
write:returns no. of bytes written on success and -1 if error.
This program was executed on UBUNTU 18.04 LTS on Sep 29 2020 and is available for free disribution,usage and execution.		    
