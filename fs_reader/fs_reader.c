/*
** fs_reader.c for my_ls in /home/barrau_h/Desktop/my_ls/fs_reader
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Nov 27 01:43:22 2014 Hippolyte Barraud
** Last update Sun Nov 30 23:26:12 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

static void look_dir(t_entity *entry, t_query *query)
{
  const char *d_name;
  char path[PATH_MAX];

  d_name = entry->name;
  if (entry->type & DT_DIR)
    {
      if ((my_strcmp(d_name, "..") != 0 && my_strcmp(d_name, ".") != 0))
	{
	  get_URI(entry, path);
	  my_printf("\n%s :\n", path);
	  list_dir(entry->full_path, query);
	}
    }
}

static t_entity get_entity(const char *dir_name, struct dirent *entry)
{
  t_entity out;
  int path_length;

  out.name = my_strdup(entry->d_name);
  out.type = entry->d_type;
  out.path = my_strdup(dir_name);
  out.lenght = entry->d_reclen;
  get_URI(&out, out.full_path);
  path_length = my_strlen(out.full_path);
  if (path_length >= PATH_MAX)
    {
      my_printf ("Le chemin d'acces est trop long.\n");
      exit (EXIT_FAILURE);
    }
  if (stat(out.full_path, &out.file) < 0)
    out.b_stat = FALSE;
  else
    out.b_stat = TRUE;
  handle_link(&out);
  return (out);
}

void free_entities(t_entity *entities)
{
  int i;

  i = 0;
  while (i < MAX_ENT + 1)
    {
      free(entities[i].path);
      free(entities[i].name);
      i++;
    }
  free(entities);
}

void list_dir (const char * dir_name, t_query *query)
{
  DIR *d;
  struct dirent *entry;
  t_entity *entities;
  int i;
  int b;

  i = 0;
  b = 0;
  entities = malloc(sizeof(t_entity) * MAX_ENT);
  if (entities == NULL)
    exit(1);
  if ((d = open_or_skip(dir_name, entities)) == NULL)
    return;
  if (!query->b_d)
    my_printf("%s:\n", dir_name);
  while ((entry = readdir(d)))
      if (!(entry->d_name[0] == '.' && !(query->b_a || query->b_A ||
					 query->b_f)))
	entities[i++] = get_entity(dir_name, entry);
  print_elems(&entities[0], i, query);
  while (b < i && query->b_R)
    look_dir(&entities[b++], query);
  close_or_die(d);
  free_entities(entities);
}
