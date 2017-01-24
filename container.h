#include "Work.cpp"
#include <vcclr.h>

static vector<image> picList;
static vector<int[2]> index;

#pragma once
namespace PictureSorting {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class container : public System::Windows::Forms::Form
	{
	public:
		container(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~container()
		{
			if (components)
			{
				delete components;
			}
		}
	private:bool openedFlag = false;
	private: System::String^ fileName;
	private: int crntCpr = 0;
	private: System::Windows::Forms::PictureBox^  leftImage;
	private: System::Windows::Forms::PictureBox^  rightImage;




	private: System::Windows::Forms::Button^  selectLeft;
	private: System::Windows::Forms::Button^  selectRight;
	private: System::Windows::Forms::Label^  rightCurrentScore;

	private: System::Windows::Forms::Label^  leftCurrentScore;

	private: System::Windows::Forms::Button^  refresh;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fieToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  websiteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fAQToolStripMenuItem;

	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  newDirectoryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  existingDirectoryToolStripMenuItem;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  saveAndQuit;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  deleteItem;
	private: System::Windows::Forms::FolderBrowserDialog^  openNewDirectory;
	private: System::Windows::Forms::SaveFileDialog^  saveFile;


	protected:


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
			this->leftImage = (gcnew System::Windows::Forms::PictureBox());
			this->rightImage = (gcnew System::Windows::Forms::PictureBox());
			this->selectLeft = (gcnew System::Windows::Forms::Button());
			this->selectRight = (gcnew System::Windows::Forms::Button());
			this->rightCurrentScore = (gcnew System::Windows::Forms::Label());
			this->leftCurrentScore = (gcnew System::Windows::Forms::Label());
			this->refresh = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newDirectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->existingDirectoryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->websiteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fAQToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->saveAndQuit = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->deleteItem = (gcnew System::Windows::Forms::Button());
			this->openNewDirectory = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->saveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->leftImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rightImage))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// leftImage
			// 
			this->leftImage->BackColor = System::Drawing::SystemColors::ControlDark;
			this->leftImage->Location = System::Drawing::Point(8, 27);
			this->leftImage->Name = L"leftImage";
			this->leftImage->Size = System::Drawing::Size(460, 354);
			this->leftImage->TabIndex = 0;
			this->leftImage->TabStop = false;
			// 
			// rightImage
			// 
			this->rightImage->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rightImage->Location = System::Drawing::Point(474, 27);
			this->rightImage->Name = L"rightImage";
			this->rightImage->Size = System::Drawing::Size(460, 354);
			this->rightImage->TabIndex = 1;
			this->rightImage->TabStop = false;
			// 
			// selectLeft
			// 
			this->selectLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->selectLeft->Location = System::Drawing::Point(8, 436);
			this->selectLeft->Name = L"selectLeft";
			this->selectLeft->Size = System::Drawing::Size(197, 41);
			this->selectLeft->TabIndex = 2;
			this->selectLeft->Text = L"Choose Left";
			this->selectLeft->UseVisualStyleBackColor = true;
			this->selectLeft->Click += gcnew System::EventHandler(this, &container::selectLeft_Click);
			// 
			// selectRight
			// 
			this->selectRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->selectRight->Location = System::Drawing::Point(474, 436);
			this->selectRight->Name = L"selectRight";
			this->selectRight->Size = System::Drawing::Size(197, 41);
			this->selectRight->TabIndex = 3;
			this->selectRight->Text = L"Chooose Right";
			this->selectRight->UseVisualStyleBackColor = true;
			this->selectRight->Click += gcnew System::EventHandler(this, &container::selectRight_Click);
			// 
			// rightCurrentScore
			// 
			this->rightCurrentScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->rightCurrentScore->AutoSize = true;
			this->rightCurrentScore->Location = System::Drawing::Point(471, 391);
			this->rightCurrentScore->Name = L"rightCurrentScore";
			this->rightCurrentScore->Size = System::Drawing::Size(78, 13);
			this->rightCurrentScore->TabIndex = 4;
			this->rightCurrentScore->Text = L"Current Score: ";
			// 
			// leftCurrentScore
			// 
			this->leftCurrentScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->leftCurrentScore->AutoSize = true;
			this->leftCurrentScore->Location = System::Drawing::Point(5, 391);
			this->leftCurrentScore->Name = L"leftCurrentScore";
			this->leftCurrentScore->Size = System::Drawing::Size(78, 13);
			this->leftCurrentScore->TabIndex = 5;
			this->leftCurrentScore->Text = L"Current Score: ";
			// 
			// refresh
			// 
			this->refresh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->refresh->Location = System::Drawing::Point(950, 68);
			this->refresh->Name = L"refresh";
			this->refresh->Size = System::Drawing::Size(80, 32);
			this->refresh->TabIndex = 6;
			this->refresh->Text = L"Refresh";
			this->refresh->UseVisualStyleBackColor = true;
			this->refresh->Click += gcnew System::EventHandler(this, &container::refresh_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fieToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1269, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fieToolStripMenuItem
			// 
			this->fieToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->optionsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fieToolStripMenuItem->Name = L"fieToolStripMenuItem";
			this->fieToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fieToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newDirectoryToolStripMenuItem,
					this->existingDirectoryToolStripMenuItem
			});
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// newDirectoryToolStripMenuItem
			// 
			this->newDirectoryToolStripMenuItem->Name = L"newDirectoryToolStripMenuItem";
			this->newDirectoryToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->newDirectoryToolStripMenuItem->Text = L"New Directory";
			this->newDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::newDirectoryToolStripMenuItem_Click);
			// 
			// existingDirectoryToolStripMenuItem
			// 
			this->existingDirectoryToolStripMenuItem->Name = L"existingDirectoryToolStripMenuItem";
			this->existingDirectoryToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->existingDirectoryToolStripMenuItem->Text = L"Existing Directory";
			this->existingDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::existingDirectoryToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::saveToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->websiteToolStripMenuItem,
					this->fAQToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// websiteToolStripMenuItem
			// 
			this->websiteToolStripMenuItem->Name = L"websiteToolStripMenuItem";
			this->websiteToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->websiteToolStripMenuItem->Text = L"Website";
			this->websiteToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::websiteToolStripMenuItem_Click);
			// 
			// fAQToolStripMenuItem
			// 
			this->fAQToolStripMenuItem->Name = L"fAQToolStripMenuItem";
			this->fAQToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->fAQToolStripMenuItem->Text = L"FAQ";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(1045, 28);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(223, 160);
			this->listBox1->TabIndex = 11;
			// 
			// listBox2
			// 
			this->listBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(1045, 221);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(223, 160);
			this->listBox2->TabIndex = 12;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button4->Location = System::Drawing::Point(474, 483);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(197, 35);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Previous Comparison";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &container::button4_Click);
			// 
			// saveAndQuit
			// 
			this->saveAndQuit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->saveAndQuit->Location = System::Drawing::Point(8, 483);
			this->saveAndQuit->Name = L"saveAndQuit";
			this->saveAndQuit->Size = System::Drawing::Size(197, 35);
			this->saveAndQuit->TabIndex = 14;
			this->saveAndQuit->Text = L"Save and Exit";
			this->saveAndQuit->UseVisualStyleBackColor = true;
			this->saveAndQuit->Click += gcnew System::EventHandler(this, &container::saveAndQuit_Click);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1045, 194);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Top Pictures ^";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1192, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Bottom Pics v";
			// 
			// deleteItem
			// 
			this->deleteItem->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->deleteItem->Location = System::Drawing::Point(1128, 387);
			this->deleteItem->Name = L"deleteItem";
			this->deleteItem->Size = System::Drawing::Size(71, 32);
			this->deleteItem->TabIndex = 17;
			this->deleteItem->Text = L"Delete";
			this->deleteItem->UseVisualStyleBackColor = true;
			this->deleteItem->Click += gcnew System::EventHandler(this, &container::deleteItem_Click);
			// 
			// saveFile
			// 
			this->saveFile->DefaultExt = L"csv";
			this->saveFile->InitialDirectory = L"./save";
			this->saveFile->RestoreDirectory = true;
			// 
			// container
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1269, 541);
			this->Controls->Add(this->deleteItem);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->saveAndQuit);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->refresh);
			this->Controls->Add(this->leftCurrentScore);
			this->Controls->Add(this->rightCurrentScore);
			this->Controls->Add(this->selectRight);
			this->Controls->Add(this->selectLeft);
			this->Controls->Add(this->rightImage);
			this->Controls->Add(this->leftImage);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"container";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Picture Sorting";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->leftImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rightImage))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	exit(EXIT_SUCCESS);
}
private: System::Void refresh_Click(System::Object^  sender, System::EventArgs^  e) {
	tempSort(&picList);
	updateRankings();
}

void updateRankings()
{
	this->listBox1->Items->Clear();
	this->listBox2->Items->Clear();
	for (int i = 0; i < picList.size(); i++)
	{
		std::string holder = picList[i].path + " ";
		holder += picList[i].score;
		gcnew String(holder.c_str());
		listBox1->Items->Add(gcnew String(holder.c_str()));
	}
	for (int i = picList.size()-1; i >= 0; i--)
	{
		std::string holder = picList[i].path + " ";
		holder += picList[i].score;
		gcnew String(holder.c_str());
		listBox2->Items->Add(gcnew String(holder.c_str()));
	}
}

private: System::Void deleteItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void newDirectoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::DialogResult result = openNewDirectory->ShowDialog();
	System::String^ folderName;
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		folderName = openNewDirectory->SelectedPath;
		folderName = (*folderName).Concat(folderName,"\\");
		pin_ptr<const wchar_t>  str1 = PtrToStringChars(folderName);
		picList = getFiles(str1);
		updateRankings();
	}
}

bool checkIfImage(string holder)
{
	bool flag = true;


	return flag;
}

vector<image> getFiles(const wchar_t* directory)
{
	vector<image> list;
	char dir[999];
	std::wcstombs(dir, directory, 999);
	std::string sDirectory = dir;
	DIR *dpdf;
	struct dirent *epdf;
	dpdf = opendir(dir);
	if (dpdf != NULL){
		while ((epdf = readdir(dpdf)) != NULL){
			if (showHiddenDirs ? (epdf->d_type == DT_DIR && string(epdf->d_name) != ".." && string(epdf->d_name) != ".") : (epdf->d_type == DT_DIR && strstr(epdf->d_name, "..") == NULL && strstr(epdf->d_name, ".") == NULL)){
				GetReqDirs(sDirectory + epdf->d_name + "/", files, showHiddenDirs);
			}
			if (epdf->d_type == DT_REG){
				list.push_back({ sDirectory + epdf->d_name, 0 });
			}
		}
	}
	closedir(dpdf);
	return list;
}


void saveUserFile()
{
	if (openedFlag)
	{
		StreamWriter^ writer = gcnew StreamWriter(fileName);
		for (int i = 0; i < picList.size(); i++)
		{
			writer->WriteLine("{0},{1}", (gcnew String(picList[i].path.c_str())), picList[i].score);
		}
	}
	else
	{
		saveFile->ShowDialog();
		if (saveFile->FileName != "")
		{
			fileName = saveFile->FileName;
			StreamWriter^ writer = gcnew StreamWriter(fileName);
			for (int i = 0; i < picList.size(); i++)
			{
				writer->WriteLine("{0},{1}", (gcnew String(picList[i].path.c_str())), picList[i].score);
			}
		}
	}
}
private: System::Void saveAndQuit_Click(System::Object^  sender, System::EventArgs^  e) {
	saveUserFile();
	exit(EXIT_SUCCESS);
}
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	saveUserFile();
}

private: System::Void existingDirectoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

}

private: System::Void selectLeft_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList[index[crntCpr][0]].score > picList[index[crntCpr][1]].score)
		picList[index[crntCpr][0]].score++;
	else
		picList[index[crntCpr][0]].score = picList[index[crntCpr][1]].score++;

	changeComparison(1);
}
private: System::Void selectRight_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList[index[crntCpr][0]].score < picList[index[crntCpr][1]].score)
		picList[index[crntCpr][1]].score++;
	else
		picList[index[crntCpr][1]].score = picList[index[crntCpr][0]].score++;

	changeComparison(1);
}

void changeComparison(int increment){
	crntCpr+=increment;
	if (index.size() < crntCpr + 1)
		for(int i = 0; i < picList.size(); i++)
		{
			index[i][0] = rand() % picList.size();
			index[i][1] = rand() % picList.size();
		}
	String^ str1 = gcnew String(picList[index[crntCpr][0]].path.c_str());
	String^ str2 = gcnew String(picList[index[crntCpr][1]].path.c_str());
	leftImage->Load(str1);
	rightImage->Load(str2);
	rightCurrentScore->Text = "Score: " + picList[index[crntCpr][1]].score;
	leftCurrentScore->Text ="Score: " + (picList[index[crntCpr][0]].score);

}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	changeComparison(-1);
}


private: System::Void websiteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ShellExecute(0, 0, L"https://github.com/xMausoleuMx/Picture-Sorting", 0, 0, SW_SHOW);
}
};
}


