# signals_task
In this task we calling signals in a loop.
Creators:
Yarin Hindi - Adiel Ben Meir

# To run the program do as following
- Download the code.
- compile with gcc main.c -o mains
- run ./mains

# The signals loop logic
In the main we creating a zombie process - so the SIGCHLD case turns on.
- 1 Now we are in the SIGCHLD case and we raise SIGUSR1 so the SIGUSR1 turns on..
- 2 Now we are in the SIGUSR1 case and we dividing by 0 so the SIGFPE signal turns on.
- 3 Now we are in the SIGFPE case and we giving out variable p a invalid adress memory reference so the SIGSEGV signal turns on.
- 4 Now we are in the SIGSEGV case and we calling abort() so the SIGABRT signal turns on.
- 5 Now we are in the SIGABRT case and we giving system a invalid commans so the SIGSYS signal turns on.
- 6 Now we are in the SIGSYS case and we exiting.


