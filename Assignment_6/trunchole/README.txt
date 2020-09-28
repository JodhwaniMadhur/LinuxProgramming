This C program is used to demonstrate the file hole and truncate function 
Here we check the file size and then if the file size is greater than 1kb we truncate it to 1kb and if it is less than 1kb we create a hole big enough to make the file size = to 1025 i.e lseek till 1kb and write one byte after it.
input type:cmd line
input type:directory name
output type:file
To check if it works or not do check the file size after execution.
Here we use stat structure to get the info of a file and dirent and DIR pointer so that we can open and read directory and apply stat function ot each file using loop
and then using st-size to check file size and using conditional statements for doing the truncate or hole creation.
This program was performed on Ubuntu Linux(18.04) on 28 Sep 2020 and is available for free distribution and usage.
