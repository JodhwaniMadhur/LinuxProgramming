This program is used to create a daemon process,it is a process which runs till the OS doesn't shut down and if it is forced to
shut,it restarts again(only applicable to OS/kernel processes).Int this case it will shut if tried to shut forcefully since it is
not a kernel process.

In this program we first create a process using fork and then we create session using setsid and then are stopping that process from taking any input or displaying any output i.e 
closing it's input and output stream and later on we seperate it from parent,here for making it daemon we are using while(1) loop
and this loops runs infinitely.This process doesn't do much except printing Process is running every 2 sec inside a file till it is shut.
This program was written on 22 December 2020 on LINUX Ubuntu 20.04 LTS and executed on the same,for this program to run properly you need to create a Log.txt
file seperately in the same folder as the .exe file and then the process will write into the Log.txt file every 2 seconds.
Thank You.