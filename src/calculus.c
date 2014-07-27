#include "grimly.h"

/*
**PRIORITIES
rudl
rdul
ludr
ldur
ulrd
urld
dlru
drlu
*/

static void	heuristic_direction_horizontal(t_data *m)
{
	if (m->current[1] - m->end[1] > 0)
	{
		if (m->current[0] - m->end[0] > 0)
			dir_ludr(m);
		else
			dir_ldur(m);
	}
	else
	{
		if (m->current[0] - m->end[0] > 0)
			dir_rudl(m);
		else
			dir_rdul(m);
	}
}

static void	heuristic_direction(t_data *m)
{
	if (ABS(m->current[0] - m->end[0]) > ABS(m->current[1] - m->end[1]))
	{
		if (m->current[0] - m->end[0] < 0)
		{
			if (m->current[1] - m->end[1] > 0)
				dir_dlru(m);
			else
				dir_drlu(m);
		}
		else
		{
			if (m->current[1] - m->end[1] > 0)
				dir_ulrd(m);
			else
				dir_urld(m);
		}
	}
	else
		heuristic_direction_horizontal(m);
}

/*
**Mettre en switch case
*/
void	recursive_path(t_data *m)
{
	if (m->current[0] >= m->size[0] || m->current[1] >= m->size[1]
		|| m->current[0] < 0 || m->current[1] < 0
		|| C_CUR == WALL
		|| (C_CUR >= DIST_0 && m->dist >= C_CUR)
		|| (C_END != END && m->dist >= C_END))
		return ;
	C_CUR = m->dist;
	m->dist++;
	heuristic_direction(m);
	m->dist--;
}
