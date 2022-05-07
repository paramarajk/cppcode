/*
fork() in C

Fork system call use for creates a new process, which is called child process,
which runs concurrently with process (which process called system call fork) 
and this process is called parent process. After a new child process created, 
both processes will execute the next instruction following the fork() system call. 
A child process uses the same pc(program counter), same CPU registers, 
same open files which use in the parent process.

It takes no parameters and returns an integer value. Below are different values returned by fork().

Negative Value: creation of a child process was unsuccessful.
Zero: Returned to the newly created child process.
Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
*/

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main()
{

	// make two process which run same 
	// program after this instruction 
	fork();

	printf("Hello world!\n");
	return 0;
}

/*o/p: 
Hello world!
Hello world!
*/

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main()
{
	fork();
	fork();
	fork();
	printf("hello\n");
	return 0;
}
/*
hello
hello
hello
hello
hello
hello
hello
hello

Number of times hello printed is equal to number of process created.
Total Number of Processes = 2n where n is number of fork system calls. So here n = 3, 23 = 8
fork ();   // Line 1
fork ();   // Line 2
fork ();   // Line 3

	   L1       // There will be 1 child process
	/     \     // created by line 1.
  L2      L2    // There will be 2 child processes
 /  \    /  \   //  created by line 2
L3  L3  L3  L3  // There will be 4 child processes
				// created by line 3

*/
//-----------------------------------------------------
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
void forkexample()
{
	// child process because return value zero 
	if (fork() == 0) {
		printf("Hello from Child!\n");
		printf("fork 0: Get pid: %d\n", getpid());
	}

	// parent process because return value non-zero. 
	else {
		printf("Hello from Parent!\n");
		printf("fork 1: Get pid: %d\n", getpid());
	}
}
int main()
{
	printf("Main: Get pid: %d\n", getpid());
	forkexample();
	return 0;
}
/*
Main: Get pid: 14380
Hello from Parent!
fork 1: Get pid: 14380
Main: Get pid: 14380
Hello from Child!
fork 0: Get pid: 14381

In the above code, a child process is created, fork() returns 0 in the
child processand positive integer to the parent process.
Here, two outputs are possible because the parent processand child process are running concurrently.
So we don’t know if OS first give control to which process a parent process or a child process.

Important: Parent processand child process are running the same program, 
	but it does not mean they are identical.OS allocate different dataand state f
	or these two processesand also control the flow of these processes can be different.See next example
//-----------------------------------------------------*/

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void forkexample()
{
	int x = 1;

	if (fork() == 0)
		printf("Child has x = %d\n", ++x);
	else
		printf("Parent has x = %d\n", --x);
}
int main()
{
	forkexample();
	return 0;
}

/*
Parent has x = 0
Child has x = 2
	 (or)
Child has x = 2
Parent has x = 0

Here, global variable change in one process does not affected two other processes 
because data/state of two processes are different. 
And also parent and child run simultaneously so two outputs are possible.
//-----------------------------------------------------*/


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int n = 10;
	pid_t pid = fork(); //creating the child process
	if (pid == 0)          //if this is a chile process
	{
		n++;
		printf("Child process started : %d : %d\n", pid, getpid());
	}
	else//parent process execution
	{
		n--;
		printf("Now i am coming back to parent process : %d : %d\n", pid, getpid());
	}
	printf("value of n: %d \n", n); //sample printing to check "n" value
	return 0;
}

/*
Output:-

Now i am coming back to parent process : 3487 : 3486
value of n: 9
Child process started : 0 : 3487
value of n: 11
*/

/*

exec family of functions in C

The exec family of functions replaces the current running process with a new process. 
It can be used to run a C program by using another C program. It comes under the header file unistd.h. 
There are many members in the exec family which are shown below with examples.

	execvp : Using this command, the created child process does not have to run the same program as the parent process does. 
	The exec type system calls allow a process to run any program files, which include a binary executable or a shell script .
	Syntax:

	int execvp (const char *file, char *const argv[]);

	file: points to the file name associated with the file being executed.
	argv:  is a null terminated array of character pointers.

	Let us see a small example to show how to use execvp() function in C. We will have two .C files ,
	EXEC.c and execDemo.c and we will replace the execDemo.c with EXEC.c by calling execvp() function in execDemo.c .
*/

//EXEC.c

#include<stdio.h>
#include<unistd.h>

int main()
{
	int i;

	printf("I am EXEC.c called by execvp() ");
	printf("\n");

	return 0;
}

Now,create an executable file of EXEC.c using command

gcc EXEC.c -o EXEC


//execDemo.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
		//A null terminated array of character
		//pointers
		char *args[]={"./EXEC",NULL};
		execvp(args[0],args);

		//All statements are ignored after execvp() call as this whole
		//process(execDemo.c) is replaced by another process (EXEC.c)
printf("Ending-----");

return 0;
}

/*Now, create an executable file of execDemo.c using command

gcc execDemo.c - o execDemo

After running the executable file of execDemo.cby using command ./excDemo, we get the following output:

I AM EXEC.c called by execvp()

When the file execDemo.c is compiled, as soon as the statement execvp(args[0],args) is executed, 
this very program is replaced by the program EXEC.c. “Ending—–” is not printed because because as soon as the execvp() 
function is called, this program is replaced by the program EXEC.c.
*/

