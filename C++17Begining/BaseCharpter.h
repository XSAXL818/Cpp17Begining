#pragma once
#include <iostream>
#include <string>

using namespace std;

class BaseCharpter{
public:
	static inline int chapter{ 0 };
	static inline int section{ 0 };

	static inline std::string titleSection{""};

	static inline void showChapterTitle(string title) {
		cout << endl << "~~~~~~~~~~~_____________~~~~~~~~~~~~测试第" << chapter++ << "章: " << titleSection << "~~~~~~~~~~~_____________~~~~~~~~~~~~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}

	static inline void showSectionTitle(string title) {
		cout << endl << endl << "**************测试" << chapter-1 << "_" << section++ << ": " << title << "**************" << endl << endl;
	}

	static inline void setChapter(int ch) {
		chapter = ch;
	}

	static inline void setSection(int sec) {
		section = sec;
	}




};

