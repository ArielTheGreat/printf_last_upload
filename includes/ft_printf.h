/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha <frocha@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:52:44 by frocha            #+#    #+#             */
/*   Updated: 2024/10/11 17:52:46 by frocha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdint.h>
#include <stdarg.h>

void print_character(const char character, int *counter);
void string_mode(char *str, int *counter_characters);
void int_mode(int integer,int *counter_characters);
void unsigned_int_mode(unsigned int integer, int *counter_characters);
void pointer_mode(unsigned long long pointer, int *counter_characters);
void hexadecimal_mode(unsigned int integer, const char format, int *counter_characters);
#endif
