/*
 ============================================================================
 Name        : Advent_2020_Day_17.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Advent of Code 2020 in C, Ansi-style
 ============================================================================
 */

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct point {
  int x;
  int y;
  int z;
};

int returnPoint(struct point* pointArray
              , int           arraySize
              , int           x
              , int           y
              , int           z) {
int i;

  for (i = 0; arraySize > i; ++i) {
    if (((x + 0) == pointArray[i].x) &&
        ((y + 0) == pointArray[i].y) &&
        ((z + 0) == pointArray[i].z)) {
      return 1;
    }
  }

  return 0;

}

int countPoint(struct point* pointArray
             , int           arraySize
             , int           x
             , int           y
             , int           z) {
int returnValue = 0;


  returnValue += returnPoint(pointArray, arraySize, x - 1, y - 1, z - 1);
  returnValue += returnPoint(pointArray, arraySize, x,     y - 1, z - 1);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y - 1, z - 1);

  returnValue += returnPoint(pointArray, arraySize, x - 1, y,     z - 1);
  returnValue += returnPoint(pointArray, arraySize, x,     y,     z - 1);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y,     z - 1);

  returnValue += returnPoint(pointArray, arraySize, x - 1, y + 1, z - 1);
  returnValue += returnPoint(pointArray, arraySize, x,     y + 1, z - 1);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y + 1, z - 1);


  returnValue += returnPoint(pointArray, arraySize, x - 1, y - 1, z);
  returnValue += returnPoint(pointArray, arraySize, x,     y - 1, z);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y - 1, z);

  returnValue += returnPoint(pointArray, arraySize, x - 1, y,     z);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y,     z);

  returnValue += returnPoint(pointArray, arraySize, x - 1, y + 1, z);
  returnValue += returnPoint(pointArray, arraySize, x,     y + 1, z);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y + 1, z);


  returnValue += returnPoint(pointArray, arraySize, x - 1, y - 1, z + 1);
  returnValue += returnPoint(pointArray, arraySize, x,     y - 1, z + 1);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y - 1, z + 1);

  returnValue += returnPoint(pointArray, arraySize, x - 1, y,     z + 1);
  returnValue += returnPoint(pointArray, arraySize, x,     y,     z + 1);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y,     z + 1);

  returnValue += returnPoint(pointArray, arraySize, x - 1, y + 1, z + 1);
  returnValue += returnPoint(pointArray, arraySize, x,     y + 1, z + 1);
  returnValue += returnPoint(pointArray, arraySize, x + 1, y + 1, z + 1);

  return returnValue;

}

int addPoint(struct point* pointArray
           , int           arraySize
           , int           x
           , int           y
           , int           z) {

  pointArray[arraySize].x = x;
  pointArray[arraySize].y = y;
  pointArray[arraySize].z = z;

  return (arraySize + 1);

}

int removePoint(struct point* pointArray
              , int           arraySize
              , int           x
              , int           y
              , int           z) {
int i;

  for (i = 0;; ++i) {
    if (((x + 0) == pointArray[i].x) &&
        ((y + 0) == pointArray[i].y) &&
        ((z + 0) == pointArray[i].z)) {
      break;
    }
  }

  for (; (arraySize - 1) > i; ++i) {
    pointArray[i] = pointArray[i + 1];
  }

  return (arraySize - 1);

}

int getMinX(struct point* pointArray
          , int           arraySize) {
int i;
int minX = 0x7FFFFFFF;

  for (i = 0; arraySize > i; ++i) {
    if ((minX + 0) > pointArray[i].x) {
      minX = pointArray[i].x;
    }
  }

  return minX;

}

int getMinY(struct point* pointArray
          , int           arraySize) {
int i;
int minY = 0x7FFFFFFF;

  for (i = 0; arraySize > i; ++i) {
    if ((minY + 0) > pointArray[i].y) {
      minY = pointArray[i].y;
    }
  }

  return minY;

}

int getMinZ(struct point* pointArray
          , int           arraySize) {
int i;
int minZ = 0x7FFFFFFF;

  for (i = 0; arraySize > i; ++i) {
    if ((minZ + 0) > pointArray[i].z) {
      minZ = pointArray[i].z;
    }
  }

  return minZ;

}

int getMaxX(struct point* pointArray
          , int           arraySize) {
int i;
int maxX = 0x80000000;

  for (i = 0; arraySize > i; ++i) {
    if ((maxX + 0) < pointArray[i].x) {
      maxX = pointArray[i].x;
    }
  }

  return maxX;

}

int getMaxY(struct point* pointArray
          , int           arraySize) {
int i;
int maxY = 0x80000000;

  for (i = 0; arraySize > i; ++i) {
    if ((maxY + 0) < pointArray[i].y) {
      maxY = pointArray[i].y;
    }
  }

  return maxY;

}

int getMaxZ(struct point* pointArray
          , int           arraySize) {
int i;
int maxZ = 0x80000000;

  for (i = 0; arraySize > i; ++i) {
    if ((maxZ + 0) < pointArray[i].z) {
      maxZ = pointArray[i].z;
    }
  }

  return maxZ;

}

int main(void) {

FILE*    filePtr;
int      fileSize;
char*    fileData;
int      lineNumber;
int      freadSize;
uint64_t answerValue = 0;
int      i;


#define nodoTest
#if defined(doTest)
  if (NULL == (filePtr = fopen("testInput.txt"
                             , "r"))) {
#else
  if (NULL == (filePtr = fopen("actualInput.txt"
                             , "r"))) {
#endif
    puts("\nFile Open Error");
    return EXIT_FAILURE;
  }

  fseek(filePtr
      , 0
      , SEEK_END);
  fileSize = ftell(filePtr);
  fseek(filePtr
      , 0
      , SEEK_SET);

  fileData = malloc(fileSize + 3);

  freadSize = fread(fileData
                  , sizeof(char)
                  , fileSize
                  , filePtr);
  if ('\n' != fileData[freadSize - 1]) {
    fileData[freadSize++] = '\n';
  }
  fileData[freadSize] = '\0';

  for (i = lineNumber = 0; '\0' != fileData[i];) {
    for (; '\n' != fileData[i]; ++i) {  }
    ++lineNumber;  ++i;
  }



//todo: Put in Data Process code
struct point* cubeSpace[2];
int           cubeSpaceSize;
int           cubeSpaceUsed[2] = { 0 };
int           currentSpace;

int           x;
int           y;
int           z;

int           minX;
int           maxX;
int           minY;
int           maxY;
int           minZ;
int           maxZ;

int           pointCount;


  cubeSpace[0] = malloc(sizeof(struct point) * (cubeSpaceSize = 512));
  cubeSpace[1] = malloc(sizeof(struct point) * cubeSpaceSize);

  for (i = y = 0; '\0' != fileData[i]; ++y, ++i) {
    for (x = 0; '\n' != fileData[i]; ++x, ++i) {
      if ('#' == fileData[i]) {
        cubeSpaceUsed[0] = addPoint(cubeSpace[0]
                                  , cubeSpaceUsed[0]
                                  , x
                                  , y
                                  , 0);
      }
    }
  }

  for (i = currentSpace = 0; 6 > i; ++i, currentSpace ^= 1) {
    minX = getMinX(cubeSpace[currentSpace], cubeSpaceUsed[currentSpace]);  maxX = getMaxX(cubeSpace[currentSpace], cubeSpaceUsed[currentSpace]);
    minY = getMinY(cubeSpace[currentSpace], cubeSpaceUsed[currentSpace]);  maxY = getMaxY(cubeSpace[currentSpace], cubeSpaceUsed[currentSpace]);
    minZ = getMinZ(cubeSpace[currentSpace], cubeSpaceUsed[currentSpace]);  maxZ = getMaxZ(cubeSpace[currentSpace], cubeSpaceUsed[currentSpace]);

    cubeSpaceUsed[currentSpace ^ 1] = 0;  //  Erase other universe before writing to it with the new values
    for (x = minX - 1; (maxX + 1) >= x; ++x) {
      for (y = minY - 1; (maxY + 1) >= y; ++y) {
        for (z = minZ - 1; (maxZ + 1) >= z; ++z) {
          pointCount = countPoint(cubeSpace[currentSpace]
                                , cubeSpaceUsed[currentSpace]
                                , x
                                , y
                                , z);
          if (returnPoint(cubeSpace[currentSpace]
                        , cubeSpaceUsed[currentSpace]
                        , x
                        , y
                        , z)) {
            if ((2 <= pointCount) && (3 >= pointCount)) {  //  Point still active
              cubeSpaceUsed[currentSpace ^ 1] = addPoint(cubeSpace[currentSpace ^ 1]
                                                       , cubeSpaceUsed[currentSpace ^ 1]
                                                       , x
                                                       , y
                                                       , z);
            }
          }
          else {
            if (3 == pointCount) {  //  Point still active
              cubeSpaceUsed[currentSpace ^ 1] = addPoint(cubeSpace[currentSpace ^ 1]
                                                       , cubeSpaceUsed[currentSpace ^ 1]
                                                       , x
                                                       , y
                                                       , z);
            }
          }
        }
      }
    }
  }

  answerValue = cubeSpaceUsed[currentSpace];


  free(cubeSpace[0]);
  free(cubeSpace[1]);

  free(fileData);
  fclose(filePtr);

  printf("\n%I64d"
       , answerValue);

	return EXIT_SUCCESS;

}
