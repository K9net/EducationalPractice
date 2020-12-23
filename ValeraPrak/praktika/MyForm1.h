#pragma once
#define _CRT_SECURE_NO_WARNINGS
//Подключаем DLL
#include "vector.h"
//Подключаем остальные библиотеки
#include <Windows.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <algorithm>
#include <string>
using namespace std;

namespace praktika {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Обьявляем массив, состоящий из букв
	static char* a[26] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	
	//Описываем функцию заполнения текстового файла
	static void CreateSymbols() {
		vector<char*> v; //Создаем вектор v
		srand(time(0));
		char* ch; //Дополнительная переменна для записи букв в вектор и текстовый файл
		FILE* f = fopen("letter.txt", "w"); //Открываем файл для записи
		ofstream f1; //Отркываем файл для записи
		f1.open("sort.txt");
		for (int i = 0; i < 10; i++) //Цикл из 100 шагов
		{	
			for(int j = 0; j < 10; j++)
			{ 
				ch = a[rand() % (sizeof a / sizeof(char*))]; //В переменную помещаем букву, созданную рандомно
				v.push_back(ch); //Помещаем букву в вектор
				fprintf(f, ch); //Помещаем букву в текстовый файл
			}
			fprintf(f, "\n"); //Добавляем отступ в текстовом файле, чтобы разделить строки по 10 символов
		}
		sort(v.begin(), v.end()); //Выполняем сортировку от меньшего к большему
		for (auto element : v) //Цикл для вывода отсортированных элементов в текстовый файл
		{	
				f1 << element; //Вывод элементов в текстовый файл
		}
		fclose(f); //Закрытие файла
		f1.close(); //Закрытие файла
	}

	//Описываем функцию для создания символов звездочек
	static void Stars() {
	FILE* f = fopen("letter.txt", "w"); //Открываем файл для записи
	for(int i = 0; i < 100; i++) //Цикл из 10000 шагов
	{
		for (int j = 0; j < 100; j++)
		{
			if (j == i) //Печатает звездочку на главной диагонали
				fprintf(f, "*");
			else
				fprintf(f, " "); //Печатает пробел везде, кроме главной диагонали
		}
		fprintf(f, "\n"); //Отступ на новую строку
	}
	fclose(f);//Закрытие файла
	}
	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
		//Элменты, которые находятся на форме
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button3;

	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	public:
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->button2->Location = System::Drawing::Point(16, 62);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(161, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Заполнить файл буквами";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(213, 62);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(161, 37);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Выполнить сортировку";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(276, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(350, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(415, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 116);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(161, 190);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(213, 116);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(161, 190);
			this->textBox2->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(410, 116);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(319, 190);
			this->textBox3->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(492, 62);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(161, 37);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Вывести звездочки";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(13, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(266, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Выполнен вход в систему под именем: ";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 332);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Name = L"MyForm1";
			this->Text = L"Вычисления";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Действия при нажатии на кнопку "Заполнить файл буквами": запускаем поток для функции, выводим textBox1
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		thread thr1(&CreateSymbols); // Поток, работающий с буквами
		thr1.join(); // Запускаем поток
		textBox1->Text = System::IO::File::ReadAllText("letter.txt"); // Помещаем содержимое файла в текстовую область	
	}	   

	//Действия при нажатии на кнопку "Вывести звездочки": запускаем поток для функции, выводим textBox3
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		thread thr2(&Stars); // Поток, создающий звездочки
		thr2.join(); // Запускаем поток
		textBox3->Text = System::IO::File::ReadAllText("letter.txt"); // Помещаем содержимое файла в текстовую область	
	}
	//Действия при нажатии на кнопку "Выполнить сортировку": запускаем поток для функции, выводим textBox2
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		textBox2->Text = System::IO::File::ReadAllText("sort.txt"); // Помещаем содержимое файла в текстовую область	
	}
};
}
