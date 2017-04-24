#include "MyApplication.h"



System::Void MyApplication::OnAddBtnClick(Object^ sender, RoutedEventArgs^ e)
{

	CompilerParameters^ param = gcnew CompilerParameters();
	param->GenerateInMemory = true;
	param->ReferencedAssemblies->Add("Microsoft.VisualBasic.dll");
	param->ReferencedAssemblies->Add("System.Windows.Forms.dll");

	String^ code = (gcnew TextRange(codeRTB->Document->ContentStart, codeRTB->Document->ContentEnd))->Text;

	CodeSnippetCompileUnit^ csu = gcnew CodeSnippetCompileUnit(code);

	CodeDomProvider^ prov = CodeDomProvider::CreateProvider("VisualBasic");
	CompilerResults^ res = prov->CompileAssemblyFromDom(param, csu);

	if (res->Errors->Count > 0)
	{
		for each (CompilerError^ var in res->Errors)
		{
			errorsListBox->Items->Add(var->ErrorText);
		}
	}
	else
	{
		array<System::Type^>^ types = res->CompiledAssembly->GetTypes();
		Type^ type = types[types->Length - 1];

		object = Activator::CreateInstance(type);

		for each (MethodInfo^ var in type->GetMethods())
		{
			methodsListBox->Items->Add(var);
		}



		for each (PropertyInfo^ var in type->GetProperties())
		{
			variablesListBox->Items->Add(var);
		}

		for each (FieldInfo^ var in type->GetFields())
		{
			variablesListBox->Items->Add(var);
		}

	}
}