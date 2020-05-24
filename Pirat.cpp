/*Программа предлагает пользователю угадать число в диапазоне от 1 до 10*/

        /*      TASKS
            Прописать код более масштабной проверки ввода пользователем
            Реализовать проверку ввода в функции game иначе программа выдает ошибки при преобразовании типов
            Отредактировать код расставить все по фэн-шую
        */


#include <iostream> // Библиотека ввода-вывода
#include <string>   //Библиотека для работы со строками требует использование namespace std
#include <Windows.h>//Для работы с кирилицей
#include <random>  // Для работы с функцией rand()
using namespace std;    //Для работы с классом string

int game(void); //Функция с описанием самой игры
int cheatcode;
int main(void)

{
    SetConsoleOutputCP(1251); //Переключает кодировку вывода в консоли на Windows 1251
    SetConsoleCP(1251); //Переключает кодировку ввода в консоль на Windows 1251
    string answer; // Хранит ответ пользователя для дальнейшей проверки на ошибки и преоборазования в численные типы
    int askint; //  Счетчик для цикла повторного запуска игрового алгоритма
    
    
    cout << "Привет! ";
    for (askint = 0; askint < 1;) //    Повторное предложение сыграть реализовано через цикл завершение программы при askint >= 1 
    {
        cout << "Хочешь сыграть в угадай число? (Y or n, Да или Нет?)\n \n";
        cin >> answer;
        if (answer == "Y" || answer == "y" || answer == "да" || answer == "Да" || answer == "ДА" || answer == "blitztest")
        {
            if (answer == "blitztest") //проверяется ввод чит-кода
            {
                cheatcode = 1;
                system("cls"); //Запускает системную команду "cls" - очистить экран консоли
                game();
            }
            else
            {
                system("cls"); //Запускает системную команду "cls" - очистить экран консоли
                game();
            }
        }
        else
        {
            //  В случае отрицательног ответа пользователя программа завершается
            if (answer == "N" || answer == "n" || answer == "нет" || answer == "Нет")
            {
                system("cls");
                cout << "Очень жаль... \nНу ты заходи... Если что... \n \nWritten by Sergey Prochukhan.\n";
                askint = 1;
            }
            else
                //  В случае некорректного ввода ответа пользователем программа ругается и повторно задает вопрос
            {
                system("cls");
                cout << "Я не понимаю твой ответ... \n \n";
                askint = 0;
            }

        }
    }
    return 0;
}

int game(void)
{
    cout << "Отлично! Я загадал число от 1 до 10 у тебя 3 попытки отгадать \n \n";
    string inputstr; // Объявлена переменная для хранения ввода пользователем
    cout << "Итак, какое же число я загадал?\n\n";
    random_device randev; //    Подключение генератора случайных целых чисел
    mt19937_64 rangenengine(randev()); //   Подключение движка Mersenne Twister Engine к генератору случайных целых чисел
    uniform_int_distribution <> randomizer (1, 10); // Объявление объекта класса uniform_int_distribution который производит случайное целое число в интервале от 1 до 10
    int randominteger = randomizer(rangenengine); // Вызвана функция генерации случайного числа в соответствии с rangenengine, результат сохранён в randominteger
    for (int count1 = 1; count1 <= 3; count1++)
    {
        if (cheatcode == 1) // условие при введенном чит коде
        {
            cout << "Даю подсказку, это число: " + to_string(randominteger) + "\n\n";
            cheatcode = 0;
        }
        else
        {}
        cin >> inputstr;
        int strtoint = stoi(inputstr); //   Объявлена целочисленная переменная с последующим преобразование введенной пользователем строки в целочисленный тип данных
        //  Временный костыль для проверки работоспособности кода программы на текущем этапе далее необходимо удалить либо закомментить
        if (strtoint != randominteger)
        {
            if (count1 < 3)
            {
                system("cls"); 
                cout << "Не угадал! У тебя осталось " + to_string(3 - count1) + " попытки \n\n";              
            }
            else
            {
                system("cls");
                cout << "Не угадал! Это было число: " + to_string(randominteger) + " \n \n";
                system("pause");
                system("cls");
                return 0;
            }
                
        }
        else
        {
            system("cls");
            cout << "Обалдеть!!! Ты угадал на " + to_string(count1) + " попытке!!! \n \n";
            return 0;
        }
            
        

    }
}


//Written by Sergey Prochukhan
