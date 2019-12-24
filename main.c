/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:58:23 by pstein            #+#    #+#             */
/*   Updated: 2019/12/22 13:13:11 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	long double a = 42.5;
	float b = 3;
	float c = a/b;
	ft_printf("%.16Lf", -LDBL_MIN);
	printf("%.16Lf", -LDBL_MIN);
	return(1);
}
