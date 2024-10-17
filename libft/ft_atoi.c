/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:40:21 by frocha            #+#    #+#             */
/*   Updated: 2024/10/07 22:40:24 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check_char(char character, int first_int_occ)
{
	if (first_int_occ && !ft_isdigit(character))
		return (4);
	if (ft_strchr("!\"#$%&'()*,./:;<=>?@[\\]^_`{|}~", character))
		return (2);
	if (ft_strchr("+-", character))
		return (3);
	if (first_int_occ == 0 && ft_isalpha(character))
		return (2);
	return (0);
}

int	handle_digit_check(const char *str, int *counter, int *digit_count)
{
	while (check_char(str[*counter], *digit_count) == 0
		|| check_char(str[*counter], *digit_count) == 3)
	{
		(*digit_count)++;
		(*counter)++;
	}
	return (check_char(str[*counter], *digit_count));
}

int	calculate_result(int counter, int end_limit, const char *str)
{
	int		result;
	int		counter2;
	int		counter3;
	int		resultado;

	counter2 = counter;
	result = 0;
	while (counter2 < end_limit)
	{
		resultado = 1;
		counter3 = end_limit - counter2;
		while (counter3 > 0)
		{
			resultado = resultado * 10;
			counter3--;
		}
		result += (str[counter] - '0') * resultado;
		end_limit--;
		counter++;
	}
	result += str[counter] - '0';
	return (result);
}

int	create_new_string(const char *str, int *result,
int counter2, int *digit_count_p)
{
	int		return_value;
	int		x_value;

	return_value = -1;
	if (str[counter2] != '\0' && check_char(str[counter2 + 1], *digit_count_p)
		== 4 && (str[counter2] == '-' || str[counter2] == '+'))
		return (-2);
	counter2--;
	x_value = counter2;
	while (counter2 > 0 && ft_isdigit(str[counter2]))
		counter2--;
	if (ft_isdigit(str[counter2]))
		counter2 = 0;
	else if (str[counter2] == '-' || str[counter2] == '+')
	{
		if (!ft_isdigit(str[counter2 + 1]))
			return (-2);
		if (str[counter2] == '-')
			return_value = 1;
		counter2++;
	}
	else
		counter2++;
	*result = calculate_result(counter2, x_value, str);
	return (return_value);
}

int	ft_atoi(const char *str)
{
	int		is_negative;
	int		result;
	int		counter;
	int		digit_count;

	digit_count = 0;
	counter = 0;
	result = 1;
	if (str[counter] == '\0')
		return (0);
	while (str[counter] == ' ' || str[counter] == '\t' || str[counter] == '\n'
		|| str[counter] == '\v' || str[counter] == 12 || str[counter] == '\r')
		counter++;
	if ((str[counter] >= 1 && str[counter] <= 31)
		|| (unsigned char)str[counter] >= 127)
		return (0);
	if (handle_digit_check(str, &counter, &digit_count) == 2
		&& digit_count == 0 && str[counter] != '\0')
		return (0);
	is_negative = create_new_string(str, &result, counter, &digit_count);
	if (is_negative == -2)
		return (0);
	if (is_negative == 1)
		result *= -1;
	return (result);
}
