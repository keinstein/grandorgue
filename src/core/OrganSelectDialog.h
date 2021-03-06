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

#ifndef ORGANSELECTDIALOG_H_
#define ORGANSELECTDIALOG_H_

#include <wx/dialog.h>
#include <wx/listctrl.h>

class GOrgueOrgan;
class GOrgueOrganList;

class OrganSelectDialog : public wxDialog
{
private:
	const GOrgueOrganList& m_OrganList;
	wxListView* m_Organs;

	enum {
		ID_ORGANS = 200
	};

	void OnOK(wxCommandEvent& event);
	void OnDoubleClick(wxListEvent& event);

public:
	OrganSelectDialog(wxWindow* parent, wxString title, const GOrgueOrganList& organList);

	const GOrgueOrgan* GetSelection();

	DECLARE_EVENT_TABLE()
};

#endif
