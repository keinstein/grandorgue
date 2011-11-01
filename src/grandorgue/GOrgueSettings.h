/*
 * GrandOrgue - free pipe organ simulator based on MyOrgan
 *
 * MyOrgan 1.0.6 Codebase - Copyright 2006 Milan Digital Audio LLC
 * MyOrgan is a Trademark of Milan Digital Audio LLC
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */

#ifndef GORGUESETTINGS_H
#define GORGUESETTINGS_H

class wxConfigBase;

class GOrgueSettings {
private:
	wxConfigBase& m_Config;
	bool m_Stereo;
	unsigned m_Concurrency;
	unsigned m_ReleaseConcurrency;

public:
	GOrgueSettings();

	void Load();

	bool GetLoadInStereo();
	void SetLoadInStereo(bool stereo);

	unsigned GetConcurrency();
	void SetConcurrency(unsigned concurrency);
	unsigned GetReleaseConcurrency();
	void SetReleaseConcurrency(unsigned concurrency);
};

#endif