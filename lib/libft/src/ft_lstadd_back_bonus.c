/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:44:25 by wcista            #+#    #+#             */
/*   Updated: 2023/01/15 16:38:46 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!lst || !new)
		return ;
	back = *lst;
	if (!back)
	{
		*lst = new;
		return ;
	}
	while (back -> next)
		back = back -> next;
	back -> next = new;
}
