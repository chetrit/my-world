/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** getnbr
*/

static int calc_number(char **str, int nb, int neg)
{
    int isneg = 0;

    if (neg == -1)
        isneg = 1;
    nb = *(*str)++ - '0';
    while (**str >= '0' && **str <= '9') {
        if (nb >= 214748264 && (**str - '0') > (7 + isneg)) {
            nb = 0;
            break;
        }
        nb = nb * 10 + (*(*str)++ - '0');
    }
    return (nb);
}

int my_getnbr_mvptr(char **str)
{
    int nb = 0;
    int neg = 1;

    while (**str < '0' || **str > '9') {
        if (**str != '-' && **str != '+')
            return (0);
        if (**str == '-')
            neg *= -1;
        (*str)++;
    }
    nb = calc_number(str, nb, neg);
    return (neg * nb);
}
