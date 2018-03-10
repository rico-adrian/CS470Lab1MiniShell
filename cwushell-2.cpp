#include<fcntl.h>
#include<stdlib.h> 
#include <dirent.h>
#include <cerrno>
#include<stdio.h>
#include<string.h>
#include <iostream>
#include <unistd.h>
#include<stdlib.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int size;
struct stackOfLines
{
	char strings[100];
};


void parsing(char* token, char** command) {
	int i = 0;
	char* strtoken = strtok(token, " \t\n");
	command[i] = strtoken;

	//tokenize string(commands)
	while (strtoken != NULL) {
		command[i++] = strtoken;
		strtoken = strtok(NULL, " \t\n");
	}
	size=i;
}

int main(int argc, char *argv[])
{
	try {
		bool b = true;
		FILE* fp;
		FILE *file;
		//char line[100];
		char lines[10000];
		char line[10000];
		struct stackOfLines s[10000];
		char lineTail[10000];
		string command;
		char** cmd;
		int fd1, fd2, count1; char buf[512];
		char buffer[100];
		FILE *file2;
		FILE* file3;
		while (b) {
			if (cmd[0] != "exit") {
				printf("cwushell > ");
			}
			cmd = new char*[100];
			getline(cin, command);
			while (command == ""|| command.at(0) == ' ') {
				cin.ignore(0,' ');
				cout << "please enter a command" << "\n" << "cwushell > ";
				for (int i = 0; i < command.length(); i++) {
					line[i] = ' ';
				}
				command = "";
				getline(cin, command);
			}
			strcpy(line,command.c_str());
			parsing(line, cmd);

		    if(strcmp(cmd[0], "cat") == 0) {
				stringstream ss;
				ss<< "cat" <<' '<< cmd[1];
				system(ss.str().c_str());
			}
			else if(strcmp(cmd[0], "cmp") == 0) {
				stringstream ss;
				ss<< "cmp" <<' '<< cmd[1] <<' ' <<cmd[2];
				system(ss.str().c_str());
			}
			else if (strcmp(cmd[0], "mv") == 0) {
				stringstream ss;
				ss<< "mv" <<' '<< cmd[1] <<' ' <<cmd[2];
				system(ss.str().c_str());
			}
			else if (strcmp(cmd[0], "ls") == 0) {
				stringstream ss;
				ss<< "ls";
				system(ss.str().c_str());
			}
			else if (strcmp(cmd[0], "help") == 0) {
				cout << "These shell commands are defined internally.Type `help' to see this list." << endl;
				cout << "exit [n]" << endl;
				cout << "mv [filename1] [filename2]" << endl;
				cout << "ls" << endl;
				cout << "cmp [filename1] [filename2]" << endl;
				cout << "tail [filename] [n]" << endl;
				cout << "cat [filename]" << endl;
			}
			else if (strcmp(cmd[0], "exit") == 0) {
				stringstream ss;
				 if (size == 2) {
					 exit(atoi(cmd[1]));
			    }
				exit(EXIT_FAILURE);
			}
			else if (strcmp(cmd[0], "tail") == 0) {
				bool fileExist = false;
				file = fopen(cmd[1], "r");
			
				if (size==2) {
						int number2=5;
					int n, count = 0, j = 0;
					// reading line by line and push to stack
					while (fscanf(file, "%[^\n]\n", lineTail) != EOF)
					{
						strcpy(s[j].strings, lineTail);
						j++;
						n = j;
						fileExist = true;
					}
					if (fileExist == false) {
						cout << "file does not exist" << endl;
						continue;
					}
					int temp = 5;
					int k = 0;
					// pop line by line
					for (j = n; j > 0; j--)
					{
						// last number lines   
						if (count == temp)
							break;
						else
							printf("%s\n", s[j - number2 + k].strings);
						k++;
						number2--;
						count++;
					}
					fclose(file);
				}
				
			    else if ( atoi(cmd[2]) ==0) {
					cout << "you need to input a number that is larger than 0" << endl;
					fclose(file);
				}
				else if ( atoi(cmd[2]) > 0) {
					int n, count = 0, j = 0;
					int number3=atoi(cmd[2]);
					// reading line by line and push to stack
					while (fscanf(file, "%[^\n]\n", lineTail) != EOF)
					{
						strcpy(s[j].strings, lineTail);
						j++;
						n = j;
						fileExist = true;
					}
					if (fileExist == false) {
						cout << "file does not exist" << endl;
						continue;
					}
					int temp = atoi(cmd[2]);
					int k = 0;
					// pop line by line
					for (j = n; j > 0; j--)
					{
						// last number lines   
						if (count == temp)
							break;
						else
							printf("%s\n", s[j - number3 + k].strings);
						k++;
						number3--;
						count++;
					}
					fclose(file);
				}
				fclose(file);
			}
			else {
				cout << "invalid input" << "\n";
			}
			for (int i = 0; i < command.length(); i++) {
				line[i] = ' ';
			}
			command = "";
		}
	}
	catch (exception& ex) {
		std::cout << "ERROR because: "
			<< ex.what() << "!\n";
	}
	return 0;
}