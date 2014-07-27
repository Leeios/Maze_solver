#include "grimly.h"
#include <fcntl.h>
#include <unistd.h>

static char	*ft_read(char *filename)
{
	int	fd;
	char	*s;
	char	buf[BUFF_SIZE + 1];
	int	r;

	s = "";
	ft_exit((fd = open(filename, O_RDONLY)) < 0, "Error opening file");
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		buf[r] = '\0';
		s = ft_strjoin(s, buf);
	}
	return (s);
}

static void	recursive_fill(t_data *m)
{
	if (m->current[1]  && C_LEFT == C_CUR - 1)
	{
		C_CUR = PATH;
		m->current[1]--;
	}
	else if (m->current[0] && C_UP == C_CUR - 1)
	{
		C_CUR = PATH;
		m->current[0]--;
	}
	else if (m->current[1] < m->size[1] && C_RIGHT == C_CUR - 1)
	{
		C_CUR = PATH;
		m->current[1]++;
	}
	else if (m->current[0] < m->size[0] && C_DOWN == C_CUR - 1)
	{
		C_CUR = PATH;
		m->current[0]++;
	}
	else
		return ;
	recursive_fill(m);
}

static void	search_path(t_data *m)
{
	m->current[0] = m->start[0];
	m->current[1] = m->start[1];
	m->dist = 3;
	recursive_path(m);
	ft_exit(C_END == END, "map error: no solution");
	m->current[0] = m->end[0];
	m->current[1] = m->end[1];
	recursive_fill(m);
}

int		main(int ac, char **av)
{
	t_data	m;
	char	*s;

	ft_exit(ac != 2, "usage : ./grimly filename");
	s = ft_read(av[1]);
	parse(s, &m);
	search_path(&m);
	print_map(&m);
	return (0);
}
