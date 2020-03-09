#include "lem-in.h"

static int		nb_antz(t_info *info, char *line)
{
	int		i;

	i = 0;
	while (line[i] && ft_isdigit((int)line[i]))
		i++;
	if (i < ft_strlen(line))
		return (0);
	info->nb_fourmi = ft_atoi(line);
	if (info->nb_fourmi == 0)
		return (0);
	return (1);
}

static void		get_start_end(t_info *info, char *line)
{
	int		i;

	i = 0;
	while (info->name[i])
		i++;
	if (ft_strnstr_eq(line, "start", 8) && ft_strlen(line) == 7)
		info->start = i;
	if (ft_strnstr_eq(line, "end", 5) && ft_strlen(line) == 5)
		info->end = i;
}

int				parsing(t_info *info)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) == 0)
		{
			//error_return(0)
			ft_printf("ERROR: An empty line has been send\n");
			exit(0);
		}
		else if (line[0] == '#')
		{
			if (line[1] == '#')
			{
				//strnstr_eq("start")
					//start = index
				//strnstr_eq("end")
					//end = index
			}
		}
		else if (i == 0)
		{
			if (nb_antz(info, line) == 0)
				return (0);
			i++;
		}
		else if (line[0] == 'L')
		{
			//link les salles
		}
		else
		{
			// if (dans les info->salle[x] la salle existe deja)
				//error
			// else
				//ajouter la salle a info->salle ET addlist ... add new salle
		}
		ft_strdel(&line);
	}
	return (1);
}