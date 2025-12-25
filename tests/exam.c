#include <unistd.h>

int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    char c;

    if (!str || str_base < 2 || str_base > 16)
        return 0;

    if (str[i] == '-')
        sign = -1, i++;
    else if (str[i] == '+')
        i++;

    while (str[i])
    {
        c = str[i];

        if (c >= '0' && c <= '9')
            c = c - '0';
        else if (c >= 'A' && c <= 'F')
            c = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            c = c - 'a' + 10;
        else
            break; 

        if (c >= str_base)
            break;

        result = result * str_base + c;
        i++;
    }

    return result * sign;
}

// void ft_print_hex(int nb){
//     char hex[] = "0123456789abcdef";
//     if (nb >= 16)
//         ft_print_hex(nb / 16);
//     write(1, &hex[nb % 16], 1);
// }


// int main(int ac, char **av){
//     if (ac == 2){
//         int i = 0;
//         unsigned int number;
//         number = 0;
//         while (av[1][i] >= '0' && av[1][i] <= '9'){
//             number = number * 10 + av[1][i] - '0';
//             i++;
//         }
//         ft_print_hex(number);
//     }
//     write (1, "\n",1);
//     return 0;
// }


#include <unistd.h>

int ft_atoi(char *str)
{
    int n = 0;

    while (*str >= '0' && *str <= '9')
    {
        n = n * 10 + (*str - '0');
        str++;
    }
    return n;
}

int pgcd(char *s1, char *s2)
{
    int a = ft_atoi(s1);
    int b = ft_atoi(s2);
    int tmp;

    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void ft_putnbr(int n)
{
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        ft_putnbr(pgcd(av[1], av[2]));
    }
    write(1, "\n", 1);
    return 0;
}

#include <stdlib.h>


int *ft_range(int start, int end){
    int *arr;
    int size;
    int i;

    if (start <= end)
        size = end - start + 1;
    else    
        size = start - end + 1; 
    arr = malloc (size * sizeof (int));
    if (!arr)
        return NULL;
    
    i = 0;
    if (start <= end){
        while (start <= end){
            arr[i] = start;
            start ++;
            i++;
        }
    }
    else {
        while (start >= end){
            arr[i] = start;
            start --;
            i++;
        }
    }
    return arr;
}
