THis function is used to print thread priority of the threads and to show the changing of thread priorities
however changing it's priority is risky and can resut in illfunction and should be avoided.

INPUT:thread,inbuilt structure that holds thread scheduling details and an integer 
OUTPUT:Prints the thread priority that we hold from the pthread_getschedparam that takes all the above input and returns priority

for changing priority:
Input:Integer for setting priority
output:None,but can print priority

we use nice function to take in the integer and change thread's priority.