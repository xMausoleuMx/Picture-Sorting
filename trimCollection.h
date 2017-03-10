#include "optionsForm.h"
#pragma once

namespace PictureSorting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	vector<image>* trimList;
	/// <summary>
	/// Summary for trimCollection
	/// </summary>
	public ref class trimCollection : public System::Windows::Forms::Form
	{
	public:
		trimCollection(vector<image>* tempList)
		{
			InitializeComponent();
			trimList = tempList;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~trimCollection()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  topCheckBox;
	private: System::Windows::Forms::CheckBox^  bottomCheckBox;
	private: System::Windows::Forms::NumericUpDown^  sectionSet;


	private: System::Windows::Forms::Button^  start;

	private: System::Windows::Forms::CheckBox^  percentCheckBox;
	private: System::Windows::Forms::CheckBox^  amountCheckBox;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::FolderBrowserDialog^  moveFilesTo;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->topCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->bottomCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->sectionSet = (gcnew System::Windows::Forms::NumericUpDown());
			this->start = (gcnew System::Windows::Forms::Button());
			this->percentCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->amountCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->moveFilesTo = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sectionSet))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(502, 285);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &trimCollection::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 387);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 37);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Yes";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(424, 387);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 37);
			this->button2->TabIndex = 2;
			this->button2->Text = L"No";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// topCheckBox
			// 
			this->topCheckBox->AutoSize = true;
			this->topCheckBox->Location = System::Drawing::Point(13, 325);
			this->topCheckBox->Name = L"topCheckBox";
			this->topCheckBox->Size = System::Drawing::Size(45, 17);
			this->topCheckBox->TabIndex = 3;
			this->topCheckBox->Text = L"Top";
			this->toolTip1->SetToolTip(this->topCheckBox, L"Will choose the top down");
			this->topCheckBox->UseVisualStyleBackColor = true;
			this->topCheckBox->CheckedChanged += gcnew System::EventHandler(this, &trimCollection::topCheckBox_CheckedChanged);
			// 
			// bottomCheckBox
			// 
			this->bottomCheckBox->AutoSize = true;
			this->bottomCheckBox->Checked = true;
			this->bottomCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->bottomCheckBox->Location = System::Drawing::Point(12, 348);
			this->bottomCheckBox->Name = L"bottomCheckBox";
			this->bottomCheckBox->Size = System::Drawing::Size(59, 17);
			this->bottomCheckBox->TabIndex = 4;
			this->bottomCheckBox->Text = L"Bottom";
			this->toolTip1->SetToolTip(this->bottomCheckBox, L"Will choose files from the bottom up.");
			this->bottomCheckBox->UseVisualStyleBackColor = true;
			this->bottomCheckBox->CheckedChanged += gcnew System::EventHandler(this, &trimCollection::bottomCheckBox_CheckedChanged);
			// 
			// sectionSet
			// 
			this->sectionSet->Location = System::Drawing::Point(244, 336);
			this->sectionSet->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->sectionSet->Name = L"sectionSet";
			this->sectionSet->Size = System::Drawing::Size(46, 20);
			this->sectionSet->TabIndex = 6;
			this->toolTip1->SetToolTip(this->sectionSet, L"This number corresponds to either the percentage or number of files that will be "
				L"selected");
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(218, 379);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(103, 44);
			this->start->TabIndex = 7;
			this->start->Text = L"Start";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &trimCollection::startButton_Click);
			// 
			// percentCheckBox
			// 
			this->percentCheckBox->AutoSize = true;
			this->percentCheckBox->Checked = true;
			this->percentCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->percentCheckBox->Location = System::Drawing::Point(424, 325);
			this->percentCheckBox->Name = L"percentCheckBox";
			this->percentCheckBox->Size = System::Drawing::Size(63, 17);
			this->percentCheckBox->TabIndex = 8;
			this->percentCheckBox->Text = L"Percent";
			this->toolTip1->SetToolTip(this->percentCheckBox, L"Will choose a percent of the overall ");
			this->percentCheckBox->UseVisualStyleBackColor = true;
			this->percentCheckBox->CheckedChanged += gcnew System::EventHandler(this, &trimCollection::percentCheckBox_CheckedChanged);
			// 
			// amountCheckBox
			// 
			this->amountCheckBox->AutoSize = true;
			this->amountCheckBox->Location = System::Drawing::Point(424, 348);
			this->amountCheckBox->Name = L"amountCheckBox";
			this->amountCheckBox->Size = System::Drawing::Size(62, 17);
			this->amountCheckBox->TabIndex = 9;
			this->amountCheckBox->Text = L"Amount";
			this->toolTip1->SetToolTip(this->amountCheckBox, L"Will choose a static number of files instead of a percentage.");
			this->amountCheckBox->UseVisualStyleBackColor = true;
			this->amountCheckBox->CheckedChanged += gcnew System::EventHandler(this, &trimCollection::amountCheckBox_CheckedChanged);
			// 
			// trimCollection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(526, 436);
			this->Controls->Add(this->amountCheckBox);
			this->Controls->Add(this->percentCheckBox);
			this->Controls->Add(this->start);
			this->Controls->Add(this->sectionSet);
			this->Controls->Add(this->bottomCheckBox);
			this->Controls->Add(this->topCheckBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"trimCollection";
			this->Text = L"Trim";
			this->Load += gcnew System::EventHandler(this, &trimCollection::trimCollection_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sectionSet))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

//checkbox to choose from the top portion of the collection
private: System::Void topCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (topCheckBox->Checked)
		bottomCheckBox->Checked = false;
	else
		bottomCheckBox->Checked = true;
}


//checkbox to choose from the bottom portion of the collection
private: System::Void bottomCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (bottomCheckBox->Checked)
		topCheckBox->Checked = false;
	else
		topCheckBox->Checked = true;
}

//checkbox to choose that the user wants a percentage of the total collection.
private: System::Void percentCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (percentCheckBox->Checked)
		amountCheckBox->Checked = false;
	else
		amountCheckBox->Checked = true;
}

//checkbox to choose that that user wants a specific amount of images from the collection.
private: System::Void amountCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (amountCheckBox->Checked)
		percentCheckBox->Checked = false;
	else
		percentCheckBox->Checked = true;
}

private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {
	bool flag = false;
	if (amountCheckBox->Checked){
		if (sectionSet->Value > trimList->size()){
			MessageBox::Show("Error:You cannot select a number larger than the amount of images in you collection.", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		}
		else if(sectionSet->Value % getValidPortions() !=0 ){

		}
		else{

		}
	}
	else if (percentCheckBox->Checked){
		if (sectionSet->Value > 100 || sectionSet->Value < 0){
			MessageBox::Show("Error:You have selected a value that is invalid when using percentages.\nIf want to select a percent of the collection make sure you choose a value between 100 and 0", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		}
		else if ((trimList->size()*sectionSet->Value/100) % getValidPortions() != 0){

		}
		else{

		}
	}
	if(flag){
		MessageBox::Show("Select the place you would like the portion of your collection to be moved to.", "Info", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		System::Windows::Forms::DialogResult result = moveFilesTo->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK){

		}
		else
			MessageBox::Show("Error:Invalid selection.", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	}
}

//gets the valid divisions for the collection based on the lowest number of comparisons
int getValidPortions(){
	int lowestComparison = INT_MAX, sectionSize = 0;
	for (int i = 0; i < trimList->size(); i++){
		if ((*trimList)[i].comparisons < lowestComparison)
			lowestComparison = (*trimList)[i].comparisons;
	}
	sectionSize = trimList->size()/pow(2,lowestComparison);
	return sectionSize;
}

private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	//Process::Start("insert path here") open the image in its default software
}

private: System::Void trimCollection_Load(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("This program will allow you to move a portion of the image collection to a seperate sub-folder\nFrom there you can do whatever you want with the files.\nNote that it will not remove them from the collection", "Info", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}
};
}
