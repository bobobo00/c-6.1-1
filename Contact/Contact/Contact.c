#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
void Menue(){
	printf("##########################\n");
	printf("##1.Add            2.Del##\n");
	printf("##3.Alt            4.Che##\n");
	printf("##5.Show           6.Cle##\n");
	printf("##7.Sort          0.Exit##\n");
	printf("##########################\n");
	printf("���������ѡ��\n");
}
int InitList(contact **ct){
	*ct = (contact_ct)malloc(sizeof(contact)+sizeof(person)*DEFAULT);
	if (!ct){
		printf("%c:%s", errno, strerror(errno));
		return 0;
	}
	else{
		(*ct)->cap = DEFAULT;
		(*ct)->size = 0;
		printf("Init contact success!\n");
	}
	return 1;
}
//void AddList(contact_ct ct){
//	if (ct->size == ct->cap-1){
//		contact_ct m;
//		m = (contact_ct)realloc(ct,sizeof(contact)+sizeof(person)*DEFAULT * 2);
//		if (m){
//			ct = m;
//			ct->cap = DEFAULT*2;
//		}
//		else{
//			printf("����ʧ��\n");
//		}
//	}
//	person a;
//	printf("��������ϵ�˵�����,�Ա�,����,�绰,��ַ:\n");
//	scanf("%s %c %d %s %s", a.name,&a.sex,&a.age,a.tele,a.address);
//	

//	ct->contact[ct->size] = a;
 //ct->size++;
//}
static int Isfull(contact_ct ct){
	return ct->size == ct->cap ? 1 : 0;
}
static int Inc(contact_ct *cp){
	int new_size = sizeof(contact)+((*cp)->cap * 2)*sizeof(person);
	contact_ct c = realloc(*cp, new_size);
	if (!c){
		printf("Inc error!\n");
		return 0;
	}
	c->cap = (*cp)->cap * 2;
	*cp = c;
	printf("Inc success!\n");
	return 1;
}
void AddList(contact_ct *cp){
	if (!Isfull(*cp) || Inc(cp)){
		person_p a=&((*cp)->contact[(*cp)->size]);
		printf("Please Enter Name:");
		scanf("%s", a->name);
		printf("Please Enter Sex:");
		scanf(" %c", &(a->sex));//sacnfǰ�ÿո��ֹ�س�����һ��scanf���롣
		printf("Please Enter age:");
		scanf(" %u", &(a->age));
		printf("Please Enter Tel:");
		scanf(" %s", a->tele);
		printf("Please Enter Address:");
		scanf(" %s", a->address);
		((*cp)->size)++;
	}
	else{
		printf("realloc error!\n");
		return;
	}
}
void DeletList(contact_ct ct){
	char per[NAME_SIZE];
	printf("������Ҫɾ����ϵ��������\n");
	scanf("%s", per);
	int i = 0;
	int flag = 1;
	int j = 0;
	while (flag){
		for (i = 0; i <= ct->size; i++){
			if (!(strcmp(ct->contact[i].name, per))){
				for (j = i; j < ct->size; j++){
					ct->contact[j] = ct->contact[j + 1];
				}
				ct->size--;
				printf("��ɾ��\n");
				flag = 0;
			}
		}
		if (flag){
			printf("��ϵ�˲����ڣ��޷�ɾ��\n");
			flag = 0;
		}
	}
}
void AlterList(contact_ct ct){
	char per[NAME_SIZE];
	printf("������Ҫ�޸���ϵ��������\n");
	scanf("%s", per);
	int i = 0;
	int flag = 1;
	for (i = 0; i <= ct->size; i++){
		if (!(strcmp(ct->contact[i].name, per))){
			printf("�������޸ĺ����ϵ������,�Ա�,����,�绰,��ַ:\n");
			scanf("%s %c %d %s %s", &ct->contact[i].name, &ct->contact[i].sex, &ct->contact[i].age, &ct->contact[i].tele, &ct->contact[i].address);
			flag = 0;
		}
	}
	if (flag){
		printf("��ϵ�˲�����!�޷��޸���Ϣ��\n");
	}
}
void CheckList(contact_ct ct){
	char per[NAME_SIZE];
	printf("������Ҫ������ϵ��������\n");
	scanf("%s", per);
	int i = 0;
	int flag = 1;
	for (i = 0; i <= ct->size; i++){
		if (!(strcmp(ct->contact[i].name, per))){
			printf("�ҵ���ϵ�ˣ�\n������%s �Ա�%d ���䣺%d �绰��%s ��ַ��%s\n", ct->contact[i].name, ct->contact[i].sex, ct->contact[i].age, ct->contact[i].tele, ct->contact[i].address);
			flag = 0;
		}
	}
	if (flag){
		printf("��ϵ�˲�����!\n");
	}
}
void ShowList(contact_ct ct){
	if (ct->size == -1){
		printf("ͨѶ¼Ϊ�գ��޷���ʾ��ϵ����Ϣ\n");
	}
	else{
		int i = 0;
		for (i = 0; i <= ct->size; i++){
			printf("������%s �Ա�%c ���䣺%d �绰��%s ��ַ��%s", ct->contact[i].name, ct->contact[i].sex, ct->contact[i].age, ct->contact[i].tele, ct->contact[i].address);
			printf("\n");
		}
	}
}
void ClearList(contact_ct ct){
	ct->size= -1;
}
//void SortList(contact_ct ct){
//	int i=0;
//	int j=0;
//	int m = 0;
//	for (i = 0; i < ct->size; i++){
//		for (j = 0; j < ct->size - i; j++){
//			if (strcmp(ct->contact[j].name, ct->contact[j + 1].name ) == 1){
//				char temp[NAME_SIZE];
//				for (m = 0; m < NAME_SIZE; m++){
//					temp[m] = ct->contact[j].name[m];
//					ct->contact[j].name[m] = ct->contact[j + 1].name[m];
//					ct->contact[j + 1].name[m] = temp[m];
//				}
//			}
//		}
//	}
//}
static int person_cmp(const void *x, const void *y){
	person_p _x = (person_p)x;
	person_p _y = (person_p)y;
	return strcmp(_x->name, _y->name);
}
void SortList(contact_ct ct){
	person_p p = ct->contact;
	qsort(p, ct->size, sizeof(person), person_cmp);
}
void DesList(contact_ct ct){
	free(ct);
	ct = NULL;
}
