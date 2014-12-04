/*
** my_printf.h for my_printf in /home/barrau_h/Desktop/my_printf
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 16 21:54:20 2014 Hippolyte Barraud
** Last update Sun Nov 16 23:15:51 2014 Hippolyte Barraud
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

enum {PAD_RIGHT = 1, PAD_ZERO = 2};
enum {TYPE_STRING = 1, TYPE_NUMBER = 2, TYPE_CHAR = 3};
enum {FALSE = 0, TRUE = 1};
typedef struct
{
  char flag;
  int type;
  int base;
  int signed_bool;
  char maj;
  int print_hidden;
}t_format;

void	my_putchar(int c);
int     my_strlen(const char *str);
int printchar(char c);

int handle_format(char *string, int *width, int *pad);
int print_string(char *string, int width, int pad, int display_octo);
char *convert_to_base(unsigned int value, int base, int format, char *out);
inline char *print_neg(int *width, int pad, int *pc, char *out);
int print_digits(int value, int base, int signed_bool, int width, int pad,
		 int format);
t_format *get_flag(const char **format);
int print_char_formatted(char c, int width, int pad);
void treat_format(const char **format, int *pad, int *width);
int print_data_from_list(t_format *flag, va_list args, int width, int pad);
int treat_flag(const char **format, int width, int pad, va_list args);
int detect_flag(const char *format, va_list args);
int my_printf ( const char * format, ... );

#endif
