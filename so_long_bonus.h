/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:03:37 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/07/07 15:56:12 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

typedef struct data
{
	char	**ar;
	char	**ar2;
	void	*intro;
	void	*mlx;
	void	*mlx_win;
	void	*pared;
	void	*suelo;
	void	*risitas;
	void	*risitas2;
	void	*birra;
	void	*cobete;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*d_uni;
	void	*d_dec;
	void	*d_cen;
	void	*d_mil;
	void	*img;
	char	*address;
	int		bpp;
	int		size;
	int		endian;
	int		res;
	int		eru;
	int		count;
	int		fin;
	int		pax;
	int		pay;
	int		pbx;
	int		pby;
	int		pcx;
	int		pcy;
	int		dor;
	int		dor2;
	int		dor3;
}				t_data;

/*MAIN*/
int		main(int argc, char **argv);
int		ft_map_len(char *map);
char	*ft_stract(char *map, int i);
int		ft_char_check(char *str);
int		ft_lines(char **array);

/*PRINTF*/
int		ft_printf(char const *str, ...);

/*SPLIT*/
void	*ft_del(char **array, int j);
char	*ft_subsplit(char const *s, char c, int i);
int		ft_strcount(const char *s, char c);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);

/*ERROR*/
int		ft_error(char **array, char *str);
int		ft_format(char *str);
int		ft_rect_check(char **array);
int		ft_player_exit_colect_check(char *str);
int		ft_border_check(char **array, int lin, int col);

/*PLAYABILITY*/
int		ft_playability(char *str);
void	ft_swept(char **arr);
int		ft_st_temp(char x, int i);
int		ft_st_map(char x, int i);
void	ft_player_pos(char	**array);

/*PLAY*/
void	ft_play(char **array, char *str);
void	ft_image(t_data *d);
int		ft_items(t_data *d);
void	ft_items_print(t_data *d);
void	ft_player(t_data *d);

/*PLAY_UTILS*/
int		ft_start(t_data *d);
int		key_hook(int keycode, t_data *d);
void	ft_check_pos(char **array, int x, int y);
int		ft_move(t_data *d, int x, int y);
void	ft_anime(t_data *d);

/*PLAY UTILS B*/
void	ft_count(t_data *d);
int		ft_clos(t_data *d);
int		ft_final_check(void);
int		ft_free(t_data *d);

/*ENEMY*/
char	**enemy_ar(char *str);
void	ft_change(char **array, int x, int y);
void	ft_enemy_set(t_data *d);
void	ft_enemy_setb(t_data *d);
void	ft_enemy_setc(t_data *d);

/*ENEMY I.A.*/
void	ft_enemy_ia(t_data *d);
void	ft_enemy_iaa(t_data *d);
void	ft_enemy_mova(t_data *d);
void	ft_enemy_iab(t_data *d);
void	ft_enemy_movb(t_data *d);

/*ENEMY CRAZY i.a.*/
void	ft_enemy_iac(t_data *d);
void	ft_enemy_movc(t_data *d);
void	ft_enemy_movc_b(t_data *d, int n);

#endif