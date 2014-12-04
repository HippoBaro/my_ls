/*
** my_ls.h for my_ls in /home/barrau_h/Desktop/my_ls/include
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Wed Nov 26 22:45:10 2014 Hippolyte Barraud
** Last update Sun Nov 30 16:03:08 2014 Hippolyte Barraud
*/

#ifndef __MY_LS_H__
# define __MY_LS_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "my_printf.h"

#define MAX_URI 250
#define MAX_ENT 9999

#define TRUE 1
#define FALSE 0

#define BOLD "\x1B[1m"
#define RBOLD "\x1B[21m"
#define KBRED "\x1B[41m"
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[93m"
#define KBLU "\x1B[94m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define RESET "\033[0m"
#define RESETB "\x1B[49m"

typedef struct s_query
{
  char *URI[MAX_URI];
  int len_URI;
  int b_l;
  int b_R;
  int b_d;
  int b_r;
  int b_t;
  int b_u;
  int b_F;
  int b_g;
  int b_f;
  int b_a;
  int b_A;
  int b_k;
}t_query;

typedef struct s_columnsw
{
  int c_size;
  int c_link;
  int c_uid;
  int c_gid;
}t_cwidth;

typedef struct s_entity
{
  struct stat file;
  char *name;
  unsigned char type;
  char *path;
  char full_path[PATH_MAX];
  unsigned short lenght;
  void *target;
  int b_target;
int b_stat;
}t_entity;

t_query parse_query(int ac, char **av);
void select_bool(char param, t_query *query);
void list_dir (const char * dir_name, t_query *query);
void free_entities(t_entity *entities);
void print_elems(t_entity *entities, int len, t_query *query);

void handle_link(t_entity *out);

DIR *open_or_skip(const char *dir_name, t_entity *entities);
void close_or_die(DIR *d);

int cmp_str(const char *str1, const char *str2);

int cmp_date(time_t date1, time_t date2);

void print_link(t_entity *entity, t_cwidth *columns);
void print_size(t_entity *entity, t_query *query, t_cwidth *columns);
void print_uid(t_entity *entity, t_query *query, t_cwidth *columns);
void print_gid(t_entity *entity, t_query *query, t_cwidth *columns);

void sort_elems(t_entity *entities, int len, t_query *query);

t_cwidth calc_columns(t_entity *entities, int len, t_query *query);

int get_URI(t_entity *entry, char out[PATH_MAX]);
long total_blocks(t_entity *entities, int len);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dst, const char *src);
char *my_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
int count_digits(int value);

#endif
