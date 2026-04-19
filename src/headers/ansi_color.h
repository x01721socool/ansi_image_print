/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi_color.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiorent <efiorent@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:48:37 by efiorent          #+#    #+#             */
/*   Updated: 2026/03/12 15:14:55 by efiorent         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_COLOR_H
# define ANSI_COLOR_H
# define ANSI_RESET "\e[0m"
# define ANSI_BLACK "0"
# define ANSI_RED "1"
# define ANSI_GREEN "2"
# define ANSI_YELLOW "3"
# define ANSI_BLUE "4"
# define ANSI_MAGENTA "5"
# define ANSI_CYAN "6"
# define ANSI_WHITE "7"
# define ANSI_COLOR(str, color_code) "\e[3" color_code "m" str ANSI_RESET
# define ANSI_BACKGROUND(str, color_code) "\e[4" color_code "m" str ANSI_RESET
# define ANSI_BRIGHT_COLOR(str, color_code) "\e[9" color_code "m" str ANSI_RESET
# define ANSI_BRIGHT_BACKGROUND(str, color_code) "\e[10" color_code "m" str ANSI_RESET
# define ANSI_COLOR_256(str, color_code) "\e[38;5;"#color_code"m" str ANSI_RESET
# define ANSI_BACKGROUND_256(str, color_code) "\e[48;5;"#color_code"m" str ANSI_RESET
# define ANSI_COLOR_RGB(str, r, g, b) "\e[38;2;"#r";"#g";"#b"m" str ANSI_RESET
# define ANSI_BACKGROUND_RGB(str, r, g, b) "\e[48;2;"#r";"#g";"#b"m" str ANSI_RESET
#endif
