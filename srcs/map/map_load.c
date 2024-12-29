/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:49:52 by matomas           #+#    #+#             */
/*   Updated: 2024/11/29 11:22:55 by matomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Esta función carga todas las líneas del archivo del mapa en la estructura `data->map`
static void	load_map_lines(int fd, t_info_map *data)
{
    char *line;
    int i;

    i = 0;
    line = get_next_line(fd);  // Leer la primera línea
    while (line != NULL)
    {
        data->map = realloc(data->map, sizeof(char *) * (i + 1));
        if (!data->map)
            ft_error_exit("Error: Fallo al asignar memoria para el mapa");
        data->map[i] = ft_strdup(line);
        free(line);
        i++;
        line = get_next_line(fd);
    }
    if (i == 0)
        ft_error_exit("Error: El archivo del mapa está vacío");
    data->map = realloc(data->map, sizeof(char *) * (i + 1));
    data->map[i] = NULL;  // Finaliza con NULL para recorrerlo fácilmente.
    data->height = i;     // Número de filas en el mapa.
}

void parse_map(const char *file, t_info_map *data)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        ft_error_exit("Error: No se puede abrir el archivo del mapa");
    load_map_lines(fd, data);
    close(fd);
    ft_map_size(data);        // Validar tamaño del mapa.
    ft_check_map(data);       // Validar formato y bordes.
    ft_check_map_objects(data); // Validar que existan P, C, y E.
}
