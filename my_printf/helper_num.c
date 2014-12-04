/*
** helper_num.c for my_printf in /home/barrau_h/Desktop/my_printf
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 16 22:25:17 2014 Hippolyte Barraud
** Last update Sun Nov 16 23:20:18 2014 Hippolyte Barraud
*/

#include"../include/my_printf.h"

int	print_digits(int value, int base, int signed_bool, int width,
		     int pad, int format)
{
  char	print_buf[4];
  register unsigned int u;
  register char *s;
  int	neg;
  int	pc;

  u = value;
  pc = 0;
  neg = 0;
  if (value == 0)
    {
      print_buf[0] = '0';
      print_buf[1] = '\0';
      return (print_string (print_buf, width, pad, 0));
    }
  if (signed_bool && base == 10 && value < 0)
    {
      neg = 1;
      u = -value;
    }
  s = print_buf - 4 + 1;
  s = convert_to_base(u, base, format, s);
  if (neg)
    s = print_neg(&width, pad, &pc, s);
  return (pc + print_string(s, width, pad, 0));
}

int	print_data_from_list(t_format *flag, va_list args, int width, int pad)
{
  int	pc;
  char	tab[2];
  char  *s;

  s = tab;
  pc = 0;
  if (flag->type == TYPE_NUMBER)
    pc += print_digits (va_arg(args, int), flag->base, flag->signed_bool,
			width, pad, flag->maj);
  else if (flag->type == TYPE_STRING)
    {
      s = (char *)va_arg(args, char *);
      pc += print_string (s?s:"(null)", width, pad, flag->print_hidden);
    }
  else
    {
      s[0] = (char)va_arg(args, int);
      s[1] = '\0';
      pc += print_string (s, width, pad, flag->print_hidden);
    }
  return (pc);
}
