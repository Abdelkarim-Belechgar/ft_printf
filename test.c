#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>



int ft_printf(const char *str, ...) {
    va_list ap;
    int len = 0;
    va_start(ap, str);
    while (*str) {
        if (*str == '%') {
            if (*(str + 1) == '%') {
                len += ft_putchar('%');
                str += 2;
                continue;
            }
            len += ft_print(str, ap);
            str++;
        } else {
            len += ft_putchar(*str);
        }
        str++;
    }
    va_end(ap);
    return len;
}

int main(void) {
    char *str = NULL;
    ft_printf("hello = %k\n", str);
    printf("hello = %k\n", str);
    return 0;
}
