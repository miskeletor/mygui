/*!
	@file
	@author		Albert Semenov
	@date		08/2010
*/
#ifndef __EDITOR_STATE_H__
#define __EDITOR_STATE_H__

#include "StateController.h"
#include "Control.h"
#include "Tools/OpenSaveFileDialog.h"
#include "MessageBoxFadeControl.h"
#include "MessageBox/MessageBox.h"
#include "SettingsWindow.h"
#include "sigslot.h"

namespace tools
{
	class EditorState :
		public StateController,
		public sigslot::has_slots<>
	{
	public:
		EditorState();
		virtual ~EditorState();

		virtual void initState();
		virtual void cleanupState();

		virtual void pauseState();
		virtual void resumeState();

	private:
		void notifyMessageBoxResultLoad(MyGUI::Message* _sender, MyGUI::MessageBoxStyle _result);
		void notifyMessageBoxResultClear(MyGUI::Message* _sender, MyGUI::MessageBoxStyle _result);
		void notifyMessageBoxResultQuit(MyGUI::Message* _sender, MyGUI::MessageBoxStyle _result);
		void notifyMessageBoxResultLoadDropFile(MyGUI::Message* _sender, MyGUI::MessageBoxStyle _result);

		void notifyEndDialog(Dialog* _sender, bool _result);
		void notifyChanges();
		void notifySettingsWindowEndDialog(Dialog* _dialog, bool _result);

		void commandFileDrop(const MyGUI::UString& _commandName, bool& _result);
		void commandLoad(const MyGUI::UString& _commandName, bool& _result);
		void commandSave(const MyGUI::UString& _commandName, bool& _result);
		void commandSaveAs(const MyGUI::UString& _commandName, bool& _result);
		void commandClear(const MyGUI::UString& _commandName, bool& _result);
		void commandSettings(const MyGUI::UString& _commandName, bool& _result);
		//void commandTest(const MyGUI::UString& _commandName, bool& _result);
		void commandRecentFiles(const MyGUI::UString& _commandName, bool& _result);
		void commandQuit(const MyGUI::UString& _commandName, bool& _result);
		void commandUndo(const MyGUI::UString& _commandName, bool& _result);
		void commandRedo(const MyGUI::UString& _commandName, bool& _result);

		void clear();
		bool save();
		void load();
		void loadDropFile();

		void showLoadWindow();
		void showSaveAsWindow();

		void updateCaption();

		bool checkCommand();

	private:
		MyGUI::UString mFileName;
		MyGUI::UString mDefaultFileName;
		MyGUI::UString mDropFileName;

		Control* mMainPane;
		OpenSaveFileDialog* mOpenSaveFileDialog;
		MessageBoxFadeControl* mMessageBoxFadeControl;
		SettingsWindow* mSettingsWindow;
	};

} // namespace tools

#endif // __EDITOR_STATE_H__