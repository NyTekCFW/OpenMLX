/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vt_settings_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:52:54 by lchiva            #+#    #+#             */
/*   Updated: 2024/06/08 00:05:13 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/openmlx.h"

static void	image_center(t_prim *s, t_vec2 *xy)
{
	t_vec2	center;
	t_vec2	offset;
	t_vec2	df;
	int		i;
	t_img	*g;

	i = -1;
	center = (t_vec2){0, 0};
	g = s->img;
	while (++i < s->cpoint)
	{
		center.x += s->point[i].x;
		center.y += s->point[i].y;
	}
	center.x /= s->cpoint;
	center.y /= s->cpoint;
	offset = (t_vec2){center.x - (g->width / 2), center.y - (g->height / 2)};
	df = (t_vec2){xy->x - offset.x, xy->y - offset.y};
	xy->y = (df.y % g->height + g->height) % g->height;
	xy->x = (df.x % g->width + g->width) % g->width;
}

static void	image_mirror(t_prim *s, t_vec2 *xy)
{
	t_vec2	m;
	t_vec2	u;

	m = (t_vec2){xy->x % (2 * s->img->width), xy->y % (2 * s->img->height)};
	if (m.x >= s->img->width)
		u.x = 2 * s->img->width - m.x - 1;
	else
		u.x = m.x;
	if (m.y >= s->img->height)
		u.y = 2 * s->img->height - m.y - 1;
	else
		u.y = m.y;
	xy->x = u.x;
	xy->y = u.y;
}

int	ml_can_draw(t_prim *s, t_vec2 xy)
{
	t_vec2	cv;

	if (xy.x < 0 || xy.y < 0)
		return (0);
	cv = (t_vec2){xy.x, xy.y};
	if (s->texture == ML_TEXTURE_IMG && s->img)
	{
		if (s->wrapping == ML_WRAP_REPEAT_CENTER)
			image_center(s, &cv);
		if (s->wrapping == ML_WRAP_MIRRORED_REPEAT)
			image_mirror(s, &cv);
		if (s->uv == ML_UV_90)
			cv = (t_vec2){cv.y, cv.x};
		s->color = get_px_color(s->img, get_px_adr(s->img, cv));
		if (is_valid_color(s->color))
		{
			if (s->color_texture != 0xFFFFFF && s->color != 0x030303)
				s->color = blend_colors(s->color_texture,
						s->color, s->intensity);
			return (1);
		}
		return (0);
	}
	return (1);
}

void	ml_savemesh(t_prim *s, t_shaders *sh)
{
	if (sh)
		s->savemesh = &sh->img;
}
