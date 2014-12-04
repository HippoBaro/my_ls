/*
** sorting_alpha.c for my_ls in /home/barrau_h/Desktop/PSU_2014_my_ls/sorting
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 30 15:45:06 2014 Hippolyte Barraud
** Last update Sun Nov 30 16:05:37 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

static char *make_case_insensitive(const char *str)
{
  int i;
  char *out;

  out = my_strdup(str);
  i = 0;
  while (out[i] != '\0')
    {
      if (out[i] >= 'A' && out[i] <= 'Z')
        out[i] += 32;
      i++;
    }
  return (out);
}

int cmp_str(const char *str1, const char *str2)
{
  char *dup1;
  char *dup2;
  int out;

  dup1 = make_case_insensitive(str1);
  dup2 = make_case_insensitive(str2);
  out = my_strcmp(dup1, dup2);
  free(dup1);
  free(dup2);
  return (out);
}
