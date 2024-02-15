#ifndef GAMEFUNCT_H

#define GAMEFUNCT_H

int playercount();
int validplay(int roll[5]);
void roller(int roll[5], int size, int start);
int checker(int roll[5], int check, int start);
void handreset(int roll[5]);

#endif