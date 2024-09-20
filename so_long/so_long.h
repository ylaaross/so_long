/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaaross <ylaaross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:34:03 by ylaaross          #+#    #+#             */
/*   Updated: 2023/05/04 12:10:52 by ylaaross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct assets_paths
{
	char	*wall_path;
	void	*wall_img;
	char	*coins_path;
	void	*coins_img;
	char	*player_path;
	void	*player_img;
	char	*ground_path;
	void	*ground_img;
	char	*exit_path;
	void	*exit_img;
	char	*exitc_path;
	void	*exitc_img;
}t_assets_paths;

typedef struct player
{
	char			**map;
	t_vars			vars;
	int				px;
	int				py;
	int				ex;
	int				ey;
	int				nbrcoins;
	int				height;
	int				width;
	int				movement;
	t_assets_paths	paths;
}t_player;

enum e_keys{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53,
	PLAYER = 4,
	COINS = 5,
	EXITC = 6,
};
void	initialise_v(int *i, int *j);
int		affiche_return(int message, t_player *player);
int		wall_check(t_player *player);
void	ft_putnbr(int nb);
int		test_assets(int p, int e, t_player *player);
char	*get_next_line(int fd);
int		wall_check(t_player *player);
int		valid_dimention(int tall, int width);
void	search(char **t, int *ii, int *jj);
int		valid(char c);
void	possibble_path_p1(char **t, int i, int *j);
void	possibble_path_p2(char **t, int i, int j);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		check_assets(t_player *player);
void	all_possibal_path(char **t, int p, int pj);
int		test_map(t_player player);
int		valid(char c);
void	search(char **t, int *ii, int *jj);
void	cp_arr(t_player p, char ***c);
void	free_2d_map(char **table);
size_t	ft_strlen(const char *s);
void	initialise_var_map(int *i, int *j);
int		check_c(char **c, t_player player);
void	concat_and_store(t_player *player, int fd);
int		strlen_w_n(char *t);
int		equal_lent(t_player *player);
void	free_all_images(t_player *player);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
void	increment_decrement_value(t_player *player, int *x, \
char **path, int action);
void	up(t_player *player);
void	down(t_player *player);
void	left(t_player *player);
void	initialise_xy(int *x, int *y, void **mlx, t_player *player);
void	right(t_player *player);
void	increment_decrement_value2(t_player *player, int *y, \
char **path, int action);
void	coins_check(t_player *player);
void	initialise_assets_variable(t_player	*player, int *i, int *j, int *e);
int		test_assets(int p, int e, t_player *player);
void	store_xy_player(t_player *player, int i, int j, int *p);
void	print_map(t_player *player);
void	paths_imgs_initialise(t_player *player);
void	coins_check(t_player *player);
void	print_m_wasd(t_player *player, int action);
void	free_all_images(t_player *player);
int		key_hook(int keycode, t_player *player);
int		size(char *s);
int		file_check(char *path);
int		file_d(char *path);
void	map_initialise(t_player *player);
int		file_d(char *path);
void	map_initialise(t_player *player);
void	print_assets(t_player *player, int assets, int i, int j);
void	print_map(t_player *player);
void	testpaths(t_player *player);
void	paths_imgs_initialise(t_player *player);
void	destroy_if_exist(t_player *player);
void	error_line(int nbr, char *line);
void	empty_last(char *res, char *line);
#endif