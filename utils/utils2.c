/*
** utils2.c for my_ls in /home/barrau_h/Desktop/my_ls/utils
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 30 03:36:55 2014 Hippolyte Barraud
** Last update Sun Nov 30 03:52:43 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

char *my_strcat(char *dst, const char *src)
{
  char *ret = dst;

  while (*dst)
    dst++;
  while ((*dst++ = *src++) != '\0');
  return (ret);
}

char *my_strdup(const char *str)
{
  size_t siz;
  char *copy;

  siz = my_strlen(str) + 1;
  if ((copy = malloc(siz)) == NULL)
      return (NULL);
  my_strcpy(copy, str);
  return (copy);
}
