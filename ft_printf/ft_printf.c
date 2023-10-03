/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:52:12 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/06/19 11:24:20 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_write_s(va_list args)
{
	char	*str;
	int		i;
	int		res;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6), 6);
	i = 0;
	res = 0;
	while (str[i] != '\0')
		res = res + write (1, &str[i++], 1);
	return (res);
}

int	ft_write_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write (1, &c, 1);
	return (1);
}

int	ft_select(const char *str, int i, va_list args)
{
	int	res;

	if (str[i] == '-' || str[i] == '0' || str[i] == '.' || \
		str[i] == '#' || str[i] == ' ' || str[i] == '+')
	{
		ft_static(-ft_static(0));
		return (ft_bonus(str, i, args));
	}
	if (str[i] == 'c')
		res = ft_write_c(args);
	if (str[i] == 's')
		res = ft_write_s(args);
	if (str[i] == 'i' || str[i] == 'd')
		res = ft_write_id(args);
	if (str[i] == '%')
		res = write(1, &str[i], 1);
	if (str[i] == 'u')
		res = ft_write_u(args);
	if (str[i] == 'x' || str[i] == 'X')
		res = ft_write_x(args, -88 + str[i]);
	if (str[i] == 'p')
		res = ft_write_p(args);
	return (res);
}

int	ft_stract_str(const char *str, va_list args)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			res = res + write(1, &str[i++], 1);
		else
		{
			i++;
			res = res + ft_select(str, i++, args);
			i = i + ft_static(0);
		}
	}
	return (res);
}

int	ft_printf(char const *str, ...)
{
	va_list		args;
	int			i;

	va_start (args, str);
	i = ft_stract_str(str, args);
	va_end (args);
	ft_static(-ft_static(0));
	return (i);
}
/* int	main(void)
{
	int	res;

	res = 0;
	res = ft_printf("%1c, %1c, %1c", '5', 'x', '\n');
	printf("\n");
	printf("res = %i", res);
	printf("\n");
	res = printf("%1c, %1c, %1c", '5', 'x', '\n');
	printf("\n");
	printf("res = %i", res);
	printf("\n");
} */

/* int	main(void)
{
	//BONUS BONUS BONUS
	
	char			str[] = "Manolete ande te mete";
	char			c;
	int				i;
	unsigned int	u;
	int 	res;

	c = 'W';
	i = 345;
	u = 624785612;
	res = 0;
	(void)str;
	res = ft_printf("%-25s", str);
	printf("\nres = %i\n", res);
	res = printf("%-25s", str);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%-25c", c);
	printf("\nres = %i\n", res);
	res = printf("%-25c", c);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%-12i", i);
	printf("\nres = %i\n", res);
	res = printf("%-12i", i);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%-12u", u);
	printf("\nres = %i\n", res);
	res = printf("%-12u", u);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%-20p", str );
	printf("\nres = %i\n", res);
	res = printf("%-20p", str);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%025i", i);
	printf("\nres = %i\n", res);
	res = printf("%025i", i);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%020x, %020i", u, i);
	printf("\nres = %i\n", res);
	res = printf("%020x, %020i", u, i);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%.18s", str);
	printf("\nres = %i\n", res);
	res = printf("%.18s", str);
	printf("\nres = %i\n", res);
	printf("\n");
	res = ft_printf("%#x, %i", u, i);
	printf("\nres = %i\n", res);
	res = printf("%#x, %i", u, i);
	printf("\nres = %i\n", res);

	i = 459;
	u = -4345235;
	res = ft_printf("%+d, %i", u, i);
	printf("\nres = %i\n", res);
	res = printf("%+d, %i", u, i);
	printf("\nres = %i\n", res);

	return (0);
} */

/* int	main(void)
{
	int				res;
	char			c;
	char	str[] = "Eres mas feo que el culo de un chimpance con pirrilera.";
	//char			*str;
	int				i;
	unsigned int	u;

	//str = NULL;
	c = 'W';
	i = -10;
	//u = 4294967295;
	u = 65448;
	printf("\n");

	res = ft_printf("MIO: %c\nstr: %s\nint: %i\nunsigned: %u\nhexa_x: %x\
	nhexa_X %X\npercent: %%\ndireccion: %p", c, str, i, u, u, u, str);
	printf ("\nres = %i\n\n", res);
	res = printf("ori: %c\nstr: %s\nint: %i\nunsigned: %u\nhexa_x: %x\
	nhexa_X %X\npercent: %%\ndireccion: %p", c, str, i, u, u, u, str);
	printf ("\nres = %i\n\n", res);
} */

/* int	main(void)
{
	int				res;
	char			c;
	char			str[] = "Te meto media hostia ke te mando a Babilon.";
	//void			*str;
	int				i;
	unsigned int	u;

	c = 'W';
	i = -10;
	u = 4294967295;
	//u = 0;
	//str = NULL;
	printf("\n");

	res = ft_printf("El caracter MIO es: %c\n", c);
	printf ("res = %i\n", res);
	res = printf("El caracter ori es: %c\n", c);
	printf ("res = %i\n\n", res);

	res = ft_printf("El string MIO es: %s\n", str);
	printf ("res = %i\n", res);
	res = printf("El string ori es: %s\n", str);
	printf ("res = %i\n\n", res);

	res = ft_printf("El int i MIO es: %i\n", i);
	printf ("res = %i\n", res);
	res = printf("El int i ori es: %i\n", i);
	printf ("res = %i\n\n", res);

	res = ft_printf("El int d MIO es: %d\n", i);
	printf ("res = %i\n", res);
	res = printf("El int d ori es: %d\n", i);
	printf ("res = %i\n\n", res);

	res = ft_printf("El porcentaje MIO es: %% \n");
	printf ("res = %i\n", res);
	res = printf("El porcentaje ori es: %% \n");
	printf ("res = %i\n\n", res);

	res = ft_printf("El unsigned MIO es: %u \n", u);
	printf ("res = %i\n", res);
	res = printf("El unsigned ori es: %u \n", u);
	printf ("res = %i\n\n", res);

	res = ft_printf("El hexadecimal_x MIO es: %x \n", u);
	printf ("res = %i\n", res);
	res = printf("El hexadecimal_x ori es: %x \n", u);
	printf ("res = %i\n\n", res);

	res = ft_printf("El hexadecimal_X MIO es: %X \n", u);
	printf ("res = %i\n", res);
	res = printf("El hexadecimal_X ori es: %X \n", u);
	printf ("res = %i\n\n", res);

	res = ft_printf("El puntero MIO es: %p \n", str);
	printf ("res = %i\n", res);
	res = printf("El puntero ori es: %p \n", str);
	printf ("res = %i\n\n", res);
} */