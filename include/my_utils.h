/*
** EPITECH PROJECT, 2020
** my_world
** File description:
** my utils header
*/

#ifndef MY_UTILS_H_
#define MY_UTILS_H_

char *my_strncat(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
void mem_init(char *str, int len);
int my_strlen(const char *str);
int my_putstr(const char *str);
int my_putstr_fd(const char *str, int fd);
char *my_string_merge(char *str1, char *str2);
void my_putnbr_in_str(int nb, char *str);
int my_getnbr(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char *str);
char *get_last_occ_slash(char *str);
int my_getnbr_mvptr(char **str);
void my_putnbr_in_end_str(int nb, char *str);

#endif /* !MY_UTILS_H_ */
