/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:25 by lchiva            #+#    #+#             */
/*   Updated: 2024/07/07 19:57:12 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENMLX_H
# define OPENMLX_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <sys/time.h>
# include "openmlx_enum.h"
# include "openmlx_math.h"
# include "openmlx_string.h"
# include "openmlx_memory.h"
# include "openmlx_img.h"
# include "openmlx_vertex.h"
# include "openmlx_video.h"

# define PI 3.14159265359

typedef struct ml_s
{
	void		*ptr;
	void		*win;
	void		(*(purge_window))();
	void		(*(new_purge_color))();
	void		(*(quit_window))();
	int			(*(set_win_size))();
	int			(*(make_window))();
	int			width;
	int			height;
	int			debug;
	int			refresh;
	__uint32_t	purge_color;
	t_texture	texture;
	t_rec		record;
	t_video		video;
}	t_ml;

t_ml	*gmlx(int e_gmlxact);
//openmlx func
int		_ml_create_window(char *title);
int		_ml_set_window_size(int w, int h);
void	_ml_purge_window(void);
void	_ml_quit(void);
void	_ml_set_purge_color(__uint32_t color);
void	_ml_set_win_data_pixel(void);
#endif