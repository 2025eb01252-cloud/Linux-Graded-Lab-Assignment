#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    int fd;

    struct Employee emp1 = {101, "Pavan", 50000};
    struct Employee emp2 = {102, "John", 60000};
    struct Employee emp3 = {103, "Mary", 70000};

    fd = open("employees.dat", O_RDWR | O_CREAT, 0644);

    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    write(fd, &emp1, sizeof(emp1));
    write(fd, &emp2, sizeof(emp2));
    write(fd, &emp3, sizeof(emp3));

    printf("Employee records written.\n");

    struct Employee updatedEmp = {102, "John", 65000};

    lseek(fd, sizeof(struct Employee), SEEK_SET);

    write(fd, &updatedEmp, sizeof(updatedEmp));

    printf("Employee record updated.\n");

    struct Employee retrieved;

    lseek(fd, 2 * sizeof(struct Employee), SEEK_SET);

    read(fd, &retrieved, sizeof(retrieved));

    printf("\nRetrieved Employee Record:\n");
    printf("ID: %d\n", retrieved.id);
    printf("Name: %s\n", retrieved.name);
    printf("Salary: %.2f\n", retrieved.salary);

    close(fd);

    return 0;
}
