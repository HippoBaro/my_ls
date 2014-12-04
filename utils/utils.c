/*
** utils.c for my_ls in /home/barrau_h/Desktop/my_ls/utils
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sat Nov 29 06:32:34 2014 Hippolyte Barraud
** Last update Sun Nov 30 03:29:41 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

int get_URI(t_entity *entry, char out[PATH_MAX])
{
  my_strcpy(out, entry->path);
  my_strcat(out, "/");
  my_strcat(out, entry->name);
  return (0);
}

long total_blocks(t_entity *entities, int len)
{
  int i;
  long tot;

  i= 0;
  tot = 0;
  while (i < len - 1)
      tot += (long)(entities + i++)->file.st_blocks;
  return (tot);
}

int my_strcmp(const char *s1, const char *s2)
{
  while (*s1 == *s2++)
      if (*s1++ == 0)
	  return (0);
  return (*(unsigned char *) s1 - *(unsigned char *) --s2);
}

char *my_strcpy(char *dst, const char *src)
{
  char *save = dst;

  while ((*dst = *src) != '\0')
    {
      dst++;
      src++;
    }
  return (save);
}
