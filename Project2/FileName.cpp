#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int lenA, int lenB) { return lenA > lenB ? lenA : lenB; }

int LCS(char* stringX, char* stringY, int Len0fstringX, int Len0fstringY) {

	if (Len0fstringX == 0 || Len0fstringY == 0) {
		return 0;
	}
	else
	{
		int len0fcase1 = 0;
		int len0fcase2 = 0;
		int len0fcase3 = 0;
		int len0fcase4 = 0;

		if (stringX[Len0fstringX - 1] == stringY[Len0fstringY - 1]) {
			len0fcase1 = (LCS(stringX, stringY, Len0fstringX - 1, Len0fstringY - 1)) + 1;
		}

		if (stringX[Len0fstringX - 1] != stringY[Len0fstringY - 1]) {
			len0fcase2 = (LCS(stringX, stringY, Len0fstringX - 1, Len0fstringY - 1));
		}
		len0fcase3 = LCS(stringX, stringY, Len0fstringX - 1, Len0fstringY); 
		len0fcase4 = LCS(stringX, stringY, Len0fstringX, Len0fstringY - 1);

		return Max(Max(Max(len0fcase2, len0fcase3), len0fcase1), len0fcase4);
	}
}

int LCS(char* stringX, char* stringY, int Len0fstringX, int Len0fstringY);

int main(void) {

	//문자열 입력구간
	char stringX[] = "ABCDE";
	char stringY[] = "ACE";

	int LCS_Len;

	int stringXLen = strlen(stringX);
	int stringYLen = strlen(stringY);

	LCS_Len = LCS(stringX, stringY, stringXLen, stringYLen);

	printf("LCS의 길이: %d \n", LCS_Len);

	return 0;
}