#include "optionsForm.h"
#using <System.dll>
#pragma once
#define currentImagePath()(gcnew String(((*searchList)[searchIndex].path.c_str())))
namespace PictureSorting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	
	/* <summary>
	    Allows a user who doesnt know exactly where to trim his collection to search for the specific point that meets his
	criteria. Uses a binary search of the image collection.
	</summary>*/ 
	public ref class searchForm : public System::Windows::Forms::Form
	{
		vector<image>* searchList;
		bool selectFromTop;
		int upperbound, lowerbound =0;
	private: System::Windows::Forms::Button^  yesButton;
	private: System::Windows::Forms::Button^  noButton;
	private: System::Windows::Forms::Label^  displayText;
	private: System::Windows::Forms::FolderBrowserDialog^  getFinalDestination;

			 int searchIndex = 0;
	public:
		searchForm(vector<image>* temp, bool istop)
		{
			InitializeComponent();
			searchList = temp;
			searchIndex = searchList->size() / 2;
			selectFromTop = istop;
			upperbound = temp->size();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~searchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  displayImage;
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
			this->displayImage = (gcnew System::Windows::Forms::PictureBox());
			this->yesButton = (gcnew System::Windows::Forms::Button());
			this->noButton = (gcnew System::Windows::Forms::Button());
			this->displayText = (gcnew System::Windows::Forms::Label());
			this->getFinalDestination = (gcnew System::Windows::Forms::FolderBrowserDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->displayImage))->BeginInit();
			this->SuspendLayout();
			// 
			// displayImage
			// 
			this->displayImage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->displayImage->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->displayImage->Location = System::Drawing::Point(13, 12);
			this->displayImage->Name = L"displayImage";
			this->displayImage->Size = System::Drawing::Size(774, 389);
			this->displayImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->displayImage->TabIndex = 0;
			this->displayImage->TabStop = false;
			this->displayImage->Click += gcnew System::EventHandler(this, &searchForm::displayImage_Click);
			// 
			// yesButton
			// 
			this->yesButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->yesButton->Location = System::Drawing::Point(13, 447);
			this->yesButton->Name = L"yesButton";
			this->yesButton->Size = System::Drawing::Size(91, 38);
			this->yesButton->TabIndex = 1;
			this->yesButton->Text = L"Yes";
			this->yesButton->UseVisualStyleBackColor = true;
			this->yesButton->Click += gcnew System::EventHandler(this, &searchForm::yesButton_Click);
			// 
			// noButton
			// 
			this->noButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->noButton->Location = System::Drawing::Point(696, 447);
			this->noButton->Name = L"noButton";
			this->noButton->Size = System::Drawing::Size(91, 38);
			this->noButton->TabIndex = 2;
			this->noButton->Text = L"No";
			this->noButton->UseVisualStyleBackColor = true;
			this->noButton->Click += gcnew System::EventHandler(this, &searchForm::noButton_Click);
			// 
			// displayText
			// 
			this->displayText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->displayText->AutoSize = true;
			this->displayText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displayText->Location = System::Drawing::Point(112, 404);
			this->displayText->Name = L"displayText";
			this->displayText->Size = System::Drawing::Size(567, 29);
			this->displayText->TabIndex = 3;
			this->displayText->Text = L"Does this image meet the requirements for the cull\? ";
			this->displayText->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// getFinalDestination
			// 
			this->getFinalDestination->Description = L"Choose the folder where you wish for the images to be moved to.";
			// 
			// searchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 497);
			this->Controls->Add(this->displayText);
			this->Controls->Add(this->noButton);
			this->Controls->Add(this->yesButton);
			this->Controls->Add(this->displayImage);
			this->Name = L"searchForm";
			this->Text = L"Trim";
			this->Load += gcnew System::EventHandler(this, &searchForm::searchForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->displayImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//open the currently displayed image in its default program.
	private: System::Void displayImage_Click(System::Object^  sender, System::EventArgs^  e) {
		Process::Start(currentImagePath());
	}

	//set up initial image and settings
	private: System::Void searchForm_Load(System::Object^  sender, System::EventArgs^  e) {
		updateImage();
		if (selectFromTop)
			displayText->Text = L"Is this image good enough to be in the top portion\? ";
		else
			displayText->Text = L"Is this image bad enough to be in the bottom portion\? ";
	}

	//change image to new indexed location
	void updateImage(){
		displayImage->Load(currentImagePath());
	}

	//User clicks the yes button
	private: System::Void yesButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (selectFromTop)
			lowerbound = searchIndex+1;		
		else
			upperbound = searchIndex-1;
		searchIndex = lowerbound + ((upperbound - lowerbound) / 2);
		checkIndex();
		updateImage();
	}

	//User clicks the no button
	private: System::Void noButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (selectFromTop)
			upperbound = searchIndex-1;
		else
			lowerbound = searchIndex+1;
		searchIndex = lowerbound + ((upperbound - lowerbound) / 2);
		checkIndex();
		updateImage();
	}

	//check and see if the search has completed, and if so move the files.
	void checkIndex(){
		bool flag = false;
		if (lowerbound == upperbound || upperbound == searchIndex || lowerbound == searchIndex){
			if (getFinalDestination->ShowDialog() == System::Windows::Forms::DialogResult::OK){
				for (int i = (selectFromTop ? searchIndex : 0); i < (selectFromTop ? searchList->size() : searchIndex); i++)
					if (!moveImage((*searchList)[i].path, getFinalDestination->SelectedPath))
						flag = true;
			}
			if (flag)
				MessageBox::Show("Error:Not all files moved\nSome Files failed to move", "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			else
				MessageBox::Show("Files Moved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			this->Close();
		}
	}
};
}
