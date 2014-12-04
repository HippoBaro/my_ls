/*
** main.c for my_printf in /home/barrau_h/Desktop/my_printf
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 16 22:01:00 2014 Hippolyte Barraud
** Last update Sun Nov 16 23:18:04 2014 Hippolyte Barraud
*/

#include "../include/my_printf.h"

int		my_printf(const char *format, ...)
{
  va_list	args;
  int		ret;

  va_start(args, format);
  ret = detect_flag(format, args);
  va_end(args);
  return (ret);
}
