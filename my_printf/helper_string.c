/*
** helper_string.c for my_printf in /home/barrau_h/Desktop/my_printf
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 16 22:20:00 2014 Hippolyte Barraud
** Last update Sun Nov 16 23:19:18 2014 Hippolyte Barraud
*/

#include"../include/my_printf.h"

void	my_putchar(int c)
{
  write(1, &c, 1);
}

int     my_strlen(const char *str)
{
  int	pos;

  pos = 0;
  while (str[pos] != '\0')
    pos = pos + 1;
  return (pos);
}

int	printchar(char c)
{
  my_putchar(c);
  return (1);
}

int	print_string(char *string, int width, int pad, int display_octo)
{
  int	pc;
  int	padchar;

  padchar = ' ';
  pc = handle_format(string, &width, &pad);
  while (*string)
    {
      if (display_octo && (*string < 32 || *string >= 127))
	{
	  pc += printchar('\\');
	  pc += print_digits ((int)*string, 8, FALSE, 3, PAD_ZERO, 'a');
	  string++;
	  continue;
	}
      pc += printchar (*string);
      string++;
    }
  while (width > 0)
    {
      printchar (padchar);
      ++pc;
      --width;
    }
  return (pc);
}

int	print_char_formatted(char c, int width, int pad)
{
  char	scr[2];

  scr[0] = c;
  scr[1] = '\0';
  return (print_string (scr, width, pad, 0));
}
