﻿//
// encoding: UTF-8 with BOM
// - So in order to print wide string to console output / read input from console we must use _setmode...
// - Use codecvt_utf8 for writing/reading from files
//

#include <iostream>
#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()
#include <string>
#include <locale>
#include <codecvt> //possible C++11?
#include <fstream>

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_WTEXT); //needed for output
    _setmode(_fileno(stdin), _O_WTEXT); //needed for input
    // nhớ chuyển font của console sang Consolas (size 16)

    std::wcout << L"Chương trình đọc và xuất chuỗi tiếng Việt\n\n";

    std::wstring username;
    std::wstring gender;
    int age;


    //// lưu file tiếng Việt (UTF-8 without BOM)
    std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);  // UTF-8
    std::wifstream fin(L"userinfo-c++.csv");
    if (!fin) {
        std::wcout << L"Không thể đọc file userinfo-c++.csv\n";
    } else {
        fin.imbue(loc);
        std::getline(fin, username);
        std::getline(fin, gender);
        fin >> age;

        std::wcout << L"Họ tên: " << username << L"\nGiới tính: " 
                   << gender
                   << L"\nTuổi: " << age << L"\n\n";

        fin.close();
    }


    std::wcout << L"Chương trình kết thúc.\n";
}