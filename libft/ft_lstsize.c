/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteag <amonteag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:04:56 by amonteag          #+#    #+#             */
/*   Updated: 2025/04/21 17:56:17 by amonteag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

/*
ft_lstsize calcula la cantidad de nodos que contiene la lista
se itera en los nodos con   lst = lst->next;
*/