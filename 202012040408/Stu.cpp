#include "Stu.h"
Stu::Stu() {
	ifstream ifile("user.txt", ios::in);
	if (!ifile) {
		cout << "open user error!" << endl;
		exit(0);
	}
	int Floor_grades, Bed_grades, Items_grades, Other_grades, Sum_grades;
	string Number, Member[4];
	while (!ifile.eof()) {
		a = new Dormitory;
		ifile >> Floor_grades >> Bed_grades >> Items_grades >> Other_grades >> Sum_grades >> Number >> Member[0] >> Member[1] >> Member[2] >> Member[3];
		a->setFloor_grades(Floor_grades);
		a->setBed_grades(Bed_grades);
		a->setItems_grades(Items_grades);
		a->setOther_grades(Other_grades);
		a->setSum_grades(Sum_grades);
		a->setNumber(Number);
		a->setMember(Member[0], Member[1], Member[2], Member[3]);
		Dorm.push_back(a);
	}
	ifile.close();
}
Stu::~Stu() {
	delete a;
}
void Stu::display_grades() {
	AVLnode* root_grades = NIL;
	root_grades=avl.build_AVL_grades(Dorm);
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "��������     ��������     ��Ʒ�ڷ�     ����     �ܺ�     �����     �����Ա     �����Ա     �����Ա     �����Ա\n";
	avl.InorderTraversal(root_grades);
	avl.clear(root_grades);
}
void Stu::display_number() {
	AVLnode* root_number = NIL;
	root_number = avl.build_AVL_number(Dorm);
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "��������     ��������     ��Ʒ�ڷ�     ����     �ܺ�     �����     �����Ա     �����Ա     �����Ա     �����Ա\n";
	avl.InorderTraversal(root_number);
	avl.clear(root_number);
}
void Stu::query() {
	AVLnode* find_root = NIL;
	AVLnode* root_number = avl.build_AVL_number(Dorm);
	cout << "������Ҫ��ѯ�������:";
	string Number;
	cin >> Number;
	find_root = avl.find(root_number, Number);
	avl.display(find_root);
	/*avl.clear(find_root);*/ //���ϻᵼ�¶���clear���򱨴�
	avl.clear(root_number);
}
void Stu::best() {
	AVLnode* root_grades = avl.build_AVL_grades(Dorm);
	AVLnode* Max=avl.findMax(root_grades);
	avl.display(Max);
	//avl.clear(Max);
	avl.clear(root_grades);
}
void Stu::worst() {
	AVLnode* root_grades = avl.build_AVL_grades(Dorm);
	AVLnode* Min = avl.findMin(root_grades);
	avl.display(Min);
	/*avl.clear(Min);*/
	avl.clear(root_grades);
}