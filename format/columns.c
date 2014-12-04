/*
** columns.c for my_ls in /home/barrau_h/Desktop/my_ls/columns
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sat Nov 29 06:28:30 2014 Hippolyte Barraud
** Last update Sun Nov 30 19:54:50 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

static int calc_columns_size(t_entity *entities, int len, t_query *query)
{
  int count;
  int countmax;
  int i;

  i = 0;
  countmax = 0;
  while (i < len)
    {
      if ((my_strcmp((entities + i)->name, "..") != 0 && my_strcmp
	   ((entities + i)->name, ".") != 0) || query->b_a || query->b_d
	  || query->b_f)
	{
	  count = count_digits((int)(entities + i)->file.st_size);
	  if (count > countmax)
	    countmax = count;
	}
      i++;
    }
  return (countmax);
}

static int calc_columns_link(t_entity *entities, int len, t_query *query)
{
  int count;
  int countmax;
  int i;

  i = 0;
  countmax = 0;
  while (i < len)
    {
      if ((my_strcmp((entities + i)->name, "..") != 0 && my_strcmp
	   ((entities + i)->name, ".") != 0) || query->b_a || query->b_d
	  || query->b_f)
	{
	  count = count_digits((int)(entities + i)->file.st_nlink);
	  if (count > countmax)
	    countmax = count;
	}
      i++;
    }
  return (countmax);
}

static int calc_columns_uid(t_entity *entities, int len, t_query *query)
{
  int count;
  int countmax;
  int i;

  i = 0;
  countmax = 0;
  while (i < len)
    {
      if ((my_strcmp((entities + i)->name, "..") != 0 && my_strcmp
	   ((entities + i)->name, ".") != 0) || query->b_a || query->b_d
	  || query->b_f)
	{
	  count = my_strlen(getpwuid((entities + i)->file.st_uid) != NULL ?
			 getpwuid((entities + i)->file.st_uid)->pw_name :
			 "Inconnu");
	  if (count > countmax)
	    countmax = count;
	}
      i++;
    }
  return (countmax);
}

static int calc_columns_gid(t_entity *entities, int len, t_query *query)
{
  int count;
  int countmax;
  int i;

  i = 0;
  countmax = 0;
  while (i < len)
    {
      if ((my_strcmp((entities + i)->name, "..") != 0 && my_strcmp
	   ((entities + i)->name, ".") != 0) || query->b_a || query->b_d
	  || query->b_f)
	{
	  count = my_strlen(getgrgid((entities + i)->file.st_gid) != NULL ?
			 getgrgid((entities + i)->file.st_gid)->gr_name :
			 "Inconnu");
	  if (count > countmax)
	    countmax = count;
	}
      i++;
    }
  return (countmax);
}

t_cwidth calc_columns(t_entity *entities, int len, t_query *query)
{
  t_cwidth out;

  out.c_size = calc_columns_size(entities, len, query);
  out.c_link = calc_columns_link(entities, len, query);
  out.c_uid = calc_columns_uid(entities, len, query);
  out.c_gid = calc_columns_gid(entities, len, query);
  return (out);
}
