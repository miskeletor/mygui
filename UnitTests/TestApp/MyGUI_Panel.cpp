/*!
	@file
	@author		Albert Semenov
	@date		01/2010
*/
/*
	This file is part of MyGUI.

	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "MyGUI_Precompiled.h"
#include "MyGUI_Panel.h"
#include "MyGUI_ResourceSkin.h"

namespace MyGUI
{

	Panel::Panel()
	{
	}

	IntSize Panel::overrideMeasure(const IntSize& _sizeAvailable)
	{
		return IntSize();//Base::overrideMeasure(_sizeAvailable);
	}

	void Panel::overrideArrange(const IntSize& _sizeOld)
	{
		//Base::overrideArrange(_sizeOld);
	}

	const IntRect& Panel::getPadding()
	{
		/*if (mWidgetClient != nullptr)
			return mWidgetClient->getPadding();*/

		return mPadding;
	}

	void Panel::setPadding(const IntRect& _value)
	{
		/*if (mWidgetClient != nullptr)
			mWidgetClient->setPadding(_value);*/

		mPadding = _value;
		invalidateMeasure();
	}

	void Panel::invalidateMeasure()
	{
	}

	void Panel::updateMeasure(Widget* _widget, const IntSize& _sizeAvailable)
	{
	}

	void Panel::updateArrange(Widget* _widget, const IntCoord& _coordPlace, const IntSize& _oldsize)
	{
	}

	IntSize Panel::getDesiredSize(Widget* _widget)
	{
		return IntSize::parse(_widget->getUserString("DesiredSize"));
	}

	void Panel::setDesiredSize(Widget* _widget, const IntSize& _value)
	{
		return _widget->setUserString("DesiredSize", _value.print());
	}

} // namespace MyGUI