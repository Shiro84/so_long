/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:50:41 by matomas           #+#    #+#             */
/*   Updated: 2024/11/29 11:38:08 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"

void ft_map_size(t_info_map *data)
{
    int i;
    int len;

    len = ft_strlen(data->map[0]);  // Longitud de la primera fila
    i = 1;
    while (data->map[i])
    {
        if ((int)ft_strlen(data->map[i]) != len)
            ft_error_exit("Error: El mapa no es rectangular");
        i++;
    }
    data->width = len;
}

void ft_check_map(t_info_map *data)
{
    int i;
    int j;

    // Validar bordes superior e inferior
    i = 0;
    while (data->map[0][i])
        if (data->map[0][i++] != '1')
            ft_error_exit("Error: El mapa no está cerrado por paredes (borde superior)");

    i = 0;
    while (data->map[data->height - 1][i])
        if (data->map[data->height - 1][i++] != '1')
            ft_error_exit("Error: El mapa no está cerrado por paredes (borde inferior)");

    // Validar bordes laterales
    i = 0;
    while (i < data->height)
    {
        if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
            ft_error_exit("Error: El mapa no está cerrado por paredes (bordes laterales)");
        i++;
    }
}

void ft_check_map_objects(t_info_map *data)
{
    int i;
    int j;
    int player = 0, exit = 0, collectibles = 0;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
                player++;
            else if (data->map[i][j] == 'E')
                exit++;
            else if (data->map[i][j] == 'C')
                collectibles++;
            else if (!ft_strchr("01PECV", data->map[i][j]))
                ft_error_exit("Error: Caracter no válido en el mapa");
            j++;
        }
        i++;
    }
    if (player != 1 || exit < 1 || collectibles < 1)
        ft_error_exit("Error: El mapa debe tener al menos 1 jugador, 1 salida y 1 coleccionable");
}
