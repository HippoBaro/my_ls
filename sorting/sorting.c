/*
** sorting.c for my_ls in /home/barrau_h/Desktop/my_ls/sorting
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Nov 28 19:02:31 2014 Hippolyte Barraud
** Last update Sun Nov 30 19:07:36 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

static void reverse_elems(t_entity *entities, int len, t_query *query)
{
  t_entity temp;
  int i;

  i = 0;
  if (!query->b_r)
    return;
  while (i < len)
    {
      temp = entities[i];
      entities[i] = entities[len];
      entities[len] = temp;
      i++;
      len--;
    }
}

static void sort_by_name(t_entity *entities, int len, t_query *query)
{
  int i;
  int didSwap;
  t_entity temp;

  didSwap = TRUE;
  i = 0;
  if (!query->b_f)
    while (didSwap)
      {
	didSwap = FALSE;
	i = 0;
	while (i < len - 1)
	  {
	    if (cmp_str((entities + i)->name, (entities + i + 1)->name) > 0)
	      {
		temp          = entities[i];
		entities[i]   = entities[i + 1];
		entities[i + 1] = temp;
		didSwap = TRUE;
	      }
	    i++;
	  }
	len--;
      }
}

static void sort_by_mdate(t_entity *entities, int len, t_query *query)
{
  int i;
  int didSwap;
  t_entity temp;

  didSwap = TRUE;
  i = 0;
  if (!query->b_f)
    while (didSwap)
      {
	didSwap = FALSE;
	i = 0;
	while (i < len)
	  {
	    if (cmp_date((entities + i)->file.st_mtime,
			 (entities + i + 1)->file.st_mtime) < 0)
	      {
		temp          = entities[i];
		entities[i]   = entities[i + 1];
		entities[i + 1] = temp;
		didSwap = TRUE;
	      }
	    i++;
	  }
	len--;
      }
}

static void sort_by_adate(t_entity *entities, int len, t_query *query)
{
  int i;
  int didSwap;
  t_entity temp;

  didSwap = TRUE;
  i = 0;
  if (!query->b_f)
    while (didSwap)
      {
	didSwap = FALSE;
	i = 0;
	while (i < len)
	  {
	    if (cmp_date((entities + i)->file.st_atime,
			  (entities + i + 1)->file.st_atime) < 0)
	      {
		temp          = entities[i];
		entities[i]   = entities[i + 1];
		entities[i + 1] = temp;
		didSwap = TRUE;
	      }
	    i++;
	  }
	len--;
      }
}

void sort_elems(t_entity *entities, int len, t_query *query)
{
  if (query->b_u)
    sort_by_adate(entities, len, query);
  else if (query->b_t)
    sort_by_mdate(entities, len, query);
  else
	sort_by_name(entities, len, query);
  if (query->b_r)
    reverse_elems(entities, len - 1, query);
}
