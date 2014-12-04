/*
** dir.c for my_ls in /home/barrau_h/Desktop/my_ls/fs_reader
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 30 12:01:19 2014 Hippolyte Barraud
** Last update Sun Nov 30 12:17:36 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

DIR *open_or_skip(const char *dir_name, t_entity *entities)
{
  DIR *d;

  if (!(d = opendir(dir_name)))
    {
      my_printf("Impossible d'ouvrir le dossier : %s\n", strerror((int)errno));
      free_entities(entities);
      return (NULL);
    }
  return (d);
}

void close_or_die(DIR *d)
{
  if (closedir(d))
    {
      my_printf("Impossible de fermer le dossier : %s\n",
		strerror((int)errno));
      exit (EXIT_FAILURE);
    }
}
