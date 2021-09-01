#include "my.h"

void	my_put_nbr (int nb)
{
	int last_digit;

	if (nb < 0 && nb >= -2147483647) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb == -2147483648)
		my_putstr("-2147483648");
	if (nb >= 0) {
		if (nb >= 10) {
			last_digit = (nb % 10);
			nb = (nb - last_digit) / 10;
			my_put_nbr(nb);
			my_putchar('0' + last_digit);
		} else {
			my_putchar('0' + nb % 10);
		}
	}
}
