//实现一个通讯录
//人的信息：
//名字+年龄+性别+电话+地址
/*
1.存放100个人的信息
2.增加联系人
3.删除指定联系人
4.查找联系人
5.修改联系人
6.排序
7.显示联系人*/
#include "contact.h"
void menu()
{
	printf("*****************************\n");
	printf("***1.add        2.del  ******\n");
	printf("***3.search     4.modify ****\n");
	printf("***5.show       6.sort   ****\n");
	printf("***0.exit    ****************\n");
	printf("*****************************\n");
}
int main()
{
	int input;
	struct contact con;
	//初始化通讯录
	initcontact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			addcontact(&con);
			break;
		case 2:
			delcontact(&con);
			break;
		case 3:
			searchcontact(&con);
			break;
		case 4:
			modifycontact(&con);
			break;
		case 5:
			showcontact(&con);
			break;
		case 6:
			sortcontact(&con);
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新选择:>");
			break;
		}
	}while (input);
}