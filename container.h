#include "Work.cpp"
#include <vcclr.h>

#using <System.dll>

static vector<image> picList;
static vector<std::pair<int,int>> index;
static std::string currentDirectory;
#pragma once
namespace PictureSorting {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;

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

	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  deleteItem;
	private: System::Windows::Forms::FolderBrowserDialog^  openNewDirectory;
	private: System::Windows::Forms::SaveFileDialog^  saveFile;
	private: System::Windows::Forms::OpenFileDialog^  openExistingSave;
	private: System::Windows::Forms::Button^  trimCollection;

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
			this->deleteItem = (gcnew System::Windows::Forms::Button());
			this->openNewDirectory = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->saveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openExistingSave = (gcnew System::Windows::Forms::OpenFileDialog());
			this->trimCollection = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->leftImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rightImage))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// leftImage
			// 
			this->leftImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->leftImage->BackColor = System::Drawing::SystemColors::ControlDark;
			this->leftImage->Location = System::Drawing::Point(8, 27);
			this->leftImage->Name = L"leftImage";
			this->leftImage->Size = System::Drawing::Size(460, 354);
			this->leftImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->leftImage->TabIndex = 0;
			this->leftImage->TabStop = false;
			this->leftImage->Click += gcnew System::EventHandler(this, &container::leftImage_Click);
			// 
			// rightImage
			// 
			this->rightImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->rightImage->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rightImage->Location = System::Drawing::Point(804, 27);
			this->rightImage->Name = L"rightImage";
			this->rightImage->Size = System::Drawing::Size(460, 354);
			this->rightImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->rightImage->TabIndex = 1;
			this->rightImage->TabStop = false;
			this->rightImage->Click += gcnew System::EventHandler(this, &container::rightImage_Click);
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
			this->selectRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->selectRight->Location = System::Drawing::Point(1067, 436);
			this->selectRight->Name = L"selectRight";
			this->selectRight->Size = System::Drawing::Size(197, 41);
			this->selectRight->TabIndex = 3;
			this->selectRight->Text = L"Chooose Right";
			this->selectRight->UseVisualStyleBackColor = true;
			this->selectRight->Click += gcnew System::EventHandler(this, &container::selectRight_Click);
			// 
			// rightCurrentScore
			// 
			this->rightCurrentScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->rightCurrentScore->AutoSize = true;
			this->rightCurrentScore->Location = System::Drawing::Point(801, 391);
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
			this->refresh->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->refresh->Location = System::Drawing::Point(594, 387);
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
			this->listBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(474, 27);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(324, 160);
			this->listBox1->TabIndex = 11;
			// 
			// listBox2
			// 
			this->listBox2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(474, 221);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(324, 160);
			this->listBox2->TabIndex = 12;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Location = System::Drawing::Point(1067, 483);
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
			// deleteItem
			// 
			this->deleteItem->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->deleteItem->Location = System::Drawing::Point(554, 436);
			this->deleteItem->Name = L"deleteItem";
			this->deleteItem->Size = System::Drawing::Size(154, 41);
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
			// openExistingSave
			// 
			this->openExistingSave->DefaultExt = L"csv";
			this->openExistingSave->FileName = L"openExistingSave";
			// 
			// trimCollection
			// 
			this->trimCollection->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->trimCollection->Location = System::Drawing::Point(554, 483);
			this->trimCollection->Name = L"trimCollection";
			this->trimCollection->Size = System::Drawing::Size(154, 35);
			this->trimCollection->TabIndex = 18;
			this->trimCollection->Text = L"Trim Collection";
			this->trimCollection->UseVisualStyleBackColor = true;
			// 
			// container
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1269, 541);
			this->Controls->Add(this->trimCollection);
			this->Controls->Add(this->deleteItem);
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

//Close the program without saving.
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	exit(EXIT_SUCCESS);
}

private: System::Void refresh_Click(System::Object^  sender, System::EventArgs^  e) {
	updateRankings();
}

void updateRankings()
{
	tempSort(&picList);
	this->listBox1->Items->Clear();
	this->listBox2->Items->Clear();
	for (int i = 0; i < picList.size(); i++)
	{
		std::ostringstream convert;
		convert << picList[i].score;
		std::string holder = convert.str() + " ";
		for (int y = currentDirectory.size(); y < picList[i].path.size(); y++)
			holder += picList[i].path[y];
		listBox1->Items->Add(gcnew String(holder.c_str()));
	}
	for (int i = picList.size()-1; i >= 0; i--)
	{
		std::ostringstream convert;
		convert << picList[i].score;
		std::string holder = convert.str() + " ";
		for (int y = currentDirectory.size(); y < picList[i].path.size(); y++)
			holder += picList[i].path[y];
		listBox2->Items->Add(gcnew String(holder.c_str()));
	}
}

private: System::Void deleteItem_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void newDirectoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	openedFlag = false;
	System::Windows::Forms::DialogResult result = openNewDirectory->ShowDialog();
	System::String^ folderName;
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		folderName = openNewDirectory->SelectedPath;
		folderName = (*folderName).Concat(folderName,"\\");
		picList = getFiles(folderName);
		updateRankings();
		changeComparison(0);
	}
	else
		MessageBox::Show("ERROR: Inavlid Choice.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	msclr::interop::marshal_context context;
	currentDirectory = context.marshal_as<std::string>(folderName);
}

void saveUserFile()
{
	if (openedFlag)
	{
		StreamWriter^ writer = gcnew StreamWriter(fileName);
		for (int i = 0; i < picList.size(); i++)
			writer->WriteLine("{0},{1}", (gcnew String(picList[i].path.c_str())), picList[i].score);
	}
	else
	{
		saveFile->ShowDialog();
		if (saveFile->FileName != "")
		{
			fileName = saveFile->FileName;
			StreamWriter^ writer = gcnew StreamWriter(fileName);
			for (int i = 0; i < picList.size(); i++)
				writer->WriteLine("{0},{1}", (gcnew String(picList[i].path.c_str())), picList[i].score);
			writer->Close();
		}
	}
}
private: System::Void saveAndQuit_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size() > 0)
		saveUserFile();
	exit(EXIT_SUCCESS);
}
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if(picList.size() > 0)
		saveUserFile();
	else
		MessageBox::Show("ERROR: There is no currently loaded comparison directory to save.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}

//open previously saved directory comparison
private: System::Void existingDirectoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openExistingSave->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamReader^ reader = gcnew StreamReader(openExistingSave->FileName);
		fileName = openExistingSave->FileName;
		msclr::interop::marshal_context context;
		std::string holder,score = "";
		bool flag = false, invalidFlag = false, errorFlag=false;
		while(reader->Peek()>=0)
		{
			holder = context.marshal_as<std::string>(reader->ReadLine());
			image temp;
			for (int i = 0; i < holder.size(); i++)
			{
				if (flag)
					score += holder[i];
				if(holder[i] == ',')
					flag = true;
				if (!flag && holder[i] != ',')
					temp.path += holder[i];
			}
			flag = false;
			temp.score = atoi(score.c_str());
			score = "";
			if (validateFile(temp.path))
				picList.push_back(temp);
			else
				invalidFlag = true;
		}
		if (picList.size() == 0){
			MessageBox::Show("ERROR: No files could be laoded from this save\nFile may be empty or corrupted", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			errorFlag = true;
		}
		if (invalidFlag)
			MessageBox::Show("ERROR: Some of the images could not be loaded. They were either moved or are no longer valid", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		(*reader).Close();
		if (!errorFlag){
			currentDirectory = getDirectory(picList);
			changeComparison(0);
			openedFlag = true;
		}
	}
	else{
		MessageBox::Show("ERROR: Failed to load file","Error Message", MessageBoxButtons::OKCancel,MessageBoxIcon::Asterisk);
	}
}

private: System::Void selectLeft_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0){
		if (picList[get<0>(index[crntCpr])].score > picList[get<1>(index[crntCpr])].score)
			picList[get<0>(index[crntCpr])].score++;

		else
			picList[get<0>(index[crntCpr])].score = picList[get<1>(index[crntCpr])].score + 1;

		changeComparison(1);
	}
	else
		MessageBox::Show("ERROR: You cannot use this button when no pictures are loaded.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}
private: System::Void selectRight_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0){
		if (picList[get<0>(index[crntCpr])].score < picList[get<1>(index[crntCpr])].score)
			picList[get<1>(index[crntCpr])].score++;
		else
			picList[get<1>(index[crntCpr])].score = picList[get<0>(index[crntCpr])].score + 1;

		changeComparison(1);
	}
	else
		MessageBox::Show("ERROR: You cannot use this button when no pictures are loaded.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}

//generate the list of image pairs for the user to compare.
void genComparisons(){
	for (int i = 0; i < picList.size(); i++)
	{
		unsigned int a = rand() % picList.size(), b = rand() % picList.size();
		bool flag = false;
		while ((a == b) || !flag )
		{
			for (int i = 0; i < index.size(); i++)
				if (!((get<0>(index[i]) == a || get<0>(index[i]) == b) && (get<1>(index[i]) == a || get<1>(index[i]) == b)))
					flag = true;
			if (index.size() == 0)
				flag = true;
			a = rand() % picList.size();
			b = rand() % picList.size();
		}
		std::pair<int, int> temp(a, b);
		index.push_back(temp);
	}
 }

//Change the comparison of the two images. Negative numbers to go back one.
void changeComparison(int increment){
	crntCpr+=increment;
	if (index.size() < crntCpr + 1)
		genComparisons();
	leftImage->Load(gcnew String(picList[get<0>(index[crntCpr])].path.c_str()));
	rightImage->Load(gcnew String(picList[get<1>(index[crntCpr])].path.c_str()));
	rightCurrentScore->Text = "Score: " + picList[get<1>(index[crntCpr])].score;
	leftCurrentScore->Text = "Score: " + (picList[get<0>(index[crntCpr])].score);
	updateRankings();

}

//Go back to the previous comparison
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	if(picList.size() > 0 && crntCpr > 0)
		changeComparison(-1);
	else
		MessageBox::Show("ERROR: There are no previous comparisons.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}

//open the github page for this program.
private: System::Void websiteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ShellExecute(0, 0, L"https://github.com/xMausoleuMx/Picture-Sorting", 0, 0, SW_SHOW);
}

//Open the left image in the default image viewing program
private: System::Void leftImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if(picList.size()>0)
		Process::Start(gcnew String(picList[get<0>(index[crntCpr])].path.c_str()));
}

//Open the right image in the default image viewing program
private: System::Void rightImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0)
		Process::Start(gcnew String(picList[get<1>(index[crntCpr])].path.c_str()));
}

};
}


