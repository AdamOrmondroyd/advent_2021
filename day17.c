#include <stdio.h>
#include <math.h>

int step(int *x, int *y, int *vx, int *vy)
{
    *x += *vx;
    *y += *vy;
    *vx = (*vx - 1) * (*vx > 0) + (*vx + 1) * (*vx < 0);
    *vy -= 1;
}

float quadratic_pos(int a, int b, int c)
{
    float x_plus = (-b + sqrt(b ^ 2 - a * a * c)) / 2 / a;
    float x_minus = (-b - sqrt(b ^ 2 - a * a * c)) / 2 / a;
    return x_plus * (x_plus >= 0) + x_minus * (x_plus < 0);
}

int min(int a, int b)
{
    return a * (a <= b) + b * (a > b);
}

int day17a()
{
    int x1, x2, y1, y2;
    FILE *file;
    file = fopen("input_example.txt", "r");

    if (file)
    {
        fscanf(file, "target area: x=%d..%d, y=%d..%d", &x1, &x2, &y1, &y2);

        // part a
        int vy_max = abs(min(y1, y2)) - 1;
        printf("max height %d\n", vy_max * (vy_max + 1) / 2);

        // part b
        int min_vx_rest = (int)ceil(quadratic_pos(1, 1, -2 * x1));
        int max_vx_rest = (int)floor(quadratic_pos(1, 1, -2 * x2));
        int vy;
        for (vy = y1; vy <= vy_max; vy++)
        {
            int offset = 0;
            int f_vy = vy;
            if (0 == vy)
            {
                offset = 1;
                f_vy = -1;
            }
            else if (vy > 0)
            {
                offset = 2 * vy + 1;
                f_vy = -f_vy - 1;
            }
        }
    }

    fclose(file);
}

int main()
{
    day17a();
    return 0;
}