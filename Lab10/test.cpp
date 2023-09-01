#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sum1(int n)
{
    if (n < 1)
        return 0;
    return n + sum1(n - 1);
}

float Sum2(float n)
{
    if (n == 1)
        return 1;
    return 1 / (n * n) + Sum2(n - 1);
}

float Pi(float n)
{
    return sqrt(6 * n);
}

bool perfectNum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
        return true;
    return false;
}

void InputArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void OutputArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void FindMaxMin(int a[], int n)
{
    int max, min, iMax, iMin;
    iMax = iMin = 0;
    max = min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            iMax = i;
        }
        if (min > a[i])
        {
            min = a[i];
            iMin = i;
        }
    }
    printf("index of Max element: %d\n", iMax);
    printf("index of Min element: %d\n", iMin);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MovePositiveUpfront(int a[], int n)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            swap(&a[index], &a[i]);
            index++;
        }
    }
}

void OddEvenIndexIncrease(int a[], int n)
{
    if (n <= 1)
        return;

    for (int i = 1; i < n - 1; i += 2)
    {
        if (a[i] > a[n - 1])
            swap(&a[i], &a[n - 1]);
    }

    OddEvenIndexIncrease(a, n - 1);
}

bool symmetric(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - 1 - i])
            return false;
    }
    return true;
}

void question1()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    printf("%d", sum1(n));
}

void question2()
{
    while (1)
    {
        float n;
        printf("N: ");
        scanf("%f", &n);
        if (n < 1)
            return;
        printf("N\t\tPi\n");
        printf("%f\t%f\n", n, Pi(Sum2(n)));
    }
}

void question3()
{
    for (int i = 6; i < 1000; i++)
    {
        if (perfectNum(i))
            printf("%d\n", i);
    }
}

void question4()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    InputArr(a, n);
    OutputArr(a, n);
}

void question5()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    InputArr(a, n);
    FindMaxMin(a, n);
}

void question6()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    InputArr(a, n);
    printf("%d", symmetric(a, n));
}

void question7()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    InputArr(a, n);
    MovePositiveUpfront(a, n);
    OutputArr(a, n);
}

void question8()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    InputArr(a, n);
    OddEvenIndexIncrease(a, n);
    OutputArr(a, n);
}

int main()
{
    int number;
    printf("Input which question number (1 to 8): ");
    printf("1. Sum1\n");
    printf("2. Sum2\n");
    printf("3. Perfect Number\n");
    printf("4. Input and Output Array\n");
    printf("5. Find Max and Min\n");
    printf("6. Symmetric Array\n");
    printf("7. Move Positive Number Upfront\n");
    printf("8. Odd Even Index Increase\n");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        question1();
        break;
    case 2:
        question2();
        break;
    case 3:
        question3();
        break;
    case 4:
        question4();
        break;
    case 5:
        question5();
        break;
    case 6:
        question6();
        break;
    case 7:
        question7();
        break;
    case 8:
        question8();
        break;
    }

    return 0;
}
