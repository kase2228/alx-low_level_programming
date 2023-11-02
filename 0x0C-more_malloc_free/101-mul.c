#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * _is_zero - Checks if a number is zero
 * @num: Number as a string
 *
 * Return: 1 if the number is zero, 0 otherwise
 */
int _is_zero(char *num) {
    while (*num) {
        if (*num != '0') {
            return 0;
        }
        num++;
    }
    return 1;
}

/**
 * _initialize_array - Initializes a character array with '0'
 * @ar: Character array
 * @lar: Length of the character array
 */
void _initialize_array(char *ar, int lar) {
    for (int i = 0; i < lar; i++) {
        ar[i] = '0';
    }
    ar[lar] = '\0';
}

/**
 * _checknum - Check if a string represents a valid number and return its length
 * @num: Number as a string
 *
 * Return: Length of the number
 */
int _checknum(char *num) {
    int ln = 0;
    while (num[ln]) {
        if (!isdigit(num[ln])) {
            printf("Error\n");
            exit(98);
        }
        ln++;
    }
    return ln;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        exit(98);
    }

    if (_is_zero(argv[1]) || _is_zero(argv[2])) {
        printf("0\n");
        return 0;
    }

    int ln1 = _checknum(argv[1);
    int ln2 = _checknum(argv[2]);
    int lnout = ln1 + ln2;
    
    char *nout = malloc(lnout + 1);
    
    if (nout == NULL) {
        printf("Error\n");
        exit(98);
    }
    
    _initialize_array(nout, lnout);
    
    int k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = 0, addl = 0;
    
    for (; k >= 0; k--, i--) {
        if (i < 0) {
            if (addl > 0) {
                int add = (nout[k] - '0') + addl;
                if (add > 9) {
                    nout[k - 1] = (add / 10) + '0';
                }
                nout[k] = (add % 10) + '0';
            }
            i = ln1 - 1;
            j--;
            addl = 0;
            ca++;
            k = lnout - 1 - ca;
        }

        if (j < 0) {
            if (nout[0] != '0') {
                break;
            }
            lnout--;
            free(nout);
            nout = malloc(lnout + 1);
            _initialize_array(nout, lnout);
            k = lnout - 1;
            i = ln1 - 1;
            j = ln2 - 1;
            ca = 0;
            addl = 0;
        }
        
        if (j >= 0) {
            int add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (nout[k] - '0') + addl;
            addl = add / 10;
            nout[k] = (add % 10) + '0';
        }
    }

    printf("%s\n", nout);
    free(nout);
    
    return 0;
}
