/*
** helper_flag.c for my_printf in /home/barrau_h/Desktop/my_printf
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 16 22:26:26 2014 Hippolyte Barraud
** Last update Sun Nov 16 23:18:47 2014 Hippolyte Barraud
*/

#include"../include/my_printf.h"

t_format	*get_flag(const char **format)
{
  int		i;
  static t_format flags[] =
    {
      { 's', TYPE_STRING, 0, FALSE, 'a', FALSE },
      { 'S', TYPE_STRING, 0, FALSE, 'a', TRUE},
      { 'd', TYPE_NUMBER, 10, TRUE, 'a', FALSE },
      { 'u', TYPE_NUMBER, 10, FALSE, 'a', FALSE },
      { 'o', TYPE_NUMBER, 8, FALSE, 'a', FALSE },
      { 'x', TYPE_NUMBER, 16, FALSE, 'a', FALSE },
      { 'X', TYPE_NUMBER, 16, FALSE, 'A', FALSE },
      { 'p', TYPE_NUMBER, 16, FALSE, 'A', FALSE },
      { 'c', TYPE_CHAR, 0, FALSE, 'A', FALSE },
      { 'b', TYPE_NUMBER, 2, FALSE, 'A', FALSE }
    };

  i = 0;
  if ((**format == 'h' || **format == 'l') && *(*format + 1) == 'd')
    {
      (*format)++;
      return (&flags[2]);
    }
  while (i < 10)
    {
      if (**format == flags[i].flag)
	return (&flags[i]);
      i++;
    }
  return (NULL);
}

int		treat_flag(const char **format, int width, int pad, va_list args)
{
  t_format	*flag;
  int		pc;

  pc = 0;
  flag = get_flag(format);
  if (flag != NULL)
    {
      if (flag->flag == 'p')
	{
	  width = 8;
	  pad = PAD_ZERO;
	}
      pc += print_data_from_list(flag, args, width, pad);
    }
  else
    {
      pc += print_char_formatted('%', 1, 0);
      pc += print_char_formatted(**format, width, pad);
    }
  return (pc);
}

int	detect_flag(const char *format, va_list args)
{
  int		width;
  int		pad;
  int		pc;

  pc = 0;
  while (*format != 0)
    {
      if (*format == '%')
	{
	  format++;
	  if (*format == '%')
	    continue;
	  width = pad = 0;
	  treat_format(&format, &pad, &width);
	  pc += treat_flag(&format, width, pad, args);
	}
      else
	pc += printchar (*format);
      format++;
    }
  return (pc);
}
