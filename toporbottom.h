#include "searchForm.h"
#pragma once

namespace PictureSorting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	///  Gets wether the user wants to trim from the top or bottom of the list
	/// </summary>
	public ref class toporbottom : public System::Windows::Forms::Form
	{
		vector<image>* passList;
	public:
		toporbottom(vector<image>* temp)
		{
			InitializeComponent();
			passList = temp;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~toporbottom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  topCheckBox;
	private: System::Windows::Forms::CheckBox^  bottomCheckBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->topCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->bottomCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(214, 44);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &toporbottom::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(222, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Would you like to choose images from the top";
			// 
			// topCheckBox
			// 
			this->topCheckBox->AutoSize = true;
			this->topCheckBox->Location = System::Drawing::Point(241, 13);
			this->topCheckBox->Name = L"topCheckBox";
			this->topCheckBox->Size = System::Drawing::Size(15, 14);
			this->topCheckBox->TabIndex = 2;
			this->topCheckBox->UseVisualStyleBackColor = true;
			this->topCheckBox->CheckedChanged += gcnew System::EventHandler(this, &toporbottom::topCheckBox_CheckedChanged);
			// 
			// bottomCheckBox
			// 
			this->bottomCheckBox->AutoSize = true;
			this->bottomCheckBox->Checked = true;
			this->bottomCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->bottomCheckBox->Location = System::Drawing::Point(16, 44);
			this->bottomCheckBox->Name = L"bottomCheckBox";
			this->bottomCheckBox->Size = System::Drawing::Size(15, 14);
			this->bottomCheckBox->TabIndex = 3;
			this->bottomCheckBox->UseVisualStyleBackColor = true;
			this->bottomCheckBox->CheckedChanged += gcnew System::EventHandler(this, &toporbottom::bottomCheckBox_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(262, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"or";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"bottom of the collection";
			// 
			// toporbottom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 79);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->bottomCheckBox);
			this->Controls->Add(this->topCheckBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"toporbottom";
			this->Text = L"toporbottom";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//makes the two checkboxes an XOR switch so that one is always checked.
private: System::Void topCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (topCheckBox->Checked)
		bottomCheckBox->Checked = false;
	else
		bottomCheckBox->Checked = true;
}
private: System::Void bottomCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (bottomCheckBox->Checked)
		topCheckBox->Checked = false;
	else
		topCheckBox->Checked = true;
}

//when the ok button is clicked open the searchform and hide this window, disposing of it after completion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	PictureSorting::searchForm^  userSearch = gcnew PictureSorting::searchForm(passList, topCheckBox->Checked);
	this->Hide();
	userSearch->ShowDialog();
	this->Close();
}

};
}
