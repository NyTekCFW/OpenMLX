/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ml_window_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:40:39 by lchiva            #+#    #+#             */
/*   Updated: 2024/06/19 17:07:44 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/openmlx.h"

static void	_ml_set_win_data(t_ml *lx)
{
	_ml_set_win_data_pixel();
	create_img((t_ui){0, 0, lx->width, lx->height, lx->purge_color},
		fill_img_color, "clear_window");
	create_img((t_ui){0, 0, lx->width, lx->height, 0},
		fill_img_color, "framework");
	lx->purge_window();
}

int	_ml_create_window(char *title)
{
	t_ml	*lx;

	lx = gmlx(ACT_GET);
	if (lx && lx->height > 0 && lx->width > 0)
	{
		lx->ptr = mlx_init();
		if (lx->ptr)
		{
			lx->win = mlx_new_window(lx->ptr, lx->width, lx->height, title);
			if (lx->win)
			{
				_ml_set_win_data(lx);
				return (1);
			}
			mlx_destroy_display(lx->ptr);
			xfree((void **)&lx->ptr);
		}
	}
	return (0);
}

int	_ml_set_window_size(int w, int h)
{
	t_ml	*lx;

	lx = gmlx(ACT_GET);
	if (lx)
	{
		lx->width = w;
		lx->height = h;
		return (1);
	}
	return (0);
}

void	_ml_purge_window(void)
{
	t_ml		*lx;

	lx = gmlx(ACT_GET);
	if (lx)
		print_img((t_vec2){0, 0}, "clear_window");
}

void	_ml_quit(void)
{
	t_ml	*lx;

	lx = gmlx(ACT_GET);
	if (lx)
	{
		purge_textures();
		if (lx->ptr && lx->win)
		{
			mlx_destroy_window(lx->ptr, lx->win);
			lx->win = NULL;
		}
		if (lx->ptr)
		{
			mlx_destroy_display(lx->ptr);
			xfree((void **)&lx->ptr);
		}
		gmlx(ACT_FREE);
	}
}
