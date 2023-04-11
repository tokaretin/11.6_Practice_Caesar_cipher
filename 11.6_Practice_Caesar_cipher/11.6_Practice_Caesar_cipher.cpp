#include <iostream>
#include <string>

std::string encrypt_caesar(std::string str, int k) {
    std::string result = "";
    for (int i = 0; i < str.length(); i++) {  // проходим по всем символам в стрке (string str)
        if (isalpha(str[i])) {                // с помощью функции isalpha() - является ли текущий символ буквой. От A-Z and a-z
            char c = str[i] + k;              // если да, то символ сдвигается на "k" позиций в алфавите и сохраняется в переменной "c".  
            if (isupper(str[i])) {            // с помощью функции isupper() - является ли текущий символ заглавной буквой 
                if (c > 'Z') {              // выходит ли символ за пределы алфавита при сдвиге на "k"
                    c -= 26;                // если символ выходит за пределы алфавита, то от него отнимается 26, чтобы символ остался в пределах алфавита
                }
                else if (c < 'A') {         // если же символ находится в пределах алфавита
                    c += 26;                // прибавляется 26, чтобы символ не вышел за пределы алфавита
                }
            }
            else {
                if (c > 'z') {              // выходит ли символ за пределы алфавита при сдвиге на "k"
                    c -= 26;                // если символ выходит за пределы алфавита, то от него отнимается 26, чтобы символ остался в пределах алфавита
                }
                else if (c < 'a') {         // если же символ находится в пределах алфавита
                    c += 26;                // прибавляется 26, чтобы символ не вышел за пределы алфавита
                }
            }
            result += c;                    // после проверок символ сохраняется в переменную "result".
        }
        else {
            result += str[i];                 // если текущий символ не является буквой, то он просто добавляется в "result".
        }
    }
    return result;                          // "result" будет содержать зашифрованную строку "s" с помощью шифра Цезаря со сдвигом "k".
}

/* В данной функции decrypt_caesar ключ k передается в функцию encrypt_caesar со знаком минус,
чтобы обратить направление сдвига и расшифровать строку. */
std::string decrypt_caesar(std::string s, int k) {    
    return encrypt_caesar(s, -k);
}

int main() {
    std::string str;
    int k;
    std::getline(std::cin, str);
    std::cin >> k;
    std::cout << encrypt_caesar(str, k) << '\n';
    std::cout << decrypt_caesar(encrypt_caesar(str, k), k) << '\n';
    return 0;
}

/* Задание 1. Шифр Цезаря
Что нужно сделать
В древности для шифрования сообщений использовался такой способ: 
все буквы в сообщении сдвигались на одно и то же число позиций в алфавите.
Число позиций могло быть как положительным, так и отрицательным и являлось 
параметром шифра — его ключом. Если для сдвига на данное число позиций 
алфавита не хватает, то он зацикливается (то есть буква с 
номером 27 — это снова буква a, буква с номером 28 — это буква b и так далее).

Например, слово abracadabra при сдвиге на десять позиций превратится 
в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. Регистр 
букв (заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar 
от строки и числа, которая возвращает исходную строку, зашифрованную шифром 
Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, 
выполняющую обратное преобразование. Считаем, что входные строки состоят 
лишь из английских букв. Если там содержатся и другие символы, то их надо 
игнорировать.

Пример 1
The quick brown fox jumps over the lazy dog

Результат
Ymj vznhp gwtbs ktc ozrux tajw ymj qfed itl

Пример 2
Lorem ipsum dolor sit amet consectetur adipiscing elit sed 
do eiusmod tempor incididunt ut labore et dolore magna aliqua 
enim ad minim veniam quis nostrud exercitation ullamco laboris 
nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in 
reprehenderit in voluptate velit esse cillum dolore eu fugiat 
nulla pariatur Excepteur sint occaecat cupidatat non proident 
sunt in culpa qui officia deserunt mollit anim id est laborum

Результат

Knqdl hortl cnknq rhs zlds bnmrdbsdstq zchohrbhmf dkhs rdc cn 
dhtrlnc sdlonq hmbhchctms ts kzanqd ds cnknqd lzfmz zkhptz Ts 
dmhl zc lhmhl udmhzl pthr mnrsqtc dwdqbhszshnm tkkzlbn kzanqhr 
mhrh ts zkhptho dw dz bnllncn bnmrdptzs Cthr ztsd hqtqd cnknq 
hm qdoqdgdmcdqhs hm unktoszsd udkhs drrd bhkktl cnknqd dt etfhzs 
mtkkz ozqhzstq Dwbdosdtq rhms nbbzdbzs btohczszs mnm oqnhcdms rtms 
hm btkoz pth neehbhz cdrdqtms lnkkhs zmhl hc drs kzanqtl

Рекомендации
Уже имея функцию encrypt_caesar, функцию decrypt_caesar можно 
реализовать в одну строчку.

Функция шифрования принимает на вход строку и смещение. Нужно 
добавить смещение к числовому значению очередной буквы, но учесть 
зацикленность нашего алфавита.

У английской буквы ‘A’ числовое значение 65. Вы можете узнать 
остальные значения при помощи cout << int(‘интересующая вас буква’); 

То есть для получения числового значения символа добавляем 
одинарные кавычки. Чтобы проверить, попадает ли символ в диапазон, 
нужно сделать if(symbol >= ‘x’ && symbol <=’z’).

Коды у заглавных и строчных символов разные. Чтобы ограничить число 
верхним пределом, можно воспользоваться оператором %.

При делении с остатком на число 26 никогда не получим число больше 
него. Значит не выйдем за пределы алфавита, а снова попадём в его 
начало (27 % 26 даёт 1, то есть снова первый символ). Чтобы зашифровать символ s, нам нужно:

Отнять от него значение первого символа алфавита (‘a’ или ‘A’ — 
вам потребуются два условия для двух разных случаев). Получим 
порядковый номер символа в алфавите.
Добавить смещение шифра, которое указывает пользователь.
Полученное значение разделить с остатком на 26. Получим порядковый 
номер символа в алфавите с учётом его зацикленности. Осталось получить 
этот символ, зная его номер. Для этого к коду первого символа алфавита 
(‘a’ или ‘A’) добавляем полученный порядковый номер. */

