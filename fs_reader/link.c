/*
** link.c for my_ls in /home/barrau_h/Desktop/my_ls/fs_reader
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 30 11:51:43 2014 Hippolyte Barraud
** Last update Sun Nov 30 11:57:10 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

void handle_link(t_entity *out)
{
  t_entity *target;

  if (DT_LNK == out->type)
    {
      if ((out->target = malloc(sizeof(t_entity))) == NULL)
	exit(1);
      target = (t_entity*)out->target;
      if (readlink(out->full_path, target->full_path, PATH_MAX) == -1)
  	{
  	  out->b_target = FALSE;
  	  return;
  	}
      out->b_target = TRUE;
      target->name = target->full_path;
      if (stat(target->full_path, &target->file) < 0)
        target->b_stat = TRUE;
      else
  	target->b_stat = TRUE;
    }
  return;
}
