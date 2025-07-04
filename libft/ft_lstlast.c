/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteag <amonteag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:49:18 by amonteag          #+#    #+#             */
/*   Updated: 2025/04/21 17:06:30 by amonteag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

/*
ft_lstlast retorna el ultimo nodo de la lista
*/