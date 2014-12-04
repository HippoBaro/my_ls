/*
** format_types.c for my_ls in /home/barrau_h/Desktop/my_ls/format
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 30 00:26:57 2014 Hippolyte Barraud
** Last update Sun Nov 30 20:00:00 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

int count_digits(int value)
{
  int count;

  count = 0;
  while (value > 0)
    {
      value = value / 10;
      count++;
    }
  if (count == 0)
    return (1);
  return (count);
}

void print_link(t_entity *entity, t_cwidth *columns)
{
  int i;
  int len_val;

  len_val = count_digits((int)entity->file.st_nlink);
  i = 0;
  while (i < columns->c_link - len_val)
    {
      my_printf(" ");
      i++;
    }
  my_printf("%d ", (int)entity->file.st_nlink);
}

void print_size(t_entity *entity, t_query *query, t_cwidth *columns)
{
  int i;
  int len_val;

  if (query->b_k)
    len_val = count_digits(((long)entity->file.st_size) / 8);
  else
    len_val = count_digits((long)entity->file.st_size);
  i = 0;
  while (i < columns->c_size - len_val)
    {
      my_printf(" ");
      i++;
    }
  if (query->b_k)
    my_printf("%d ", ((int)entity->file.st_size) / 8);
  else
    my_printf("%d ", (int)entity->file.st_size);
}

void print_uid(t_entity *entity, t_query *query, t_cwidth *columns)
{
  int i;
  char *value;

  if (query->b_g)
    return;
  value = ((getpwuid(entity->file.st_uid) != NULL) ?
	   getpwuid(entity->file.st_uid)->pw_name : "Inconnu");
  i = 1;
  while (i < (columns->c_uid + 1) - my_strlen(value))
    {
      my_printf(" ");
      i++;
    }
  my_printf("%s ", value);
}

void print_gid(t_entity *entity, t_query *query, t_cwidth *columns)
{
  int i;
  char *value;

  if (query->b_g)
    return;
  value = (getgrgid(entity->file.st_gid) != NULL ?
	   getgrgid(entity->file.st_gid)->gr_name : "Inconnu");
  i = 1;
  while (i < (columns->c_gid + 1) - my_strlen(value))
    {
      my_printf(" ");
      i++;
    }
  my_printf("%s ", value);
}
