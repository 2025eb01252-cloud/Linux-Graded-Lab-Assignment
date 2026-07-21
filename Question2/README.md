# Question 2 - Process Monitoring and Zombie Prevention

## Objective
Develop a C program that creates child processes, monitors execution, prevents zombie processes, and terminates unresponsive child processes.

## Process Creation
The parent process creates a child process using fork().

## Monitoring
The parent monitors the child process and checks whether it is still running.

## Signal Handling
If the child process becomes unresponsive, the parent sends SIGKILL using kill().

## Zombie Prevention
The parent uses waitpid() to collect the child process exit status and prevent zombie processes.

## Compilation

```bash
gcc process_monitor.c -o process_monitor

