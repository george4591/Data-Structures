#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

typedef struct Student
{
	char* name;
} Student;

typedef struct Node
{
	Student* info;
	Node* pNext;
} Node;

// function signatures for memory management
Student* createInfo(char*);
Node* createNode(Student* info);

// function signatures for list operations
void insertHead(Node** head, Student* info);
Node* insertTail(Node* head, Student* info);
void insertNode(Node* node, Student* info);
void printList(Node*);

int main()
{
	Node* list;
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

		char** agenda[26];
		memset(agenda, NULL, 26 * sizeof(char**));

		short tmp[26];
		memcpy(tmp, freq, 26 * sizeof(short));

		for (int i = 0; i < index; ++i)
		{
			int pos = *names[i] - 'A';
			if (agenda[pos] == NULL)
			{
				agenda[pos] = (char**)malloc(sizeof(char*) * tmp[pos]);
			}

			agenda[pos][tmp[pos] - 1] = (char*)malloc(sizeof(char) * strlen(names[i]) + 1);
			strcpy(agenda[pos][tmp[pos] - 1], names[i]);
			tmp[pos]--;
		}

		for (int i = 0; i < 26; ++i)
		{
			if (agenda[i])
			{
				printf("Group %c:\n", i + 'A');
				for (int j = 0; j < freq[i]; ++j)
				{
					printf("\tName: %s\n", agenda[i][j]);

					Student* student = createInfo(agenda[i][j]);
					insertNode(&list, student);
					list = insertTail(list, student);
				}
			}
		}
	}

	return 0;
}

void insertNode(Node** head, Student* info)
{
	// 1,connect node to the structure

	Node* node = createInfo(node);
	node->pNext = *head;


	// 2 connect the structure to the node
	*head = node;
}

Node* insertTail(Node* head, Student* info)
{
	// 1,connect node to the structure

	Node* node = createInfo(node);

	if (head == NULL)
	{
		head = node;
	}
	else {
		// 2 connect the structure to the node
		Node* tmp = head;
		while (tmp->pNext)
		{
			tmp = tmp->pNext;
		}

		tmp->pNext = node;
	}

	return head;
}

Student* createInfo(char* name)
{
	Student* value = (Student*)malloc(sizeof(Student));
	value->name = (char*)malloc(strlen(name) + 1);
	strcpy(value->name, name);

	return value;
}

Node* createNode(Student* info)
{
	Node* value = (Node*)malloc(sizeof(Node));
	value->info = info;
	value->pNext = NULL;
}
