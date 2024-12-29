/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:40:44 by matomas           #+#    #+#             */
/*   Updated: 2024/11/29 11:56:21 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void ft_validate_paths(t_info_map *data)
{
    char **copy;
    int i;

    copy = malloc(sizeof(char *) * (data->height + 1));
    if (!copy)
        ft_error_exit("Error: Fallo al asignar memoria para validar caminos");
    i = 0;
    while (data->map[i])
    {
        copy[i] = ft_strdup(data->map[i]);  // Crear una copia del mapa
        i++;
    }
    copy[i] = NULL;

    flood_fill(copy, data->x, data->y, data);  // Inicia desde la posición del jugador

    i = 0;
    while (copy[i])
        free(copy[i++]);
    free(copy);

    if (data->collectibles > 0 || data->exit_reachable == 0)
        ft_error_exit("Error: El jugador no puede alcanzar todos los objetos o la salida");
}
