/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2019 GrandOrgue contributors (see AUTHORS)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GORGUEBUTTON_H
#define GORGUEBUTTON_H

#include "GOrgueEventHandler.h"
#include "GOrgueKeyReceiver.h"
#include "GOrgueMidiConfigurator.h"
#include "GOrgueMidiReceiver.h"
#include "GOrgueMidiSender.h"
#include "GOrguePlaybackStateHandler.h"
#include "GOrgueSaveableObject.h"
#include <wx/string.h>

class GOrgueConfigReader;
class GOrgueConfigWriter;
class GOrgueMidiEvent;
class GrandOrgueFile;

class GOrgueButton : private GOrgueEventHandler, protected GOrgueSaveableObject, protected GOrguePlaybackStateHandler,
	public GOrgueMidiConfigurator
{
protected:
	GrandOrgueFile* m_organfile;
	GOrgueMidiReceiver m_midi;
	GOrgueMidiSender m_sender;
	GOrgueKeyReceiver m_shortcut;
	bool m_Pushbutton;
	bool m_Displayed;
	wxString m_Name;
	bool m_Engaged;
	bool m_DisplayInInvertedState;
	bool m_ReadOnly;

	void ProcessMidi(const GOrgueMidiEvent& event);
	void HandleKey(int key);

	void Save(GOrgueConfigWriter& cfg);

	void AbortPlayback();
	void StartPlayback();
	void PreparePlayback();
	void PrepareRecording();

public:
	GOrgueButton(GrandOrgueFile* organfile, MIDI_RECEIVER_TYPE midi_type, bool pushbutton);
	virtual ~GOrgueButton();
	void Init(GOrgueConfigReader& cfg, wxString group, wxString name);
	void Load(GOrgueConfigReader& cfg, wxString group);
	bool IsDisplayed();
	bool IsReadOnly();
	const wxString& GetName();

	virtual void Push();
	virtual void Set(bool on);
	virtual void Display(bool onoff);
	bool IsEngaged() const;
	bool DisplayInverted() const;
	void SetElementID(int id);
	void SetShortcutKey(unsigned key);
	void SetPreconfigIndex(unsigned index);

	wxString GetMidiName();
	void ShowConfigDialog();

	wxString GetElementStatus();
	std::vector<wxString> GetElementActions();
	void TriggerElementActions(unsigned no);
};

#endif
