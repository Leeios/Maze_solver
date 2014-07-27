#include "grimly.h"

static void	ft_init_map(t_data *m)
{
	int	i;

	i = -1;
	ft_exit((m->map = (int **)malloc(sizeof(int *) * m->size[0])) == NULL
		, "malloc error");
	while (++i < m->size[0])
		ft_exit((m->map[i] = (int *)malloc(sizeof(int) * m->size[1])) == NULL
			, "malloc error");
}

static int	check_map(t_data *m, char **s, int *i, int *j)
{
	ft_exit(((**s == '\n' && *j != m->size[1]) || (**s != '\n' && *j == m->size[1]))
		, "map error");
	if (**s == '\n')
	{
		(*i)++;
		(*s)++;
		*j = 0;
	}
	if (*i >= m->size[0] || !(**s) || **s == '\n')
		return (1);
	ft_exit(!(ISVALID(**s)), "map error");
	return (0);
}

static void	fill_map(t_data *m, char c, int i, int j)
{
	if (c == m->symbols[2])
	{
		m->map[i][j] = START;
		m->start[0] = i;
		m->start[1] = j;
	}
	else if (c == m->symbols[3])
	{
		m->map[i][j] = END;
		m->end[0] = i;
		m->end[1] = j;
	}
}

static void	convert_map(char *s, t_data *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_map(m);
	while (*s)
	{
		if (check_map(m, &s, &i, &j))
			return ;
		if (*s == m->symbols[0])
			m->map[i][j] = EMPTY;
		else if (*s == m->symbols[1])
			m->map[i][j] = WALL;
		else
			fill_map(m, *s, i, j);
		j++;
		s++;
	}
}

void		parse(char *s, t_data *m)
{
	ft_exit(!ISNBR(s[0]), "map error: No lines number");
	m->size[0] = ft_uatoi(&s);
	m->size[1] = 0;
	ft_exit(!s[0] || !s[1] || !s[2] || !s[3] || !s[4]
		|| s[5] != '\n', "map error: Not enough symbols");
	m->symbols[0] = s[0];
	m->symbols[1] = s[1];
	m->symbols[2] = s[2];
	m->symbols[3] = s[3];
	m->symbols[4] = s[4];
	s += 6;
	while (s[m->size[1]] && s[m->size[1]] != '\n')
		m->size[1]++;
	convert_map(s, m);
}
