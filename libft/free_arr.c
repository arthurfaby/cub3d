/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirabaud <pirabaud@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:19:59 by pirabaud          #+#    #+#             */
/*   Updated: 2022/12/14 21:58:35 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}
