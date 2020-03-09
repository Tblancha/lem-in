/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 22:26:42 by tblancha          #+#    #+#             */
/*   Updated: 2020/01/12 22:50:09 by tblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
 ** ____ INCLUDE
*/

# include "./libft/libft.h"
# include <stdarg.h>

/*
 ** ____ DEFINE
*/

# define BUFF_SIZE_2	128

/*
 ** ____ BINAIRE
*/

# define DIESE			1
# define PLUS			2
# define SPACE			4
# define MINUS			8
# define ZERO			16
# define PRECISION		32
# define CONV_H			64
# define CONV_HH		128
# define CONV_L_MIN		256
# define CONV_LL		512
# define CONV_L_MAJ		1024
# define CONV_J			2048
# define CONV_Z			4096
# define ETOILE			8192

/*
 ** ____ STRUCTURE
*/

typedef struct		s_buff
{
	char	buffer[BUFF_SIZE_2];
	int		index;
	int		len;
}					t_buff;

typedef struct		s_info_data
{
	int				flag;
	int				type;
	int				padding;
	int				precision;
	int				conversion;
	int				len_arg;
	int				arg_int;
	int				sign;
	int				check;
	int				last_char;
	char			*arg_str;

}					t_info_data;

/*
 ** ____ ENUM TYPE
*/

typedef enum		e_type
{
	TYPE_NONE,
	TYPE_C,
	TYPE_S,
	TYPE_P,
	TYPE_D,
	TYPE_O,
	TYPE_U,
	TYPE_X_MIN,
	TYPE_X_MAJ,
	TYPE_F,
	TYPE_PERCENT,
	NUMBER_ELEMENT_ENUM,
}					t_type;

/*
 ** ____ FT_PRINTF
*/

int					ft_printf(const char *format, ...);

/*
 ** ____ WRITE_TO_BUFF
*/

void				flush_buff(t_buff *buff);
void				ft_repeat_char_buff(t_buff *buff, char c, int n);
void				ft_putchar_buff(t_buff *buff, char c);
void				ft_putstr_buff(t_buff *buff, char *str);
void				ft_putnstr_buff(t_buff *buff, char *str, int n);

/*
 ** ____ PARSE_PERCENT
*/

void				parse_percent(t_info_data *data, char **str);

/*
 ** ____ FT_ABS
*/

intmax_t			ft_abs(intmax_t x);

/*
 ** ____ CONVERT_TO_BASE
*/

char				*convert_to_base_uintmax_t(uintmax_t number, char *base);
char				*convert_to_base_intmax_t(intmax_t number, char *base);
char				*convert_float(long double number);

/*
 ** ____ CONVERT_VA_ARG
*/

void				va_arg_type_c(va_list arg, t_info_data *data);
void				va_arg_type_s(va_list arg, t_info_data *data);
void				va_arg_type_p(va_list arg, t_info_data *data);
void				va_arg_type_d(va_list arg, t_info_data *data);
void				va_arg_type_o(va_list arg, t_info_data *data);
void				va_arg_type_u(va_list arg, t_info_data *data);
void				va_arg_type_x_min(va_list arg, t_info_data *data);
void				va_arg_type_x_maj(va_list arg, t_info_data *data);
void				va_arg_type_f(va_list arg, t_info_data *data);

/*
 ** ____ TYPEDEF POINTEUR SUR FONCTION
*/

typedef void		(*t_pf_dispatch_type)(va_list, t_buff *, t_info_data *);

/*
 ** ____ IGNORE_FLAG
*/

void				ignore_flag(t_info_data *data, int flag);
void				ignore_flag_priority(t_info_data *data, int strong,
		int weak);
void				ignore_flag_for_d(t_info_data *data);
void				ignore_flag_for_o_x_xmaj(t_info_data *data);
void				ignore_flag_for_float(t_info_data *data);
void				ignore_flag_for_u(t_info_data *data);
void				ignore_flag_for_c_s(t_info_data *data);
void				ignore_flag_for_none(t_info_data *data);
void				ignore_flag_for_p(t_info_data *data);

/*
 ** ____ REAL_VALUE_OF_PADDING
*/

int					real_value_of_padding_c_s(t_info_data *data);
int					real_value_of_padding_pdiuxxmaj(t_info_data *data);
int					real_value_of_padding_o(t_info_data *data);

/*
 ** ____ DISPATCH_TYPE
*/

t_pf_dispatch_type	pf_dispatch_type(int type);
void				dispatch_type_c(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_s(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_p(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_d(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_o(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_u(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_x_min(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_x_maj(va_list arg, t_buff *buff,
		t_info_data *data);
void				dispatch_type_f(va_list arg, t_buff *buff,
		t_info_data *data);

/*
 ** ____ APPLY_PRECISION
*/

void				apply_precision_c(t_buff *buff, t_info_data *data);
void				apply_precision_s(t_buff *buff, t_info_data *data);
void				apply_precision_pdiouxxmaj(t_buff *buff, t_info_data *data);

/*
 ** ____ APPLY_FLAG_ROUTER
*/

void				apply_flag_router_c(t_buff *buff, t_info_data *data);
void				apply_flag_router_s(t_buff *buff, t_info_data *data);
void				apply_flag_router_other(t_buff *buff, t_info_data *data);

/*
 ** DIESE_SIGN_CORRECTION_PADDING
*/

char				*correction_precision_padding_flag_zero(t_info_data *data);
void				handler_signe_or_flag_plus(t_buff *buff, t_info_data *data);
void				prefix_router(t_buff *buff, t_info_data *data);

#endif
