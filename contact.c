#include "contact.h"
#define max 10
void initcontact(contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
void addcontact(contact* pc)
{
	assert(pc);
	if (pc->count == max)
	{
		printf("通讯录已满，无法增加联系人");
		return 0;
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("增加成功\n");
}
void showcontact(const contact* pc)
{
	assert(pc);
	int i=0;
	for (int i = 0; i < pc->count; i++)
	{
		printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n",pc->data[i].name, 
											pc->data[i].age,
											pc->data[i].sex,
											pc->data[i].tele, 
											pc->data[i].addr);
	}
}
int findbyname(contact* pc,char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name)==0)
		{
			return i;
		}
	}
}
void delcontact(contact* pc)
{
	char name[20];
	assert(pc);
	if (pc->count == 0)
	{
		printf("没有信息可以删除\n");
		return 0;
	}
	printf("请输入名字:>");
	scanf("%s", name);
	//查找
	int ret=findbyname(pc,name);
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
	}
	for (int i = ret; i < pc->count; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}
void searchcontact(contact* pc)
{
	char name[20];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int ret = findbyname(pc, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%20s\t%3d\t%5s\t%12s\t%30s\n", pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].tele,
		pc->data[ret].addr);
}
void modifycontact(contact* pc)
{
	char name[20];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int ret = findbyname(pc, name); 
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	printf("要修改的人的信息已查找到，开始修改\n");
	printf("请输入名字:>");
	scanf("%s", pc->data[ret].name);
	printf("\n请输入年龄:>");
	scanf("%d", &(pc->data[ret].age));
	printf("\n请输入性别:>");
	scanf("%s", pc->data[ret].sex);
	printf("\n请输入电话:>");
	scanf("%s", pc->data[ret].tele);
	printf("\n请输入地址:>");
	scanf("%s", pc->data[ret].addr);
	pc->count++;
	printf("修改成功\n");
}
int cmp_peo_byname(const void* e1, const void* e2)
{
	return strcmp(((people*)e1)->name,((people*)e2)->name);
}
void sortcontact(contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(people), cmp_peo_byname);
	printf("排序成功\n");
}

