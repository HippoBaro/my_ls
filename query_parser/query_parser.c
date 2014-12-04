/*
** query_parser.c for my_ls in /home/barrau_h/Desktop/my_ls/query_parser
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Wed Nov 26 23:00:37 2014 Hippolyte Barraud
** Last update Sun Nov 30 19:44:17 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

static t_query get_query()
{
  t_query out;

  out.len_URI = 0;
  out.b_l = FALSE;
  out.b_R = FALSE;
  out.b_d = FALSE;
  out.b_r = FALSE;
  out.b_t = FALSE;
  out.b_u = FALSE;
  out.b_F = FALSE;
  out.b_g = FALSE;
  out.b_f = FALSE;
  out.b_a = FALSE;
  out.b_A = FALSE;
  out.b_k = FALSE;
  return (out);
}

static int analyse_arg(char *arg, t_query *query)
{
  int i;

  i = 0;
  if (arg[0] == '-')
    while (arg[i] != '\0')
      select_bool(arg[i++], query);
  else
    {
      if (arg[my_strlen(arg) - 1] == '/' && my_strlen(arg) > 1)
        arg[my_strlen(arg) - 1] = '\0';
      query->URI[query->len_URI++] = arg;
    }
  return (0);
}

t_query parse_query(int ac, char **av)
{
  t_query query;
  int i;

  i = 1;
  query = get_query();
  if (ac > 1)
    while (i < ac)
      analyse_arg(av[i++], &query);
  if (query.len_URI == 0)
    {
      query.len_URI = 1;
      query.URI[0] = ".";
    }
  return (query);
}
