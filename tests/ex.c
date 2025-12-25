
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// size_t ft_strcspn(const char *s, const char *reject)
// {
//     size_t counter = 0;

//     while (*s)
//     {
//         const char *tmp = reject;

//         while (*tmp)
//         {
//             if (*s == *tmp)
//                 return counter;
//             tmp++;
//         }

//         counter++;
//         s++;
//     }

//     return counter;
// }

size_t ft_strlen(char *str){
    int length;

    length = 0;
    while (*str){
        length ++;
        str ++;
    }
    return (length);
}

// int is_power_of_2(unsigned int n)
// {
//     if (n == 0)
//         return 0;

//     while (n % 2 == 0) 
//         n = n / 2;


//     return (n == 1);
// }


#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 7;               // نبدأ من البت الأعلى
    while (i >= 0)            // نكرر لكل البتات
    {
        char bit = ((octet >> i) & 1) + '0'; // استخراج البت وتحويله لحرف '0' أو '1'
        write(1, &bit, 1);    // طباعة البت
        i--;
    }
    write(1, "\n", 1);        // سطر جديد بعد الطباعة
}

unsigned char	reverse_bits(unsigned char octet){
    int i = 7;
    unsigned char result;

    result = 0;
    while (i >= 0){
        result = result * 2 + (octet % 2);
        octet = octet / 2;
    }
    return result;
}


void    ft_union(char *s1, char *s2)
{
    int used[256] = {0};
    int i = 0;
    while (s1 && s1[i]){
        if (used[(unsigned char)s1[i]] == 0){
            used[(unsigned char)s1[i]] = 1;
            write (1, &s1[i], 1);
        }
        i++;
    }
    i = 0;

    while (s2 && s2[i]){
        if (used[(unsigned char)s2[i]] == 0){
            used[(unsigned char)s2[i]] = 1;
            write (1, &s2[i], 1);
        }
        i++;
    }
}

#include <unistd.h>

int wdmatch(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s2[j] && s1[i])
    {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return (s1[i] == '\0');
}


int add_prime_sum(int nb){
    int i;
    int j;
    int is_prime;
    int sum;

    if (nb < 2)
        return(0);
    sum = 0;
    i = 2;
    while (i <= nb){
        is_prime = 1;
        j = 2;
        while (j * j <= i){
            if (i % j == 0){
                is_prime = 0;
                break;
            }
            j++;
        }
        if (is_prime)
            sum += i;
        i++;
    }
    return (sum);
}



void	ft_epur_str(char *str)
{
	int first_word = 1;

	while (*str)
	{
		if (*str != ' ' && *str != '\t') 
		{
			if (!first_word) 
				write(1, " ", 1);
			while (*str && *str != ' ' && *str != '\t') 
			{
				write(1, str, 1);
				str++;
			}
			first_word = 0;
		}
		else 
			str++;
	}
}


int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void ft_expand_str(char *str)
{
    int i = 0;
    int first_word = 1;

    while (str[i])
    {
        // Skip spaces and tabs
        while (str[i] && is_space(str[i]))
            i++;
        if (!str[i])
            break;

        // Print word
        if (!first_word)
            write(1, "   ", 3); // three spaces between words
        first_word = 0;

        while (str[i] && !is_space(str[i]))
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}



int main(int argc, char **argv)
{
    int i;

    if (argc == 2)
    {
        ft_epur_str(argv[1]);
        
    }
    write(1, "\n", 1);
    return (0);
}









// int wdmatch(char *s1, char *s2){
//     while (*s1 && *s2){
//         if (*s2 == *s1)
//             s1++;
//         s2++;
//     }
//     return (*s1 == '\0');
// }