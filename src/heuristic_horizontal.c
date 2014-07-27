#include "grimly.h"

void	dir_ludr(t_data *m)
{
	m->current[1]--;
	recursive_path(m);
	m->current[1]++;
	m->current[0]--;
	recursive_path(m);
	m->current[0] += 2;
	recursive_path(m);
	m->current[0]--;
	m->current[1]++;
	recursive_path(m);
	m->current[1]--;
}

void	dir_ldur(t_data *m)
{
	m->current[1]--;
	recursive_path(m);
	m->current[1]++;
	m->current[0]++;
	recursive_path(m);
	m->current[0] -= 2;
	recursive_path(m);
	m->current[0]++;
	m->current[1]++;
	recursive_path(m);
	m->current[1]--;
}

void	dir_rudl(t_data *m)
{
	m->current[1]++;
	recursive_path(m);
	m->current[1]--;
	m->current[0]--;
	recursive_path(m);
	m->current[0] += 2;
	recursive_path(m);
	m->current[0]--;
	m->current[1]--;
	recursive_path(m);
	m->current[1]++;
}

void	dir_rdul(t_data *m)
{
	m->current[1]++;
	recursive_path(m);
	m->current[1]--;
	m->current[0]++;
	recursive_path(m);
	m->current[0] -= 2;
	recursive_path(m);
	m->current[0]++;
	m->current[1]--;
	recursive_path(m);
	m->current[1]++;
}
