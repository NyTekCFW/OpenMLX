/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:05:05 by lchiva            #+#    #+#             */
/*   Updated: 2024/06/03 19:15:20 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/openmlx.h"

//Setup Exemple
int	main(void)
{
	t_ml		*lx;
	t_prim		c;

	lx = gmlx(ACT_INIT);
	if (lx)
	{
		lx->purge_color = 0x7f7f7f;
		if (lx->set_win_size(600, 600) && lx->make_window("OpenMLX Showcase"))
		{
			register_img("./textures/rock.xpm");
			c = ml_begin(ML_PRIM_TRIANGLES);
			ml_settexture(&c, "/rock.xpm");
			ml_color(&c, 0xff0000);
			ml_setintensity(&c, 0.6);
			ml_setuv(&c, ML_UV_0);
			ml_vertex(&c, (t_vec2){0, 0});
			ml_vertex(&c, (t_vec2){600, 0});
			ml_vertex(&c, (t_vec2){600, 600});
			ml_setwrap(&c, ML_WRAP_MIRRORED_REPEAT);
			ml_end(&c);
			while (1)
				;
			lx->quit_window();
		}
	}
}
