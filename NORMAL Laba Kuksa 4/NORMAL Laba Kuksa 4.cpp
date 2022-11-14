/******************************************************************************
Кукса Кирилл Сергеевич
КТбо1-2
Лабораторная работа №4 «Файлы данных»
Вариант № 5
Задание: Написать программу, которая во вводимом с клавиатуры тексте
         заменит буквы «ь» (a) на «ъ» (b) и выведет результат на экран.
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    FILE* fin, * fout;
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    char t;
    char text[1000];
    int i;
    if (fin == NULL) puts("Ошибка открытия файла");
    else
    {
        while (!feof(fin))
        {
            fgets(text, 1000, fin);
            for (i = 0; text[i] != '\0'; i++)
            {
                t = text[i];
                if (t == 'a')
                {
                    t = 'b';
                    fprintf(fout, "%c", t);
                }
                else
                {
                    if (t == 'A')
                    {
                        t = 'B';
                        fprintf(fout, "%c", t);
                    }
                    else
                        fprintf(fout, "%c", t);
                }
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}