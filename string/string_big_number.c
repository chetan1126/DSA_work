#include <stdio.h>
#include <string.h>

int main()
{
    int n, arr[10], temp;
    char result[100] = "";
    char str[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Bubble Sort based on last digit
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if((arr[j] / 10)%10 < arr[j + 1] % 10)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Convert numbers to string and concatenate
    for(int i = 0; i < n; i++)
    {
        sprintf(str, "%d", arr[i]);
        strcat(result, str);
    }

    printf("%s\n", result);

    return 0;
}