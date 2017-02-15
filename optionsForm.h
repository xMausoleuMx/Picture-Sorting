#pragma once

namespace PictureSorting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	static bool* updateContinuosly;
	/// <summary>
	/// Summary for optionsForm
	/// </summary>
	public ref class optionsForm : public System::Windows::Forms::Form
	{
	public:
		optionsForm(bool* continuoslyUpdate)
		{
			InitializeComponent();
			updateContinuosly = continuoslyUpdate;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~optionsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  leftImageKey;
	private: System::Windows::Forms::Button^  rightImageKey;
	private: System::Windows::Forms::Button^  saveKey;
	private: System::Windows::Forms::Button^  helpKey;
	private: System::Windows::Forms::Button^  exitKey;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->leftImageKey = (gcnew System::Windows::Forms::Button());
			this->rightImageKey = (gcnew System::Windows::Forms::Button());
			this->saveKey = (gcnew System::Windows::Forms::Button());
			this->helpKey = (gcnew System::Windows::Forms::Button());
			this->exitKey = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.38396F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.61604F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				23)));
			this->tableLayoutPanel1->Controls->Add(this->checkBox1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->checkBox2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label8, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->leftImageKey, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->rightImageKey, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->saveKey, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->helpKey, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->exitKey, 1, 7);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 23)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(258, 237);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(137, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &optionsForm::checkBox1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Continuosly update the ranked list";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(137, 34);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(15, 14);
			this->checkBox2->TabIndex = 2;
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Open specific directory on open ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Hotkeys:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 85);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Choose Left Image";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 114);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(103, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Choose Right Image";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 142);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Save";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 171);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Help";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 198);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Exit";
			// 
			// leftImageKey
			// 
			this->leftImageKey->Location = System::Drawing::Point(137, 88);
			this->leftImageKey->Name = L"leftImageKey";
			this->leftImageKey->Size = System::Drawing::Size(31, 23);
			this->leftImageKey->TabIndex = 11;
			this->leftImageKey->Text = L"A";
			this->leftImageKey->UseVisualStyleBackColor = true;
			this->leftImageKey->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &optionsForm::leftImageKey_KeyDown);
			// 
			// rightImageKey
			// 
			this->rightImageKey->Location = System::Drawing::Point(137, 117);
			this->rightImageKey->Name = L"rightImageKey";
			this->rightImageKey->Size = System::Drawing::Size(31, 22);
			this->rightImageKey->TabIndex = 12;
			this->rightImageKey->Text = L"D";
			this->rightImageKey->UseVisualStyleBackColor = true;
			this->rightImageKey->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &optionsForm::rightImageKey_KeyDown);
			// 
			// saveKey
			// 
			this->saveKey->Location = System::Drawing::Point(137, 145);
			this->saveKey->Name = L"saveKey";
			this->saveKey->Size = System::Drawing::Size(31, 23);
			this->saveKey->TabIndex = 13;
			this->saveKey->Text = L"S";
			this->saveKey->UseVisualStyleBackColor = true;
			this->saveKey->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &optionsForm::saveKey_KeyDown);
			// 
			// helpKey
			// 
			this->helpKey->Location = System::Drawing::Point(137, 174);
			this->helpKey->Name = L"helpKey";
			this->helpKey->Size = System::Drawing::Size(31, 21);
			this->helpKey->TabIndex = 14;
			this->helpKey->Text = L"F1";
			this->helpKey->UseVisualStyleBackColor = true;
			this->helpKey->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &optionsForm::helpKey_KeyDown);
			// 
			// exitKey
			// 
			this->exitKey->Location = System::Drawing::Point(137, 201);
			this->exitKey->Name = L"exitKey";
			this->exitKey->Size = System::Drawing::Size(34, 22);
			this->exitKey->TabIndex = 15;
			this->exitKey->Text = L"F4";
			this->exitKey->UseVisualStyleBackColor = true;
			this->exitKey->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &optionsForm::exitKey_KeyDown);
			// 
			// optionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(277, 261);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"optionsForm";
			this->Text = L"Options";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBox1->Checked)
		(*updateContinuosly) =  true;
	else
		(*updateContinuosly) = false;
}


private: System::Void leftImageKey_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

}
private: System::Void rightImageKey_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

}
private: System::Void saveKey_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

}
private: System::Void helpKey_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

}
private: System::Void exitKey_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

}
};
}
