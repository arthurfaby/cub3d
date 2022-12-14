/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_char_and_increment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:08:10 by blevrel           #+#    #+#             */
/*   Updated: 2022/10/19 21:09:20 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_fill_char_and_increment(char *res, char *src, int *i, int *j)
{
	res[*j] = src[*i];
	(*i)++;
	(*j)++;
}
