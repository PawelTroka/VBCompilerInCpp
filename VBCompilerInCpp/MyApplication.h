#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Windows;
using namespace System::Windows::Controls;
using namespace System::Windows::Markup;
using namespace System::CodeDom;
using namespace System::CodeDom::Compiler;
using namespace System::Windows::Documents;
using namespace System::Reflection;

ref class MyApplication :
public Application
{
private: Button ^addBtn, ^invokeBtn, ^setBtn;
private: RichTextBox ^codeRTB;
private: TextBox ^invokeTB, ^setTB;
private: ListBox ^methodsListBox, ^errorsListBox, ^variablesListBox;

private: Object ^object;


private: System::Void OnSelectionMethodsListBoxChanged(Object^ sender,
	SelectionChangedEventArgs^ e)
{
	// Add your code here
}

private: System::Void OnSelectionVariablesListBoxChanged(Object^ sender,
	SelectionChangedEventArgs^ e)
{
	// Add your code here
}

private: System::Void OnSetBtnClick(Object^ sender,
	RoutedEventArgs^ e)
{

}


private: System::Void OnInvokeBtnClick(Object^ sender,
	RoutedEventArgs^ e)
{
	MethodInfo^ method = (MethodInfo^)methodsListBox->SelectedItem;

	method->Invoke(object, gcnew array < System::Object^, 1 > {invokeTB->Text});
}

private: System::Void OnAddBtnClick(Object^ sender, RoutedEventArgs^ e);


public:
	MyApplication(Window ^win) {

		addBtn = (Button^)win->FindName("addBtn");
		addBtn->Click += gcnew RoutedEventHandler(this, &MyApplication::OnAddBtnClick);



		invokeBtn = (Button^)win->FindName("invokeBtn");
		invokeBtn->Click += gcnew RoutedEventHandler(this, &MyApplication::OnInvokeBtnClick);



		setBtn = (Button^)win->FindName("setBtn");
		setBtn->Click += gcnew RoutedEventHandler(this, &MyApplication::OnSetBtnClick);


		codeRTB = (RichTextBox^)win->FindName("codeRTB");


		invokeTB = (TextBox^)win->FindName("invokeTB");
			
			
		setTB = (TextBox^)win->FindName("setTB");


		errorsListBox=(ListBox^)win->FindName("errorsListBox");

		methodsListBox = (ListBox^)win->FindName("methodsListBox");
		methodsListBox->SelectionChanged += gcnew
			System::Windows::Controls::SelectionChangedEventHandler(this,
			&MyApplication::OnSelectionMethodsListBoxChanged);



		variablesListBox = (ListBox^)win->FindName("variablesListBox");
		variablesListBox->SelectionChanged += gcnew
			System::Windows::Controls::SelectionChangedEventHandler(this,
			&MyApplication::OnSelectionVariablesListBoxChanged);
	}
};

