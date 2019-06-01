#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
int main(){
	contact_ct ct;
	int quit = 0;
	int select = 0;
	if (InitList(&ct)){
		while (!quit){
			Menue();
			scanf("%d", &select);
			switch (select){
			case 1:
				AddList(&ct);
				break;
			case 2:
				DeletList(ct);
				break;
			case 3:
				AlterList(ct);
				break;
			case 4:
				CheckList(ct);
				break;
			case 5:
				ShowList(ct);
				break;
			case 6:
				ClearList(ct);
				break;
			case 7:
				SortList(ct);
				break;
			case 0:
				quit = 1;
				break;
			default:
				break;
			}
		}
	}
	DesList(ct);
	system("pause");
	return 0;
}