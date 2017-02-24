#include "Work.cpp"

#pragma once
namespace PictureSorting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static vector<setting>* userSettings;
	/// <summary>
	/// Summary for optionsForm
	/// </summary>
	public ref class optionsForm : public System::Windows::Forms::Form
	{
	public:
		optionsForm(vector<setting>* temp)
		{
			userSettings = temp;
			InitializeComponent();
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
	private: System::Windows::Forms::CheckBox^  checkBoxUpdateContinuously;
	protected:

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBoxScoreSort;
	private: System::Windows::Forms::CheckBox^  checkBoxRatingSort;




	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::OpenFileDialog^  selectStartupCollection;
	private: System::Windows::Forms::CheckBox^  checkBoxOpenOnStartup;
	private: System::Windows::Forms::Label^  fileChosen;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::ComponentModel::IContainer^  components;
	private: bool doneLoading = false;
















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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBoxUpdateContinuously = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBoxScoreSort = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxRatingSort = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxOpenOnStartup = (gcnew System::Windows::Forms::CheckBox());
			this->fileChosen = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->selectStartupCollection = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				82.02247F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				17.97753F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				214)));
			this->tableLayoutPanel1->Controls->Add(this->checkBoxUpdateContinuously, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->checkBoxScoreSort, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->checkBoxRatingSort, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->checkBoxOpenOnStartup, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->fileChosen, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->label5, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label6, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->label7, 2, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 8;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 26)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 23)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(393, 237);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// checkBoxUpdateContinuously
			// 
			this->checkBoxUpdateContinuously->AutoSize = true;
			this->checkBoxUpdateContinuously->Location = System::Drawing::Point(149, 3);
			this->checkBoxUpdateContinuously->Name = L"checkBoxUpdateContinuously";
			this->checkBoxUpdateContinuously->Size = System::Drawing::Size(15, 14);
			this->checkBoxUpdateContinuously->TabIndex = 0;
			this->checkBoxUpdateContinuously->UseVisualStyleBackColor = true;
			this->checkBoxUpdateContinuously->CheckedChanged += gcnew System::EventHandler(this, &optionsForm::checkBoxUpdateContinuously_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Continuously update the ranked list";
			this->toolTip1->SetToolTip(this->label1, L"Refresh the top and bottom lists every time there is a change in the scores of th"
				L"e collection. Note there will be performance imapcts.");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Open specific directory on open ";
			this->toolTip1->SetToolTip(this->label2, L"On open, load a collection of images that has been previously saved.");
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Sort by score";
			this->toolTip1->SetToolTip(this->label3, L"Sort the pictures by their raw score.(default)");
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Sort by rating";
			this->toolTip1->SetToolTip(this->label4, L"Sort pictures by their rating (score divided by the number of comparisons).");
			// 
			// checkBoxScoreSort
			// 
			this->checkBoxScoreSort->AutoSize = true;
			this->checkBoxScoreSort->Checked = true;
			this->checkBoxScoreSort->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxScoreSort->Location = System::Drawing::Point(149, 67);
			this->checkBoxScoreSort->Name = L"checkBoxScoreSort";
			this->checkBoxScoreSort->Size = System::Drawing::Size(15, 14);
			this->checkBoxScoreSort->TabIndex = 6;
			this->checkBoxScoreSort->UseVisualStyleBackColor = true;
			this->checkBoxScoreSort->CheckedChanged += gcnew System::EventHandler(this, &optionsForm::checkBoxScoreSort_CheckedChanged);
			// 
			// checkBoxRatingSort
			// 
			this->checkBoxRatingSort->AutoSize = true;
			this->checkBoxRatingSort->Location = System::Drawing::Point(149, 93);
			this->checkBoxRatingSort->Name = L"checkBoxRatingSort";
			this->checkBoxRatingSort->Size = System::Drawing::Size(15, 14);
			this->checkBoxRatingSort->TabIndex = 7;
			this->checkBoxRatingSort->UseVisualStyleBackColor = true;
			this->checkBoxRatingSort->CheckedChanged += gcnew System::EventHandler(this, &optionsForm::checkBoxRatingSort_CheckedChanged);
			// 
			// checkBoxOpenOnStartup
			// 
			this->checkBoxOpenOnStartup->AutoSize = true;
			this->checkBoxOpenOnStartup->Location = System::Drawing::Point(149, 35);
			this->checkBoxOpenOnStartup->Name = L"checkBoxOpenOnStartup";
			this->checkBoxOpenOnStartup->Size = System::Drawing::Size(15, 14);
			this->checkBoxOpenOnStartup->TabIndex = 8;
			this->checkBoxOpenOnStartup->UseVisualStyleBackColor = true;
			this->checkBoxOpenOnStartup->CheckedChanged += gcnew System::EventHandler(this, &optionsForm::checkBoxOpenOnStartup_CheckedChanged);
			// 
			// fileChosen
			// 
			this->fileChosen->AutoSize = true;
			this->fileChosen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fileChosen->Location = System::Drawing::Point(181, 32);
			this->fileChosen->Name = L"fileChosen";
			this->fileChosen->Size = System::Drawing::Size(89, 13);
			this->fileChosen->TabIndex = 9;
			this->fileChosen->Text = L"No file chosen";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(181, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(205, 26);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Will enable the ranked list to continuously update";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(181, 64);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(112, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Will rank files by score";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(181, 90);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(112, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Will rank files by rating";
			// 
			// selectStartupCollection
			// 
			this->selectStartupCollection->Filter = L"CSV (*.csv)|*.csv|All files (*.*)|*.*";
			// 
			// optionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(417, 261);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"optionsForm";
			this->Text = L"Options";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			load();
		}
#pragma endregion

//load the values for the options box from the ini file
void load(){
	if ((*userSettings)[0].flag)
		checkBoxUpdateContinuously->Checked = true;
	if ((*userSettings)[1].path.compare("") || (*userSettings)[1].path.compare("false")){
		fileChosen->Text = gcnew String((*userSettings)[1].path.c_str());
		checkBoxOpenOnStartup->Checked = true;
	}
	if ((*userSettings)[2].flag)
		checkBoxScoreSort->Checked = true;
	if ((*userSettings)[3].flag)
		checkBoxRatingSort->Checked = true;
	doneLoading = true;
}

//if the first checkbox is ticked change the setting to continuously sort
private: System::Void checkBoxUpdateContinuously_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBoxUpdateContinuously->Checked)
		(*userSettings)[0].flag =  true;
	else
		(*userSettings)[0].flag = false;

	writeConfig();
}

//if the second checkbox is ticked open a openFileDialog and have the user select the save file that they want open by default
private: System::Void checkBoxOpenOnStartup_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if(doneLoading){//so that it doesnt open when the form is first opened
		if (checkBoxOpenOnStartup->Checked){
			if ((selectStartupCollection->ShowDialog() == System::Windows::Forms::DialogResult::OK)){
				fileChosen->Text = selectStartupCollection->FileName;
				(*userSettings)[1].flag = true;
				(*userSettings)[1].path = Stringtostring(selectStartupCollection->FileName);
				writeConfig();
			}
		}
		else{//if they disable this setting it sets the path to empty.
			(*userSettings)[1].flag = false;
			(*userSettings)[1].path = "";
			writeConfig();
			fileChosen->Text = "No file chosen";
		}
	}
}

//if the third checkbox is ticked then set the sorting method to score
private: System::Void checkBoxScoreSort_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBoxScoreSort->Checked){
		checkBoxRatingSort->Checked = false;
		(*userSettings)[2].flag = true;
		(*userSettings)[3].flag = false;
	}
	else
		checkBoxRatingSort->Checked = true;

	writeConfig();
}

//if the fourth checkbox is ticked then set the sorting method to rating
private: System::Void checkBoxRatingSort_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (checkBoxRatingSort->Checked){
		checkBoxScoreSort->Checked = false;
		(*userSettings)[2].flag = false;
		(*userSettings)[3].flag = true;
	}
	else
		checkBoxScoreSort->Checked = true;

	writeConfig();
	
}

//write the new settings to the ini file
void writeConfig(){
	StreamWriter^ writer = gcnew StreamWriter("config.ini");
	for (int i = 0; i < (*userSettings).size(); i++){
		if (!(*userSettings)[i].path.compare("")){
			string holder = ((*userSettings)[i].flag ? "true" : "false");
			writer->WriteLine("{0} = {1}", gcnew String((*userSettings)[i].name.c_str()), gcnew String(holder.c_str()));
		}
		else{
			writer->WriteLine("{0} = {1}", gcnew String((*userSettings)[i].name.c_str()), gcnew String((*userSettings)[1].path.c_str()));
		}
	}
	writer->Close();
}
};
}
