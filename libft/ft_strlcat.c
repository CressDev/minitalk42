/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:07:37 by amonteag          #+#    #+#             */
/*   Updated: 2025/06/23 19:00:42 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + src_len);
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	s1[] = "Hola";
	char	s2[] = "Mundo";
	unsigned int	size = 10;
	
	printf("Resultado: %s\n", s1);
    printf("Longitud: %zu\n", ft_strlcat(s1, s2, size));
    printf("Resultado final: %s\n", s1);

    return (0);
}
*/
/*
ft_strlcat concatena un size de str2 a  str1 
lo hace al final del len de destino mas el iterador
size debe de ser mayor que dest_len para poder iniciar la copia
en caso contrario retorna el size mas el len de src
*/
