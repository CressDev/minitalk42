/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteag <amonteag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:04:45 by amonteag          #+#    #+#             */
/*   Updated: 2025/04/21 17:45:35 by amonteag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content)
{
	t_list	*newnodo;

	newnodo = (t_list *)malloc(sizeof(t_list));
	if (!newnodo)
		return (NULL);
	newnodo->content = (void *)content;
	newnodo->next = NULL;
	return (newnodo);
}
/*
ft_lstnew crea un nodo reservado con malloc
le asigna sus dos valores el contenido mediante uncasteo a puntero void
y el sugundo null a el nodo siguiente
*/