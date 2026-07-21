# Question 3 - Secure File Processing Using Linux System Calls

## Objective
Develop a program that uses Linux system calls to create, update, and retrieve employee records efficiently.

## System Calls Used

### open()
Creates or opens the employee data file.

### write()
Writes employee records to the file.

### lseek()
Moves the file pointer directly to a specific employee record without reading the entire file.

### read()
Retrieves employee records from any location in the file.

### close()
Closes the file and releases system resources.

## Compilation

```bash
gcc employee_records.c -o employee_records
```

## Execution

```bash
./employee_records
```

## Sample Output

```text
Employee records written.
Employee record updated.

Retrieved Employee Record:
ID: 103
Name: Mary
Salary: 70000.00
```
