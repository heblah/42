#include <stdlib.h>
#include <stdio.h>

int     linear_congruenial_generator(int x_gen, int c)
{
    int     a;
    int     m;
    
    a = 2;
    m = 9;
    return((((a * x_gen + c) % m)));
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        int rand_num = 3;
        int x = ft_atoi(argv[1]);
        int y = ft_atoi(argv[2]);
        int density = ft_atoi(argv[3]);
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j ++) {
                rand_num = linear_congruenial_generator(rand_num, j);
                if (rand_num < density) 
                {
                    printf("o");
                }
                else 
                {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}
