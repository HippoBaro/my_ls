/*
** format.c for my_ls in /home/barrau_h/Desktop/my_ls/format
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sat Nov 29 05:59:00 2014 Hippolyte Barraud
** Last update Sun Nov 30 04:11:19 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

static void print_filetype(t_entity *entity, t_query *query)
{
  if (query->b_F)
    {
      if (S_ISDIR(entity->file.st_mode))
	my_printf("/");
      else if (DT_LNK == entity->type)
	my_printf("@");
      else if (S_ISFIFO(entity->file.st_mode))
	my_printf("|");
      else if ((S_ISREG(entity->file.st_mode)) &&
	       (entity->file.st_mode & 0111))
	my_printf("*");
    }
}

static void print_filename(t_entity *entity, t_query *query)
{
  if (S_ISDIR(entity->file.st_mode))
    my_printf(BOLD KBLU "%s" RESET RBOLD, entity->name);
  else if (!entity->b_stat)
    my_printf(KBRED KYEL "%s" RESET RESETB, entity->name);
  else if (DT_LNK == entity->type)
    my_printf(KCYN "%s" RESET, entity->name);
  else if ((S_ISREG(entity->file.st_mode)) &&
	   (entity->file.st_mode & 0111))
    my_printf(KGRN "%s" RESET, entity->name);
  else
    my_printf("%s", entity->name);
  print_filetype(entity, query);
  if (DT_LNK == entity->type && query->b_l)
    {
      my_printf(" -> ");
      if (entity->b_target == TRUE)
	print_filename(entity->target, query);
      else
	my_printf("Erreur de lecture du lien.");
      return;
    }
  my_printf("\n");
}

static void print_acl(t_entity *entity)
{
  my_printf((S_ISDIR(entity->file.st_mode)) ? "d" : "-");
  my_printf((entity->file.st_mode & S_IRUSR) ? "r" : "-");
  my_printf((entity->file.st_mode & S_IWUSR) ? "w" : "-");
  my_printf((entity->file.st_mode & S_IXUSR) ? "x" : "-");
  my_printf((entity->file.st_mode & S_IRGRP) ? "r" : "-");
  my_printf((entity->file.st_mode & S_IWGRP) ? "w" : "-");
  my_printf((entity->file.st_mode & S_IXGRP) ? "x" : "-");
  my_printf((entity->file.st_mode & S_IROTH) ? "r" : "-");
  my_printf((entity->file.st_mode & S_IWOTH) ? "w" : "-");
  my_printf((entity->file.st_mode & S_IXOTH) ? "x " : "- ");
}

static void print_line(t_entity *entity, t_query *query, t_cwidth *columns)
{
  char *date;

  print_acl(entity);
  print_link(entity, columns);
  print_uid(entity, query, columns);
  print_gid(entity, query, columns);
  print_size(entity, query, columns);
  date = ctime(&(entity->file.st_mtime));
  if (date != NULL)
    date[my_strlen(date) - 1] = '\0';
  my_printf("%s ", date != NULL ? date : "Date inconnue");
  print_filename(entity, query);
}

void print_elems(t_entity *entities, int len, t_query *query)
{
  int i;
  t_cwidth columns;

  i = 0;
  sort_elems(entities, len, query);
  if (query->b_l && !query->b_d)
    my_printf("total : %d\n", total_blocks(entities, len));
  columns = calc_columns(entities, len, query);
  while (i < len)
    {
      if ((my_strcmp((entities + i)->name, "..") != 0 &&
	   my_strcmp((entities + i)->name, ".") != 0) || query->b_a || query->b_d
	  || query->b_f)
	{
	  if (query->b_l == FALSE)
	      print_filename((entities + i), query);
	  else
	      print_line((entities + i), query, &columns);
	}
      i++;
    }
}
