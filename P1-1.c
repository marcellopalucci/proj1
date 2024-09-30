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

#define DEBUG 1 // RESET THIS TO 0 BEFORE SUBMITTING YOUR CODE

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
  int FOUND = 0;
  int candOffset_0 = 0;
  int candOffset_1 = 144;
  int candOffset_2 = 288;
  int candOffset_3 = 432;
  int candOffset_4 = 576;
  int candOffset_5 = 720;
  int candOffset_6 = 864;
  int candOffset_7 = 1008;
  int testPixel;
  

  for(int i = 0; i < IconSize; i++) {
    testPixel = Candidates[candOffset_1 + i];
    if (Candidates[candOffset_0 + i] == Pattern[i]) {
      if (Candidates[candOffset_1 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_2 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_4 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_5 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_6 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_7 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 0;
        break;
      }
    } else if (Candidates[candOffset_1 + i] == Pattern[i]) {
      if (Candidates[candOffset_0 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_2 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_4 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_5 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_6 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_7 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 1;
        break;
      }
    } else if (Candidates[candOffset_2 + i] == Pattern[i]) {
      if (Candidates[candOffset_0 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_1 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_4 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_5 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_6 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_7 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 2;
        break;
      }
    } else if (Candidates[candOffset_3 + i] == Pattern[i]) {
      if (Candidates[candOffset_0 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_1 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_2 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_4 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_5 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_6 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_7 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 3;
        break;
      }
    } else if (Candidates[candOffset_4 + i] == Pattern[i]) {
      if (Candidates[candOffset_0 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_1 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_2 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_5 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_6 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_7 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 4;
        break;
      }
    } else if (Candidates[candOffset_5 + i] == Pattern[i]) {
      if (Candidates[candOffset_0 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_1 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_2 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_4 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_6 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_7 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 5;
        break;
      }
    } else if (Candidates[candOffset_6 + i] == Pattern[i]) {
      if (Candidates[candOffset_0 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_1 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_2 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_4 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_5 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_7 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 6;
        break;
      }
    } else if (Candidates[candOffset_7 + i] == Pattern[i]) {
      if (Candidates[candOffset_0 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_1 + i] == Pattern[i]) {
        continue;
      } else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_3 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_4 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_5 + i] == Pattern[i]) {
        continue;
      }else if (Candidates[candOffset_6 + i] == Pattern[i]) {
        continue;
      } else {
        Match = 7;
        break;
      }
    } 

  }



  // DELETE THE FOLLOWING LINE. It assigns a temp value so shell code works.
  // Match = 42; //<-- delete this

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

