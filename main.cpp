#include <iostream>
#include <string>
#include <algorithm>
#include "myfuncs.cpp"

using namespace std;

int main()
{
    while(true)
    {
        bool repeatable = false;
        string ans;
        long n;
        cout << "Для начала необходимо ввести число n." 
        << endl << "Использовать консоль или файл для получения значения?[ф/к] ";
        getline(cin, ans);
        if (ans == "ф")
            n = file_input();
        else if (ans == "к")
        {
            n = console_input();
            repeatable = true;
        }
        else
        {
            cout << "Выберите одну из предложенных опций посредством введения соответствующей буквы!" 
            << endl << endl;
            continue;
        }
        double farengate[n];
        cels_to_farenheit(farengate, n);
        while (true)
        {
            ans = "";
            cout << "Необходимо выбрать способ вывода данных. Файл или консоль?[ф/к] ";
            getline(cin, ans);
            if (ans == "ф")
            {
                file_output(farengate, n);
                break;
            }
            else if (ans == "к")
            {
                if (n > 20)
                {
                    double to_out[20];
                    copy(farengate, farengate + 21, to_out);
                    long part = 20;
                    console_output(to_out, part);
                    cout << "..." << endl << endl;
                    cout << n - 20 << " значений были выведены в файл output.txt для экономии места." << endl;
                    file_output(farengate, n);
                }
                else
                {
                    console_output(farengate, n);  
                }
                break;
            }
            else
            {
                cout << "Выберите одну из предложенных опций посредством введения соответствующей буквы!" 
                << endl << endl;
                continue;
            }
        }

        while(true)
        {
            if (repeatable)
            {
                cout << "Желаете повторить?[Д/н] ";
                ans = "";
                getline(cin, ans);
                if (ans == "Д" || ans == "д")
                    break;
                else if (ans == "Н" || ans == "н")
                    return 0;
                else
                {
                    cout << "Введите корректный ответ на вопрос!" << endl << endl;
                    continue;
                }
            }
            return 0;
        }
    }
    return 0; 
}