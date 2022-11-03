#include <stdio.h>
#include <string.h>

void kmp(char text[100], char pattern[100]);
void PrefixFunction(char pattern[100], int N, int a[100]);
char  pat[100];
int flag=0;
int count=0;
char line[500];
char a[100];

int main(int argc, char* argv[])
{
    //get the pattern by user input
    printf("Enter the pattern : ");
    gets(pat);


//read the modules file
FILE* file = fopen("D:\\modules.txt", "r");

if(!file){
printf("\n Unable to open ");
return -1;
}

// get line by line from the file and copy the line into another char array and then pass into the match functtion
while (fgets(line, sizeof(line), file)) {
     strcpy(a, line);  //copy the line to the char array a
     kmp(a, pat); //calling kmp function

}

fclose(file);              //close the file
printf("number of matches: %d",count);  //print the total count
return 0;
}


void kmp(char text[100], char pattern[100]) {

    int m,n;
    int i = 0;
    int j = 0;

//convert all the lowercase letters to uppercase in the text
     for (int i = 0; text[i]!='\0'; i++) {
      if(text[i] >= 'a' && text[i] <= 'z') {
         text[i] = text[i] - 32;
      }
    }

//convert all the lowercase letters to uppercase in the Pattern
     for (int i = 0; pattern[i]!='\0'; i++) {
      if(pattern[i] >= 'a' && pattern[i] <= 'z') {
         pattern[i] = pattern[i] - 32;
      }
    }
    //get the length of the pattern and the text
    m = strlen(pattern);
    n = strlen(text);

   int a[m]; //empty array with size of the pattern

   //pass the pattern to prefix function
   PrefixFunction(pattern, m, a);

   while (i < n) {

      if (pattern[j] == text[i]) {  //compare pattern with the text, if its matching increment i and j values
         j++;
         i++;
      }

      if (j == m) {
         count=count+1;   // if pattern match with text then print the line and increment the count by 1
         j = a[j - 1];
         printf("%s\n", line);
      }

        if (i < n && pattern[j] != text[i]) {
          if (j != 0){     //if a mismatch found and j value not equal to 0, we go to the previous array value
          j = a[j - 1];}
          else{               //else we increment the i value
          i = i + 1;
         }

      }

   }

}


//create the prefix function
void PrefixFunction(char pattern[100], int N, int a[100]) {
   int len = 0;
   int i = 1;
   a[0] = 0;

   while (i < N) {
      if (pattern[i] == pattern[len]) {
         len++;
         a[i] = len;  //computing pi array
         i++;
      }
      else {

         if (len != 0)
         len = a[len - 1]; //go to the value of the previous index of the array

         else {
            a[i] = 0;  //if not a match pot 0 in the array
            i++;
         }
      }
   }
}


