#include "swap.h"

void neg_pos_rearrange(int arr[], int n)
{

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != flag)
                swap(&arr[i], &arr[flag]);
            flag++;
        }
    }
}