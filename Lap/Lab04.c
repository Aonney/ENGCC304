#include <stdio.h>

int main() {
    long long employeeID = 68543210077 - 2;
    double salary = 120000.00;

    printf("Expected Output:\n");
    printf("Employees ID = %lld\n", employeeID);
    printf("Salary = U$ %.2f\n", salary);

    return 0;
}

//case 2

#include <stdio.h>

int main() {
    char employeeID[11];
    int hours;
    double salaryPerHour, totalSalary;

    printf("Input the Employees ID(Max. 10 chars): \n");
    scanf("%10s", employeeID);

    printf("Input the working hrs: \n");
    scanf("%d", &hours);

    printf("Salary amount/hr: \n");
    scanf("%lf", &salaryPerHour);

    totalSalary = hours * salaryPerHour;

    printf("\nExpected Output:\n");
    printf("Employees ID = %s\n", employeeID);
    printf("Salary = U$ %.2lf\n", totalSalary);

    return 0;
}



