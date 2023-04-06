#include <math.h>
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    int length = (int)floor(log10(x)) + 1;
    int arr[length];
    int i = 0;
    do
    {
        arr[i] = x % 10;
        x /= 10;
        i++;
    } while (x != 0);
    for (int i = 0; i <= length / 2 - 1; i++)
    {
        if (arr[i] != arr[length - 1 - i])
            return false;
    }

    return true;
}