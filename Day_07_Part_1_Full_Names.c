/*
 ============================================================================
 Name        : Advent_2020_Day_6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <windows.h>
#include <tchar.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sgSearch(char* searchData
           , char* searchString
           , int  depth) {
int  i;
int  j;
int  k;
int  returnValue = 0;
char nameString[64];


  printf("%s[ "
       , searchString);
  for (i = 0; '\0' != searchData[i];) {
    for (k = 0; ' ' != (nameString[k] = searchData[i + k]); ++k) {  }  for (k++;   ' ' != (nameString[k] = searchData[i + k]); ++k) {  }  nameString[k] = '\0';
    for (j = 0; (searchString[j] == nameString[j]) && (strlen(searchString) > j); ++j) {  }
    if ((searchString[j] == nameString[j]) && (strlen(searchString) == j)) {  //  Found the Entry
      if ('\n' == searchData[i + j + 1]) {  //  Null Bags Inside
        break;
      }
      for (i += (j + 2); '\n' != searchData[i]; ) {
        for (k = 0; ' ' != (nameString[k] = searchData[i + k]); ++k) {  }  for (k++;   ' ' != (nameString[k] = searchData[i + k]); ++k) {  }  nameString[k] = '\0';
        for (j = 0; ("shiny gold"[j] == nameString[j]) && (strlen("shiny gold") > j); ++j) {  }
        if (("shiny gold"[j] == nameString[j]) && (strlen("shiny gold") == j)) {  //  Found "shiny gold "
          printf(" SHINY GOLD ");
          returnValue |= 1;
        }
        else {
          returnValue |= (sgSearch(searchData
                        , nameString
                        , depth + 1)) ? 1 : 0;
        }
        for (; (('0' > searchData[i]) || ('9' < searchData[i])) && ('\n' != searchData[i]); ++i) {  }
        i += ('\n' != searchData[i]) ? 1 : 0;
      }
      break;  //  Have read through the Record
    }
    for (; '\n' != searchData[i]; ++i) {  }  ++i;
  }

  printf("%s"
       , (returnValue) ? "*]" : " ]");

  return returnValue;

}


int main(void) {
FILE* filePtr;
int   fileSize;
char* fileData;
int   checkSize;
int   errorFlag = 0;
int   answerValue;
char  answer[10] = { '\0' };

int   i;
int   j;
int   k;
char  nameString[64];
char* compData;

int   sgCount;

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

    if (NULL == (fileData = malloc(fileSize + 1))) {
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
        fileData[checkSize] = '\0';


        compData = malloc(fileSize + 1);
        for (i = j = 0; '\0' != fileData[i];) {
          for (; ' ' != (compData[j] = fileData[i]); ++j, ++i) {  }  compData[j++] = fileData[i++];   //  First Descriptor Word
          for (; ' ' != (compData[j] = fileData[i]); ++j, ++i) {  }  compData[j++] = fileData[i++];   //  Second Descriptor Word
          for (; ' ' != fileData[i]; ++i) {  } ++i;                                                   //  Skip "bags"
          for (; ' ' != fileData[i]; ++i) {  } ++i;                                                   //  Skip "contain"
          if ('n' == fileData[i]) {                                                                   //  Skip "no other bags"
            for (; '.' != fileData[i]; ++i) {  }  ++i;
          }
          else {
            for (; '.' != fileData[i];) {
              compData[j++] = fileData[i++];        ++i;                                                 //  Get Number of Bags
              for (; ' ' != (compData[j] = fileData[i]); ++j, ++i) {  }  compData[j++] = fileData[i++];  //  Skip First Descriptor
              for (; ' ' != (compData[j] = fileData[i]); ++j, ++i) {  }  compData[j++] = fileData[i++];  //  Skip Second Descriptor
              for (; (',' != fileData[i]) && ('.' != fileData[i]); ++i) {  }  //  Skip "bag" and "bags"
              i = (',' == fileData[i]) ? (i + 2) : i;
            }  ++i;
          }
          if ('\n' == fileData[i]) {
            compData[j++] = fileData[i++];
          }
        }
        if ('\n' != compData[j - 1]) {  compData[j++] = '\n';  }
        compData[j] = '\0';

        for (i = sgCount = 0; '\0' != compData[i];) {
          for (k = 0; ' ' != (nameString[k] = compData[i + k]); ++k) {  }  for (k++;   ' ' != (nameString[k] = compData[i + k]); ++k) {  }  nameString[k] = '\0';
          for (j = 0; ("shiny gold"[j] == nameString[j]) && (strlen("shiny gold") > j); ++j) {  }
          if (("shiny gold"[j] != nameString[j]) || (strlen("shiny gold") != j)) {  //  Skip "shiny gold "
            if (sgSearch(compData
                       , nameString
                       , 1)) {
              ++sgCount;
            }
          }
          for (; '\n' != compData[i]; ++i) {  }  ++i;
          if ('\0' != compData[i]) {
            printf("\n");
          }
        }

        free(compData);


      }
      free(fileData);
    }
    fclose(filePtr);
  }

  if (!errorFlag) {
    if (!(answerValue = sgCount)) {
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
