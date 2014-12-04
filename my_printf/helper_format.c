/*
** helper_format.c for my_printf in /home/barrau_h/Desktop/my_printf
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 16 22:22:46 2014 Hippolyte Barraud
** Last update Sun Nov 16 23:23:18 2014 Hippolyte Barraud
*/

#include"../include/my_printf.h"

void	treat_format(const char **format, int *pad, int *width)
{
  while (**format == ' ')
    (*format)++;
  if (**format == '-')
    {
      (*format)++;
      *pad = PAD_RIGHT;
    }
  while (**format == '0')
    {
      (*format)++;
      *pad |= PAD_ZERO;
    }
  while (**format >= '0' && **format <= '9')
    {
      *width *= 10;
      *width += **format - '0';
      (*format)++;
    }
}

int	handle_format(char *string, int *width, int *pad)
{
  int	len;
  int	padchar;
  int	pc;

  pc = 0;
  padchar = ' ';
  if (*width > 0)
    {
      len = my_strlen(string);
      if (len >= *width)
	*width = 0;
      else
	*width -= len;
      if (*pad == PAD_ZERO)
	padchar = '0';
    }
  if (*pad != PAD_RIGHT)
    {
      while (*width > 0)
	{
	  pc += printchar (padchar);
	  (*width)--;
	}
    }
  return (pc);
}

char	*convert_to_base(unsigned int value, int base, int format, char *out)
{
  int	t;

  while (value)
    {
      t = value % base;
      if (t >= 10)
	t += format - '0' - 10;
      *--out = t + '0';
      value /= base;
    }
  return (out);
}

inline char	*print_neg(int *width, int pad, int *pc, char *out)
{
  if (*width && (pad == PAD_ZERO))
    {
      printchar ('-');
      (*pc)++;
      --(*width);
    }
  else
    *--out = '-';
  return (out);
}
