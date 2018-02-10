/*************************************************************************
    > File Name: parse_metafile.c
    > Author: tongxianglong
    > Mail: studentTxl@163.com 
    > Created Time: Fri 09 Feb 2018 12:10:37 PM CST
 ************************************************************************/
parse_metafile.c
#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"parse_metafile.h"
#include"shal.h"

char *metafile_content = NULL;
long filesize;

int piece_length = 0;
char *pieces = NULL;
int piece_length = 0;

int multi_file = 0;
char *file_name = NULL;
long long file_length = 0;
Files *files_head = NULL;

unsigned char info_hash[20];
unsigned char peer_id[20];

Announce_list *announce_list_head = NULL;

int read_metafile(char *metafile_name)
{
	long i;

	FILE *fp = fopen(metafile_name, "rb");
	if(fp == NULL)
	{
		printf("%s:%d can not open file!\n", _FILE_ , _LINE_);
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
	if(filesize == -1)
	{
		printf("%s:%d fseek failed\n", _FILE_, _LINE_);
		return -1;
	}
	metafile_content = (char *)malloc(filesize + 1);
	if(metafile_content == NULL)
	{
		printf("%s:%d malloc failed\n", _FILE_, _LINE_);
		return -1;
	}
	fseek(fp, 0, SEEK_SET);
	for(i=0; i<filesize; ++i)
		matefile_count[i] = fgetc(fp);
	metafile_count[i] = 0;
	fclose(fp);
#ifdef DEBUG
	printf("metafile size is: %ld\n", filesize);
#endif
	return 0;
}

int find_keyword(char *keyword, long *position)
{
	long i;

	*position = -1;
	if(keyword == NULL)
		return 0;

	for(i=0; i<filesize-strlen(keyord); ++i)
	{
		if(memcmp(&metafile_content[i], keyword, strlen(keyword))==0)
		{
			*position = -1;
			return 1;
		}
	}
	return 0;
}








