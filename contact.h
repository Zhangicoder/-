#define _CRT_SECURE_NO_WARNINGS
#pragma once
//类型的声明
#include<string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct people
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}people;
typedef struct contact
{
	people data[100];//用来存放人的信息
	int count ;//记录通讯录中实际人数
}contact;
//初始化通讯录
void initcontact(contact* pc);
//增加联系人到通讯录
void addcontact(contact* pc);
//打印通讯录中的信息
void showcontact(const contact* pc);
//删除通讯录中的信息
void delcontact(contact* pc);
//查找通讯录中的信息
void searchcontact(contact* pc);
//修改通讯录中的信息
void modifycontact(contact* pc);
//排序
void sortcontact(contact* pc);


