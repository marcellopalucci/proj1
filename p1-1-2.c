//=================================================================
// Copyright 2024 Georgia Tech.  All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must not be made publicly available anywhere.
//=================================================================

/*
Please fill in the following
 Student Name: Marcello Palucci
 Date: 9/29/2024

ECE 2035 Project 1-2

This is the only file that should be modified for the C implementation
of Project 1.

Do not include any additional libraries.
-----------------------------------------------
      I c o n   M a t c h

This program loads 8 icons (each is a 12x12 array of pixels) into a
linear array of candidates and a single icon that serves as a pattern,
which matches exactly one candidate icon.

Add code to find which of the eight candidates matches the pattern icon.
*/

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0 // RESET THIS TO 0 BEFORE SUBMITTING YOUR CODE

#define IconSize (12 * 12)
#define NumCandidates 8
#define CandidateArraySize (IconSize * NumCandidates)

int Load_Mem(char *InputFileName, int Candidates[], int Pattern[]);
int Load_N_Values(FILE *FP, int N, int Array[]);

int main(int argc, char *argv[]) {
  int	Candidates[CandidateArraySize];
  int	Pattern[IconSize];
  int	Length, Match;

  if (argc != 2) {
    printf("usage: P1-1 valuefile\n");
    exit(1);
  }
  Length = Load_Mem(argv[1], Candidates, Pattern);
  if (Length != CandidateArraySize + IconSize) {
     printf("valuefile does not contain valid data.\n");
     exit(1);
  }
  if (DEBUG){
     printf("Sample debugging print statement.\n");
  }

  /* Your icon matching code goes here */
  //point to the base of each candidate
  int *cand_0 = Candidates + 0;
  int *cand_1 = Candidates + 144;
  int *cand_2 = Candidates + 288;
  int *cand_3 = Candidates + 432;
  int *cand_4 = Candidates + 576;
  int *cand_5 = Candidates + 720;
  int *cand_6 = Candidates + 864;
  int *cand_7 = Candidates + 1008;
  
  //for loop which iterates through an IconSize of 144.
  //first if statement checks for a black pixel in the Patter array, since
  //we are not so interested in those pixels.
  //each outer if statement compares the ith pixel in the Pattern array
  //to an ith pixel of a Candidate's array. Then the inner loop checks whether
  //that same pixel is found in another candidate, and if so
  //continues the loop, otherwise break the loop and declare a match
  for(int i = 0; i < IconSize; i++) {
    if (Pattern[i] == 0) {
      continue;
    }
    if (*(cand_0 + i) == Pattern[i]) {
      if (*(cand_1 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_2 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_3 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_4 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_5 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_6 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_7 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 0;
        break;
      }
    } else if (*(cand_1 + i) == Pattern[i]) {
      if (*(cand_0 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_2 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_3 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_4 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_5 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_6 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_7 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 1;
        break;
      }
    } else if (*(cand_2 + i) == Pattern[i]) {
      if (*(cand_0 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_1 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_3 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_4 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_5 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_6 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_7 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 2;
        break;
      }
    } else if (*(cand_3 + i) == Pattern[i]) {
      if (*(cand_0 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_1 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_2 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_4 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_5 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_6 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_7 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 3;
        break;
      }
    } else if (*(cand_4 + i) == Pattern[i]) {
      if (*(cand_0 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_1 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_2 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_3 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_5 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_6 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_7 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 4;
        break;
      }
    } else if (*(cand_5 + i) == Pattern[i]) {
      if (*(cand_0 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_1 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_2 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_3 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_4 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_6 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_7 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 5;
        break;
      }
    } else if (*(cand_6 + i) == Pattern[i]) {
      if (*(cand_0 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_1 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_2 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_3 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_4 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_5 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_7 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 6;
        break;
      }
    } else if (*(cand_7 + i) == Pattern[i]) {
      if (*(cand_0 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_1 + i) == Pattern[i]) {
        continue;
      } else if (*(cand_2 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_3 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_4 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_5 + i) == Pattern[i]) {
        continue;
      }else if (*(cand_6 + i) == Pattern[i]) {
        continue;
      } else {
        Match = 7;
        break;
      }
    } 

  }

  printf("The matching icon is %d\n", Match);
  exit(0);
}

/* This routine loads in pairs of integers of the form "Addr: Value"
from a named file in the local directory. Each pair is delimited by a
newline. The first values are placed in the passed integer arrays
Candidates and Pattern. The number of input integers is returned. */

int Load_Mem(char *InputFileName, int Candidates[], int Pattern[]) {
  int	Nc, Np;
   FILE	*FP;

   FP = fopen(InputFileName, "r");
   if (FP == NULL) {
      printf("%s could not be opened; check the filename\n", InputFileName);
      return 0;
   } else {
     Nc = Load_N_Values(FP, CandidateArraySize, Candidates);
     if (Nc == CandidateArraySize)
       Np = Load_N_Values(FP, IconSize, Pattern);
     fclose(FP);
     return Nc+Np;
   }
}

int Load_N_Values(FILE *FP, int N, int Array[]){
  int i, NumVals, Addr, Value;
  for (i = 0; i < N; i++){
    NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
    if (NumVals == 2)
      Array[i] = Value;
    else 
      return(i);
  }
  return(N);
}

