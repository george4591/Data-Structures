#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>



int main()
{
	FILE* pFile = fopen("Data.txt", "r");
	char* names[100];
	memset(names, NULL, 100 * sizeof(char*));
	static short freq[26] = { 0 };

	if (pFile)
	{
		char buffer[128];
		int index = 0;

		fscanf(pFile, "%s", buffer);

		while (!feof(pFile))
		{
			names[index] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
			strcpy(names[index], buffer);

			int pos = *(names[index++] + 0) - 'A';
			freq[pos]++;
			fscanf(pFile, "%s", buffer);
		}
	}

	char** agenda[26];
	memset(agenda, NULL, 26 * sizeof(char**));

	return 0;
}
