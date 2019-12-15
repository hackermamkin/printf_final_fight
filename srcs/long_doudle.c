/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_doudle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:31:34 by gfreddie          #+#    #+#             */
/*   Updated: 2019/12/15 12:13:26 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char				*str_rewrite(char *str, int i)
{
	int		j;
	char	*str_new;

	str_new = (char *)malloc(sizeof(char) * (i + 1));
	str_new[i] = '\0';
	j = 0;
	while (i - j > 0)
	{
		str_new[j] = str[j];
		j++;
	}
	return (str_new);
}

int					ft_ssttrr_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*str_revers(char *str)
{
	char	*str_new;
	int		i;
	int		j;

	j = 0;
	i = ft_ssttrr_len(str);
	str_new = (char *)malloc(sizeof(char) * (i + 1));
	str_new[i] = '\0';
	i--;
	while (i >= 0)
	{
		str_new[j] = str[i];
		j++;
		i--;
	}
	free(str);
	return (str_new);
}

char				*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (s1 && s2)
	{
		if ((str = (char *)malloc(sizeof(char) *ft_ssttrr_len(s1)
						+ ft_ssttrr_len(s2) + 1)) == NULL)
			return (NULL);
		i = 0;
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char				*normalizer(char *str, char *str1)
{
	char	*str_new;
	char	*str1_new;
	int		i;
	int		fix;
	int		len;

	len = ft_ssttrr_len(str);
	len--;
	fix = 0;
	i = len;
	if (len == 0)
	{
		str_new = (char *)malloc(sizeof(char) * (2));
		str_new[0] = '0';
		str_new[1] = '\0';
		i = 0;
	}
	else
	{
		while (str[i] == '0')
			i--;
		str_new = (char *)malloc(sizeof(char) * (i + 2));
		str_new[i + 1] = '\0';
		fix = i + 1;
		len = 0;
	}
	while (len < fix)
	{
		str_new[len] = str[i];
		len++;
		i--;
	}
	len = ft_ssttrr_len(str1);
	str1_new = (char *)malloc(sizeof(char) * (len + 1));
	str1_new[len] = '\0';
	len--;
	i = 0;
	while (len >= 0)
	{
		str1_new[i] = str1[len];
		i++;
		len--;
	}
	return (ft_strplus(ft_strplus(str_new, ".", 1, 0), str1_new, 1, 1));
}

char				*zero_str(int	i)
{
	char	*str;


	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = '0';
		i--;
	}
	return (str);
}

char				*ft_itoa_base1(unsigned long long nb)
{
	char				*str;
	int					i;
	unsigned long long	pow;

	pow = nb;
	i = 1;
	while (pow /= 2)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	while (nb)
	{
		str[i--] = nb % 2 + '0';
		nb /= 2;
	}
	return (str);
}

char		*long_plus(char *str, char *str_plus)//сложение двух строчных чисел
{
	int					i;
	int					j;
	int					nb;
	int					a;

	j = 0;
	i = 0;
	nb = 0;
	if (str_plus == NULL)
		return (str);
	while (str[i] && str_plus[j])
	{
		if (str[i] == '.')
		{
			i++;
			j++;
		}
		else
		{
			a = str[i] + str_plus[j] + nb - '0' - '0';
			str[i] = a % 10 + '0';
			nb = a / 10;
			i++;
			j++;
		}
	}
	free(str_plus);
	return (str);
}

char		*double_power(int pow)//возведение степени двойки
{
	int		i;
	int		nb;
	int		a;
	char	*str;

	i = 1;
	if (pow == 0)
	{
		str = (char *)malloc(sizeof(char) * (2));
		str[0] = '1';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (pow + 1));
	str[0] = '1';
	while (i < pow)
	{
		str[i] = '0';
		i++;
	}
	str[pow] = '\0';
	i = 0;
	nb = 0;
	while (pow > 0)
	{
		while (str[i])
		{
			a = (str[i] - '0') * 2 + nb;
			str[i] = a % 10 + '0';
			nb = a / 10;
			i++;
		}
		i = 0;
		pow--;
	}
	return (str);
}

char		*str_small_part(int		pow)//дробная часть
{
	int		i;
	int		nb;
	int		a;
	char	*str;
	
	nb = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (pow + 1));
	str[pow] = '\0';
	while (i < pow)
	{
		str[i] = '0';
		i++;
	}
	i = 0;
	str[0] = '1';
	while (pow)
	{
		while (str[i])
		{
			a = (str[i] - '0') * 5 + nb;
			str[i] = a % 10 + '0';
			nb = a / 10;
			i++;
		}
		i = 0;
		pow--;
	}
	return (str);
}

int			check_after_stop(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '.')
		i++;
	return (i);
}

char		*okruglenie(char *str, int precision)
{
	char	*str_plus;
	int		i;
	int		fix;

	str_plus = NULL;
	i = check_after_stop(str);
	fix = i;
	while (str[i] && precision)
	{
		precision--;
		i++;
	}
	if (precision)
	{
		str = ft_strplus(str, zero_str(precision), 1, 1);
		return (str);
	}
	if (precision == 0)
	{
		i++;
		if (str[i] >= '5' && str[i] <= '9')
		{
			str = str_rewrite(str, i);
			str_plus = ft_strplus(zero_str(i - 1), "1", 1, 0);
			str_plus = str_revers(long_plus(str_revers(str),
						str_revers(str_plus)));
		}
		else
			str = str_rewrite(str, i);
	}
	if (str_plus)
		return (str_plus);
	return (str);
}

//ft_strplus - стрджоин который фришит пишется ft_strplus(char *s1, char *s2, int i, int j) где i и j говорят фришить строу или нет 

int			mod(int exp)
{
	if (exp < 0)
		return ((-1) * exp);
	return (exp);
}
/*
char		*whole_number(char *str_new_whole, char *str_new_small)
{
	char	*str;
	char	*str1;
	char	*str_new;
	int		i;
	int		j;
	int		symbols_value;

	i = 0;
	str = zero_str(ft_ssttrr_len(str_new_whole) - 1);
	str1 = zero_str(ft_ssttrr_len(str_new_small) - 1);
	symbols_value = ft_ssttrr_len(str_new_whole);
	printf("str_new_whole = %s\n", str_new_whole);
	while (str_new_whole[i])
	{
		if (str_new_whole[i] == '1')
		{
			str_new = double_power(i);
			str = long_plus(ft_strplus(str_new, zero_str(symbols_value - i - 1), 1, 1), str);
		}
		i++;
	}
	symbols_value = ft_ssttrr_len(str_new_small);
	i = 0;
	j = 0;
	if (ft_ssttrr_len(str) == 2)
		j = 1;
	while (str_new_small[i])
	{
		if (str_new_small[i] == '1')
		{
			write(1, "1", 1);
			str_new = str_small_part(i + j);
			write(1, "2", 1);
			str1 = long_plus(ft_strjoin(zero_str(symbols_value - i), str_new), str1);
		}
		i++;
	}
	return (normalizer(str, str1));
}

char		*whole_part(char *str, long long int exp, int precision)
{
	char				*str_new_whole;
	char				*str_new_small;
	unsigned long long	i;
	unsigned long long	j;
	long long int		fix;
	int					value;

	i = 0;
	j = 0;
	value = 0;
	fix = exp;
	if (exp > 63)
	{
		str_new_whole = zero_str(exp);
		str_new_small = zero_str(1);
	}
	if (exp <= 0)
	{
		str_new_whole = zero_str(1);
		value = mod(exp);
		str_new_small = zero_str(value + 64);
	}
	if (exp >= 0 && exp <= 63)
	{
		while (exp >= 0)
		{
			str_new_whole[i] = str[exp];
			exp--;
			i++;
		}
	}
	exp = fix;
	i = exp;
	if (exp < 63)
	{
		if (exp < 0)
			i = 0;
		if (exp == 0)
			i = 1;
		exp++;
		while (str[i])
		{
			str_new_small[j + value] = str[i];
			j++;
			i++;
			exp++;
		}
	}
	free(str);
	return(okruglenie(whole_number(str_new_whole, str_new_small), precision));
}*/

char			*whole_part(char *str, long int exp, int precision)
{
	int		i;
	char	*str00;
	char	*str01;
	char	*str_plus;
	char	*result;

	printf("str = %s\n", str);
	i = 0;
	str00 = zero_str(1000);
	str01 = zero_str(1000);
	while (str[i])
	{
		if (str[i] == '1')
		{
			if (exp >= 0)
			{
				str_plus = double_power(exp);
				str00 = long_plus(str00, ft_strjoin(str_plus, zero_str(1000 - ft_ssttrr_len(str_plus))));
			}
			else
			{
				str_plus = str_small_part(mod(exp));
				str01 = long_plus(str01, ft_strjoin(zero_str(1000 - ft_ssttrr_len(str_plus)), str_plus));
			}
		}
		i++;
		exp--;
	}
	printf("str00 = %s\n", str00);
	printf("str01 = %s\n", str01);
	result = okruglenie(normalizer(str00, str01), precision);
	if (result[0] == '.')
		result = ft_strjoin("0", result);
	return(result);
}

typedef union					union_d
{
	long double	a;
	struct
	{
		long long int	mant : 64;
		unsigned long long	exp : 15;
		long long int	sign : 1;
	}							b_bit;
}								union_double;

char		*str_dd(va_list *va, t_flags *flags)
{
	union_double bb;
	long double b;
	unsigned long long	exp;

	if (flags->type == L)
		b = va_arg(*va, long double);
	else
		b = va_arg(*va, double);
	if (flags->precision == -1)
		flags->precision = 6;
	printf("precision = %d\n",flags->precision);
	bb.a = b;
	printf("exp before = %lld\n", bb.b_bit.exp);
	exp = bb.b_bit.exp - 16383;
	printf("exp = %lld\n", exp);
	if (bb.b_bit.sign != 0)
		return (ft_strplus("-", whole_part(ft_itoa_base1(bb.b_bit.mant),
						exp, flags->precision), 0, 1));
	return (whole_part(ft_itoa_base1(bb.b_bit.mant), exp,
				flags->precision));
}
