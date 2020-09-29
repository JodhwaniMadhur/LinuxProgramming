This C program is simple and is used to demonstrate the concept to open a file and display it's file descriptor.
Here we use open system call to open the file and we pass it the file name and mode in which we want to open the file,since here we do not perform any operations but providing a mode is 
necessary so we provide read mode(O_RDONLY) to the file and then after displaying fd on succesfull open call we close the file or else display error message if unsuccessfull.
Input Parameter:File Name
Input Type:Command Line
Output Type:Standard Output.
Output:On success display file descriptor else display error message.
This program was compiled and executed by me on UBUNTU 18.04 LTS on 29 September 2020.
