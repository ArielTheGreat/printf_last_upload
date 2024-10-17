/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:29 by frocha            #+#    #+#             */
/*   Updated: 2024/10/11 17:52:31 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

void	print_character(const char character, int *counter)
{
	write(1,&character,1);
	*counter = *counter + 1;
}

void check_type_string(va_list args, const char character, int *counter_characters)
{
	if (character == 'c')
		print_character(va_arg(args, int), counter_characters);
	else if (character == 's')
		string_mode(va_arg(args, char *), counter_characters);
	else if (character == 'p')
		pointer_mode(va_arg(args, unsigned long long), counter_characters);
	else if (character == 'd' || character == 'i')
		int_mode(va_arg(args, int), counter_characters);
	else if (character == 'u')
		unsigned_int_mode(va_arg(args, unsigned int), counter_characters);
	else if (character == 'x' || character == 'X')
		hexadecimal_mode(va_arg(args, unsigned int), character, counter_characters);
	else
		print_character(character, counter_characters);
}

int	ft_printf(const char *format, ...)
{
	int		counter_characters;
	int i;
	va_list	args;

	i = 0;
	counter_characters = 0;
	va_start(args, format);
	while(format[i] != '\0'){
		if (format[i] == '%'){
			check_type_string(args, format[i+1], &counter_characters);
			i++;
		}else
		{
			print_character(format[i], &counter_characters);
		}
		i++;
	}
	va_end(args);
	return (counter_characters);
}

// int main()
// {
// 	char *s = "SKJAHjk";
// 	int i = ft_printf("%p\n", s);
// 	int a = printf("%p\n", s);
// 	printf("%i\n",i);
// 	printf("%i",a);
// 	return 0;
// }