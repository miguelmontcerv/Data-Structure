// Hanoi Tower
/* This is an ordinary hanoi's tower program */
#include <stdio.h>
void HanoiTower (int disk, char from, char to, char aux);

int
main (void)
{
  int max;
  scanf ("%d", &max);

  HanoiTower (max, 'A', 'C', 'B');
  printf ("\n");
  return 0;
}

void
HanoiTower (int disk, char from, char to, char aux)
{
  if (disk == 1)
    {
      printf ("Disk %d: %c -> %c\n", disk, from, to);
      return;
    }
  HanoiTower (disk - 1, from, aux, to);
  printf ("Disk %d: %c -> %c\n", disk, from, to);
  HanoiTower (disk - 1, aux, to, from);
}
