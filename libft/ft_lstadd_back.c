/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:24:36 by yarutiun          #+#    #+#             */
/*   Updated: 2022/08/23 13:59:32 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neww)
{
	t_list	*temp;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = neww;
		}
		else
		{
			temp = ft_lstlast(*(lst));
			temp->next = neww;
		}
	}
}
