

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);  
	int a;
    do {
        cout << "Введіть номер завдання (1-3)( Вихід = 0). : ";
        cin >> a;
        switch (a) {
        case 1:
        {
            string n;
            string v;

            cout << "Введіть рядок 1: ";
            cin.ignore();
            getline(cin, n);
            cout << "Введіть рядок 2: ";
            cin.ignore();
            getline(cin, v);
            ofstream file1("file1.txt");
            ofstream file2("file2.txt");

            if (file1.is_open()) {
                file1 << n << endl;
                file1.close();
            }

            if (file2.is_open()) {
                file2 << v << endl;
                file2.close();
            }

            ifstream read1("file1.txt");
            ifstream read2("file2.txt");
			string line1, line2;
            while (getline(read1, line1) && getline(read2, line2))
            {
                if (line1 != line2)
                {
					cout << "Рядки не однакові." << endl;
                    cout << "Файл 1: " << line1 << endl;
                    cout << "Файл 2: " << line2 << endl;
                }
                else
                {
					cout << "Рядки однакові." << endl;
                    cout << "Файл 1: " << line1 << endl;
                    cout << "Файл 2: " << line2 << endl;
                }
            }
        }
        break;

        case 2:
        {

            string n;

            cout << "Введіть рядок 1: "<<endl;
            cin.ignore();
            getline(cin, n);

            ofstream file2("file3.txt");

            if (file2.is_open()) {
                file2 << n << endl;
                file2.close();
            }
            ifstream read1("file3.txt");
            string line1;
            int sumR = 0;

            while (getline(read1, line1)) {
                sumR++;
            }
            read1.clear();
            read1.seekg(0);
            cout << "Кількість рядків у файлі: " << sumR << endl;
            char ch;
            int sumC = 0;
            while (read1.get(ch)) {
                sumC++;
            }
            read1.clear();
            read1.seekg(0);
            cout << "Кількість символів у файлі: " << sumC-1 << endl;
            char cv;
            int sumN = 0;
            while (read1.get(cv))
            {
                if (cv >= '0' && cv <= '9')
                {
                    sumN++;
                }
            }
            cout << "Кількість цифр: " << sumN << endl;
            read1.clear();
            read1.seekg(0);
            char cx;
            int sumG = 0;
			int sumP = 0;
            while (read1.get(cx))
            {
                if (cx == 'a' || cx == 'e' || cx == 'i' || cx == 'o' || cx == 'u' ||
                    cx == 'A' || cx == 'E' || cx == 'I' || cx == 'O' || cx == 'U')
                {
                    sumG++;
                }
                else if ((cx >= 'a' && cx <= 'z') || (cx >= 'A' && cx <= 'Z'))
                {
                    sumP++;
                }
            }
            cout << "Кількість голосних: " << sumG << endl;
            cout << "Кількість приголосних: " << sumP << endl;
            read1.clear();
            read1.seekg(0);
            ofstream file3("file4.txt");
            if (file3.is_open()) {
                file3 << "Кількість символів у файлі: " << sumC - 1 << endl <<
                    "Кількість рядків у файлі: " << sumR << endl <<
                    "Кількість голосних: " << sumG << endl <<
                    "Кількість приголосних: " << sumP << endl <<
                    "Кількість цифр: " << sumN << endl;
                file3.close();
            }
            break;
        }
        case 3:
        {
            string n;

            cout << "Введіть рядок 1: " << endl;
            cin.ignore();
            getline(cin, n);

            ofstream file6("file5.txt");

            if (file6.is_open()) {
                file6 << n << endl;
                file6.close();
            }
            ifstream read1("file5.txt");
            string line1;
            char cx;
			string text = "";
            while (read1.get(cx))
            {
                if (cx >= 'a' && cx <= 'z')
                {
                    cx = cx + 3;

                    if (cx > 'z')
                    {
                        cx = cx - 26;
                    }
                }

                if (cx >= 'A' && cx <= 'Z')
                {
                    cx = cx + 3;

                    if (cx > 'Z')
                    {
                        cx = cx - 26;
                    }
                }
				text += cx;
				
            }
            cout << "Шифрований текст: " << text<< endl;
            ofstream file3("file7.txt");
            if (file3.is_open()) {
                file3 << "Шифрований текст: " << text << endl;
                file3.close();

            }
			break;
           }

        case 0:
            cout << "Вихід з програми."<< endl;
            break;

        default:
            cout << "Неправильний вибір!"<< endl;
        }

    } while (a != 0);
}

