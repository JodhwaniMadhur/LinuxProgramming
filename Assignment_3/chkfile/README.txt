This program is used for reading the contents inside a directory using readdir()
for this we need to first open directory using opendir() and then use a loop for the to be read from readdir() and then using stat structure function of OS,
we pass the file to be checked to stat and if file is present it return zero else it will return 1 if file is not present.
These programs are Linux specific and I used Ubuntu Linux 18.04 to execute them and can be used by you for modification or making copy and distribution of it.
Thank You. 
