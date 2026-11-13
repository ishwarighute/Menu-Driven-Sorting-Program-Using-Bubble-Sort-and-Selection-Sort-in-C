#include <stdio.h>

// Function for Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function for Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to display array
void displayArray(int arr[], int n)
{
    int i;

    printf("\nSorted Array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Main Function
int main()
{
    int arr[100];
    int n, choice, i;

    printf("================================\n");
    printf("     MENU-DRIVEN SORTING PROGRAM\n");
    printf("================================\n");

    printf("\nEnter the number of elements (1-100): ");
    
    if (scanf("%d", &n) != 1 || n < 1 || n > 100)
    {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("\nEnter %d numbers:\n", n);

    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }
    }

    do
    {
        printf("\n========== SORTING MENU ==========\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Exit\n");
        printf("==================================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                bubbleSort(arr, n);
                printf("\nBubble Sort Selected!");
                displayArray(arr, n);
                break;

            case 2:
                selectionSort(arr, n);
                printf("\nSelection Sort Selected!");
                displayArray(arr, n);
                break;

            case 3:
                printf("\nThank you for using the program!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1, 2 or 3.\n");
        }

    } while (choice != 3);

    return 0;
}