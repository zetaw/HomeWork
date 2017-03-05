#include "ploynomialList.h"
#include <cstdlib>
using namespace std;
void printMenu() {
	cout << "============================================================" << endl;
	cout << "=                         菜单                             =" << endl;
	cout << "============================================================" << endl;
	cout << "=                        0.退出                            =" << endl;
	cout << "=                        1.创建                            =" << endl;
	cout << "=                        2.显示                            =" << endl;
	cout << "=                        3.复制                            =" << endl;
	cout << "=                        4.求和                            =" << endl;
	cout << "=                        5.求差                            =" << endl;
	cout << "=                        6.求值                            =" << endl;
	cout << "=                        7.销毁                            =" << endl;
	cout << "=                        8.修改                            =" << endl;
	cout << "=                        9.微分                            =" << endl;
	cout << "=                      10.不定积分                         =" << endl;
	cout << "=                       11.定积分                          =" << endl;
	cout << "=                     12.多项式乘法                        =" << endl;
	cout << "=                     13.多项式除法                        =" << endl;
	cout << "=                       14.求余式                          =" << endl;
	cout << "=                       15.乘方                            =" << endl;
	cout << "=                     16.最大公因式                        =" << endl;
	cout << "=                     17.最小公倍式                        =" << endl;
	cout << "============================================================" << endl;
}

void printWelcome() {
	cout << "============================================================" << endl;
	cout << "=                                                          =" << endl;
	cout << "=                欢迎使用稀疏多项式运算器                  =" << endl;
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
				cout << "请输入次数和与之对应的系数，一行一个次数和系数，用空格隔开，输入-1来结束输入流程：" << endl;
				cin >> *list[index];
				break;
			case 2:
				for (int i = 1; i <= index; i++) cout << i << ". " << *list[i];
				system("pause");
				break;
			case 3:
				cout << "你要拷贝第几号多项式？" << endl;
				cin >> m;
				index++;
				list[index] = new ploynomialList(*list[m]);
				break;
			case 4:
				cout << "请输入相加的几个多项式的下标，以空格隔开，输入0来结束输入：" << endl;
				m = 0;
				index++;
				list[index] = new ploynomialList;
				for (;;) {
					cin >> m;
					if (m == 0) break;
					if (m > index) {
						cerr << "输入错误，请重新输入！" << endl;
						continue;
					}
					*list[index] = *list[index] + *list[m];
				}
				break;
			case 5:
				cout << "请输入做差的两个多项式的下标：" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(*list[m] - *list[n]);
				break;
			case 6:
				cout << "请输入要求值的多项式的下标：" << endl;
				cin >> m;
				if (m > index) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				cout << "x=";
				cin >> x;
				cout << list[m]->value(x) << endl;
				system("pause");
				break;
			case 7:
				cout << "请输入要销毁的多项式的下标：" << endl;
				cin >> m;
				if (m > index) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				delete list[m];
				for (i = m; i < index; i++) list[i] = list[i + 1];
				list[index] = NULL;
				index--;
				break;
			case 8:
				cout << "请输入要修改的多项式的下标：" << endl;
				cin >> m;
				if (m > index) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				cout << "请选择：" << endl;
				cout << "0.退出" << endl << "1.清空多项式" << endl << "2.修改指定次数的系数" << endl;
				cin >> n;
				if (n == 0) break;
				else if (n == 1)list[m]->clear();
				else if (n == 2) {
					cout << "请输入要修改的系数的次数和系数：" << endl;
					pNode t;
					cin >> t.exp >> t.coef;
					if (list[m]->setNode(t) == -1) {
						cerr << "输入错误，请重新输入！" << endl;
						system("pause");
						break;
					}
				}
				else {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				break;
			case 9:
				cout << "请输入要求导的多项式的下标：" << endl;
				cin >> m;
				if (m > index) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				cout << "请输入求导的次数：" << endl;
				cin >> n;
				index++;
				list[index] = new ploynomialList(list[m]->nDiff(n));
				break;
			case 10:
				cout << "由于作者水平限制，不定积分的常数项无法表示！" << endl;
				cout << "请输入要不定积分的多项式的下标：" << endl;
				cin >> m;
				if (m > index) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(list[m]->integral());
				break;
			case 11:
				cout << "请输入要定积分的多项式的下标：" << endl;
				cin >> m;
				if (m > index) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				cout << "请输入积分左边界和右边界：" << endl;
				cin >> l >> r;
				cout << list[m]->definiteIntegral(l, r) << endl;
				system("pause");
				break;
			case 12:
				cout << "请输入相乘的几个多项式的下标，以空格隔开，输入0来结束输入：" << endl;
				m = 0;
				index++;
				list[index] = new ploynomialList(0);
				for (;;) {
					cin >> m;
					if (m == 0) break;
					if (m > index) {
						cerr << "输入错误，请重新输入！" << endl;
						continue;
					}
					*list[index] = *list[index] * *list[m];
				}
				break;
			case 13:
				cout << "请输入做差的两个多项式的下标：" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(*list[m] / *list[n]);
				break;
			case 14:
				cout << "请输入求余式的两个多项式的下标：" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(*list[m] % *list[n]);
				break;
			case 15:
				cout << "请输入要乘方的多项式的下标：" << endl;
				cin >> m;
				if (m > index) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				cout << "请输入乘方的次数：" << endl;
				cin >> n;
				if (n <= 0) {
					cerr << "输入错误，请重新输入！" << endl;
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
				cout << "请输入求最大公因式的两个多项式的下标：" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(list[m]->gcd(*list[n]));
				break;
			case 17:
				cout << "请输入求最小公倍式的两个多项式的下标：" << endl;
				cin >> m >> n;
				if ((m > index) || (n > index)) {
					cerr << "输入错误，请重新输入！" << endl;
					system("pause");
					break;
				}
				index++;
				list[index] = new ploynomialList(list[m]->lcm(*list[n]));
				break;
		}
	}
}