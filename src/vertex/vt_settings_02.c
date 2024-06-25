/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vt_settings_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:38:54 by lchiva            #+#    #+#             */
/*   Updated: 2024/06/25 21:30:39 by lchiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/openmlx.h"

void	ml_overwrite_fix(t_prim *s, t_vec4 *ijt)
{
	if (ijt->w >= s->savemesh->height)
		ijt->w = s->savemesh->height - 1;
	else if (ijt->w < 0)
		ijt->w = 0;
	if (ijt->y >= s->savemesh->width)
		ijt->y = s->savemesh->width - 1;
	else if (ijt->y < 0)
		ijt->y = 0;
}

void	ml_overwrite(t_prim *s, int overwrite)
{
	if (overwrite >= 0 && overwrite < 2)
		s->overwrite = overwrite;
}
