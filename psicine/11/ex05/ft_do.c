#include <unistd.h>
 
long	ft_plus(int num1, int num2)
{
	return (num1 + num2);
}
 
long	ft_minor(int num1, int num2)
{
	return (num1 - num2);
}
 
long	ft_multi(int num1, int num2)
{
	return (num1 * num2);
}
 
long	ft_div(int num1, int num2)
{
	if (num2 == 0)
		return (-1);
	return (num1 / num2);
}
 
long	ft_mod(int num1, int num2)
{
	if (num2 == 0)
		return (-1);
	return (num1 % num2);
}
