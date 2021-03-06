#include "trimCollection.h"
#using <System.dll>

static vector<image> picList;
static vector<vector<image>> strictSortList;
static vector<std::pair<int,int>> index;
static std::string currentDirectory;
static vector<setting> settings;
static vector<int>shorcuts{112,115, 65, 68, 83};
#define leftString()(gcnew String(picList[get<0>(index[crntCpr])].path.c_str()))
#define rightString()(gcnew String(picList[get<1>(index[crntCpr])].path.c_str()))
#define updateContinuously()(settings[0].flag)
#define sortByScore()(settings[2].flag)
#define sortByRating()(settings[3].flag)

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
			loadSettings();
		}

	protected:
		/* <summary>
		Sorts pictures in a head to head fashion with user input and then ranks them accordingly.
		</summary>*/
		~container()
		{
			if (components)
			{
				delete components;
			}
		}
	private:bool openedFlag = false, saveDifference = false, strictSort = false;
	private: System::String^ fileName;
	private: int crntCpr = 0;
	private: int strictSortindex = 0, strictSortLeftIndex = 0, strictSortRightIndex = 0;
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

	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  websiteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fAQToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  newDirectoryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  existingDirectoryToolStripMenuItem;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  saveAndQuit;

	private: System::Windows::Forms::ListBox^  topImages;

	private: System::Windows::Forms::FolderBrowserDialog^  openNewDirectory;
	private: System::Windows::Forms::SaveFileDialog^  saveFile;
	private: System::Windows::Forms::OpenFileDialog^  openExistingSave;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  leftPath;
	private: System::Windows::Forms::ToolStripStatusLabel^  rightPath;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::Label^  leftNumComparisons;
	private: System::Windows::Forms::Label^  leftRating;
	private: System::Windows::Forms::Label^  rightNumComparisons;
	private: System::Windows::Forms::Label^  rightRating;




	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolStripMenuItem^  editOptions;
	private: System::Windows::Forms::Button^  trimCollection;
	private: System::Windows::Forms::ToolStripMenuItem^  addItemsToolStripMenuItem;
	private: System::Windows::Forms::Label^  lowestComparisonLabel;

	private: System::Windows::Forms::Label^  totalImagesLabel;
	private: System::Windows::Forms::Label^  averageComparisonsLabel;
	private: System::Windows::Forms::Label^  totalComparisonsLabel;
	private: System::Windows::Forms::ToolStripMenuItem^  enablePerfectSortToolStripMenuItem;






	private: System::ComponentModel::IContainer^  components;

	protected:

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
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addItemsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editOptions = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->websiteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fAQToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->topImages = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->saveAndQuit = (gcnew System::Windows::Forms::Button());
			this->openNewDirectory = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->saveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openExistingSave = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->averageComparisonsLabel = (gcnew System::Windows::Forms::Label());
			this->totalComparisonsLabel = (gcnew System::Windows::Forms::Label());
			this->lowestComparisonLabel = (gcnew System::Windows::Forms::Label());
			this->totalImagesLabel = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->leftPath = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->rightPath = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->leftNumComparisons = (gcnew System::Windows::Forms::Label());
			this->leftRating = (gcnew System::Windows::Forms::Label());
			this->rightNumComparisons = (gcnew System::Windows::Forms::Label());
			this->rightRating = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->trimCollection = (gcnew System::Windows::Forms::Button());
			this->enablePerfectSortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->leftImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rightImage))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// leftImage
			// 
			this->leftImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->leftImage->BackColor = System::Drawing::SystemColors::ControlDark;
			this->leftImage->Location = System::Drawing::Point(8, 27);
			this->leftImage->Name = L"leftImage";
			this->leftImage->Size = System::Drawing::Size(460, 362);
			this->leftImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->leftImage->TabIndex = 0;
			this->leftImage->TabStop = false;
			this->toolTip1->SetToolTip(this->leftImage, L"Click to open image in default image viewing software");
			this->leftImage->Click += gcnew System::EventHandler(this, &container::leftImage_Click);
			this->leftImage->MouseEnter += gcnew System::EventHandler(this, &container::leftImage_MouseEnter);
			this->leftImage->MouseLeave += gcnew System::EventHandler(this, &container::leftImage_MouseLeave);
			// 
			// rightImage
			// 
			this->rightImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->rightImage->BackColor = System::Drawing::SystemColors::ControlDark;
			this->rightImage->Location = System::Drawing::Point(804, 27);
			this->rightImage->Name = L"rightImage";
			this->rightImage->Size = System::Drawing::Size(460, 362);
			this->rightImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->rightImage->TabIndex = 1;
			this->rightImage->TabStop = false;
			this->toolTip1->SetToolTip(this->rightImage, L"Click to open image in default image viewing software");
			this->rightImage->Click += gcnew System::EventHandler(this, &container::rightImage_Click);
			this->rightImage->MouseEnter += gcnew System::EventHandler(this, &container::rightImage_MouseEnter);
			this->rightImage->MouseLeave += gcnew System::EventHandler(this, &container::rightImage_MouseLeave);
			// 
			// selectLeft
			// 
			this->selectLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->selectLeft->Location = System::Drawing::Point(8, 444);
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
			this->selectRight->Location = System::Drawing::Point(1067, 444);
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
			this->rightCurrentScore->Location = System::Drawing::Point(801, 399);
			this->rightCurrentScore->Name = L"rightCurrentScore";
			this->rightCurrentScore->Size = System::Drawing::Size(78, 13);
			this->rightCurrentScore->TabIndex = 4;
			this->rightCurrentScore->Text = L"Current Score: ";
			this->toolTip1->SetToolTip(this->rightCurrentScore, L"Score of the above image");
			// 
			// leftCurrentScore
			// 
			this->leftCurrentScore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->leftCurrentScore->AutoSize = true;
			this->leftCurrentScore->Location = System::Drawing::Point(5, 399);
			this->leftCurrentScore->Name = L"leftCurrentScore";
			this->leftCurrentScore->Size = System::Drawing::Size(78, 13);
			this->leftCurrentScore->TabIndex = 5;
			this->leftCurrentScore->Text = L"Current Score: ";
			this->toolTip1->SetToolTip(this->leftCurrentScore, L"Score of the above image");
			// 
			// refresh
			// 
			this->refresh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->refresh->Location = System::Drawing::Point(594, 395);
			this->refresh->Name = L"refresh";
			this->refresh->Size = System::Drawing::Size(80, 32);
			this->refresh->TabIndex = 6;
			this->refresh->Text = L"Refresh";
			this->toolTip1->SetToolTip(this->refresh, L"Refreshes the top and bottom lists");
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
			this->fieToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->exitToolStripMenuItem
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
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// newDirectoryToolStripMenuItem
			// 
			this->newDirectoryToolStripMenuItem->Name = L"newDirectoryToolStripMenuItem";
			this->newDirectoryToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->newDirectoryToolStripMenuItem->Text = L"New Directory";
			this->newDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::newDirectoryToolStripMenuItem_Click);
			// 
			// existingDirectoryToolStripMenuItem
			// 
			this->existingDirectoryToolStripMenuItem->Name = L"existingDirectoryToolStripMenuItem";
			this->existingDirectoryToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->existingDirectoryToolStripMenuItem->Text = L"Existing Collection";
			this->existingDirectoryToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::existingDirectoryToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addItemsToolStripMenuItem,
					this->editOptions, this->enablePerfectSortToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// addItemsToolStripMenuItem
			// 
			this->addItemsToolStripMenuItem->Name = L"addItemsToolStripMenuItem";
			this->addItemsToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->addItemsToolStripMenuItem->Text = L"Add Items to Collection";
			this->addItemsToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::addItemsToolStripMenuItem_Click);
			// 
			// editOptions
			// 
			this->editOptions->Name = L"editOptions";
			this->editOptions->Size = System::Drawing::Size(199, 22);
			this->editOptions->Text = L"Options";
			this->editOptions->Click += gcnew System::EventHandler(this, &container::editOptions_Click);
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
			this->fAQToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::fAQToolStripMenuItem_Click);
			// 
			// topImages
			// 
			this->topImages->FormattingEnabled = true;
			this->topImages->Location = System::Drawing::Point(0, 0);
			this->topImages->Name = L"topImages";
			this->topImages->Size = System::Drawing::Size(324, 316);
			this->topImages->TabIndex = 11;
			this->toolTip1->SetToolTip(this->topImages, L"double click on an item to open it externally");
			this->topImages->DoubleClick += gcnew System::EventHandler(this, &container::topImages_DoubleClick);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Location = System::Drawing::Point(1067, 491);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(197, 35);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Previous Comparison";
			this->toolTip1->SetToolTip(this->button4, L"Goes back to the previous comparison but does not revert the choice made.");
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &container::button4_Click);
			// 
			// saveAndQuit
			// 
			this->saveAndQuit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->saveAndQuit->Location = System::Drawing::Point(8, 491);
			this->saveAndQuit->Name = L"saveAndQuit";
			this->saveAndQuit->Size = System::Drawing::Size(197, 35);
			this->saveAndQuit->TabIndex = 14;
			this->saveAndQuit->Text = L"Save and Exit";
			this->saveAndQuit->UseVisualStyleBackColor = true;
			this->saveAndQuit->Click += gcnew System::EventHandler(this, &container::saveAndQuit_Click);
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
			this->openExistingSave->Filter = L"CSV (*.csv)|*.csv|All files (*.*)|*.*";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->groupBox1->Controls->Add(this->averageComparisonsLabel);
			this->groupBox1->Controls->Add(this->totalComparisonsLabel);
			this->groupBox1->Controls->Add(this->lowestComparisonLabel);
			this->groupBox1->Controls->Add(this->totalImagesLabel);
			this->groupBox1->Controls->Add(this->topImages);
			this->groupBox1->Location = System::Drawing::Point(474, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(324, 362);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			// 
			// averageComparisonsLabel
			// 
			this->averageComparisonsLabel->AutoSize = true;
			this->averageComparisonsLabel->Location = System::Drawing::Point(163, 344);
			this->averageComparisonsLabel->Name = L"averageComparisonsLabel";
			this->averageComparisonsLabel->Size = System::Drawing::Size(116, 13);
			this->averageComparisonsLabel->TabIndex = 16;
			this->averageComparisonsLabel->Text = L"Average Comparisons: ";
			this->toolTip1->SetToolTip(this->averageComparisonsLabel, L"How many times on average each picture has been compared.");
			// 
			// totalComparisonsLabel
			// 
			this->totalComparisonsLabel->AutoSize = true;
			this->totalComparisonsLabel->Location = System::Drawing::Point(163, 321);
			this->totalComparisonsLabel->Name = L"totalComparisonsLabel";
			this->totalComparisonsLabel->Size = System::Drawing::Size(97, 13);
			this->totalComparisonsLabel->TabIndex = 15;
			this->totalComparisonsLabel->Text = L"Total Comparisons:";
			this->toolTip1->SetToolTip(this->totalComparisonsLabel, L"Total number of comparisons done for this collection");
			// 
			// lowestComparisonLabel
			// 
			this->lowestComparisonLabel->AutoSize = true;
			this->lowestComparisonLabel->Location = System::Drawing::Point(5, 344);
			this->lowestComparisonLabel->Name = L"lowestComparisonLabel";
			this->lowestComparisonLabel->Size = System::Drawing::Size(107, 13);
			this->lowestComparisonLabel->TabIndex = 14;
			this->lowestComparisonLabel->Text = L"Lowest Comparisons:";
			this->toolTip1->SetToolTip(this->lowestComparisonLabel, L"Displays the number of times the image with the lowest number of comparisons has "
				L"been compared");
			// 
			// totalImagesLabel
			// 
			this->totalImagesLabel->AutoSize = true;
			this->totalImagesLabel->Location = System::Drawing::Point(5, 321);
			this->totalImagesLabel->Name = L"totalImagesLabel";
			this->totalImagesLabel->Size = System::Drawing::Size(71, 13);
			this->totalImagesLabel->TabIndex = 13;
			this->totalImagesLabel->Text = L"Total Images:";
			this->toolTip1->SetToolTip(this->totalImagesLabel, L"Number of images in the collection");
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripProgressBar1,
					this->leftPath, this->toolStripStatusLabel1, this->rightPath
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 527);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1269, 22);
			this->statusStrip1->TabIndex = 20;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->toolStripProgressBar1->Size = System::Drawing::Size(100, 16);
			// 
			// leftPath
			// 
			this->leftPath->Name = L"leftPath";
			this->leftPath->Size = System::Drawing::Size(24, 17);
			this->leftPath->Text = L"left";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(27, 17);
			this->toolStripStatusLabel1->Text = L"and";
			// 
			// rightPath
			// 
			this->rightPath->Name = L"rightPath";
			this->rightPath->Size = System::Drawing::Size(32, 17);
			this->rightPath->Text = L"right";
			// 
			// leftNumComparisons
			// 
			this->leftNumComparisons->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->leftNumComparisons->AutoSize = true;
			this->leftNumComparisons->Location = System::Drawing::Point(154, 399);
			this->leftNumComparisons->Name = L"leftNumComparisons";
			this->leftNumComparisons->Size = System::Drawing::Size(125, 13);
			this->leftNumComparisons->TabIndex = 21;
			this->leftNumComparisons->Text = L"Number of Comparisons: ";
			this->toolTip1->SetToolTip(this->leftNumComparisons, L"How many times this image has been compared to another");
			// 
			// leftRating
			// 
			this->leftRating->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->leftRating->AutoSize = true;
			this->leftRating->Location = System::Drawing::Point(383, 399);
			this->leftRating->Name = L"leftRating";
			this->leftRating->Size = System::Drawing::Size(41, 13);
			this->leftRating->TabIndex = 22;
			this->leftRating->Text = L"Rating:";
			this->toolTip1->SetToolTip(this->leftRating, L"Uses an algorithm that takes number of comparisons into account.");
			// 
			// rightNumComparisons
			// 
			this->rightNumComparisons->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->rightNumComparisons->AutoSize = true;
			this->rightNumComparisons->Location = System::Drawing::Point(972, 399);
			this->rightNumComparisons->Name = L"rightNumComparisons";
			this->rightNumComparisons->Size = System::Drawing::Size(125, 13);
			this->rightNumComparisons->TabIndex = 23;
			this->rightNumComparisons->Text = L"Number of Comparisons: ";
			this->toolTip1->SetToolTip(this->rightNumComparisons, L"How many times this image has been compared to another");
			// 
			// rightRating
			// 
			this->rightRating->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->rightRating->AutoSize = true;
			this->rightRating->Location = System::Drawing::Point(1187, 399);
			this->rightRating->Name = L"rightRating";
			this->rightRating->Size = System::Drawing::Size(41, 13);
			this->rightRating->TabIndex = 24;
			this->rightRating->Text = L"Rating:";
			this->toolTip1->SetToolTip(this->rightRating, L"Uses an algorithm that takes number of comparisons into account.");
			// 
			// trimCollection
			// 
			this->trimCollection->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->trimCollection->Location = System::Drawing::Point(594, 444);
			this->trimCollection->Name = L"trimCollection";
			this->trimCollection->Size = System::Drawing::Size(80, 41);
			this->trimCollection->TabIndex = 25;
			this->trimCollection->Text = L"Trim Collection";
			this->toolTip1->SetToolTip(this->trimCollection, L"Opens a new window to select a portion of your collection to move to a new folder"
				L"");
			this->trimCollection->UseVisualStyleBackColor = true;
			this->trimCollection->Click += gcnew System::EventHandler(this, &container::trimCollection_Click);
			// 
			// enablePerfectSortToolStripMenuItem
			// 
			this->enablePerfectSortToolStripMenuItem->Name = L"enablePerfectSortToolStripMenuItem";
			this->enablePerfectSortToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->enablePerfectSortToolStripMenuItem->Text = L"Enable Perfect Sort";
			this->enablePerfectSortToolStripMenuItem->Click += gcnew System::EventHandler(this, &container::enablePerfectSortToolStripMenuItem_Click);
			// 
			// container
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1269, 549);
			this->Controls->Add(this->trimCollection);
			this->Controls->Add(this->rightRating);
			this->Controls->Add(this->rightNumComparisons);
			this->Controls->Add(this->leftRating);
			this->Controls->Add(this->leftNumComparisons);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->saveAndQuit);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->refresh);
			this->Controls->Add(this->leftCurrentScore);
			this->Controls->Add(this->rightCurrentScore);
			this->Controls->Add(this->selectRight);
			this->Controls->Add(this->selectLeft);
			this->Controls->Add(this->rightImage);
			this->Controls->Add(this->leftImage);
			this->Controls->Add(this->menuStrip1);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"container";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Picture Sorting";
			this->Load += gcnew System::EventHandler(this, &container::container_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &container::container_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->leftImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rightImage))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//load the users settings from a file.
void loadSettings(){
	if (validateFile("config.ini")){ //checks to make sure there is an ini file to read from
		StreamReader^ reader = gcnew StreamReader("config.ini");
		string holder, flagTemp = "", nameTemp = "";
		int y = 0;
		bool flag = false, defaultCollection = false;
		while (reader->Peek() >= 0)
		{
			setting k;
			holder = Stringtostring(reader->ReadLine());
			for (int i = 0; i < holder.size(); i++){
				if (flag)
					flagTemp += holder[i];
				if (holder[i] == '='){
					flag = true;
					i++;
				}
				if (!flag && holder[i] != ' ')
					nameTemp += holder[i];
			}
			k.name = nameTemp;
			if (!flagTemp.compare("false"))
				k.flag = false;
			else
				k.flag = true;
			
			flag = false;
			if (y == 1 && flagTemp.compare("false")){
				defaultCollection = true;
				k.path = flagTemp;
			}
			settings.push_back(k);
			y++;
			nameTemp = "";
			flagTemp = "";
		}
		if (defaultCollection)//if the setting for the openSpecificDirectory is not "false" assume that it is a path to a savefile and open it.
			openFile(gcnew String(settings[1].path.c_str()));
		reader->Close();
	}
	else{//if there is no ini file generate a new one with default values
		MessageBox::Show("ERROR: No configuration file could be found.\nGenerating one with default values", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		StreamWriter^ writer = gcnew StreamWriter("config.ini");
		writer->WriteLine("continuouslyUpdate = false");
		writer->WriteLine("openSpecificDirectory = false");
		writer->WriteLine("sortByScore = true");
		writer->WriteLine("sortByRating = false");
		writer->Close();
		setting temp;
		temp.name = "continuouslyUpdate";
		temp.flag = false;
		settings.push_back(temp);
		temp.name = "openSpecificDirectory";
		temp.flag = false;
		settings.push_back(temp);
		temp.name = "sortByScore";
		temp.flag = true;
		settings.push_back(temp);
		temp.name = "sortByRating";
		temp.flag = false;
		settings.push_back(temp);
	}
}

//Close the program without saving.
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	quit();
}

//button to trigger the refresh of the top and bottom lists
private: System::Void refresh_Click(System::Object^  sender, System::EventArgs^  e) {
	updateRankings();
}

//updates the top and bottom lists with sorted scores.
void updateRankings(){
	if (strictSort) {
		totalComparisonsLabel->Text = "Aproximate Number of Comparisons to go: " + ((int)(picList.size()*log(picList.size())) - picList.size()*(picList.size() - strictSortList.size()));//replace later!!
		averageComparisonsLabel->Text = "Number of Blocks remaining: " + strictSortList.size();
	}
	else{
		int minComparisons = INT_MAX, totalComparisons = 0;
		float averageCompairisons = 0;
		vector<image> sortedList = picList;
		if (updateContinuously() && sortByScore())
			continuousScoreSort(&sortedList);
		else if (updateContinuously() && sortByRating())
			continuousRatingSort(&sortedList);
		else if (!updateContinuously() && sortByRating())
			ratingSort(&sortedList);
		else if (!updateContinuously() && sortByScore())
			scoreSort(&sortedList);
		this->topImages->Items->Clear();
		for (int i = 0; i < sortedList.size(); i++){//adding items to the top list
			std::string holder = std::to_string(sortedList[i].score) + " ";
			for (int y = currentDirectory.size(); y < sortedList[i].path.size(); y++)
				holder += sortedList[i].path[y];
			topImages->Items->Add(gcnew String(holder.c_str()));
			totalComparisons += sortedList[i].comparisons;
			if (sortedList[i].comparisons < minComparisons)
				minComparisons = sortedList[i].comparisons;
		}
		lowestComparisonLabel->Text = "Lowest Comparisons: " + minComparisons;
		totalComparisonsLabel->Text = "Total Comparisons: " + totalComparisons / 2;
		averageComparisonsLabel->Text = "Average Comparisons: " + totalComparisons / sortedList.size();
	}
	totalImagesLabel->Text = "Total Images: " + (int)(picList.size());
}

//open up a new directory of images
private: System::Void newDirectoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	openedFlag = false;
	System::Windows::Forms::DialogResult result = openNewDirectory->ShowDialog();
	System::String^ folderName;
	if (result == System::Windows::Forms::DialogResult::OK){
		index.clear();
		folderName = openNewDirectory->SelectedPath;
		folderName = (*folderName).Concat(folderName,"\\");
		picList = getFiles(folderName);
		if (picList.size() ==0)
			MessageBox::Show("ERROR: No files could be loaded from the chosen directory.\nMake sure there are files of an acceptable file type.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		genComparisons();
		changeComparison(0);
		currentDirectory = Stringtostring(folderName);
		updateRankings();
		totalImagesLabel->Text = "Total Images: " + (int)(picList.size());
		lowestComparisonLabel->Text = "Lowest Comparisons: 0";
	}
	else
		MessageBox::Show("ERROR: Inavlid Choice.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	
}

//save the current scores and comparisons to a csv to be opened later
void saveUserFile(){
	if(saveDifference){
		if (openedFlag) {//if the current directory was read from a file update that same file
			if (strictSort)
				strictSortSave();
			else{
				StreamWriter^ writer = gcnew StreamWriter(fileName);
				for (int i = 0; i < picList.size(); i++)
					writer->WriteLine("{0},{1},{2}", (gcnew String(picList[i].path.c_str())), picList[i].score, picList[i].comparisons);
				writer->Close();
				saveDifference = false;
				MessageBox::Show("Save successful!", "Save", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
		}
		else{//if the current directory is one that has never been saved then save it as a new file		
			if (saveFile->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				if (saveFile->FileName != ""){
					fileName = saveFile->FileName;
					if (strictSort)
						strictSortSave();
					else {
						StreamWriter^ writer = gcnew StreamWriter(fileName);
						for (int i = 0; i < picList.size(); i++)
							writer->WriteLine("{0},{1},{2}", (gcnew String(picList[i].path.c_str())), picList[i].score, picList[i].comparisons);
						writer->Close();
						saveDifference = false;
						MessageBox::Show("Save successful!", "Save", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
						openedFlag = true;
					}
				}
			}
		}
	}

	
}

//save file and exit the program
private: System::Void saveAndQuit_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size() > 0)//only save if there is a directory loaded
		saveUserFile();
	if (!saveDifference)
		quit();
}

//Clicked on File > Save
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if(picList.size() > 0)
		saveUserFile();
	else
		MessageBox::Show("ERROR: There is no currently loaded comparison directory to save.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}

//counts the number of lines in a savefile so that the progress bar knows how to represent the steps.
private: int countFileLines(String^ filePath){
	StreamReader^ r = gcnew StreamReader(filePath);
	 int i = 0;
	 while (r->ReadLine())
		 i++;

	 return i;
}

//opens a collection when given the path of a csv containing all of the saved data
void openFile(System::String^ filename){
	int minComparisons = INT_MAX;
	toolStripProgressBar1->Visible = true;
	toolStripProgressBar1->Minimum = 1;
	toolStripProgressBar1->Maximum = countFileLines(filename); //counts the number of lines in a file so that the progress bar knows how much is left
	toolStripProgressBar1->Value = 1;
	toolStripProgressBar1->Step = 1;
	StreamReader^ reader = gcnew StreamReader(filename);
	vector<image> tempList;
	fileName = filename;
	std::string holder, score = "", compare = "";
	bool invalidFlag = false, errorFlag = false;
	int flag = 0;
	holder = Stringtostring(reader->ReadLine());
	if (holder.compare("strictSort")){
		loadStrictSort();
	}
	else{
		while (reader->Peek() >= 0) {
			holder = Stringtostring(reader->ReadLine());
			image temp;
			for (int i = 0; i < holder.size(); i++) {
				if (flag == 1 && holder[i] != ',')
					score += holder[i];
				if (flag == 2)
					compare += holder[i];
				if (holder[i] == ',')
					flag++;
				if (!flag && holder[i] != ',')
					temp.path += holder[i];
			}
			flag = 0;
			temp.score = atoi(score.c_str());//convert score to an int
			temp.comparisons = atoi(compare.c_str());
			if (temp.comparisons < minComparisons)
				minComparisons = temp.comparisons;
			score = "";
			compare = "";
			if (validateFile(temp.path))
				tempList.push_back(temp);
			else
				invalidFlag = true;
			toolStripProgressBar1->PerformStep();
		}
	}
	//if no items are loaded throw an error
	if (tempList.size() == 0){
		MessageBox::Show("ERROR: No files could be loaded from this save\nFile may be empty or corrupted", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		errorFlag = true;
	}
	//if some images can not be loaded or are not valid tell the user via error box
	if (invalidFlag)
		MessageBox::Show("ERROR: Some of the images could not be loaded. They were either moved or are no longer valid", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	(*reader).Close();
	if (!errorFlag){
		lowestComparisonLabel->Text = "Lowest Comparisons: " + minComparisons;
		picList = tempList;
		if(sortByScore())
			scoreSort(&picList);
		if(sortByRating())
			ratingSort(&picList);
		currentDirectory = getDirectory(picList);
		genComparisons();
		changeComparison(0);
		updateRankings();
		openedFlag = true; //flag to show that that user opened a pre existing file
	}
	toolStripProgressBar1->Visible = false;
}


//open previously saved directory comparison
private: System::Void existingDirectoryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {	
	if (openExistingSave->ShowDialog() == System::Windows::Forms::DialogResult::OK){//ask user to select the save file
		index.clear();
		openFile(openExistingSave->FileName);
		totalImagesLabel->Text = "Total Images: " + (int)(picList.size());
	}
	else
		MessageBox::Show("ERROR: Failed to load file","Error Message", MessageBoxButtons::OKCancel,MessageBoxIcon::Asterisk);

}

//User chose an image and that image will now increment its score by either 1 or be set to 1+score of other image
private: void selectItem(int choice){
	switch (choice){
	case 1:
		if (picList[get<0>(index[crntCpr])].score < picList[get<1>(index[crntCpr])].score)
			picList[get<1>(index[crntCpr])].score++;
		else
			picList[get<1>(index[crntCpr])].score = picList[get<0>(index[crntCpr])].score + 1;
		break;
	case 2:
		if (picList[get<0>(index[crntCpr])].score > picList[get<1>(index[crntCpr])].score)
			picList[get<0>(index[crntCpr])].score++;

		else
			picList[get<0>(index[crntCpr])].score = picList[get<1>(index[crntCpr])].score + 1;
		break;
	}
	picList[get<0>(index[crntCpr])].comparisons++;
	picList[get<1>(index[crntCpr])].comparisons++;
	saveDifference = true;
}

//when user selects the left image, increment the score and change the comparison
private: System::Void selectLeft_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0){
		if (strictSort) {
			strictSortLeftIndex++;
			if(strictSortLeftIndex < strictSortList[strictSortindex].size())
				loadStrictSortComparison();
			else {
				for (int i = strictSortRightIndex; i < strictSortList[strictSortindex].size(); i++) {
					picList.push_back(strictSortList[strictSortindex][i]);
				}
				strictSortCompress();
			}

		}
		else {
			selectItem(2);
			changeComparison(1);
		}
	}
	else
		MessageBox::Show("ERROR: You cannot use this button when no pictures are loaded.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}

//when user selects the right image, increment the score and change the comparison
private: System::Void selectRight_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0){
		if (strictSort) {
			strictSortRightIndex++;
			if (strictSortRightIndex < strictSortList[strictSortindex].size())
				loadStrictSortComparison();
			else {
				for (int i = strictSortLeftIndex; i < strictSortList[strictSortindex].size(); i++) {
					picList.push_back(strictSortList[strictSortindex][i]);
				}
				strictSortCompress();
			}

		}
		else {
			selectItem(1);
			changeComparison(1);
		}
	}
	else
		MessageBox::Show("ERROR: You cannot use this button when no pictures are loaded.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
}

//generate the list of image pairs for the user to compare.
void genComparisons(){
	srand(time(NULL));
	int k = picList.size()-1;
	while (k > 0)
	{
		bool flag = false, inflag = false;
		int c = rand() % k;
		if (checkIfCompared(k)){
			k--;
			inflag = true;
		}
		if (!inflag){ 
			if (picList[c].score == picList[k].score && checkIfCompared(c)){
					pair<int, int> temp(c, k);
					index.push_back(temp);
					k--;
			}
			else{
				for (int i = c; i < k; i++){//if the two chosen pictures do not have the same score search for one that does. only searches up to maintain some randomness
					if (picList[i].score == picList[k].score && i != k){
						if (!checkIfCompared(i)){
							pair<int, int> temp(i, k);
							index.push_back(temp);
							flag = true;
							k--;
							break;
						}
					}
				}
				if (!flag){
					pair<int, int> temp(c, k);
					index.push_back(temp);
					k--;
				}
			}
		}
	}
	comparisonSort(&index);
 }


//sorts the pairs of images by the number of comparisons they have gone through
vector<std::pair<int, int>> comparisonMerge(vector<std::pair<int, int>> left, vector<std::pair<int, int>> right)
{
	vector<std::pair<int, int>> holder;
	int i = 0, k = 0;
	do{
		if (picList[get<0>(right[k])].comparisons + picList[get<1>(right[k])].comparisons > picList[get<0>(left[i])].comparisons + picList[get<1>(left[i])].comparisons){
			holder.push_back(left[i]);
			i++;
		}
		else{
			holder.push_back(right[k]);
			k++;
		}
	} while (i < left.size() && k < right.size());
	while (i < left.size()){
		holder.push_back(left[i]);
		i++;
	}
	while (k < right.size()){
		holder.push_back(right[k]);
		k++;
	}
	return holder;
}

void comparisonSort(vector<std::pair<int, int>>* list)
{
	if (list->size() <= 1)
		return;
	vector<std::pair<int, int>> left, right;
	left.assign(list->begin(), list->begin() + ((list->size()) / 2));
	right.assign(list->begin() + (list->size() / 2), list->end());
	comparisonSort(&left);
	comparisonSort(&right);
	(*list) = comparisonMerge(left, right);
	return;
}

//check to see if a item already has a comparison
bool checkIfCompared(int c){
	bool inflag = false;
	for (int i = 0; i < index.size(); i++){
		if (c == get<0>(index[i]) || c == get<1>(index[i])){
			return true;
		}
	}
	return false;
}

//Change the comparison of the two images. Negative numbers to go back one.
void changeComparison(int increment){
	crntCpr+=increment;
	if (index.size() < crntCpr+1){
		pair<int, int> temp = index[crntCpr-1];
		index.clear();
		genComparisons();
		index.insert(index.begin(),temp);
		crntCpr = 1;
	}
	try{
		leftImage->Load(leftString());
	}
	catch (...){ //to catch files that can not be loaded by picturebox (usually corrupt) 
		MessageBox::Show("ERROR: File could not be loaded by box, it may\nbe corrupt or an unsuported format.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		picList.erase(picList.begin()+ get<0>(index[crntCpr]));
		index.clear();
		genComparisons();
		changeComparison(1);
	}
	try{
		rightImage->Load(rightString());
	}
	catch (...){//to catch files that can not be loaded by picturebox (usually corrupt) 
		MessageBox::Show("ERROR: File could not be loaded by box, it may\nbe corrupt or an unsuported format.\n", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		picList.erase(picList.begin() + get<1>(index[crntCpr]));
		index.clear();
		genComparisons();
		changeComparison(1);
	}
	//set all the dependent text after the images are loaded
	rightCurrentScore->Text = "Score: " + picList[get<1>(index[crntCpr])].score;
	leftCurrentScore->Text = "Score: " + (picList[get<0>(index[crntCpr])].score);
	rightNumComparisons->Text = "Number of comparisons: " + picList[get<1>(index[crntCpr])].comparisons;
	leftNumComparisons->Text = "Number of comparisons: " + picList[get<0>(index[crntCpr])].comparisons;
	rightRating->Text = "Rating: " + Math::Round(getRating(picList[get<1>(index[crntCpr])]),2);
	leftRating->Text = "Rating: " + Math::Round(getRating(picList[get<0>(index[crntCpr])]),2);
	leftPath->Text = leftString();
	rightPath->Text = rightString();
	if (updateContinuously()) //only update ranking if that setting is active
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
	Process::Start("https://github.com/xMausoleuMx/Picture-Sorting");
}

//Open the left image in the default image viewing program
private: System::Void leftImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if(picList.size()>0)
		Process::Start(leftString());
}

//Open the right image in the default image viewing program
private: System::Void rightImage_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0)
		Process::Start(rightString());
}
//When an item in the top listbox is double clicked, it is opened externally
private: System::Void topImages_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size() > 0){
		string holder = getFullPath(topImages->SelectedItem->ToString());
		Process::Start(gcnew String(holder.c_str()));
	}
}

//used to get the partial path displayed in the listboxes and search for their full paths
private: string getFullPath(System::String^ partial){
	string holder = Stringtostring(partial);
	string target;
	for (int i = holder.size(); i > 0; i--){ //cut off the score and just retrieve the partial path.
		if (holder[i] == ' '){
			target.assign(holder.begin()+i+1, holder.end());
			break;
		}
	 }
	for (int i = 0; i < picList.size(); i++){
		size_t found = picList[i].path.find(target);
		if (found != string::npos){
			return picList[i].path;
		}
	}
}

//shortcut keys
private: System::Void container_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::F1)//opens github page
		Process::Start("https://github.com/xMausoleuMx/Picture-Sorting");
	if (e->KeyCode == Keys::F4)//closes program
		quit();
	if ((e->KeyCode == Keys::D) && picList.size() > 0){//selects right image
		selectItem(1);
		changeComparison(1);
	}
	if ((e->KeyCode == Keys::A) && picList.size() > 0){//selects left image
		selectItem(2);
		changeComparison(1);
	}
	if (e->KeyCode == Keys::S && picList.size() > 0){//saves file
		saveUserFile();
	}
}

//opens the wiki on github
private: System::Void fAQToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Process::Start("https://github.com/xMausoleuMx/Picture-Sorting/wiki");
}

//close the program
void quit(){
	if (!saveDifference)//checks if the user has made changes since the last save and prompts them to save before quitting if not
		exit(EXIT_SUCCESS);
	else{
		if (MessageBox::Show("You have unsaved changes to your directory, would\nyou like to save them before you quit?", "Save?", MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes){
			saveUserFile();
			quit();
		}
		else
			exit(EXIT_SUCCESS);
	}
}

//open the form to edit user options
private: System::Void editOptions_Click(System::Object^  sender, System::EventArgs^  e) {
	optionsForm ^ optionWindow = gcnew optionsForm(&settings);
	optionWindow->ShowDialog();
}

//open the trim collection window when the corresponding is button pressed
private: System::Void trimCollection_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size() > 0){
		ratingSort(&picList);
		PictureSorting::trimCollection^  trimWindow = gcnew PictureSorting::trimCollection(&picList);
		trimWindow->ShowDialog();
		genComparisons();
		updateRankings();
		saveDifference = true;
	}
}

//add items to the collection from a user selected directory
private: System::Void addItemsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::DialogResult result = openNewDirectory->ShowDialog();
	System::String^ folderName;
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		vector<image> tempList;
		folderName = openNewDirectory->SelectedPath;
		folderName = (*folderName).Concat(folderName, "\\");
		tempList = getFiles(folderName);
		if (tempList.size() == 0)
			MessageBox::Show("ERROR: No files could be loaded from the chosen directory.\nMake sure there are files of an acceptable file type.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		for (int i = 0; i < tempList.size(); i++){//checks if the file is already in the collection.
			bool flag = false;
			for (int k = 0; k < picList.size(); k++){
				if (!tempList[i].path.compare(picList[k].path)){
					flag = true;
					break;
				}
			}
			if (!flag){
				picList.insert(picList.end(), tempList[i]);
			}
		}
		saveDifference = true;
		updateRankings();
		genComparisons();
	}
}

//Changes the mouse cursor when hovering over the pictureboxes to indacate they are clickable 

private: System::Void rightImage_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	
	Cursor = Cursors::Default;
}
private: System::Void leftImage_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	Cursor = Cursors::Default;
}
private: System::Void leftImage_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0)
		Cursor = Cursors::Hand;
}		 
private: System::Void rightImage_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size()>0)
		Cursor = Cursors::Hand;
}

private: System::Void container_Load(System::Object^  sender, System::EventArgs^  e) {
}

//clicked from the toolstrip to enable a perfect sort of the current image collection.
private: System::Void enablePerfectSortToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (picList.size() < 1){
		MessageBox::Show("You need to load a collection of images before you can turn on strict sort.", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
		return;
	}
	std::string holder = "By selecting this you are committing to sorting by a strict merge sort method.\nSorting this way will mean the collection will be out of order until the entire thing has been sorted and you will not be able to stop in the middle when the collection is \"close enough\"\nGiven the size of the collection it will take ";
	holder += std::to_string((int)(picList.size()*log(picList.size())));
	holder += " comparisons until the collection is sorted.\nPress OK to continue";
	if (System::Windows::Forms::DialogResult::OK == MessageBox::Show(gcnew String(holder.c_str()), "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk)) {
		strictSort = true;
		generateStrictSort(&picList);
		loadStrictSortComparison();
	}

}


void loadStrictSortComparison() {
	try {
		leftImage->Load(gcnew String(strictSortList[strictSortindex][strictSortLeftIndex].path.c_str()));
	}
	catch (...) {
		MessageBox::Show("ERROR: Left file could not be loaded by box, it may\nbe corrupt or an unsuported format.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	}
	try {
		if(strictSortindex+1 <strictSortList.size())
			rightImage->Load(gcnew String(strictSortList[strictSortindex+1][strictSortRightIndex].path.c_str()));
		else
			rightImage->Load(gcnew String(strictSortList[0][strictSortRightIndex].path.c_str()));
	}
	catch (...) {
		MessageBox::Show("ERROR: Right file could not be loaded by box, it may\nbe corrupt or an unsuported format.", "Error Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	}
}

/*
vector<image> mergeStrictSort(vector<image> left, vector<image> right) {
	vector<image>holder;
	int i = 0, k = 0;
	do {
		if (compare(left[i], right[k])) {
			holder.push_back(left[i]);
			i++;
		}
		else {
			holder.push_back(right[k]);
			k++;
		}
	} while (i < left.size() && k < right.size());
	while (i < left.size()) {
		holder.push_back(left[i]);
		i++;
	}
	while (k < right.size()) {
		holder.push_back(right[k]);
		k++;
	}
	return holder;
}
*/
void generateStrictSort(vector<image>* list) {
	if (list->size() <= 1) {
		strictSortList.push_back(*list);
		return;
	}
	vector<image> left, right;
	left.assign(list->begin(), list->begin() + ((list->size()) / 2));
	right.assign(list->begin() + (list->size() / 2), list->end());
	generateStrictSort(&left);
	generateStrictSort(&right);
	//(*list) = mergeStrictSort(left, right);
	return;
}

void strictSortCompress() {
	strictSortList[strictSortindex] = picList;
	strictSortList.erase(strictSortList.begin() + strictSortindex + 1);
	strictSortLeftIndex = 0;
	strictSortRightIndex = 0;
	if (strictSortindex + 1 < strictSortList.size())
		strictSortindex++;
	else
		strictSortindex = 0;
	if (strictSortList.size() == 1) {
		MessageBox::Show("Sorting Complete", "temporary Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	}
	else
		loadStrictSortComparison();
}

void strictSortSave(){
	StreamWriter^ writer = gcnew StreamWriter(fileName);
	writer->WriteLine("strictSort");
	for (int i = 0; i < strictSortList.size(); i++) {
		for (int y = 0; y < strictSortList[i].size(); y++) {
			writer->Write("{0},", gcnew String(strictSortList[i][y].path.c_str()));
		}
		writer->WriteLine(" ");
	}
	writer->Close();
	openedFlag = true;
	saveDifference = false;
}

void loadStrictSort() {
	StreamReader^ reader = gcnew StreamReader(fileName);
	string holder;
	while (reader->Peek() >= 0) {
		holder = Stringtostring(reader->ReadLine());
		vector<image> temp;
		string path;
		for (int i = 0; i < holder.size(); i++) {
			if (holder[i] == ',') {
				image blank;
				blank.path = path;
				temp.push_back(blank);
				path = "";
			}
			else
				path += holder[i];
		}
		strictSortList.push_back(temp);
	}
	reader->Close();
}
};

}
