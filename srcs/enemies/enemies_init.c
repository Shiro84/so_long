/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:31:18 by matomas           #+#    #+#             */
/*   Updated: 2024/11/27 16:31:28 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemies.h"
#include "so_long.h"
#include <stdlib.h>

void init_enemies(t_info_map *data)
{
    int i;
    int j;

    // Inicializa enemigos en el mapa (en este ejemplo los enemigos están marcados como 'X')
    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'X')  // 'X' representa un enemigo
            {
                // Colocar al enemigo (solo la inicialización en este ejemplo)
                // Se podrían agregar más acciones para inicializar su estado
            }
            j++;
        }
        i++;
    }
}
