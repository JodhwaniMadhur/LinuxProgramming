This C program was build to display the file which has largest size inside a directory but if there is no file and a directory it displays 4096 i.e 4KB for directory.
In this program i have used stat structure and taken size from it using st_size and taken long long int for comparison since it returns size in bytes,
here we check if the size is greater than the previous highest file size and if yes we assign that to m variable or else if not we just discard it and move on.
in the end we print the m variable.
These programs are Linux specific and I used Ubuntu Linux 18.04 to execute them and can be used by you for modification or making copy and distribution of it.
Thank You. 
