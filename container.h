#include "Work.cpp"

static vector<image> picList;

#pragma once
namespace PictureSorting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  selectRight;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
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
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  deleteItem;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->selectRight = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->deleteItem = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Location = System::Drawing::Point(8, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(460, 354);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &container::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox2->Location = System::Drawing::Point(474, 27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(460, 354);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &container::pictureBox2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 436);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(197, 41);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Choose Left";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// selectRight
			// 
			this->selectRight->Location = System::Drawing::Point(474, 436);
			this->selectRight->Name = L"selectRight";
			this->selectRight->Size = System::Drawing::Size(197, 41);
			this->selectRight->TabIndex = 3;
			this->selectRight->Text = L"Chooose Right";
			this->selectRight->UseVisualStyleBackColor = true;
			this->selectRight->Click += gcnew System::EventHandler(this, &container::selectRight_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(471, 391);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Current Score: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 391);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Current Score: ";
			// 
			// refresh
			// 
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
			this->fieToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::fieToolStripMenuItem_Click);
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
			// 
			// existingDirectoryToolStripMenuItem
			// 
			this->existingDirectoryToolStripMenuItem->Name = L"existingDirectoryToolStripMenuItem";
			this->existingDirectoryToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->existingDirectoryToolStripMenuItem->Text = L"Existing Directory";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->saveToolStripMenuItem->Text = L"Save";
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
			// 
			// fAQToolStripMenuItem
			// 
			this->fAQToolStripMenuItem->Name = L"fAQToolStripMenuItem";
			this->fAQToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->fAQToolStripMenuItem->Text = L"FAQ";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(1045, 28);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(223, 160);
			this->listBox1->TabIndex = 11;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &container::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(1045, 221);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(223, 160);
			this->listBox2->TabIndex = 12;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(474, 483);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(197, 35);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Previous Comparison";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(8, 483);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(197, 35);
			this->button6->TabIndex = 14;
			this->button6->Text = L"Save and Exit";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1045, 194);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Top Pictures ^";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1192, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Bottom Pics v";
			// 
			// deleteItem
			// 
			this->deleteItem->Location = System::Drawing::Point(1128, 387);
			this->deleteItem->Name = L"deleteItem";
			this->deleteItem->Size = System::Drawing::Size(71, 32);
			this->deleteItem->TabIndex = 17;
			this->deleteItem->Text = L"Delete";
			this->deleteItem->UseVisualStyleBackColor = true;
			this->deleteItem->Click += gcnew System::EventHandler(this, &container::deleteItem_Click);
			// 
			// container
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1269, 541);
			this->Controls->Add(this->deleteItem);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->refresh);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selectRight);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"container";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Picture Sorting";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &container::container_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void container_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void fieToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	exit(EXIT_SUCCESS);
}
private: System::Void refresh_Click(System::Object^  sender, System::EventArgs^  e) {
	tempSort(&picList);
	updateRankings();
}
private: System::Void selectRight_Click(System::Object^  sender, System::EventArgs^  e) {
}

void updateRankings()
{
	this->listBox1->Items->Clear();
	for (int i = 0; i < picList.size(); i++)
	{
		std::string holder = picList[i].path + " ";
		holder += picList[i].score;
		gcnew String(holder.c_str());
		listBox1->Items->Add(gcnew String(holder.c_str()));
	}
	for (int i = picList.size(); i >0; i--)
	{
		std::string holder = picList[i].path + " ";
		holder += picList[i].score;
		gcnew String(holder.c_str());
		listBox2->Items->Add(gcnew String(holder.c_str()));
	}
}

private: System::Void deleteItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
};

}

