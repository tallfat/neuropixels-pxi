/*
------------------------------------------------------------------

This file is part of the Open Ephys GUI
Copyright (C) 2020 Allen Institute for Brain Science and Open Ephys

------------------------------------------------------------------

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __NEUROPIXNHP_PASSIVE_H_2C4C2D67__
#define __NEUROPIXNHP_PASSIVE_H_2C4C2D67__

#include "../NeuropixComponents.h"

#include "../API/v1/NeuropixAPI.h"
#include "../API/v3/NeuropixAPI.h"

# define SAMPLECOUNT 64

class Neuropixels_NHP_Passive : public Probe
{
public:
	Neuropixels_NHP_Passive(Basestation* bs, Headstage* hs, Flex* fl);

	void getInfo() override;

	void initialize() override;

	void selectElectrodes(ProbeSettings settings, bool shouldWriteConfiguration = true) override;
	void setAllReferences(int referenceIndex, bool shouldWriteConfiguratio = true) override;
	void setAllGains(int apGainIndex, int lfpGainIndex, bool shouldWriteConfiguration = true) override;
	void setApFilterState(bool disableHighPass, bool shouldWriteConfiguration = true) override;
	void writeConfiguration() override;

	void startAcquisition() override;
	void stopAcquisition() override;

	void calibrate() override;

	void run() override; // acquire data

	bool generatesLfpData() { return true; }
	bool hasApFilterSwitch() { return true; }

	Neuropixels::electrodePacket packet[SAMPLECOUNT];
	Neuropixels::NP_ErrorCode errorCode;

	Array<int> channel_map;

};


#endif  // _NEUROPIXNHP_PASSIVE_2C4C2D67__
