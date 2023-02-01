#include "Admin.h"
using namespace std;
string Admin::password = "111111";
Admin::Admin() {
	string u, b;
	u = "user.txt";
	b = "Adminpassword.txt";
	if (_access(b.c_str(), 0) == -1)
	{
		passwordfilesave();
	}
	else {
		ifstream ifilein("Adminpassword.txt", ios::in);
		if (!ifilein)cout << "open Adminpassword error!" << endl;
		string Password;
		while (!ifilein.eof()) {
			ifilein >> Password;
			Admin::password = Password;
		}
		ifilein.close();
	}
	if (_access(u.c_str(), 0) == -1) {
		petfilesave();
	}
	else
	{
		ifstream ifile("user.txt", ios::in);
		if (!ifile)cout << "open user error!" << endl;
		int Floor_grades, Bed_grades,Items_grades,Other_grades,Sum_grades;
		string Number,Member[4];
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
}
Admin::~Admin() {
	delete a;
}
string Admin::getpassword() {
	return password;
}
void Admin::petfilesave() {
	ofstream ofile("user.txt");
	if (!ofile)
	{
		cout << "open user error!" << endl;
	}
	for (int i = 0; i < Dorm.size(); ++i)
	{
		ofile << Dorm[i]->getFloor_grades() << " "
			<< Dorm[i]->getBed_grades() << " "
			<< Dorm[i]->getItems_grades() << " "
			<< Dorm[i]->getOther_grades() << " "
			<< Dorm[i]->getSum_grades() << " "
			<< Dorm[i]->getNumber() << " "
			<< Dorm[i]->getMember()[0]<<" "
			<< Dorm[i]->getMember()[1]<<" "
			<< Dorm[i]->getMember()[2]<<" "
			<< Dorm[i]->getMember()[3];
		if (i != Dorm.size() - 1)
		{
			ofile << "\n";
		}
	}
	ofile.close();
	cout << "�û���Ϣ����ɹ�!\n";
}
void Admin::passwordfilesave() {
	ofstream ofilein("Adminpassword.txt");
	if (!ofilein) {
		cout << "open admin error!" << endl;
	}
	string Password = password;
	ofilein << Password;
	ofilein << endl;
	ofilein.close();
}
void Admin::display() {
	cout << "�ܹ���" << Dorm.size() << "��������Ϣ\n";
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "��������     ��������     ��Ʒ�ڷ�     ����     �ܺ�     �����     �����Ա     �����Ա     �����Ա     �����Ա\n";
	for (auto m : Dorm) {
		cout << left << setw(8) << m->getFloor_grades() << "     ";
		cout << left << setw(8) << m->getBed_grades() << "     ";
		cout << left << setw(8) << m->getItems_grades() << "     ";
		cout << left << setw(4) << m->getOther_grades() << "     ";
		cout << left << setw(4) << m->getSum_grades() << "     ";
		cout << left << setw(6) << m->getNumber() << "     ";
		cout << left << setw(8) << m->getMember()[0] << "     ";
		cout << left << setw(8) << m->getMember()[1] << "     ";
		cout << left << setw(8) << m->getMember()[2] << "     ";
		cout << left << setw(8) << m->getMember()[3] << endl;
	}
}
void Admin::addDorm() {
	int n, j = 1;
	int Floor_grades, Bed_grades, Items_grades, Other_grades, Sum_grades;
	string Number, Member[4];
	cout << "����������ӵ�������Ŀ:";
	cin >> n;
	if (n <= 0) {
		cout << "�����ӵ���Ϣ��Ŀ����С��1\n";
		addDorm();
	}
	else
	{
		while (j <= n) {
			int flag = 1;
			cout << "�����뱾�����ӵ�" << j << "������������:";
			cin >> Number;
			for (auto m : Dorm) {
				if (m->getNumber() == Number) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				a = new Dormitory;
				a->setNumber(Number);
				cout << "�����뱾�����ӵ�" << j << "������ĵ���ɼ�:";
				cin >> Floor_grades;
				a->setFloor_grades(Floor_grades);
				cout << "�����뱾�����ӵ�" << j << "������Ĵ��̳ɼ�:";
				cin >> Bed_grades;
				a->setBed_grades(Bed_grades);
				cout << "�����뱾�����ӵ�" << j << "���������Ʒ�ɼ�:";
				cin >> Items_grades;
				a->setItems_grades(Items_grades);
				cout << "�����뱾�����ӵ�" << j << "������������ɼ�:";
				cin >> Other_grades;
				a->setOther_grades(Other_grades);
				a->setSum_grades(Floor_grades + Bed_grades + Items_grades + Other_grades);
				cout << "�����뱾�����ӵ�" << j << "������ĵ�һ����Ա:";
				cin >> Member[0];
				cout << "�����뱾�����ӵ�" << j << "������ĵڶ�����Ա:";
				cin >> Member[1];
				cout << "�����뱾�����ӵ�" << j << "������ĵ�������Ա:";
				cin >> Member[2];
				cout << "�����뱾�����ӵ�" << j << "������ĵ��ĸ���Ա:";
				cin >> Member[3];
				a->setMember(Member[0], Member[1], Member[2], Member[3]);
				Dorm.push_back(a);
				Admin::petfilesave();
			}
			else {
				cout << "�������Ѵ���!\n";
				continue;
			}
			j++;
		}
		cout << "��Ϣ������!" << endl;
	}
}
void Admin::deleteDorm() {
	int flag = 0, i = 0;
	string Number;
	cout << "������Ҫɾ��������:";
	cin >> Number;
	for (auto m : Dorm) {
		if (m->getNumber() == Number) {
			flag = 1;
			Dorm.erase(Dorm.begin() + i);
			cout << "ɾ���ɹ�!" << endl;
			Admin::petfilesave();
			break;
		}
		i++;
	}
	if (!flag) {
		cout << "��������Һ�����!\n";
		deleteDorm();
	}
}

void Admin::changeDorm() {
	int a = 1, flag = 0;
	string Number;
	cout << "��������Ҫ�޸���Ϣ����������Ӧ�������:";
	cin >> Number;
	for (auto m : Dorm) {
		int k = 0;
		if (m->getNumber() == Number) {
			flag = 1;
			cout << "------------------\n";
			cout << "0.����\n";
			cout << "1.�޸ĵ���ɼ�\n";
			cout << "2.�޸Ĵ��̳ɼ�\n";
			cout << "3.�޸���Ʒ�ɼ�\n";
			cout << "4.�޸������ɼ�\n";
			cout << "5.�޸������Ա\n";
			cout << "------------------\n";
			while (a) {
				if (!k) {
					cout << "��������Ҫ�޸ĵ���Ϣ���:";
				}
				cin >> a;
				switch (a) {
				case 1: {
					cout << "����ɼ��޸�Ϊ:";
					int Floor_grades;
					cin >> Floor_grades;
					m->setFloor_grades(Floor_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "�޸ĳɹ�!\n";
					k++;
					break;
				}
				case 2: {
					cout << "���̳ɼ��޸�Ϊ:";
					int Bed_grades;
					cin >> Bed_grades;
					m->setBed_grades(Bed_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "�޸ĳɹ�!\n";
					k++;
					break;
				}
				case 3: {
					cout << "��Ʒ�ɼ��޸�Ϊ:";
					int Items_grades;
					cin >> Items_grades;
					m->setItems_grades(Items_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "�޸ĳɹ�!\n";
					k++;
					break;
				}
				case 4: {
					cout << "�����ɼ��޸�Ϊ:";
					int Other_grades;
					cin >> Other_grades;
					m->setOther_grades(Other_grades);
					m->setSum_grades(m->getBed_grades() + m->getFloor_grades() + m->getItems_grades() + m->getOther_grades());
					cout << "�޸ĳɹ�!\n";
					k++;
					break;
				}
				case 5: {
					cout << "�����Ա�޸�Ϊ:";
					string Mem[4];
					for (int i = 0; i < 4; i++) {
						cin >> Mem[i];
					}
					m->setMember(Mem[0],Mem[1],Mem[2],Mem[3]);
					cout << "�޸ĳɹ�!\n";
					k++;
					break;
				}
				case 0: {
					system("cls");
					menu.menu2();
					Admin::petfilesave();
					return;
				}
				default:cout << "����0��5��ѡ��!\n";
				}
			}
		}
	}
	if (!flag)
	{
		cout << "�������������!\n";
		Admin::changeDorm();
	}
}
void Admin::sortDorm() {
	AVL avl;
	AVLnode* root=NIL;
	root = avl.build_AVL_grades(Dorm);
	cout << "-------------------------------------------------------------------------------------------\n";
	cout << "��������     ��������     ��Ʒ�ڷ�     ����     �ܺ�     �����     �����Ա     �����Ա     �����Ա     �����Ա\n";
	avl.InorderTraversal(root);
	avl.clear(root);
}
bool Admin::load() {
	char ch;
	string mima(6, '\0');
	int i = 0;
	cout << "���������Ա����:";
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (i > 0) {
				i--;
				cout << "\b \b";
			}
			else
				cout << "\a";
		}
		else {
			cout << "*";
			mima[i] = ch;
			i++;
		}
	}
	if (mima.compare(Admin::getpassword())) {
		cout << "\n�������!\n";
		system("pause");
		return 0;
	}
	else return 1;
}
string inputpassword() {
	char ch;
	int i = 0;
	string mima(6, '\0');
	while ((ch = _getch()) != '\r')
	{
		if (ch == '\b')
		{
			if (i > 0)
			{
				i--;
				cout << "\b \b";
			}
			else
				cout << "\a";
		}
		else
		{
			printf("*");
			mima[i] = ch;
			i++;
		}
	}
	return mima;
}
void Admin::changepassword() {
	string mima1, mima2;
	cout << "����������ĺ������:";
	mima1 = inputpassword();
	cout << endl;
	cout << "���ٴ�ȷ������:";
	mima2 = inputpassword();
	if (mima1.compare(mima2)) {
		cout << "\n�����������벻ͬ!\n";
		Admin::changepassword();
	}
	else
	{
		password = mima1;
		passwordfilesave();
		cout << "\n�޸ĳɹ�!" << endl;
	}
}
