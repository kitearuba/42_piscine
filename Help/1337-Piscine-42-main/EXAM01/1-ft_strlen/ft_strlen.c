#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
        i++;
        //write   (1, [i], 1);
    return (str[i]);

}
int main (void)
{
    char x[5] = "1234"
    int len = ft_strlen(x);

    int i = ft_strlen(str);
    write   (1, &i, 1);
    return (0);
}
