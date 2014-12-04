/*
** my_ls.c for my_ls in /home/barrau_h/Desktop/my_ls
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Nov 27 00:07:27 2014 Hippolyte Barraud
** Last update Sun Nov 30 19:37:46 2014 Hippolyte Barraud
*/

#include"include/my_ls.h"

int main(int ac, char **av)
{
  t_query query;
  t_entity entity;
  int i;

  i = 0;
  query = parse_query(ac, av);
  if (!query.b_d)
    while (i < query.len_URI)
      {
	if (i > 0)
	  printf("\n");
	list_dir(query.URI[i++], &query);
      }
  else
    while (i < query.len_URI)
      {
	entity.name = query.URI[i];
	if (stat(query.URI[i++], &entity.file) == -1)
	  my_printf("Erreur lors de l'accès au fichier.\n");
	print_elems(&entity, 1, &query);
      }
  return (0);
}
