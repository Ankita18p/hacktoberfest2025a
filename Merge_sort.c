#include<stdio.h>

void mergeSort(int a[], int lb, int ub);
void merge(int a[], int lb, int mid, int ub);

int main() 
{
    int n = 0;
    int a[100]; 

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > 100) 
	{
        printf("Error: Number of elements exceeds array size.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }

    printf("The original array is:");
    for (int i = 0; i < n; i++) 
	{
        printf("\t%d", a[i]);
    }
    printf("\n");

    mergeSort(a, 0, n - 1);

    printf("The sorted array is:");
    for (int i = 0; i < n; i++) 
	{
        printf("\t%d", a[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(int a[], int lb, int ub) 
{
    if (lb < ub) 
	{
        int mid = lb + (ub - lb) / 2; 
        mergeSort(a, lb, mid);          
        mergeSort(a, mid + 1, ub);      
        merge(a, lb, mid, ub);         
    }
}

void merge(int a[], int lb, int mid, int ub) 
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[100]; 

    while (i <= mid && j <= ub) 
	{
        if (a[i] <= a[j]) 
		{
            b[k] = a[i];
            i++;
        } else 
		{
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) 
	{
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub) 
	{
        b[k] = a[j];
        j++;
        k++;
    }

    for (int l = lb; l <= ub; l++) 
	{
        a[l] = b[l];
    }
}
