/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2011 GrandOrgue contributors (see AUTHORS)
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
 * MA 02111-1307, USA.
 */

#include "GOrguePipeConfig.h"
#include "GrandOrgueFile.h"
#include "IniFileConfig.h"

GOrguePipeConfig::GOrguePipeConfig(GrandOrgueFile* organfile, GOrguePipeUpdateCallback* callback) :
	m_OrganFile(organfile),
	m_Callback(callback),
	m_Group(),
	m_NamePrefix(),
	m_Amplitude(0),
	m_DefaultAmplitude(0),
	m_Tuning(0),
	m_DefaultTuning(0)
{
}

void GOrguePipeConfig::Load(IniFileConfig& cfg, wxString group, wxString prefix)
{
	m_Group = group;
	m_NamePrefix = prefix;
	m_DefaultAmplitude = cfg.ReadFloat(group, prefix + wxT("AmplitudeLevel"), 0, 1000, false, 100);
	m_Amplitude = cfg.ReadFloat(group, prefix + wxT("Amplitude"), 0, 1000, false, m_DefaultAmplitude);
	m_DefaultTuning = cfg.ReadFloat(group, prefix + wxT("PitchTuning"), -1200, 1200, false, 0);
	m_Tuning = cfg.ReadFloat(group, prefix + wxT("Tuning"), -1200, 1200, false, m_DefaultTuning);
	m_Callback->UpdateAmplitude();
	m_Callback->UpdateTuning();
}

void GOrguePipeConfig::Save(IniFileConfig& cfg, bool prefix)
{
	cfg.SaveHelper(prefix, m_Group, m_NamePrefix + wxT("Amplitude"), m_Amplitude);
	cfg.SaveHelper(prefix, m_Group, m_NamePrefix + wxT("Tuning"), m_Tuning);
}

float GOrguePipeConfig::GetAmplitude()
{
	return m_Amplitude;
}

float GOrguePipeConfig::GetDefaultAmplitude()
{
	return m_DefaultAmplitude;
}

void GOrguePipeConfig::SetAmplitude(float amp)
{
	m_Amplitude = amp;
	m_OrganFile->Modified();
	m_Callback->UpdateAmplitude();
}

float GOrguePipeConfig::GetTuning()
{
	return m_Tuning;
}

float GOrguePipeConfig::GetDefaultTuning()
{
	return m_DefaultTuning;
}

void GOrguePipeConfig::SetTuning(float cent)
{
	m_Tuning = cent;
	m_OrganFile->Modified();
	m_Callback->UpdateTuning();
}