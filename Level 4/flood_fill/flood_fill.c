
#include <stdio.h>
#include "flood_fill.t_point.h"
// typedef struct	s_point
// {
// 	int x;
// 	int y;
// } t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
int main() {
    // Declare a modifiable 2D array
    char grid[][6] = {
        "aaaaa",
        "abbba",
        "abbba",
        "abbba",
        "aaaaa"
    };

    // Convert the 2D array to a pointer array
    char *tab[5];
    for (int i = 0; i < 5; i++)
        tab[i] = grid[i];

    t_point size = {5, 5};      // Grid dimensions
    t_point begin = {4, 4};     // Starting point

    // Apply flood fill
    flood_fill(tab, size, begin);
    // flood_fill(grid, size, begin);

    // Print the modified grid
    for (int i = 0; i < size.y; i++)
        printf("%s\n", grid[i]);

    return 0;
}