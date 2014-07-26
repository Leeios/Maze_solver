#ifndef GRIMLY_H
#define GRIMLY_H

#define BUFF_SIZE 1023
#define MAX_INT 246000000
#define ABS(n) ((n) > 0 ? (n) : -(n))
#define ISNBR(n) (n >= '0' && n <= '9')
#define ISVALID(n) (n == m->symbols[0] || n == m->symbols[1] || n == m->symbols[2] || n == m->symbols[3])
#define C_CUR m->map[m->current[0]][m->current[1]]
#define C_LEFT m->map[m->current[0]][m->current[1] - 1]
#define C_RIGHT m->map[m->current[0]][m->current[1] + 1]
#define C_UP m->map[m->current[0] - 1][m->current[1]]
#define C_DOWN m->map[m->current[0] + 1][m->current[1]]
#define C_END m->map[m->end[0]][m->end[1]]
#define TRACE "/"
#define START -1
#define END 1
#define EMPTY 0
#define WALL 2
#define PATH -2
#define DIST_0 3

# include <stdlib.h>
# include <stdio.h>

/*
**Order of symbols
**EMPTY
**FULL
**START
**END
**PATH
*/

typedef struct	s_data
{
	int	**map;
	int	size[2];
	char	symbols[5];
	int	current[2];
	int	start[2];
	int	end[2];
	int	dist;
}		t_data;

/*
**PARSE
*/
void	parse(char *s, t_data *m);

/*
**CALCULUS (replace by rec_path)
*/
void	recursive_path(t_data *m);

/*
**HEURISTIC
*/
void	dir_ludr(t_data *m);
void	dir_ldur(t_data *m);
void	dir_rudl(t_data *m);
void	dir_rdul(t_data *m);
void	dir_ulrd(t_data *m);
void	dir_urld(t_data *m);
void	dir_dlru(t_data *m);
void	dir_drlu(t_data *m);

/*
**DISPLAY
*/
void	print_map(t_data *m);
void	print_map_int(t_data *m);

/*
**LIBFT
*/
void	ft_putstr_fd(char *s, int fd);
void	ft_exit(int test, char *s);
char	*ft_strjoin(char *s, char *t);
int	ft_uatoi(char **nbr);

#endif
