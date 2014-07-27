#include "grimly.h"
#include <unistd.h>

static void	ft_display_char(t_data *m, int n)
{
	if (n == EMPTY)
		ft_exit(0 > write(1, &(m->symbols[0]), 1), "Writing error");
	else if (n == WALL)
		ft_exit(0 > write(1, &(m->symbols[1]), 1), "Writing error");
	else if (n == START)
		ft_exit(0 > write(1, &(m->symbols[2]), 1), "Writing error");
	else if (n == END)
		ft_exit(0 > write(1, &(m->symbols[3]), 1), "Writing error");
	else if (n == PATH)
		ft_exit(0 > write(1, &(m->symbols[4]), 1), "Writing error");
	else
		ft_exit(0 > write(1, TRACE, 1), "Writing error");
}

void		print_map(t_data *m)
{
	int i, j;
	i = j = -1;

	m->map[m->start[0]][m->start[1]] = START;
	m->map[m->end[0]][m->end[1]] = END;
	while (++i < m->size[0])
	{
		j = -1;
		while (++j < m->size[1])
			ft_display_char(m, m->map[i][j]);
		ft_exit(0 > write(1, "\n", 1), "Writing error");
	}
}
