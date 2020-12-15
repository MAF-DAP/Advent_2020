/*
 ============================================================================
 Name        : Advent_2020_Day_6a.c
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

int main(void) {
FILE* filePtr;
char* fileData;
int   fileSize;
int   checkSize;
int   i;
int   j;
int   questionRecord[26];
int   questionTotal;


#define nodoTest
#ifdef  doTest
  if (NULL == (filePtr = fopen("src/inputa.txt"
                             , "rb"))) {
#else
  if (NULL == (filePtr = fopen("src/inputActual.txt"
                             , "rb"))) {
#endif
    puts("No File Open Joy");
  }
  else {
    fseek(filePtr
        , 0
        , SEEK_END);
    fileSize = ftell(filePtr);
    fseek(filePtr
        , 0
        , SEEK_SET);

    if (NULL == (fileData = malloc(fileSize + 4))) {
      puts("No Malloc Joy");
    }
    else {
      if (fileSize != (checkSize = fread(fileData
                      , sizeof(char)
                      , fileSize
                      , filePtr))) {
        puts("No Read Joy");
      }
      else {
        if (('\r' != fileData[fileSize - 1]) && ('\n' != fileData[fileSize - 1])) {
          fileData[fileSize++] = '\r';  fileData[fileSize++] = '\n';
        }
        fileData[fileSize] = '\0';
        for (i = questionTotal = 0; '\0' != fileData[i];) {
          for (j = 0; 26 > j; ++j) {  questionRecord[j] = 0;  }
          for (;;) {
            if (('\r' == fileData[i]) || ('\n' == fileData[i])) {
              if (('\r' == fileData[i]) && ('\n' == fileData[i + 1])) {
                i += 2;
              }
              else if (('\n' == fileData[i]) && ('\r' == fileData[i + 1])) {
                i += 2;
              }
              else {
                ++i;
              }
              if (('\r' == fileData[i]) || ('\n' == fileData[i]) || ('\0' == fileData[i])) {
                break;
              }
            }
            else {
              for (; ('\r' != fileData[i]) && ('\n' != fileData[i]); ++i) {  questionRecord[fileData[i] - 'a'] = 1;  }
            }
          }
          for (j = 0; 26 > j; ++j) {  if (questionRecord[j]) {  ++questionTotal;  }  }
          if (('\r' == fileData[i]) || ('\n' == fileData[i])) {
            if (('\r' == fileData[i]) && ('\n' == fileData[i + 1])) {
              i += 2;
            }
            else if (('\n' == fileData[i]) && ('\r' == fileData[i + 1])) {
              i += 2;
            }
            else {
              ++i;
            }
          }
        }
      }
      free(fileData);
    }
    fclose(filePtr);
  }

	puts("Good to Go"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
