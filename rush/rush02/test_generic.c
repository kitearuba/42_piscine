

#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 100

char* ft_strchr(char *s, int c) {
   int i;

   i = 0;
   while (s[i] != '\0')
   {
       if (s[i] == c)
           return (&s[i]);
       i++;
   }
   return NULL;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' )
	{
		if (str[i] == '\n')
			str[i] = ' ';
		write(1, &str[i], 1);
		i++;
	}
}

int ft_atoi(char *s) {
    int num;
    int sign;
    int i;

    num = 0;
    sign = 1;
    i = 0;
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return (num * sign);
}

ssize_t ft_fgets(char* buf, int buf_size, int fd) {
    int i;

    i = 0;
    while (i < buf_size - 1) {
        ssize_t result = read(fd, &buf[i], 1);
        if (result <= 0) { // End of file or error
            if (i == 0) return result; // No data read
            break;
        }
        if (buf[i] == '\n') { // read new line
            i++;
            break;
        }
        i++;
    }
    buf[i] = '\0';
    return i; // i = number of bytes read
}



int find_value_in_file(char* filename, int target)
{
	char *error = "Error on reading file";
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
	{
        ft_putstr(error);
        return -1;
    }
    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (ft_fgets(line, MAX_LINE_LENGTH, fd) > 0) {
        char* colon = ft_strchr(line, ':');
        if (colon) {
            *colon = '\0';
            int number = ft_atoi(line);
            if (number == target) {
                found = 1;
				ft_putstr(colon + 2);
                break;
            }
        }
    }

    close(fd);
    return found;
}

void ft_verify_number(char* filename, long long target) {
    if (target < 21){        
        find_value_in_file(filename, target);
    } else if (target < 100) {
        int tens = target / 10 * 10;
        int units = target % 10;
        find_value_in_file(filename, tens);
        if (units > 0) {
            ft_verify_number(filename, units);
        }
    } else if (target < 1000) {
	//	if (target / 100 == 1)
			
        int hundreds = target / 100;
        int remainder = target % 100;
		if (hundreds >= 1) ft_verify_number(filename, hundreds);
        find_value_in_file(filename, 100);
        if (remainder > 0) ft_verify_number(filename, remainder);
    } else {
        // For numbers 1000 and above, find the correct magnitude and handle accordingly
        long long place = 1000;
        long long higher = target;
        while (higher / 1000 >= 1000) {
            place *= 1000;
            higher /= 1000;
        }
        long long leading = target / place;
        long long remainder = target % place;

        ft_verify_number(filename, leading);
        find_value_in_file(filename, place);

        if (remainder > 0) {
            // This ensures correct spacing and handling for numbers like "1001" (e.g., one thousand one)
            if (remainder < 100) find_value_in_file(filename, 0); // For "zero" if needed, adjust based on your formatting needs
            ft_verify_number(filename, remainder);
        }
    }
}

int main(int argc, char *argv[]) {
	char *error = "Error on input";
    if (argc != 2) {
		ft_putstr(error);
		return 1;
    }

    char* filename = "numbers.dict";
	int target = ft_atoi(argv[1]);
    //int found =
		ft_verify_number(filename, target);
   /* if (found == 0) {
		ft_putstr(error);
    }*/

    return 0;
}
