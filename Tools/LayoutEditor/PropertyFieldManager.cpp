/*!
	@file
	@author		Albert Semenov
	@date		08/2010
*/
#include "Precompiled.h"
#include "PropertyFieldManager.h"
#include "PropertyFieldComboBox.h"
#include "PropertyFieldEditBox.h"
#include "PropertyFieldEditBoxAccept.h"

template <> tools::PropertyFieldManager* MyGUI::Singleton<tools::PropertyFieldManager>::msInstance = nullptr;
template <> const char* MyGUI::Singleton<tools::PropertyFieldManager>::mClassTypeName("PropertyFieldManager");

namespace tools
{

	PropertyFieldManager::PropertyFieldManager()
	{
	}

	PropertyFieldManager::~PropertyFieldManager()
	{
	}

	void PropertyFieldManager::initialise()
	{
	}

	void PropertyFieldManager::shutdown()
	{
	}

	IPropertyField* PropertyFieldManager::createPropertyField(MyGUI::Widget* _window, const std::string& _type, MyGUI::Widget* _currentWidget)
	{
		IPropertyField* result = nullptr;

		if ("Name" == _type)
			result = new PropertyFieldEditBox();
		else if ("Type" == _type)
			result = new PropertyFieldComboBox();
		else if ("Skin" == _type)
			result = new PropertyFieldComboBox();
		else if ("Position" == _type)
			result = new PropertyFieldEditBox();
		else if ("Layer" == _type)
			result = new PropertyFieldComboBox();
		else if ("String" == _type)
			result = new PropertyFieldEditBox();
		else if ("StringAccept" == _type)
			result = new PropertyFieldEditBoxAccept();
		else if ("Align" == _type)
			result = new PropertyFieldComboBox();
		else if ("FileName" == _type)
			result = new PropertyFieldEditBox();
		else if ("1 int" == _type)
			result = new PropertyFieldEditBox();
		else if ("2 int" == _type)
			result = new PropertyFieldEditBox();
		else if ("4 int" == _type)
			result = new PropertyFieldEditBox();
		else if ("alpha" == _type)
			result = new PropertyFieldEditBox();
		else if ("1 float" == _type)
			result = new PropertyFieldEditBox();
		else if ("2 float" == _type)
			result = new PropertyFieldEditBox();
		else if ("Colour" == _type)
			result = new PropertyFieldEditBox();
		else
			result = new PropertyFieldComboBox();

		result->initialise(_window,  _type, _currentWidget);
		return result;
	}

} // namespace tools