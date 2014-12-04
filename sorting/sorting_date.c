/*
** sorting_date.c for my_ls in /home/barrau_h/Desktop/PSU_2014_my_ls/sorting
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Sun Nov 30 16:11:25 2014 Hippolyte Barraud
** Last update Sun Nov 30 19:12:44 2014 Hippolyte Barraud
*/

#include "../include/my_ls.h"

static char *convert_month(char *month)
{
  if (my_strcmp(month, "Jan") == 0)
    return ("01");
  else if (my_strcmp(month, "Feb") == 0)
    return ("02");
  else if (my_strcmp(month, "Mar") == 0)
    return ("03");
  else if (my_strcmp(month, "Apr") == 0)
    return ("04");
  else if (my_strcmp(month, "May") == 0)
    return ("05");
  else if (my_strcmp(month, "Jun") == 0)
    return ("06");
  else if (my_strcmp(month, "Jul") == 0)
    return ("07");
  else if (my_strcmp(month, "Aug") == 0)
    return ("08");
  else if (my_strcmp(month, "Sep") == 0)
    return ("09");
  else if (my_strcmp(month, "Oct") == 0)
    return ("10");
  else if (my_strcmp(month, "Nov") == 0)
    return ("11");
  else if (my_strcmp(month, "Dec") == 0)
    return ("12");
  return ("00");
}

static char *substring(char *str, int start, int end)
{
  char *out;
  int i;

  i = 0;
  if ((out = malloc(sizeof(char) * (end - start))) == NULL)
    exit (EXIT_FAILURE);
  while (start < end)
      out[i++] = str[start++];
  return (out);
}

static void reformat_date(char *date, char *dup)
{
  char month[3];
  char *tmp;

  dup[0] = '\0';
  my_strcat(dup, (tmp = substring(date, 20, 23)));
  free(tmp);
  month[0] = date[4];
  month[1] = date[5];
  month[2] = date[6];
  dup[4] = '\0';
  my_strcat(dup, convert_month(month));
  dup[6] = (date[8] != ' ') ? date[8] : '0' ;
  dup[7] = date[9];
  dup[8] = '\0';
  my_strcat(dup, (tmp = substring(date, 11, 18)));
  free (tmp);
  dup[16] = '\0';
}

int cmp_date(time_t date1, time_t date2)
{
  char dup1[17];
  char dup2[17];
  int out;

  reformat_date((ctime(&date1) != NULL ? ctime(&date1) : "Erreur"), dup1);
  reformat_date((ctime(&date2) != NULL ? ctime(&date2) : "Erreur"), dup2);
  out = my_strcmp(dup1, dup2);
  return (out);
}
