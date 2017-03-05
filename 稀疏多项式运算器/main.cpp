#include "ploynomialList.h"
#include <cstdlib>
using namespace std;
void printMenu() {
	cout << "============================================================" << endl;
	cout << "=                         �˵�                             =" << endl;
	cout << "============================================================" << endl;
	cout << "=                        0.�˳�                            =" << endl;
	cout << "=                        1.����                            =" << endl;
	cout << "=                        2.��ʾ                            =" << endl;
	cout << "=                        3.����                            =" << endl;
	cout << "=                        4.���                            =" << endl;
	cout << "=                        5.���                            =" << endl;
	cout << "=                        6.��ֵ                            =" << endl;
	cout << "=                        7.����                            =" << endl;
	cout << "=                        8.�޸�                            =" << endl;
	cout << "=                        9.΢��                            =" << endl;
	cout << "=                      10.��������                         =" << endl;
	cout << "=                       11.������                          =" << endl;
	cout << "=                     12.����ʽ�˷�                        =" << endl;
	cout << "=                     13.����ʽ����                        =" << endl;
	cout << "=                       14.����ʽ                          =" << endl;
	cout << "=                       15.�˷�                            =" << endl;
	cout << "=                     16.�����ʽ                        =" << endl;
	cout << "=                     17.��С����ʽ                        =" << endl;
	cout << "============================================================" << endl;
}

void printWelcome() {
	cout << "============================================================" << endl;
	cout << "=                                                          =" << endl;
	cout << "=                ��ӭʹ��ϡ�����ʽ������                  =" << endl;
	cout << "=                      Made By WYY                         =" << endl;
	cout << "=                                                          =" << endl;
	cout << "============================================================" << endl;
	cout << endl;
}

int main() {
	printWelcome();
	int choice=0;
	ploynomialList *list[10000];
	int index = 0, e;
	double x, l, r, c;
	for (;;) {
		int m, n, i, j;
		printMenu();
		cin >> choice;
		switch (choice) {
			case 0:return 0;
			case 1:
				index++;
				list[index] = new ploynomialList;
				cout << "�������������֮��Ӧ��ϵ����һ��һ��������ϵ�����ÿո����������-1�������������̣�" << endl;
				cin >> *list[index];
				break;
			case 2:
				for (int i = 1; i <= index; i++) cout << i << ". " << *list[i];
				system("pause");
				break;
			case 3:
				cout << "��Ҫ�����ڼ��Ŷ���ʽ��" << endl;
				cin >> m;
				index++;
				list[index] = new ploynomialList(*list[m]);
				break;
			case 4:
				cout << "��������ӵļ�������ʽ���±꣬�Կո����������0���������룺" << endl;
				m = 0;
				index++;
				list[index] = new ploynomialList;
				for (;;) {
					cin >> m;
					if (m == 0) break;
					if (m > index) {
						cerr << "����������������룡" << endl;
						continue;
					}
					*list[index] = *list[index] + *list[m];
				}
				break;
			case 5:
				cout << "�������������������ʽ���±꣺" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(*list[m] - *list[n]);
				break;
			case 6:
				cout << "������Ҫ��ֵ�Ķ���ʽ���±꣺" << endl;
				cin >> m;
				if (m > index) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				cout << "x=";
				cin >> x;
				cout << list[m]->value(x) << endl;
				system("pause");
				break;
			case 7:
				cout << "������Ҫ���ٵĶ���ʽ���±꣺" << endl;
				cin >> m;
				if (m > index) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				delete list[m];
				for (i = m; i < index; i++) list[i] = list[i + 1];
				list[index] = NULL;
				index--;
				break;
			case 8:
				cout << "������Ҫ�޸ĵĶ���ʽ���±꣺" << endl;
				cin >> m;
				if (m > index) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				cout << "��ѡ��" << endl;
				cout << "0.�˳�" << endl << "1.��ն���ʽ" << endl << "2.�޸�ָ��������ϵ��" << endl;
				cin >> n;
				if (n == 0) break;
				else if (n == 1)list[m]->clear();
				else if (n == 2) {
					cout << "������Ҫ�޸ĵ�ϵ���Ĵ�����ϵ����" << endl;
					pNode t;
					cin >> t.exp >> t.coef;
					if (list[m]->setNode(t) == -1) {
						cerr << "����������������룡" << endl;
						system("pause");
						break;
					}
				}
				else {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				break;
			case 9:
				cout << "������Ҫ�󵼵Ķ���ʽ���±꣺" << endl;
				cin >> m;
				if (m > index) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				cout << "�������󵼵Ĵ�����" << endl;
				cin >> n;
				index++;
				list[index] = new ploynomialList(list[m]->nDiff(n));
				break;
			case 10:
				cout << "��������ˮƽ���ƣ��������ֵĳ������޷���ʾ��" << endl;
				cout << "������Ҫ�������ֵĶ���ʽ���±꣺" << endl;
				cin >> m;
				if (m > index) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(list[m]->integral());
				break;
			case 11:
				cout << "������Ҫ�����ֵĶ���ʽ���±꣺" << endl;
				cin >> m;
				if (m > index) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				cout << "�����������߽���ұ߽磺" << endl;
				cin >> l >> r;
				cout << list[m]->definiteIntegral(l, r) << endl;
				system("pause");
				break;
			case 12:
				cout << "��������˵ļ�������ʽ���±꣬�Կո����������0���������룺" << endl;
				m = 0;
				index++;
				list[index] = new ploynomialList(0);
				for (;;) {
					cin >> m;
					if (m == 0) break;
					if (m > index) {
						cerr << "����������������룡" << endl;
						continue;
					}
					*list[index] = *list[index] * *list[m];
				}
				break;
			case 13:
				cout << "�������������������ʽ���±꣺" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(*list[m] / *list[n]);
				break;
			case 14:
				cout << "����������ʽ����������ʽ���±꣺" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(*list[m] % *list[n]);
				break;
			case 15:
				cout << "������Ҫ�˷��Ķ���ʽ���±꣺" << endl;
				cin >> m;
				if (m > index) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				cout << "������˷��Ĵ�����" << endl;
				cin >> n;
				if (n <= 0) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(0);
				for (int p = 0; p < n; p++) {
					*list[index] = *list[index] * *list[m];
				}
				break;
			case 16:
				cout << "�������������ʽ����������ʽ���±꣺" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(list[m]->gcd(*list[n]));
				break;
			case 17:
				cout << "����������С����ʽ����������ʽ���±꣺" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "����������������룡" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(list[m]->lcm(*list[n]));
				break;
		}
	}
}