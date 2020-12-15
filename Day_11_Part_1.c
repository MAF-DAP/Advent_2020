/*
 ============================================================================
 Name        : Advent_2020_Day_11.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>


int numberOccupied(char* roomSetting
                 , int   x
                 , int   y
                 , int   cols
                 , int   rows) {
int returnValue = 0;


  if (x != 0) {
    if (y != 0) {
      if ('#' == roomSetting[((y - 1) * (cols + 1)) + (x - 1)]) {
        ++returnValue;
      }
    }
    if ('#' == roomSetting[((y + 0) * (cols + 1)) + (x - 1)]) {
      ++returnValue;
    }
    if ((y + 1) < rows) {
      if ('#' == roomSetting[((y + 1) * (cols + 1)) + (x - 1)]) {
        ++returnValue;
      }
    }
  }

  if (0 != y) {
    if ('#' == roomSetting[((y - 1) * (cols + 1)) + (x + 0)]) {
      ++returnValue;
    }
    if ((x + 1) < cols) {
      if ('#' == roomSetting[((y - 1) * (cols + 1)) + (x + 1)]) {
        ++returnValue;
      }
    }
  }

  if ((x + 1) < cols) {
    if ('#' == roomSetting[((y + 0) * (cols + 1)) + (x + 1)]) {
      ++returnValue;
    }
    if ((y + 1) < rows) {
      if ('#' == roomSetting[((y + 1) * (cols + 1)) + (x + 1)]) {
        ++returnValue;
      }
    }
  }

  if ((y + 1) < rows) {
    if ('#' == roomSetting[((y + 1) * (cols + 1)) + (x + 0)]) {
      ++returnValue;
    }
  }

  return returnValue;

}



int main(void) {

FILE* filePtr;
int   fileSize;
char* fileData;
int   lineNumber;
int   checkSize;
int   errorFlag   = 0;
int   answerValue = 0;
char  answer[10]  = { '\0' };
int   i;


#define nodoTest
#ifdef  doTest
  if (NULL == (filePtr = fopen("testInput.txt"
                             , "r"))) {
#else
  if (NULL == (filePtr = fopen("actualInput.txt"
                             , "r"))) {
#endif
    puts("No File Open Joy");  errorFlag = 1;
  }
  else {
    fseek(filePtr
        , 0
        , SEEK_END);
    fileSize = ftell(filePtr);
    fseek(filePtr
        , 0
        , SEEK_SET);

    if (NULL == (fileData = malloc(fileSize + 3))) {
      puts("No Malloc Joy");  errorFlag = 1;
    }
    else {
      if (!(checkSize = fread(fileData
                            , sizeof(char)
                            , fileSize
                            , filePtr))) {
        puts("No Read Joy");  errorFlag = 1;
      }
      else {
        if ('\n' != fileData[checkSize - 1]) {
          fileData[checkSize++] = '\n';
        }
        fileData[checkSize] = '\0';

        for (i = lineNumber = 0; '\0' != fileData[i];) {
          for (; '\n' != fileData[i]; ++i) {  }
          ++lineNumber;  ++i;
        }



//todo: Put in Data Process code
char* roomSetting[2];
int   currentRoom;
int   iteration;
int   cols;
int   rows           = lineNumber;
int   x;
int   y;
int   sameFlag;


        roomSetting[0] = malloc(fileSize + 3);
        roomSetting[1] = malloc(fileSize + 3);
        for (i = 0; '\0' != (roomSetting[0][i] = roomSetting[1][i] = fileData[i]); ++i) {  }
        for (cols = 0; '\n' != fileData[cols]; ++cols) {  }

        for (i = 0; '\0' != roomSetting[0][i]; ++i) {
          if ('L' == roomSetting[0][i]) {
            roomSetting[0][i] = '#';
          }
        }

        for (currentRoom = iteration = 0;; currentRoom ^= 1, ++iteration) {
          for (y = 0; (rows + 0) > y; ++y) {
            for (x = 0; (cols + 0) > x; ++x) {
              if ('L' == roomSetting[currentRoom][(y * (cols + 1)) + x]) {
                if (0 == numberOccupied(roomSetting[currentRoom]
                                      , x
                                      , y
                                      , cols
                                      , rows)) {
                  roomSetting[currentRoom ^ 1][(y * (cols + 1)) + x] = '#';
                }
                else {
                  roomSetting[currentRoom ^ 1][(y * (cols + 1)) + x] = 'L';
                }
              }
              else if ('#' == roomSetting[currentRoom][(y * (cols + 1)) + x]) {
                if (4 <= numberOccupied(roomSetting[currentRoom]
                                      , x
                                      , y
                                      , cols
                                      , rows)) {
                  roomSetting[currentRoom ^ 1][(y * (cols + 1)) + x] = 'L';
                }
                else {
                  roomSetting[currentRoom ^ 1][(y * (cols + 1)) + x] = '#';
                }
              }
            }
          }
          for (y = 0, sameFlag = 1; (sameFlag) && ((rows + 0) > y); ++y) {
            for (x = 0; (sameFlag) && ((cols + 0) > x); ++x) {
              if (roomSetting[currentRoom][(y * (cols + 1)) + x] != roomSetting[currentRoom ^ 1][(y * (cols + 1)) + x]) {
                sameFlag = 0;
              }
            }
          }
          if (sameFlag) {
            break;
          }
        }

        for (answerValue = 0, i = 0; '\0' != roomSetting[0][i]; ++i) {
          if ('#' == roomSetting[0][i]) {
            ++answerValue;
          }
        }

        free(roomSetting[0]);
        free(roomSetting[1]);

      }
      free(fileData);
    }
    fclose(filePtr);
  }

  if (!errorFlag) {
    if (!answerValue) {
      answer[i = 8] = '0';
    }
    else {
      for (i = 8; answerValue; --i, answerValue /= 10) {
        answer[i] = (answerValue % 10) + '0';
      }
      ++i;
    }
    printf("\n%s"
         , &answer[i]);
  }

	return EXIT_SUCCESS;
}
