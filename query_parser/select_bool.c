/*
** select_bool.c for my_ls in /home/barrau_h/Desktop/PSU_2014_my_ls/query_parser
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 30 19:41:39 2014 Hippolyte Barraud
** Last update Sun Nov 30 19:45:06 2014 Hippolyte Barraud
*/

#include"../include/my_ls.h"

static void select_bool2(char param, t_query *query)
{
  if (param == 'f')
    query->b_f = TRUE;
  else if (param == 'a')
    query->b_a = TRUE;
  else if (param == 'A')
    query->b_A = TRUE;
  else if (param == 'k')
    query->b_k = TRUE;
}

void select_bool(char param, t_query *query)
{
  if (param == 'l')
    query->b_l = TRUE;
  else if (param == 'R')
    query->b_R = TRUE;
  else if (param == 'd')
    query->b_d = TRUE;
  else if (param == 'r')
    query->b_r = TRUE;
  else if (param == 't')
    query->b_t = TRUE;
  else if (param == 'u')
    query->b_u = TRUE;
  else if (param == 'F')
    query->b_F = TRUE;
  else if (param == 'g')
    {
      query->b_l = TRUE;
      query->b_g = TRUE;
    }
  select_bool2(param, query);
}
