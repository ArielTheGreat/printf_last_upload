/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:53:00 by frocha            #+#    #+#             */
/*   Updated: 2024/10/11 17:53:02 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>

void	string_mode(char *str, int *counter_characters)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while(str[i] != '\0')
		{
			print_character(str[i], counter_characters);
			i++;
		}
	}else{
		ft_putstr_fd("(null)", 1);
		*counter_characters = 6;
	}
}

void	int_mode(int integer, int *counter_characters)
{
	char	*str;
	int i;

	i = 0;
	str = ft_itoa(integer);
	while(str[i] != '\0')
	{
		print_character(str[i], counter_characters);
		i++;
	}
	free(str);
}

void	unsigned_int_mode(unsigned int integer, int *counter_characters)
{
	char	*str;
	int i;
	
	i = 0;
	str = ft_itoa(integer);
	while(str[i] != '\0')
	{
		print_character(str[i], counter_characters);
		i++;
	}
	free(str);
}

void print_decimal(char *str, int *counter_characters)
{
	int counter_length_str;

	counter_length_str = ft_strlen(str);
	while(counter_length_str > 0)
	{
		print_character(str[counter_length_str], counter_characters);
		counter_length_str--;
	}
	print_character(str[0],counter_characters);
	*counter_characters = *counter_characters - 1;
}

void create_hexadecimal_pointer(uintptr_t memory_address, char *str)
{
	char *hexadecimal_list;
	int counter2;
	int c_index;

	hexadecimal_list = "0123456789abcdef";
	counter2 = 0;
	while(memory_address / 16 != 0)
	{
		c_index = memory_address % 16;
		str[counter2] = hexadecimal_list[c_index];
		memory_address /= 16;
		counter2++;
	}
	c_index = memory_address % 16;
	str[counter2] = hexadecimal_list[c_index];
	str[counter2 + 1] = '\0';
}

void	decimal_to_hex(uintptr_t memory_address, int *counter)
{
	char *str;

	str = (char *)malloc(11*sizeof(char));
	create_hexadecimal_pointer(memory_address, str);
	print_decimal(str, counter);
	free(str);
}

void create_hexadecimal_mode(unsigned int memory_address, int *counter, char *str, const char format)
{
	char *hexadecimal_list;
	int counter2;
	int c_index;

	hexadecimal_list = "0123456789abcdef";
	if (format == 'X')
		hexadecimal_list = "0123456789ABCDEF";
	counter2 = 0;
	while(memory_address / 16 != 0)
	{
		c_index = memory_address % 16;
		str[counter2] = hexadecimal_list[c_index];
		memory_address /= 16;
		*counter += 1;
		counter2++;
	}
	c_index = memory_address % 16;
	str[counter2] = hexadecimal_list[c_index];
	str[counter2 + 1] = '\0';
}

void hexadecimal_mode(unsigned int integer, const char format, int *counter_characters)
{
	char *str;

	str = (char *)malloc(11*sizeof(char));
	create_hexadecimal_mode(integer, counter_characters, str, format);
	print_decimal(str, counter_characters);
	free(str);
}

void	pointer_mode(unsigned long long pointer, int *counter_characters)
{
	int counter2;
	char *str;

	counter2 = 0;
	uintptr_t memory_int = (uintptr_t)pointer;
	str = "0x";
	ft_putstr_fd(str, 1);
	*counter_characters = *counter_characters+2;
	decimal_to_hex(memory_int,counter_characters);
}
