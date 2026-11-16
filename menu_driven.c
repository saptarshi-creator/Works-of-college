#include <stdio.h>
#include <stdlib.h>
int main() {
    int choice, a[10], n,i,insert, ele;

    //Creation of an array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    } 

    //printing the array
    printf("The elements of the array are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    //Menu-driven program 
    do {
        printf("Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Find the maximum element\n");
        printf("4. Find the minimum element\n");
        printf("5. Sorting the array\n");
        printf("6. Binary Search\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You selected Option 1.\n");
                printf("Enter the element to insert: ");
                scanf("%d", &insert);
                printf("Enter your element: ");
                scanf("%d", &ele);
                if(insert < 1 || insert > n + 1) {
                    printf("Invalid position. Please try again.\n");
                } else {
                    for (i = n; i >= insert; i--) {
                        a[i] = a[i - 1];
                    }
                    a[insert - 1] = ele;
                    n++;
                    printf("Element inserted successfully.\n");
                    printf("The elements of the array are: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break;
            case 2:
                printf("You selected Option 2.\n");
                printf("Enter the position of the element to delete: ");
                scanf("%d", &insert);
                if(insert < 1 || insert > n) {
                    printf("Invalid position. Please try again.\n");
                } else {
                    for (i = insert - 1; i < n - 1; i++) {
                        a[i] = a[i + 1];
                    }
                    n--;
                    printf("Element deleted successfully.\n");
                    printf("The elements of the array are: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                printf("You selected Option 3.\n");
                int max = a[0];
                for (i = 1; i < n; i++) {
                    if (a[i] > max) {
                        max = a[i];
                    }
                }
                printf("The maximum element in the array is: %d\n", max);
                break;
            case 4:
                printf("You selected Option 4.\n");
                int min = a[0];
                for (i = 1; i < n; i++) {
                    if (a[i] < min) {
                        min = a[i];
                    }
                }
                printf("The minimum element in the array is: %d\n", min);
                break;
            case 5:
                printf("You selected Option 5.\n");
                //Sorting the array using bubble sort
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (a[j] > a[j + 1]) {
                            int temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }
                printf("The array after sorting is: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            case 6:
                printf("You selected Option 6.\n");
                int key, low = 0, high = n - 1, mid;
                int found = 0;
                if(n == 0) {
                    printf("Array is empty. Cannot perform binary search.\n");
                    break;
                }
                for(i = 0; i < n - 1; i++) {
                    for(int j = 0; j < n - i - 1; j++) {
                        if(a[j] > a[j + 1]) {
                            int temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }
                printf("Enter the element to search: ");
                scanf("%d", &key);
                while(low <= high) {
                    mid = (low + high) / 2;
                    if(a[mid] == key) {
                        found = 1;
                        break;
                    } else if(a[mid] < key) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if(found) {
                    printf("Element found at position %d.\n", mid + 1);
                } else {
                    printf("Element not found.\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}