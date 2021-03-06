/*
 ============================================================================
 Name        : Advent_2020_Day_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {
#define nodoTest
#ifdef  doTest
#define TREEWIDTH 65
char treeSpread[][TREEWIDTH + 1] = {
//    01234567890123456789012345678901234567890123456789012345678901234567890
//              1111111111222222222233333333334444444444555555555566666666667
     "..##.........##.........##.........##.........##.........##......."
  ,  "#...#...#..#...#...#..#...#...#..#...#...#..#...#...#..#...#...#.."
  ,  ".#....#..#..#....#..#..#....#..#..#....#..#..#....#..#..#....#..#."
  ,  "..#.#...#.#..#.#...#.#..#.#...#.#..#.#...#.#..#.#...#.#..#.#...#.#"
  ,  ".#...##..#..#...##..#..#...##..#..#...##..#..#...##..#..#...##..#."
  ,  "..#.##.......#.##.......#.##.......#.##.......#.##.......#.##....."
  ,  ".#.#.#....#.#.#.#....#.#.#.#....#.#.#.#....#.#.#.#....#.#.#.#....#"
  ,  ".#........#.#........#.#........#.#........#.#........#.#........#"
  ,  "#.##...#...#.##...#...#.##...#...#.##...#...#.##...#...#.##...#..."
  ,  "#...##....##...##....##...##....##...##....##...##....##...##....#"
  ,  ".#..#...#.#.#..#...#.#.#..#...#.#.#..#...#.#.#..#...#.#.#..#...#.#"
  ,  "*"
#else
#define TREEWIDTH 31
char treeSpread[][TREEWIDTH + 1] = {
//  01234567890123456789012345678901234567890123456789012345678901234567890
//            1111111111222222222233333333334444444444555555555566666666667
   ".......#................#......"
,  "...#.#.....#.##.....#..#......."
,  "..#..#.#......#.#.#............"
,  "....#...#...##.....#..#.....#.."
,  "....#.......#.##......#...#..#."
,  "...............#.#.#.....#..#.."
,  "...##...#...#..##.###...##....."
,  "##..#.#...##.....#.#..........#"
,  ".#....#..#..#......#....#....#."
,  "...........................#..."
,  "..........#.......#..#.....#.#."
,  "..#.......###..#.#.......#.#..."
,  "....#..#....#....#..........#.."
,  "..##..#.......#.#...#.........."
,  ".....#.......#.....#....#......"
,  "..........##..#................"
,  "....##.#..###...#..##.....#.#.."
,  "..#..#.#.#...#......#...#.....#"
,  "....#.#....#...####.##........."
,  "..#.........##...##.#..#..#...."
,  ".#......#...#..#..##.#........."
,  ".#....#.......#..##..##..#.#.#."
,  "...........#....#......#......."
,  "..#....#....#...............#.."
,  "..#.....#....###.##.....#.#..#."
,  "#..........#.#......#.#....#..."
,  "....###...#.#.....#....#.####.#"
,  "........#......#...#...#..##..#"
,  "...##..............##.#.......#"
,  "#..........#...........#.#....#"
,  "#...#....#..####..#............"
,  "###....#........#.............."
,  "...#.##....................#.##"
,  "...#..#.....#.....##...#....#.."
,  ".......###.#...#.........#....."
,  ".#..#.....#.#..#.....#........."
,  "#................#............."
,  "...#......#.#.....##.#.#....#.."
,  "...#..#.#..#.....#...#....#...."
,  ".......#......#........#.....#."
,  ".#.##..##.....#.#......#.#.#..."
,  "#...............#.....#....#..."
,  ".....#...........#..##........."
,  ".....#..#........##..#..#.....#"
,  "..###.#.#.......#.#...........#"
,  "##....##....#.#....##...#.##.##"
,  "..................##.#.#.....#."
,  ".#...........###...#..........."
,  ".#.#....#......#....###.#......"
,  ".......#.##...#...#..#.#......."
,  "..#.....#.#....#..#............"
,  ".....#..#..#....#..#.........#."
,  "..##.#......#.....#...#.#..#.#."
,  ".........#......#....##.......#"
,  "#........#..#.#......#...#.#..#"
,  "...#....#.#..#....##.......###."
,  "..#...#......#.##..........#..."
,  "........#..#..#...#.......#...."
,  ".##.#..#...#..#........#.#.####"
,  "#..#..#..........#....##...#..."
,  "....#...#........##........#..."
,  ".#......#.......#..#..#........"
,  "#...#.#......#....#............"
,  "#........#..##.#...##.........."
,  "...#..##.....#......##.#..#.#.."
,  ".#.#.....#.....#.####.#..##...."
,  "..........###....#.##...#......"
,  ".......#.......#..#.#.#.##.#..#"
,  "..#.#....#......#.#...#.......#"
,  ".#...#....#......#...#........."
,  ".#....#..#....#.##.#....#..##.."
,  "...#..#.#..................#..."
,  ".##..#.............##.........#"
,  "...#.#.#................#.....#"
,  "...###..###..................#."
,  "........##.##..#.#...#.....#..."
,  ".##...##...#...#....#...#......"
,  "#..#....#..#..#.#....#..####..."
,  ".#...............##....##.#...."
,  "#..#................#...#..#..."
,  ".#....#.....#..#.#........#...."
,  "...............##.#..##..##...."
,  ".#......#........#....#.#...#.#"
,  ".#.....#...##.#........#.##.#.#"
,  "..###............#..#.#....#..."
,  "..#.....#.........#....#..#.#.."
,  ".##.....#.#..........#.#....##."
,  "...#...#....#..#......#.#.#..#."
,  "#.....#...#....##...#.......##."
,  ".......#.#.........##.........."
,  "............##.#.##...#.......#"
,  ".....#........##...#........#.."
,  ".#........#.#.#.#....#........."
,  "#....#..#....#.#..#...#.#......"
,  "....##...........#...#...##.#.#"
,  "......#...##.###.....#........."
,  "............#..##....##......#."
,  "......##....#...#.#....#......#"
,  "#..#..#..#.#.#.........#...##.#"
,  "...#.........#...#.........##.#"
,  "#.#.....#.......#.##..#..#....."
,  "##................#......#....#"
,  "....#..#.......#....##.....#..."
,  ".....#..#...#...#......#.#....#"
,  "..#....#.....#.........#.....#."
,  "..#..#..........#.....#........"
,  ".......#..##.#......#.#........"
,  ".............##.....#....#....."
,  "...#....#..#.#.#..............."
,  "........#....##..#...#........#"
,  "..##...............#.....#....#"
,  "........##.#.##.#......#..#...."
,  "..#.##.......#..........##..#.."
,  ".#..............#.#.##........."
,  ".#.......#....#....#.#.#......."
,  ".#.##.......#....#......###.#.."
,  ".......#...#............##....."
,  "........#.#..........##..#....."
,  "...###..#......#.....##..#..#.."
,  "...........##......#....#......"
,  "..............#....#..#..#.#..#"
,  "....#...#......#.##...#........"
,  ".#.............#..#......###.#."
,  "#...#..#.#..............##..#.#"
,  "....................#.........#"
,  "..##..#......#.###.....#...#.#."
,  ".#....#.#........#...#........#"
,  "..#....#.....#..............#.."
,  "##..........#..#..#...#........"
,  "...........#..##...#.......#..."
,  "........##.............#......."
,  "#....#........#..#.#.###..#...."
,  "...........##..........##......"
,  "#......#.....##.#.##......##..."
,  "..#......#.........#.......#..#"
,  "......#.#....##..##.#...#.#...#"
,  "......#..................##...."
,  "...#....#.#...#.#.......##....."
,  "#.#...##...##........#...##...."
,  "..#.......#.#.#...#............"
,  ".......#......#..#...#........."
,  "#...#..#...........##.........."
,  "......#....#.........#.#....#.."
,  "#......#........#...#..##....#."
,  ".....#.......##..#.#......#..#."
,  "...........#......#...#......#."
,  "#.#.##.....#....#.....##......#"
,  ".....##..#.#.#.###........#.#.."
,  "...#...#.#......#......#......."
,  "......###....#..##...#.#.##...."
,  "#.....#.....#.................."
,  "...#...#......#...............#"
,  "..#............##..#.....#....."
,  ".#....#...#...#...#...#..#....."
,  ".##......#.........#.###.#....."
,  "#.#.##.......##...#........##.#"
,  ".##.#.#......#.....#...#.....#."
,  "....####.##.......#..##..##.#.."
,  "#.#.......#..##....###..#...#.."
,  "..#..#....#...#.#.#.#...#......"
,  "##.........#.##................"
,  "........#.....................#"
,  "..#...........#..#..##.#..#.#.."
,  "#...#...................#.###.."
,  "##..#............#.........#..#"
,  "...............##...#...##....#"
,  "#.#.....#..#.......#......#...."
,  ".#...#......#............#....."
,  "#.......#...#..#....#.......#.."
,  "...#....#.##.#....#....#.#....."
,  "...#..#..............#..#.#..#."
,  ".........#.....#.#...#..#....#."
,  "..#..#..#...##.....##.#.....#.."
,  ".#.#..........#........#......."
,  "...............#........#.#.#.."
,  ".#......#.....#..............#."
,  "........#.#..............#.#..."
,  ".......#.#....#..#.#.#..#.#.##."
,  "...##..#...#.#..#...........#.."
,  "#...###.#.....#..#........#...."
,  ".#...##...##...##.#.....###...."
,  ".........#......#.#..##.#.#...."
,  "#....#.#..#...#.#.#....#..#..#."
,  ".#.#...#......###.....#........"
,  "#.....#.#.......#..#.#...#....."
,  ".................#.#....#..##.."
,  "#...........#....###..#......#."
,  "##.#..#....#.#.#.#............."
,  "#.....#..#...#........#........"
,  "..#..#......#..#.##.#.........."
,  "...#....#..#..........#.#.##.##"
,  "#........#...#.......#..##.#..."
,  ".#.#..#....#.#....#......#....."
,  "##.......##.#........#...#..##."
,  "##.##.....#.......#####.#....#."
,  "..#..###.#.#..#....###..#.##..#"
,  "#.........#.............#.#...#"
,  "..#...##.#..................#.."
,  ".....#.#....#.#..#.#........#.#"
,  "......#.......#.#..##.#.#..#..."
,  "..#......#.#..##......#..#....#"
,  "..##..#..#.##.#..#....#...##..."
,  "###....#...##....##.........#.."
,  "#........##.........#......#..#"
,  "...#.........#......#.##......."
,  ".....#.#.#....#......#........."
,  "..#...........#....#......#.#.."
,  "##........#...##.....######...."
,  "....#..#..##.......#..#..#....."
,  "..#....#..##....#......##....#."
,  "...##....#........##......#...."
,  ".#.#...###...#......#.........."
,  "#....#..#.##.........#...#....."
,  "......#..#.........#.##.....#.."
,  "...#............##....#......#."
,  "...#.....##.....#........#.#..#"
,  "......#.#..#......#.....#..##.."
,  "#.#.........##..........#......"
,  "..###.....#..#....##..........#"
,  ".............##..#....#..##...."
,  "....#.#....##..#......#...#...."
,  "....###.....#..#.......#......."
,  "............#..#..............."
,  "......#........#..#......#....."
,  ".#........#.......#.##.......#."
,  "..#.........#..#.#.....##....#."
,  "...#.......#.......#.......##.#"
,  "#......##.#.....#......##.#..#."
,  "#..........#.................#."
,  "....#..##...........#.....#.#.."
,  "#.###...#............#.#....#.#"
,  "....#......#.#..###....##..#..."
,  "....#...#..........##.........."
,  "..#.#............#...#...###..."
,  "......#...#......#..#.#........"
,  ".#.......#..#...........##...#."
,  "##...#...##....##.#..#..#.#...."
,  ".......#........#............##"
,  ".#......#...#.#................"
,  "#.#........#.#....#..#.##......"
,  ".......#.#...#....##.......##.."
,  "........#.#.#.........##..##..."
,  "..##...............#.#.###.#..."
,  "......#.#....#..#......##.....#"
,  "###.........#.....#.#.....##..."
,  ".#.#....#.....#.#.##..#.......#"
,  "..#..#.#......#...##..##.#..#.."
,  "...#........#..#....#.........."
,  "#...#.#...#..##....##.........."
,  ".........#........#.##....#..#."
,  "..#...#.#.......##..........##."
,  "###...........##.#......#.#..#."
,  "...#....#...#..#..#......#....."
,  ".....##.......###.#....###..##."
,  "...#...#..........#.#......#..."
,  "....#.....##...##..#.#........#"
,  ".....#...#..#.....##...##....#."
,  "................##.#.##....##.#"
,  ".#..#..#....#.....#....#..#...#"
,  ".....###.....#................."
,  "#...#..##..#.........#........."
,  ".....#..#................#....."
,  ".#..#...#......#..#............"
,  "...#...#.#....#....##...#...##."
,  "..........#....#.#..#.#.....#.."
,  "....#...###.##...#..#..#......#"
,  "#...#.......#..........#..#...."
,  ".#............#..##.......#...#"
,  "....#..#...#............#..#.#."
,  ".#....#.......#..#.#......#...."
,  "...#...#............#...#.....#"
,  "....#.#.#..##.#.....#...#.#...."
,  "......#.#.#......#..#...#.....#"
,  "......##.....#.............#..."
,  "..#...#..#.#....#.............."
,  ".#.#..#....#.#..##....###.##..."
,  "..#...........#....#.###.#....#"
,  ".....#.........#.#............."
,  "...#.#.....#......###......##.."
,  "...#...#.....#................."
,  "...#..#...##.....##.........#.."
,  "..#...#..#..##..#...#........#."
,  "##..#.#.##.#....#...........#.."
,  ".......#....##....#...##..#..#."
,  "#.......##.#...##...##..#.....#"
,  "....#.#...............#......#."
,  "....#.#...#.....#....#......#.."
,  ".#.........#.#....###........#."
,  ".#.#.....#.....#.#.#....#.#...."
,  "............#...........#.#..##"
,  "#...#......#..#......#.#......."
,  "...#.#.#.....#..#...#..##......"
,  "...#.#..#...#....#.........#.#."
,  "........#..#......##.....#...#."
,  "...#..#..............#..#......"
,  ".........#.......#...#......#.."
,  ".#......#.....#.....#......#..."
,  "......#.......#....#...#.#....."
,  ".#.....#.##..#........#...#...."
,  "#.....##..##....#.#.......#..#."
,  ".#..#...#..#.......#..........."
,  "..#..#...#.....##....#.....#..."
,  "#.#..............#....#..#....."
,  ".........##...#......#.##...##."
,  ".###...#.#...#.....#.........#."
,  ".....#..........##...#..#....##"
,  ".#..#......#....##.#...#......."
,  ".............###.#.#..#.#.#...#"
,  ".......#...##..#..#.....###...."
,  "##.......#...........#....#.#.."
,  "##......#...#.#................"
,  ".#.####..##.#...............#.."
,  "..#...#.#.#..#...#........#...#"
,  ".##..##.##.....#.......#..#.#.."
,  "...................#......#.#.."
,  "#.##..#..........#............."
,  "##..#......#....#.#............"
,  ".#........#.....##...#........."
,  ".##....#..#..##..........#...#."
,  "#..........##........#..#..#.#."
,  "####.###.#.....#....#..#.#....#"
,  "..#...#...#.#.......#....#...#."
,  "......##.###..##.#.###......#.#"
,  "*"
#endif
};
int x;
int y;
int treehit11;
int treehit31;
int treehit51;
int treehit71;
int treehit12;
uint64_t treeProduct = 1;


// Right 1 - Down 1
  for (x = y = treehit11 = 0; '*' != treeSpread[y][0]; x += 1, ++y) {
    if ('#' == treeSpread[y][x % TREEWIDTH]) {
      ++treehit11;
    }
  }
  treeProduct *= treehit11;

// Right 3 - Down 1
  for (x = y = treehit31 = 0; '*' != treeSpread[y][0]; x += 3, ++y) {
    if ('#' == treeSpread[y][x % TREEWIDTH]) {
      ++treehit31;
    }
  }
  treeProduct *= treehit31;

// Right 5 - Down 1
  for (x = y = treehit51 = 0; '*' != treeSpread[y][0]; x += 5, ++y) {
    if ('#' == treeSpread[y][x % TREEWIDTH]) {
      ++treehit51;
    }
  }
  treeProduct *= treehit51;

// Right 7 - Down 1
  for (x = y = treehit71 = 0; '*' != treeSpread[y][0]; x += 7, ++y) {
    if ('#' == treeSpread[y][x % TREEWIDTH]) {
      ++treehit71;
    }
  }
  treeProduct *= treehit71;

// Right 1 - Down 2
  for (x = treehit12 = 0, y = 1; '*' != treeSpread[y][0]; ++y) {
    if (0 == (y % 2)) {
      if ('#' == treeSpread[y][++x % TREEWIDTH]) {
        ++treehit12;
      }
    }
  }
  treeProduct *= treehit12;

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
