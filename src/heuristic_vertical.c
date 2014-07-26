#include "grimly.h"

void	dir_ulrd(t_data *m)
{
	m->current[0]--;
	recursive_path(m);
	m->current[0]++;
	m->current[1]--;
	recursive_path(m);
	m->current[1] += 2;
	recursive_path(m);
	m->current[1]--;
	m->current[0] += 2;
	recursive_path(m);
}

void	dir_urld(t_data *m)
{
	m->current[0]--;
	recursive_path(m);
	m->current[0]++;
	m->current[1]++;
	recursive_path(m);
	m->current[1] -= 2;
	recursive_path(m);
	m->current[1]++;
	m->current[0] += 2;
	recursive_path(m);
}

void	dir_dlru(t_data *m)
{
	m->current[0]++;
	recursive_path(m);
	m->current[0]--;
	m->current[1]--;
	recursive_path(m);
	m->current[1] += 2;
	recursive_path(m);
	m->current[1]--;
	m->current[0] -= 2;
	recursive_path(m);
}

void	dir_drlu(t_data *m)
{
	m->current[0]++;
	recursive_path(m);
	m->current[0]--;
	m->current[1]++;
	recursive_path(m);
	m->current[1] -= 2;
	recursive_path(m);
	m->current[1]++;
	m->current[0] -= 2;
	recursive_path(m);
}
