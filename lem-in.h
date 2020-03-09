#ifndef LEM_IN_H
# define LEM_IN_H

#include "libftprintf/libft/libft.h"
#include "libftprintf/ft_printf.h"

typedef struct s_salle
{
	intmax_t	index;
	char		*name;
	int			x;
	int			y;
	t_salle		*link;
	t_salle		*next;
}				t_salle;

typedef struct s_info
{
	t_salle		*begin;
	t_salle		*salles;
	int			nb_fourmi;
	char		**name;			//parsing
	t_salle		*start;
	t_salle		*end;
}				t_info;

#endif